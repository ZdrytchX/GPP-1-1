//Following was retreived from http://games.linuxdude.com/tamaps/archive/cpm1_dev_docs.zip
#include "../qcommon/q_shared.h"
#include "bg_public.h"
#include "bg_local.h"
#include "bg_promode.h"

//doublejump
float cpm_pm_jump_z;

// Physics VQ3
/*
float	cpm_pm_airstopaccelerate = 1;
float	cpm_pm_aircontrol = 0;
float	cpm_pm_strafeaccelerate = 1;
float	cpm_pm_wishspeed = 400;
*/
//Physics CPM
float	cpm_pm_airstopaccelerate = 2.5;  //2.5 - marauders climb walls
float	cpm_pm_aircontrol = 150;
float	cpm_pm_strafeaccelerate = 70;
float	cpm_pm_wishspeed = 30;
//testing
float pm_bunnyhopspeedcap = 1000;
float pm_bunnyhopaccel = 0.08;

void CPM_UpdateSettings(int num)
{
	// num = 0: normal quake 3
	// num = 1: pro mode
		// Physics VQ3
		if(!CPM_ON)
		{
	  cpm_pm_airstopaccelerate = 1;
	  cpm_pm_aircontrol = 0;
	  cpm_pm_strafeaccelerate = 1;
	  cpm_pm_wishspeed = 400;
	  pm_accelerate = 10;
	  pm_friction = 6;
	  cpm_pm_jump_z = 0; // turn off double-jump in vq3
	  pm_bunnyhopspeedcap = 1000;
    pm_bunnyhopaccel = 0.0;
	  }
	  else {
			// Physics CPM
		cpm_pm_aircontrol = 150;
		cpm_pm_strafeaccelerate = 70;
		cpm_pm_wishspeed = 30;
		//Adjust for Tremulous Balance
		cpm_pm_airstopaccelerate = 2.5; //2.5 - marauders climb walls
		pm_accelerate = 10; //15
		pm_friction = 6; //8
		cpm_pm_jump_z = 100/*/230*/; // enable double-jump //100
		pm_bunnyhopspeedcap = 1000*BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] );
		if (BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] ) > 1.5)
		pm_bunnyhopaccel = 0.08*1.5;
		else
    pm_bunnyhopaccel = 0.08*BG_FindAirAccelerationForClass( pm->ps->stats[ STAT_PCLASS ] );
		}
		
		//Following does nothing now since tremulous is missing a function that quake has, long story, replaced with the CPM_ON global var above
	if (num)
	{
		cpm_pm_jump_z = 100/*/230*/; // enable double-jump //100
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
