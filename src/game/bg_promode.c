/*
=========================================================================================================
This file contains code that was retreived and modified from
http://games.linuxdude.com/tamaps/archive/cpm1_dev_docs.zip

Tremulous is free software; you can redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation.

Tremulous is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

ProMode Background Info:

Challenge ProMode Arena is a Quake 3 Arena mod that involves weapon balance and physics modifications
such as doublejump and air control. CPMA was greatly loved by Quake fans and its physics has been
implemented into games such as WarSow and Xonotic. ZdrytchX (ViruS in-game) has implemented the physics
from the above URL to add ProMode physics to this mod, GPP-1.1 Arena.

Pre-Made Physics Modes:
Vanilla is Normal Tremulous of course, although I'm not sure where the '400' came from.
ProTrem is my own personal setting.
ProMode are "the old" 2001 CPMA original settings (The "new" CPMA source has never been released at the
point this was written).
Source - TF2/C is a combination of Team Fortress 2 and Team Fortress Classic settings, as I do not
actually know the raw values nor have the source code.

If you need to ask any questions, feel free to e-mail me at ultrarandomvirus@hotmail.com or
http://youtube.com/zdrytchx

This source *should* be up at http://github.com/zdrytchx/GPP-1-1 and feel free to commit or place issues.
=========================================================================================================
*/
#include "../qcommon/q_shared.h"
#include "bg_public.h"
#include "bg_local.h"
#include "bg_promode.h"

//doublejump
float cpm_pm_jump_z;

// Physics Initiation
                                      //ProMode   | Vanilla | ProTrem | Source - TF2  | TF Classic
float	cpm_pm_airstopaccelerate = 2.5; //2.5       | 1       | 2.5     | 1             | 1
float	cpm_pm_aircontrol = 150;        //150       | 0       | 150     | 0             | 0
float	cpm_pm_strafeaccelerate = 30;   //70        | 1       | 70      | 150           | 1000 //I actually don't know
float	cpm_pm_wishspeed = 30;          //30        | 400     | 30      | 30            | 30 //I actually don't know
//Add-Ons =)
float pm_bunnyhopspeedcap = 1200;     //0         | 0       | 1200    | 0             | 0
float pm_bunnyhopaccel = 0.08;        //0.00      | 0.00    | 0.08    | 0             | 0

qboolean pm_q1strafe = qfalse;        //qfalse    | qfalse  | qfalse  | qtrue         | qtrue
qboolean pm_q3strafe = qtrue;         //qfalse    | qfalse  | qtrue   | qtrue         | qfalse

//The speedcap and speedcaplimit are multiplied by BG_FindSpeedForClass()
//Note that GSrc's units are slightly different.
float pm_groundspeedcap = 0;          //0         | 0       | 0       | 320           | 512
//A multiplier for ground speed when speedcap has been breached
float pm_groundspeedcapfriction = 1;  //1         | 1       | 1       | 1             | 0.5 
//At pm_groundspeedcap this becomes the speed
float pm_groundspeedcaplimit = 0;     //0         | 0       | 0       | 320           | 0

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

	if ( (pm->ps->movementDir && pm->ps->movementDir !=4) || wishspeed == 0.0) 
		return; // can't control movement if not moving forward or backward

	zspeed = pm->ps->velocity[2]; //nice little hack
	pm->ps->velocity[2] = 0;
	speed = VectorNormalize(pm->ps->velocity);

	dot = DotProduct(pm->ps->velocity,wishdir);
	k = 32;

	if (BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] ) > 1.5)
	k *= cpm_pm_aircontrol*dot*dot*pml.frametime*1.5; //marauders turn way too fast
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
