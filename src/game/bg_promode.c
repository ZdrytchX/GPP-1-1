/*
=========================================================================================================
This file contains code that was retreived and modified from
http://games.linuxdude.com/tamaps/archive/cpm1_dev_docs.zip

Tremulous is free software; you can redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation.

Tremulous is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

If you need to ask any questions, feel free to e-mail me at ultrarandomvirus@hotmail.com or
http://youtube.com/zdrytchx

This source *should* be up at http://github.com/zdrytchx/GPP-1-1 and feel free to commit or place issues.
=========================================================================================================
*/

#include "../qcommon/q_shared.h"
#include "bg_public.h"
#include "bg_local.h"
#include "bg_promode.h"

/*
=========================================================================================================
ProMode Background Info:

Challenge ProMode Arena is a Quake 3 Arena mod that involves weapon balance and physics modifications
such as doublejump and air control. CPMA was greatly loved by Quake 3:A fans and its physics has been
implemented into games such as WarSow and Xonotic. ZdrytchX (ViruS in-game) has implemented the physics
from the above URL to add ProMode physics to this mod, GPP-1.1 Arena.

                         CPM Physics Controls:
  Forward/Back gives "air control", which basically turns your character for you without losing speed.
  Strafe Left/Right gives the ability to stop in mid air quickly, and allows you to turn tight corners
      (However unlike air control you have to turn smoothly, and not too quick else you lose speed fast)
  Diagonal Strafe + Forward/Back is basically normal controls, they're kept this way so you can strafe
      jump without losing speed.

*************************Pre-Made Physics Modes:*************************

These settings that I provide for you fps (fast-paced-shooter, not that CoD crap) geeks out there, I made
some settings that simulate other game physics. Most of them are accurate, but the bunnyhop acceleration
amongst some other minorities hasn't had their algorithm checked so they aren't perfect. However the values
provided are mostly true, as some arrive from the Xonotic *official* configs that were provided with
Xonotic v0.6.

ProMode [Q3]  - "the old" 2001 CPMA original settings (The "new" CPM source has never been released at
  the point this was written). It is also known as CPMA, or Challenge ProMode Arena. The cliptime is
  unconfirmed, but I feel that it equates to the double jump timer.
  
Vanilla Trem [ioQ3]- Normal Tremulous of course. The '400 wishspeed' is actually just means it'll
  accelerate up to 400 ups if possible for the class. I increased to 500 because dretch uses 448.
  The actual cliptime for VQ3 physics is 250 but it appears to be patched out of tremulous.

ProTrem^ - my own personal setting. A.K.A. GPP-1.1 Arena's default. The reason why I chose to have
  a smaller cliptime is because marauder already has its own cliptime of 200 msec. It'll be hard
  to get used to both 400 and 200 msec at once.

TF2 [Source] - Simulates settings in Team Fortress 2 as of 2013 (Not all of which are actual values,
  but some are true. Note that hammer units are slightly different (x1.25?).
  
TFC [GoldSrc] - Simulates settings in Team Fortress Classic (Not actual values, just estimates)

Xonotic*^ [DarkPlaces] - Simulates settings for Xonotic. Xonotic is a community-driven mod that used to
  support Nexuiz until they went commercial. They have fantastic graphics although choppy animations
  and inaccurate client game predictions (Q1 online didn't have cgame prediction).
  There's one thing I won't duplicate here by the way, and that's the anti-strafe acceleration part
  (You can't strafe jump past the bhop limit)
  Xonotic 0.7 just has a speed limit of 900 instead of 800 AFAIK.
  
WarSow*^ [???]  - Not Sure, but it's from a Q2 mod. Gameplay is pretty much CPM with a dodge/dash key
  (similar to gpp's except you can dash forward and wallhop with it), a really strong air control
  (however with a STRONG speed penalty* for turning too quickly or using it at a wide angle) and a
  fantastic "noodle" lightning gun which they trashed out with the ammo strengths system. :'/
  WarSow's famous for their cartoon graphics AFAIK.
  I actually got the WarSow config data from Xonotic's pre-made settings that simulate WarSow physics.
  Note that the cliptime for WarSow is only for bunnyhopping up stairs judging from sound repeat rates.
  Doesn't apply for walls. It may actually not be an actual velocity clip because WarSow already has bhop
  so just put this as 0 when setting up WarSow settings. The settings provided were insufficent, and only
  provided data about its air control settings.
  WarSow's bunnyhop-up-stairs is weird; it only jumps once every 0.4 seconds (double jump time)
  and only applies if you're bhopping. It also allows you to "slide" off stairs like the ramp slide thing.
  And so my implemention of the weird bunnyhop isn't perfect, but it works to some extent. You may find
  yourself sliding off stair-case-like pillars, if they even exist.
  WarSow's forward bunnyhop apparently has a penalty when you're above the limit and slows you down unless
  you don't press 'forward' in air. I'll just ignore this feature for now.
  
Newbie's Physics^ - Just another one of my personal settings, comes with all-directional super strong air
  control, in other words you can pretty much make a fake WarSow dash in air with this since there's no
  air control penalty if you do it right. Comes with a strong bunnyhop up to 3000 ups because you can't
  strafe jump.

QuakeWorld& [Q1, slightly modded] - Quake 1 physics, QuakeWorld style. No step-up in mid air, but
  QuakeWorld's modified physics allows ramp jumping and ramp sliding. Identical to TFC's physics,
  without the speed limit, and has air (strafe) acceleration of 150. Apparently doesn't allow
  step-ups in air.
  There's also a weird issue with Quake 1 where people reckon there's a similar speed limit to
  TFC's but I haven't confirmed it myself.

Quake 2: I'm still new to Quake 2, so I haven't throughly analysed it yet. Apparently it's almost identicle
  to Quake 3, and id even left some evidence of it.

Quake 3: (Team)Arena [VQ3] - Same as 1.1 physics pretty much, only that it had a cliptime of 250 msec.

*TODO: Air Control Penalty (Makes the player slow down if they turn too fast
^TODO: Fix Bunnyhop Acceleration, it seems to bug people outside of the map from extreme acceleration
      that appears out of nowhere.
&Note: QW doesn't have Step-Ups in mid-air. I honestly don't like it, so I might not just not add it.
      I'm actually not sure if TF:C has this missing feature too, because I never played it.
=========================================================================================================
*/

//TODO: Set to a variable, 0 = CPM and 6 = WarSow etc.
//Game Mode Physics Defaults Table
// ___________________________________________________________________________________________________
//|---------.---------.---------.-------------.-----------------.-------------.--------------[-][0][X]|
//|Challenge| Vanilla | ProTrem |Source - Team|  Team Fortress  | XONOTIC-ish | WarSow 0.42  |Newbie's|
//| ProMode |  Trem   |(GPP-1.1)|Fortress 2   |Classic (GoldSrc)|  (0.6)      |(Bhop Classic)|Physics |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| 400?    | 0       | 200     |0            | 0               | 0           | 0            | 0      |
//|(Unconf.)|         |         |             |                 |             | (400 stairs) | 0      |
//| 2.5     | 1       | 2.5     |1            | 1               | 3           | 2.5          | 9      |
//| 150     | 0       | 165     |0            | 0               | 250(125 * 2)| 300 //150 * 2| 9999   |
//| 1       | 1       | 0.8     |1            | 1               | 1           | 1            | 1      |
//| qfalse  | qfalse  | qtrue   |qfalse       | qfalse          | qtrue       | qtrue        | qfalse |
//| 70      | 1       | 70      |150          | 10              | 100         | 70           | 9      |
//|                                                 Query: What is sv_stopspeed 100? (xonotic configs)|
//| 30      | 500     | 30      |30           | 30              | 24          | 30           | 10     |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| 0.370370| 0       | 0.5     |0            | 0               | 0           | 0.37037037037| 0      |
//| qfalse  | qfalse  | qfalse  |qtrue        | qtrue           | qfalse      | qtrue        | qfalse |
//| qfalse  | qfalse  | qfalse  |qfalse       | qfalse          | qfalse      | qfalse       | qfalse |
//| 2(1?)   | 0       | 2       |0            | 0               | 1           | 2(1?)        | 2      |
//| qfalse  | qfalse  | qfalse  |qfalse       | qfalse          | qfalse      | qtrue        | qfalse |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| qfalse  | qfalse  | qtrue   |qfalse       | qfalse          | qtrue       | qtrue        | qtrue  |
//| 0       | 0       | 1200    |0            | 0               | 800   (0.7  | 925          | 3000   |
//|         |         |         |             |                 |  uses 900)  |              |        |
//| 0.00    | 0       | 0.08    |0            | 0               | 0.1593      | 0.1593       | 0.3    |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| 1       | 1       | 1       |1            | 1               | 2           | 1            | 1      |
//| 15      | 10      | 10      |8 //Approx   | 10 //Don't Know | 15          | 15           | 10     |
//| 8       | 8       | 6       |5 //Approx   | 6 // Don't Know | 8           | 8            | 6      |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| qfalse  | qfalse  | qfalse  |qtrue        | qtrue           | qfalse      | qfalse       | qtrue  |
//| qfalse  | qfalse  | qtrue   |qtrue        | qfalse          | qtrue       | qfalse       | qtrue  |
//| qfalse  | qfalse  | qfalse  |qfalse       | qfalse          | qfalse      | qfalse       | qtrue  |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| 0       | 0       | 0       |320          | 512             | 0           | 0            | 0      |
//| 0       | 0       | 0       |0            | 0.5             | 0           | 0            | 0      |
//| 0       | 0       | 0       |320          | 0               | 0           | 0            | 0      |
//'---------'---------'---------'-------------'-----------------'-------------'--------------'--------'
// _______________________________________
//|-----------.-------.---------.[-][0][X]|
//|QuakeWorld | Quake | Quake 3:| Quake   |
//| (Quake 1) |   2   |  Arena  |   Live  |
//|-----------+-------+---------+---------|
//| 0         | 0     | 250     | 250     |
//| 1(2.5?)   | 1     | 1       | 1       |
//| 0         | 0     | 0       | 0       |
//| 1         | 1     | 1       | 1       |
//| qfalse    | qfalse| qfalse  | qfalse  |
//| 70(2*30?) | 1     | 1       | 1       |
//| 30        | 1     | 1       | 1       |
//| 500       | 500   | 500     | 500     |
//|-----------+-------+---------+---------|
//| 0         | 0     | 0       | 0.5     |
//| qtrue     | qtrue | qfalse  | qfalse  |
//| qtrue     | qtrue | qfalse  | qfalse  |
//| 2         | 2     | 0       | 1       |
//| qfalse    | qfalse| qfalse  | qfalse  |
//|-----------+-------+---------+---------|
//| qfalse    | qfalse| qfalse  | qfalse  |
//| 0         | 0     | 0       | 0       |
//| 0         | 0     | 0       | 0       |
//|-----------+-------+---------+---------|
//| 1         | 1     | 1       | 1       |
//| 10        | 10    | 10      | 10      |
//| 6         | 6     | 6       | 6       |
//|-----------+-------+---------+---------|
//| qtrue     | qfalse| qfalse  | qfalse  |
//| qfalse    | qfalse| qfalse  | qfalse  |
//| qfalse    | qfalse| qfalse  | qfalse  |
//|-----------+-------+---------+---------|
//| 0         | 0     | 0       | 0       |
//| 0         | 0     | 0       | 0       |
//| 0         | 0     | 0       | 0       |
//'-----------'-------'---------'---------'

///\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\..
//==============================Physics Initiation==============================>
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/''

//-------------------------------------------------------------------------------
//Challenge ProMode Main features
//-------------------------------------------------------------------------------

float	cpm_pm_cliptime = 200; //A very buggy exploit of vq3 is reimplemented with this.
float	cpm_pm_airstopaccelerate = 2.5;
float	cpm_pm_aircontrol = 165; 
float cpm_pm_aircontrolmod = 0.8;
//This makes most aliens turn faster when you're on a larger attack angle, except for granger and marauder.
//Marauder and normal granger use the opposite, where large attack angles don't turn you as much.
qboolean  cpm_pm_aircontrolmoding = qtrue;
float	cpm_pm_strafeaccelerate = 70;
float	cpm_pm_wishspeed = 30; //Portion of 320 in mid air accel that contributes to the sharp acceleration
//For Double jump, see next section
//For Ground friction/accel settings, see Standard Physics section

//-------------------------------------------------------------------------------
//Jump Settings
//-------------------------------------------------------------------------------

//TODO: ADV Marauder doesn't doublejump (don't want its walljump to doublejump either)
float cpm_pm_jump_z = 0.5; //CPM: 100/270 (normal jumpvel is 270, doublejump default 100) = 0.37037

//You slide up ramps if your upward velocity is higher than than your double jump velocity.
qboolean pm_q1rampslide = qfalse;

//You slip down ramps with little friction because you 'bounce'.
//TODO: Not working properly, still receive friction
//Possibility: Remove vector angle change?
//possibility2: Remove step-down completely
qboolean pm_q1rampslip = qfalse;

//0 = 1.1/VQ3/up Vel = jump, 1 = Bob's OC/Add Vel only, 2 = GPP/{MG}/up Vel must be > jump, else just add
int   pm_rampjump = 2; //0, 1, 2 only

//Warsow's doublejump prevents spamming jump sound and helps bhopping up stairs.
//Advisable not to use this, my opinion (slide in vents when bhopping)
//Also prevents from jumping, which makes it feel like marauder without walljump
//Note: This is not actually what happens in WSW, because here you still stick to
//the surface of the stairs, and if I can fix this I can fix rampsliding
qboolean pm_doublejump_wsw_style = qfalse; //clips velocity when double jumping up stairs
                                          //uses cpm_pm_cliptime for the duration

//-------------------------------------------------------------------------------
//Bunnyhop (Acceleration and Autojump) Settings
//-------------------------------------------------------------------------------

qboolean pm_autojump = qfalse;
float pm_bunnyhopspeedcap = 0; //(TODO: No Penalty for turning)  
float pm_bunnyhopaccel = 0;    //accel = bhopaccel - bhopaccel * ([speed-320]/bhopspeedcap-320)

//-------------------------------------------------------------------------------
//Standard Physics - Moved from bg_pmove.c here
//-------------------------------------------------------------------------------

float pm_airaccelerate = 1.0f;
float	pm_accelerate = 10;         //Ground Acceleration        
float	pm_friction = 6;            //Ground Friction

//-------------------------------------------------------------------------------
//Air Strafe settings for Air Physics types
//-------------------------------------------------------------------------------

qboolean pm_q1strafe = qfalse;//Allows cpm_pm_strafeaccelerate and cpm_pm_wishspeed
                              //to take effect in ALL directions, feels like
                              //CS:Source, TF, QW and all them Q1-based games
                              
qboolean pm_q3strafe = qtrue; //Allows you to accelerate even when past the cpm_pm_wishspeed
                              //and hence allows "half-beat strafe jumping" for VQ3-ers
                              
qboolean pm_aircontrol_alldir = qfalse; //Sets air control in all directions
                              //(prevents strafe jumping as well)
                              
//-------------------------------------------------------------------------------
//Speed Limiters (VALVε - Source/GoldSRC games only)
//-------------------------------------------------------------------------------

//The speedcap and speedcaplimit are multiplied by BG_FindSpeedForClass()
//Note that GSrc's units are slightly different.
//TODO: Fix the Speed Limit bug with wallwalkers! (Don't change these settings folks yet)
float pm_groundspeedcap = 0;          
//A multiplier for ground speed when speedcap has been breached
float pm_groundspeedcapfriction = 0;  
//This one is not finished (Not Working)
//when speedcap has been breached speed becomes this
float pm_groundspeedcaplimit = 0;

//-------------------------------------------------------------------------------
//Unused Variables
//-------------------------------------------------------------------------------

//float pm_jumpheight; //Height at which one can jump if stamina < allowable && > absolute min

//this does nothing now - supposed to be vote-compatible, but I don't have a g_gametype cvar
//to refer to

void CPM_UpdateSettings(int num)
{
	// num = 0: normal quake 3
	// num = 1: pro mode
		// Physics VQ3
//		if(!CPM_ON)
	if (num)
	{
					// Physics CPM
		cpm_pm_aircontrol = 150;
		cpm_pm_strafeaccelerate = 70;
		cpm_pm_wishspeed = 30;
		//Adjust for Tremulous Balance
		cpm_pm_airstopaccelerate = 2.5; //2.5 - marauders climb walls
		cpm_pm_aircontrolmod = 1.0;
		pm_accelerate = 15; //15
		pm_friction = 8; //8
		cpm_pm_jump_z = 100/*/230*/; // enable double-jump //100
		pm_bunnyhopspeedcap = 1200*BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] );
		if (BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] ) > 1.5)
		pm_bunnyhopaccel = 0.08*1.5;
		else
    pm_bunnyhopaccel = 0.08*BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] );
	}
  else
  {
  	cpm_pm_airstopaccelerate = 1;
	  cpm_pm_aircontrol = 0;
	  cpm_pm_strafeaccelerate = 1;
	  cpm_pm_wishspeed = 400; //400? Since when? Shouldn't it be 320?
	  cpm_pm_aircontrolmod = 1.0;
	  pm_accelerate = 10;
	  pm_friction = 6;
	  cpm_pm_jump_z = 0; // turn off double-jump in vq3
	  pm_bunnyhopspeedcap = 0;
    pm_bunnyhopaccel = 0.0;
  }
}

void CPM_PM_Aircontrol (pmove_t *pm, vec3_t wishdir, float wishspeed )
{
	float	zspeed, speed, dot, k;
	int		i;

	if (( (pm->ps->movementDir && pm->ps->movementDir !=4) || wishspeed == 0.0) && !pm_aircontrol_alldir) 
		return; // can't control movement if not moving forward or backward unless pm_aircontrol_alldir is true

	zspeed = pm->ps->velocity[2]; //nice little hack
	pm->ps->velocity[2] = 0;
	speed = VectorNormalize(pm->ps->velocity);

	dot = DotProduct(pm->ps->velocity,wishdir);
	k = 32;
	
  //marauders turn way too fast
  //2 -> 3 dots for better handling (91 degrees turns little, 89 degrees used to turn a lot but not turns little
	if (BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] ) > 1.5 && cpm_pm_aircontrolmoding)
	k *= cpm_pm_aircontrol*dot*dot*dot*pml.frametime*1.5;
	//Give default air control to classes human or smaller
	else if (BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] ) == 1.0 && cpm_pm_aircontrolmoding)
	k *= cpm_pm_aircontrol*cpm_pm_aircontrolmod*dot*dot
	*pml.frametime*BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] );
	//else make turning speed dependable on angle
	else if (cpm_pm_aircontrolmoding)
	k *= cpm_pm_aircontrol*cpm_pm_aircontrolmod*cpm_pm_aircontrolmod*dot
	*pml.frametime*BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] );
	
	//default cpm
  else
	k *= cpm_pm_aircontrol*dot*dot*pml.frametime*BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] );
	
	if (dot > 0) {	// we can't change direction while slowing down
		for (i=0; i < 2; i++)
			pm->ps->velocity[i] = pm->ps->velocity[i]*speed + wishdir[i]*k;
		VectorNormalize(pm->ps->velocity);
	}
	
	for (i=0; i < 2; i++) 
		pm->ps->velocity[i] *=speed;

	pm->ps->velocity[2] = zspeed; //give the z vel back
}
