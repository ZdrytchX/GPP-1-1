/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.
Copyright (C) 2000-2006 Tim Angus

This file is part of Tremulous.

Tremulous is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Tremulous is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tremulous; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#include "g_local.h"

#define MISSILE_PRESTEP_TIME  50

/*
================
G_BounceMissile

================
*/
void G_BounceMissile( gentity_t *ent, trace_t *trace )
{
  vec3_t  velocity;
  float dot;
  int   hitTime;

  // reflect the velocity on the trace plane
  hitTime = level.previousTime + ( level.time - level.previousTime ) * trace->fraction;
  BG_EvaluateTrajectoryDelta( &ent->s.pos, hitTime, velocity );
  dot = DotProduct( velocity, trace->plane.normal );
  VectorMA( velocity, -2 * dot, trace->plane.normal, ent->s.pos.trDelta );

  if( ent->s.eFlags & EF_BOUNCE_HALF )
  {
    VectorScale( ent->s.pos.trDelta, 0.65, ent->s.pos.trDelta );
    // check for stop
    if( trace->plane.normal[ 2 ] > 0.2 && VectorLength( ent->s.pos.trDelta ) < 40 )
    {
      G_SetOrigin( ent, trace->endpos );
      return;
    }
  }

  VectorAdd( ent->r.currentOrigin, trace->plane.normal, ent->r.currentOrigin );
  VectorCopy( ent->r.currentOrigin, ent->s.pos.trBase );
  ent->s.pos.trTime = level.time;
}


/*
================
G_ExplodeMissile

Explode a missile without an impact
================
*/
void G_ExplodeMissile( gentity_t *ent )
{
  vec3_t    dir;
  vec3_t    origin;

  BG_EvaluateTrajectory( &ent->s.pos, level.time, origin );
  SnapVector( origin );
  G_SetOrigin( ent, origin );

  // we don't have a valid direction, so just point straight up
  dir[ 0 ] = dir[ 1 ] = 0;
  dir[ 2 ] = 1;

  ent->s.eType = ET_GENERAL;

  //TA: tired... can't be fucked... hack
  if( ent->s.weapon != WP_LOCKBLOB_LAUNCHER &&
      ent->s.weapon != WP_FLAMER )
    G_AddEvent( ent, EV_MISSILE_MISS, DirToByte( dir ) );

  ent->freeAfterEvent = qtrue;

  // splash damage
  if( ent->splashDamage )
    G_RadiusDamage( ent->r.currentOrigin, ent->parent, ent->splashDamage,
                    ent->splashRadius, ent, ent->splashMethodOfDeath );

  trap_LinkEntity( ent );
}

void AHive_ReturnToHive( gentity_t *self );

/*
================
G_MissileImpact

================
*/
void G_MissileImpact( gentity_t *ent, trace_t *trace )
{
  gentity_t   *other, *attacker;
  qboolean    returnAfterDamage = qfalse;
  vec3_t      dir;

  other = &g_entities[ trace->entityNum ];
  attacker = &g_entities[ ent->r.ownerNum ];

  // check for bounce
  if( !other->takedamage &&
      ( ent->s.eFlags & ( EF_BOUNCE | EF_BOUNCE_HALF ) ) )
  {
    G_BounceMissile( ent, trace );

    //only play a sound if requested
    if( !( ent->s.eFlags & EF_NO_BOUNCE_SOUND ) )
      G_AddEvent( ent, EV_GRENADE_BOUNCE, 0 );

    return;
  }

  if( !strcmp( ent->classname, "grenade" ) )//|| !strcmp( ent->classname, "ablob" ) )
  {
    //grenade doesn't explode on impact
    G_BounceMissile( ent, trace );

    //only play a sound if requested
    if( !( ent->s.eFlags & EF_NO_BOUNCE_SOUND ) )
      G_AddEvent( ent, EV_GRENADE_BOUNCE, 0 );

    return;
  }
  else if( !strcmp( ent->classname, "lockblob" ) )
  {
    if( other->client && other->client->ps.stats[ STAT_PTEAM ] == PTE_HUMANS )
    {
      other->client->ps.stats[ STAT_STATE ] |= SS_BLOBLOCKED;
      other->client->lastLockTime = level.time + LOCKBLOB_LIFETIME;
      AngleVectors( other->client->ps.viewangles, dir, NULL, NULL );
      other->client->ps.stats[ STAT_VIEWLOCK ] = DirToByte( dir );
    }
    if( other->client && other->client->ps.stats[ STAT_PTEAM ] == PTE_ALIENS )
    {
      other->client->ps.stats[ STAT_STATE ] |= SS_BLOBLOCKED; //too overpowered againts aliens otherwise so use SS_SLOWLOCKED
      other->client->lastLockTime = level.time + (LOCKBLOB_LIFETIME*((500 - other->client->ps.stats[ STAT_MAX_HEALTH ])/300) + LOCKBLOB_LOCKTIME );
        //actually, nah, ill keep it like this:
	//6000*((500 - 480)/300) //was /600 but changed because dretches simply die in one hit and will be ignored.
      AngleVectors( other->client->ps.viewangles, dir, NULL, NULL );
      other->client->ps.stats[ STAT_VIEWLOCK ] = DirToByte( dir );
    }
  }
  else if( !strcmp( ent->classname, "slowblob" ) || !strcmp( ent->classname, "ablob" ) )
  {
    if( other->client )//&& other->client->ps.stats[ STAT_PTEAM ] == PTE_HUMANS
    {
      other->client->ps.stats[ STAT_STATE ] |= SS_SLOWLOCKED;
      other->client->lastSlowTime = level.time;
      AngleVectors( other->client->ps.viewangles, dir, NULL, NULL );
      other->client->ps.stats[ STAT_VIEWLOCK ] = DirToByte( dir );
    }
  }
  else if( !strcmp( ent->classname, "hive" ) )
  {
    if( other->s.eType == ET_BUILDABLE && other->s.modelindex == BA_A_HIVE )
    {
      if( !ent->parent )
        G_Printf( S_COLOR_YELLOW "WARNING: hive entity has no parent in G_MissileImpact\n" );
      else
        ent->parent->active = qfalse;

      G_FreeEntity( ent );
      return;
    }
    else
    {
      //prevent collision with the client when returning
      ent->r.ownerNum = other->s.number;

      ent->think = AHive_ReturnToHive;
      ent->nextthink = level.time + FRAMETIME;

      //only damage humans
      if( other->client && other->client->ps.stats[ STAT_PTEAM ] == PTE_HUMANS ){
        returnAfterDamage = qtrue; }
      else
        return;
    }
  }

  // impact damage
  if( other->takedamage )
  {
    // FIXME: wrong damage direction?
    if( ent->damage )
    {
      vec3_t  velocity;

      BG_EvaluateTrajectoryDelta( &ent->s.pos, level.time, velocity );
      if( VectorLength( velocity ) == 0 )
        velocity[ 2 ] = 1;  // stepped on a grenade

      G_Damage( other, ent, attacker, velocity, ent->s.origin, ent->damage,
        0, ent->methodOfDeath );
    }
  }

  if( returnAfterDamage )
    return;

  // is it cheaper in bandwidth to just remove this ent and create a new
  // one, rather than changing the missile into the explosion?

  if( other->takedamage && other->client )
  {
    G_AddEvent( ent, EV_MISSILE_HIT, DirToByte( trace->plane.normal ) );
    ent->s.otherEntityNum = other->s.number;
  }
  else if( trace->surfaceFlags & SURF_METALSTEPS )
    G_AddEvent( ent, EV_MISSILE_MISS_METAL, DirToByte( trace->plane.normal ) );
  else
    G_AddEvent( ent, EV_MISSILE_MISS, DirToByte( trace->plane.normal ) );

  ent->freeAfterEvent = qtrue;

  // change over to a normal entity right at the point of impact
  ent->s.eType = ET_GENERAL;

  SnapVectorTowards( trace->endpos, ent->s.pos.trBase );  // save net bandwidth

  G_SetOrigin( ent, trace->endpos );

  // splash damage (doesn't apply to person directly hit)
  if( ent->splashDamage )
    G_RadiusDamage( trace->endpos, ent->parent, ent->splashDamage, ent->splashRadius,
                    other, ent->splashMethodOfDeath );

  trap_LinkEntity( ent );
}


/*
================
G_RunMissile

================
*/
void G_RunMissile( gentity_t *ent )
{
  vec3_t    origin;
  trace_t   tr;
  int     passent;

  // get current position
  BG_EvaluateTrajectory( &ent->s.pos, level.time, origin );

  // ignore interactions with the missile owner
  passent = ent->r.ownerNum;

  // trace a line from the previous position to the current position
  trap_Trace( &tr, ent->r.currentOrigin, ent->r.mins, ent->r.maxs, origin, passent, ent->clipmask );

  if( tr.startsolid || tr.allsolid )
  {
    // make sure the tr.entityNum is set to the entity we're stuck in
    trap_Trace( &tr, ent->r.currentOrigin, ent->r.mins, ent->r.maxs, ent->r.currentOrigin, passent, ent->clipmask );
    tr.fraction = 0;
  }
  else
    VectorCopy( tr.endpos, ent->r.currentOrigin );

  ent->r.contents = CONTENTS_SOLID; //trick trap_LinkEntity into...
  trap_LinkEntity( ent );
  ent->r.contents = 0; //...encoding bbox information

  if( tr.fraction != 1 )
  {
    // never explode or bounce on sky
    if( tr.surfaceFlags & SURF_NOIMPACT )
    {
      // If grapple, reset owner
      if( ent->parent && ent->parent->client && ent->parent->client->hook == ent )
        ent->parent->client->hook = NULL;

      G_FreeEntity( ent );
      return;
    }

    G_MissileImpact( ent, &tr );
    if( ent->s.eType != ET_MISSILE )
      return;   // exploded
  }

  // check think function after bouncing
  G_RunThink( ent );
}


//=============================================================================

/*
=================
fire_flamer

=================
*/
gentity_t *fire_flamer( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;
  vec3_t    pvel;

  VectorNormalize (dir);

  bolt = G_Spawn();
  bolt->classname = "flame";
  bolt->nextthink = level.time + FLAMER_LIFETIME;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_FLAMER;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = FLAMER_DMG;
  bolt->splashDamage = FLAMER_DMG * FLAMER_RADIUS_MOD;
  bolt->splashRadius = FLAMER_RADIUS;
  bolt->methodOfDeath = MOD_FLAMER;
  bolt->splashMethodOfDeath = MOD_FLAMER_SPLASH;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -11.0f; //don't burn self upon walls
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 11.0f;

  bolt->s.pos.trType = TR_LINEAR; //TR_LINEAR
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( self->client->ps.velocity, FLAMER_LAG, pvel );
  VectorMA( pvel, FLAMER_SPEED, dir, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth

  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}

//=============================================================================

/*
=================
fire_blaster

=================
*/
gentity_t *fire_blaster( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize (dir);
//  int teamkillmod
//  teamkillmod = 1;

  bolt = G_Spawn();
  bolt->classname = "blaster";
  bolt->nextthink = level.time + 10000;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_BLASTER;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
//if (g_mode_teamkill.integer == 1)
//{ teamkillmod = 10 }
  bolt->damage = BLASTER_DMG;// * teamkillmod;
  bolt->splashDamage = BLASTER_PUSH;// * teamkillmod;//blasterjump!
  bolt->splashRadius = BLASTER_RADIUS;
  bolt->methodOfDeath = MOD_BLASTER;
  bolt->splashMethodOfDeath = MOD_TARGET_LASER; //It doesn't kill anything anyway.
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;

bolt->s.pos.trType = TR_LINEAR;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, BLASTER_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth

  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}

//================================================
/*
====================
mdriverfire
====================
*/
gentity_t *fire_mdriver( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;
  vec3_t    pvel;
  VectorNormalize (dir);

  bolt = G_Spawn();
  bolt->classname = "mdriver";
  bolt->nextthink = level.time + MDRIVER_LIFETIME;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_MASS_DRIVER;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = MDRIVER_DMG;
  bolt->splashDamage = MDRIVER_SPLASH;
  bolt->splashRadius = MDRIVER_RADIUS;
  bolt->methodOfDeath = MOD_MDRIVER;
  bolt->splashMethodOfDeath = MOD_MDRIVER_SPLASH;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;

  bolt->s.pos.trType = TR_GRAVITY;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( self->client->ps.velocity, MDRIVER_LAG, pvel ); //ripped from
  VectorMA( pvel, MDRIVER_SPEED, dir, bolt->s.pos.trDelta );  //flamer
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth

  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}


//=============================================================================

/*
=================
fire_pulseRifle

=================
*/
gentity_t *fire_pulseRifle( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize (dir);

  bolt = G_Spawn();
  bolt->classname = "pulse";
  bolt->nextthink = level.time + 20000; 
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_PULSE_RIFLE;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = PRIFLE_DMG;
  bolt->splashDamage = 0;
  bolt->splashRadius = 0;
  bolt->methodOfDeath = MOD_PRIFLE;
  bolt->splashMethodOfDeath = MOD_PRIFLE;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;

  bolt->s.pos.trType = TR_LINEAR; //TR_SINE to test; //linear
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, PRIFLE_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth

  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}

//=============================================================================

/*
=================
fire_luciferCannon

=================
*/
gentity_t *fire_luciferCannon( gentity_t *self, vec3_t start, vec3_t dir, int damage, int radius )
{
  gentity_t *bolt;
  int localDamage = (int)( ceil( ( (float)damage /
                                   (float)LCANNON_TOTAL_CHARGE ) * (float)LCANNON_DAMAGE ) );

  VectorNormalize( dir );

  bolt = G_Spawn( );
  bolt->classname = "lcannon";

  if( damage == LCANNON_TOTAL_CHARGE )
	{
    bolt->nextthink = level.time + 1;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -0.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 0.0f;
  VectorScale( dir, LCANNON_SPEED, bolt->s.pos.trDelta );
  bolt->splashRadius = localDamage;
	}
  else if ( damage == LCANNON_SECONDARY_DAMAGE ) //then it must be a secondary fire
	{
    bolt->nextthink = level.time + 30000;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -0.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 0.0f;
  VectorScale( dir, LCANNON_SECONDARY_SPEED, bolt->s.pos.trDelta );
  bolt->splashRadius = LCANNON_SECONDARY_RADIUS;
	}
  else if ( damage < LCANNON_TOTAL_CHARGE )
	{
    bolt->nextthink = level.time + 100000;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -0.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 0.0f;
  VectorScale( dir, ((float)(1.00 - ((localDamage - LCANNON_TOTAL_CHARGE) / 150)) * LCANNON_SPEED), bolt->s.pos.trDelta );
  bolt->splashRadius = localDamage / 2 + 50;
	}
  else //glitch fix
	{
    bolt->nextthink = level.time + 100000;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -2.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 2.0f;
  VectorScale( dir, LCANNON_SPEED, bolt->s.pos.trDelta ); //Just give it a default speed
	}

  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_LUCIFER_CANNON;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = localDamage;
  bolt->splashDamage = localDamage / 2;
//  bolt->splashRadius = localDamage / 2;//Dynamic radius declared above, default radius;
  bolt->methodOfDeath = MOD_LCANNON;
  bolt->splashMethodOfDeath = MOD_LCANNON_SPLASH;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;

  bolt->s.pos.trType = TR_LINEAR;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth

  VectorCopy( start, bolt->r.currentOrigin );
  return bolt;
}

/*
=================
launch_grenade

=================
*/
gentity_t *launch_grenade( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize( dir );

  bolt = G_Spawn( );
  bolt->classname = "grenade";
  bolt->nextthink = level.time + 5000;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_GRENADE;
  bolt->s.eFlags = EF_BOUNCE_HALF;
  bolt->s.generic1 = WPM_PRIMARY; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = GRENADE_DAMAGE * GRENADE_DAMAGE_BUFF;
  bolt->splashDamage = GRENADE_DAMAGE;
  bolt->splashRadius = GRENADE_RANGE;
  bolt->methodOfDeath = MOD_GRENADE_DIRECT; //Custom MOD
  bolt->splashMethodOfDeath = MOD_GRENADE;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -3.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 3.0f;
  bolt->s.time = level.time;

  bolt->s.pos.trType = TR_GRAVITY;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, GRENADE_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth

  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}
//=============================================================================

/*
================
AHive_ReturnToHive

Adjust the trajectory to point towards the hive
================
*/
void AHive_ReturnToHive( gentity_t *self )
{
  vec3_t  dir;
  trace_t tr;

  if( !self->parent )
  {
    G_Printf( S_COLOR_YELLOW "WARNING: AHive_ReturnToHive called with no self->parent\n" );
    return;
  }

  trap_UnlinkEntity( self->parent );
  trap_Trace( &tr, self->r.currentOrigin, self->r.mins, self->r.maxs,
              self->parent->r.currentOrigin, self->r.ownerNum, self->clipmask );
  trap_LinkEntity( self->parent );

  if( tr.fraction < 1.0f )
  {
    //if can't see hive then disperse
    VectorCopy( self->r.currentOrigin, self->s.pos.trBase );
    self->s.pos.trType = TR_STATIONARY;
    self->s.pos.trTime = level.time;

    self->think = G_ExplodeMissile;
    self->nextthink = level.time + HIVE_HIVE_STUN;
    self->parent->active = qfalse; //allow the parent to start again
  }
  else
  {
    VectorSubtract( self->parent->r.currentOrigin, self->r.currentOrigin, dir );
    VectorNormalize( dir );

    //change direction towards the hive
    VectorScale( dir, HIVE_SPEED, self->s.pos.trDelta );
    SnapVector( self->s.pos.trDelta );      // save net bandwidth
    VectorCopy( self->r.currentOrigin, self->s.pos.trBase );
    self->s.pos.trTime = level.time;

    self->think = G_ExplodeMissile;
    self->nextthink = level.time + HIVE_LIFETIME;
    self->parent->active = qfalse; //allow the parent to start again
  }
}

/*
================
AHive_SearchAndDestroy

Adjust the trajectory to point towards the target
================
*/
void AHive_SearchAndDestroy( gentity_t *self )
{
  vec3_t dir;
  trace_t tr;

  trap_Trace( &tr, self->r.currentOrigin, self->r.mins, self->r.maxs,
              self->target_ent->r.currentOrigin, self->r.ownerNum, self->clipmask );

  //if there is no LOS or the parent hive is too far away or the target is dead or notargeting, return
  if( tr.entityNum == ENTITYNUM_WORLD ||
      Distance( self->r.currentOrigin, self->parent->r.currentOrigin ) > ( HIVE_RANGE * 5 ) ||
      self->target_ent->health <= 0 || self->target_ent->flags & FL_NOTARGET )
  {
    self->r.ownerNum = ENTITYNUM_WORLD;

    self->think = AHive_ReturnToHive;
    self->nextthink = level.time + FRAMETIME;
  }
  else
  {
    VectorSubtract( self->target_ent->r.currentOrigin, self->r.currentOrigin, dir );
    VectorNormalize( dir );

    //change direction towards the player
    VectorScale( dir, HIVE_SPEED, self->s.pos.trDelta );
    SnapVector( self->s.pos.trDelta );      // save net bandwidth
    VectorCopy( self->r.currentOrigin, self->s.pos.trBase );
    self->s.pos.trTime = level.time;

    self->nextthink = level.time + HIVE_DIR_CHANGE_PERIOD;
  }
}

/*
=================
fire_hive
=================
*/
gentity_t *fire_hive( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize ( dir );

  bolt = G_Spawn( );
  bolt->classname = "hive";
  bolt->nextthink = level.time + HIVE_DIR_CHANGE_PERIOD;
  bolt->think = AHive_SearchAndDestroy;
  bolt->s.eType = ET_MISSILE;
  bolt->s.eFlags |= EF_BOUNCE|EF_NO_BOUNCE_SOUND;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_HIVE;
  bolt->s.generic1 = WPM_PRIMARY; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = HIVE_DMG;
  bolt->splashDamage = 0; //not to high - it kills trappers
  bolt->splashRadius = 0;
  bolt->methodOfDeath = MOD_SWARM;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = self->target_ent;

  bolt->s.pos.trType = TR_LINEAR;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, HIVE_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth
  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}

//=============================================================================

/*
=================
fire_lockblob
=================
*/
gentity_t *fire_lockblob( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize ( dir );

  bolt = G_Spawn( );
  bolt->classname = "lockblob";
  bolt->nextthink = level.time + 5000;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_LOCKBLOB_LAUNCHER;
  bolt->s.generic1 = WPM_PRIMARY; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = LOCKBLOB_DMG;
  bolt->splashDamage = LOCKBLOB_SPLASH;
  bolt->splashRadius = LOCKBLOB_RADIUS;
  bolt->methodOfDeath = MOD_LOCKBLOB; //changed as it kills
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;
/*
if ( self->client && self->client->ps.stats[ STAT_PTEAM ] == PTE_ALIENS ) //'client' = buildable
	{
  bolt->s.pos.trType = TR_GRAVITY;
  bolt->s.eFlags = EF_BOUNCE_HALF;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -5.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 5.0f;
	}
else if ( !( self->client ) )	{
  bolt->s.pos.trType = TR_LINEAR;
	}
*/
  bolt->s.pos.trType = TR_LINEAR;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, 500, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth
  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}

/*
=================
fire_slowBlob
=================
*/
gentity_t *fire_slowBlob( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize ( dir );

  bolt = G_Spawn( );
  bolt->classname = "slowblob";
  bolt->nextthink = level.time + ABUILDER_BLOB_LIFETIME;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_ABUILD2;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = ABUILDER_BLOB_DMG;
  bolt->splashDamage = ABUILDER_BLOB_SPLASH_DMG;
  bolt->splashRadius = ABUILDER_BLOB_RADIUS;
  bolt->methodOfDeath = MOD_SLOWBLOB;
  bolt->splashMethodOfDeath = MOD_SLOWBLOB;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;
//  bolt->s.eFlags = EF_BOUNCE_HALF;// | EF_NO_BOUNCE_SOUND;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -5.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 5.0f;

  bolt->s.pos.trType = TR_GRAVITY;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, ABUILDER_BLOB_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth
  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}

/*
=================
fire_paraLockBlob
=================
*/
gentity_t *fire_paraLockBlob( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize ( dir );

  bolt = G_Spawn( );
  bolt->classname = "lockblob";
  bolt->nextthink = level.time + 18000;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_LOCKBLOB_LAUNCHER;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = 0;
  bolt->splashDamage = 0;
  bolt->splashRadius = 0;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;

  bolt->s.pos.trType = TR_GRAVITY;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, LOCKBLOB_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth
  VectorCopy( start, bolt->r.currentOrigin );

  return bolt;
}

/*
=================
fire_bounceBall
=================
*/
gentity_t *fire_bounceBall( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize ( dir );

  bolt = G_Spawn( );
  bolt->classname = "bounceball";
  bolt->nextthink = level.time + 12000;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_ALEVEL3_UPG;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = LEVEL3_BOUNCEBALL_DMG;
  bolt->splashDamage = LEVEL3_BOUNCEBALL_DMG; //KABOOM!
  bolt->splashRadius = LEVEL3_BOUNCEBALL_SPLASH_RADIUS; //raise this higher for acid bombs! (not recommended as it can sometimes be overpowering... unless you decreased ammo to 1
  bolt->methodOfDeath = MOD_LEVEL3_BOUNCEBALL;
  bolt->splashMethodOfDeath = MOD_LEVEL3_BOUNCEBALL_SPLASH;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;
//The following boundry box is for acid bomb. Its annoying to snipe with.
//  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -5.0f;
//  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 5.0f;

  bolt->s.pos.trType = TR_GRAVITY;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, LEVEL3_BOUNCEBALL_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth
  VectorCopy( start, bolt->r.currentOrigin );
//  bolt->s.eFlags |= EF_BOUNCE_HALF; //only use if the barb is actually a bomb
  /*bolt->s.eFlags |= EF_BOUNCE; / =D*/

  return bolt;
}

/*
=================
fire_airBlast
=================
*/
gentity_t *fire_airBlast( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize ( dir );

  bolt = G_Spawn( );
  bolt->classname = "airblast";
  bolt->nextthink = level.time + FLAMER_AIRBLAST_PERIOD;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_FLAMER;
  bolt->s.generic1 = self->s.generic1;
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = FLAMER_AIRBLAST_DMG;
  bolt->splashDamage = FLAMER_AIRBLAST_DMG;
  bolt->splashRadius = FLAMER_AIRBLAST_RADIUS;
  bolt->methodOfDeath = MOD_AIRBLAST;
  bolt->splashMethodOfDeath = MOD_AIRBLAST;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -FLAMER_AIRBLAST_SIZE;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = FLAMER_AIRBLAST_SIZE;

  bolt->s.pos.trType = TR_LINEAR;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, FLAMER_AIRBLAST_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth
  VectorCopy( start, bolt->r.currentOrigin );
  return bolt;
}

/*
=================
fire_ablob
=================
*/
gentity_t *fire_aBlob( gentity_t *self, vec3_t start, vec3_t dir )
{
  gentity_t *bolt;

  VectorNormalize ( dir );

  bolt = G_Spawn( );
  bolt->classname = "ablob";
  bolt->nextthink = level.time + LEVEL4_ABLOB_LIFETIME;
  bolt->think = G_ExplodeMissile;
  bolt->s.eType = ET_MISSILE;
  bolt->r.svFlags = SVF_USE_CURRENT_ORIGIN;
  bolt->s.weapon = WP_ALEVEL4;
  bolt->s.generic1 = self->s.generic1; //weaponMode
  bolt->r.ownerNum = self->s.number;
  bolt->parent = self;
  bolt->damage = LEVEL4_ABLOB_DMG;
  bolt->splashDamage = LEVEL4_ABLOB_DMG;
  bolt->splashRadius = LEVEL4_ABLOB_RADIUS;
  bolt->methodOfDeath = MOD_LEVEL4_ABLOB;
  bolt->splashMethodOfDeath = MOD_LEVEL4_ABLOB;
  bolt->clipmask = MASK_SHOT;
  bolt->target_ent = NULL;
  bolt->r.mins[ 0 ] = bolt->r.mins[ 1 ] = bolt->r.mins[ 2 ] = -3.0f;
  bolt->r.maxs[ 0 ] = bolt->r.maxs[ 1 ] = bolt->r.maxs[ 2 ] = 3.0f;

  bolt->s.pos.trType = TR_GRAVITY;
  bolt->s.pos.trTime = level.time - MISSILE_PRESTEP_TIME;   // move a bit on the very first frame
  VectorCopy( start, bolt->s.pos.trBase );
  VectorScale( dir, LEVEL4_ABLOB_SPEED, bolt->s.pos.trDelta );
  SnapVector( bolt->s.pos.trDelta );      // save net bandwidth
  VectorCopy( start, bolt->r.currentOrigin );
  bolt->s.eFlags |= EF_BOUNCE_HALF; //dont explode upon contact with the world

  return bolt;
}
