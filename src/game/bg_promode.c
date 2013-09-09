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

ProMode [Q3]  - "the old" 2001 CPMA original settings (The "new" CPM source has never been released at
  the point this was written). It is also known as CPMA, or Challenge ProMode Arena. The cliptime is
  unconfirmed.
  
Vanilla Trem [ioQ3]- Normal Tremulous of course. The '400 wishspeed' is actually just means it'll
  accelerate up to 400 ups if possible for the class. I increased to 500 because dretch uses 448.
  The actual cliptime for VQ3 physics is unconfirmed but it appears to be patched out of tremulous.

ProTrem - my own personal setting. A.K.A. GPP-1.1 Arena's default. The reason why I chose to have
  a smaller cliptime is because marauder already has its own cliptime of 200 msec. It'll be hard
  to get used to both 400 and 200 msec at once.

QuakeWorld [Q1, slightly modded] - Quake 1 physics, QuakeWorld style. No step-up in mid air, but
  QuakeWorld's modified physics allows ramp jumping and ramp sliding. Identical to TFC's physics,
  without the speed limit, and has air (strafe) acceleration of 150.

TF2 [Source] - Simulates settings in Team Fortress 2 as of 2013 (Not all of which are actual values,
  but some are true. Note that hammer units are slightly different (x1.25?).
  
TFC [GoldSrc] - Simulates settings in Team Fortress Classic (Not actual values, just estimates)

Xonotic* [DarkPlaces] - Simulates settings for Xonotic. Xonotic is a community-driven mod that used to
  support Nexuiz until they went commercial. They have fantastic graphics although choppy animations
  and inaccurate client game predictions (Q1 online didn't have cgame prediction).
  
WarSow* [???]  - Not Sure, but it's from a Q2 mod. Gameplay is pretty much CPM with a dodge/dash key
  (similar to gpp's except you can dash forward and wallhop with it), a really strong air control
  (however with a STRONG speed penalty* for turning too quickly or using it at a wide angle) and a
  fantastic "noodle" lightning gun which they trashed out with the ammo strengths system. :'/
  WarSow's famous for their cartoon graphics AFAIK.
  I actually got the WarSow config data from Xonotic's pre-made settings that simulate WarSow physics.
  Note that the cliptime for WarSow is only for bunnyhopping up stairs judging from sound repeat rates.
  Doesn't apply for walls. It may actually not be an actual velocity clip because WarSow already has bhop
  so just put this as 0 when setting up WarSow settings.
  
Newbie's Physics - Just another one of my personal settings, comes with all-directional super strong air
  control, in other words you can pretty much make a fake WarSow dash in air with this since there's no
  air control penalty if you do it right. Comes with a strong bunnyhop up to 3000 ups because you can't
  strafe jump.

*TODO: Air Control Penalty (Makes the player slow down if they turn too fast
  I could try clipping velocity without any friction or ground acceleration.
=========================================================================================================
*/

float pm_jumpheight; //Height at which one can jump if stamina < allowable && > absolute min
float pm_jumpmag = 1.00;

//TODO: Set to a variable, 0 = CPM and 6 = WarSow
//Game Mode Physics Defaults
// ___________________________________________________________________________________________________
//|---------.---------.---------.-------------.-----------------.-------------.--------------[-][0][X]|
//|Challenge| Vanilla | ProTrem |Source - Team|  Team Fortress  | XONOTIC-ish | WarSow 0.42  |Newbie's|
//| ProMode |  Trem   |(GPP-1.1)|Fortress 2   |Classic (GoldSrc)|   0.6       |(Bhop Classic)|Physics |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| 400?    | 0       | 200     |0            | 0               | 0           | 0            | 0      |
//|(Unconf.)|         |         |             |                 |             | (400 stairs) | 0      |
//| 2.5     | 1       | 2.5     |1            | 1               | 3           | 2.5          | 9      |
//| 150     | 0       | 165     |0            | 0               | 250(125 * 2)| 300 //150 * 2| 9999   |
//| 1       | 1       | 0.8     |1            | 1               | 1           | 1            | 1      |
//| qfalse  | qfalse  | qtrue   |qfalse       | qfalse          | qtrue       | qtrue        | qfalse |
//| 70      | 1       | 70      |150          | 1000            | 100         | 70           | 9      |
//|                                                 Query: What is sv_stopspeed 100? (xonotic configs)|
//| 30      | 500     | 30      |30           | 30 //Don't know | 24          | 30           | 10     |
//|---------+---------+---------+-------------+-----------------+-------------+--------------+--------|
//| 0.370370| 0       | 0.5     |0            | 0               | 0           | 0.37037037037| 0      |
//| qfalse  | qfalse  | qfalse  |qtrue        | qtrue           | qfalse      | qtrue        | qfalse |
//| 2(1?)   | 0       | 2       |0            | 0               | 1           | 2(1?)        | 2      |
//| qfalse  | qfalse  | qfalse  |qfalse       | qfalse          | qtrue       | qtrue        | qfalse |
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
//==========Physics Initiation==========
//-------------------------------------------------------------------------------
//CPM Main
//-------------------------------------------------------------------------------
float	cpm_pm_cliptime = 200; //A very buggy exploit of vq3 is reimplemented with this.
float	cpm_pm_airstopaccelerate = 2.5;
float	cpm_pm_aircontrol = 165; 
float cpm_pm_aircontrolmod = 0.8;
//This makes most aliens turn faster when you're on a larger attack angle, except for granger and marauder.
//Marauder and normal granger use the opposite, where large attack angles don't turn you as much.
qboolean  cpm_pm_aircontrolmoding = qtrue;
float	cpm_pm_strafeaccelerate = 70;
float	cpm_pm_wishspeed = 30;

//-------------------------------------------------------------------------------
//Jump Settings
//-------------------------------------------------------------------------------
//TODO: ADV Marauder doesn't doublejump (don't want its walljump to doublejump either)
float cpm_pm_jump_z = 0.5; //CPM: 100/270 (normal jumpvel is 270, doublejump default 100) = 0.37037
qboolean pm_q1rampslide = qfalse;
//0 = 1.1/VQ3/up Vel = jump, 1 = Bob's OC/Add Vel only, 2 = GPP/{MG}/up Vel must be > jump, else just add
int   pm_rampjump = 2; //0, 1, 2 only
qboolean pm_doublejump_wsw_style = qtrue; //clips velocity when double jumping up stairs

//-------------------------------------------------------------------------------
//Bunnyhop Settings
//-------------------------------------------------------------------------------
qboolean pm_autojump = qfalse;
float pm_bunnyhopspeedcap = 0; //(TODO: No Penalty for turning)  
float pm_bunnyhopaccel = 0;    //accel = bhopaccel - bhopaccel * ([speed-320]/bhopspeedcap-320)

//-------------------------------------------------------------------------------
//Moved from bg_pmove.c here
//-------------------------------------------------------------------------------
float pm_airaccelerate = 1.0f;
float	pm_accelerate = 10;         //Ground Acceleration        
float	pm_friction = 6;            //Ground Friction

//-------------------------------------------------------------------------------
//Air Strafe settings
//-------------------------------------------------------------------------------
qboolean pm_q1strafe = qfalse;//Allows cpm_pm_strafeaccelerate and cpm_pm_wishspeed
                              //to take effect in ALL directions, feels like
                              //CS:Source, TF, QW and all them Q1-based games
qboolean pm_q3strafe = qtrue; //Allows you to accelerate even when past the cpm_pm_wishspeed
                              //and hence allows "half-beat strafe jumping" for VQ3-ers
qboolean pm_aircontrol_alldir = qfalse; //Sets air control in all directions
                              //(prevents strafe jumping as well)
//-------------------------------------------------------------------------------
//Speed Limiters
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

void CPM_UpdateSettings(int num) //does nothing now
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
	
  //marauders turn way too fast //2 -> 3 dots for better handling (91 degrees turns little, 89 degrees used to turn a lot but not turns little
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
