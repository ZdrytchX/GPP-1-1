/*
   ===========================================================================
   Copyright (C) 2007 Amine Haddad

 ** This file is modified by Thomas Rinsma, I take no copyright at all

   This file is part of Tremulous.

   The original works of vcxzet (lamebot3) were used a guide to create TremBot.

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
#include "g_bot.h"

int G_BotBuyUpgrade ( gentity_t *ent, int upgrade )
{
    //already got this?
    if( BG_InventoryContainsUpgrade( upgrade, ent->client->ps.stats ) )
        return 0;

    //can afford this?
    if( BG_FindPriceForUpgrade( upgrade ) > (short)ent->client->ps.persistant[ PERS_CREDIT ] )
        return 0;

    //have space to carry this?
    if( BG_FindSlotsForUpgrade( upgrade ) & ent->client->ps.stats[ STAT_SLOTS ] )
        return 0;

    //are we /allowed/ to buy this?
    if( !BG_FindPurchasableForUpgrade( upgrade ) )
        return 0;

    //are we /allowed/ to buy this?
    if( !BG_FindStagesForUpgrade( upgrade, g_humanStage.integer ) || !BG_UpgradeIsAllowed( upgrade ) )
        return 0;
        
    if( upgrade == UP_BATTLESUIT && g_bot_bsuit.integer == 0 )
        return 0;

    if( upgrade == UP_AMMO )
        G_GiveClientMaxAmmo( ent, qfalse );
    else
        //add to inventory
        BG_AddUpgradeToInventory( upgrade, ent->client->ps.stats );

    if( upgrade == UP_BATTPACK )
        G_GiveClientMaxAmmo( ent, qtrue );

    //subtract from funds
    G_AddCreditToClient( ent->client, -(short)BG_FindPriceForUpgrade( upgrade ), qfalse );

    return 1;
}
int G_BotBuyWeapon ( gentity_t *ent, int weapon )
{
    int maxAmmo, maxClips;

    //already got this?
    if( BG_InventoryContainsWeapon( weapon, ent->client->ps.stats ) )
        return 0;

    //can afford this?
    if( BG_FindPriceForWeapon( weapon ) > (short)ent->client->ps.persistant[ PERS_CREDIT ] )
        return 0;

    //have space to carry this?
    if( BG_FindSlotsForWeapon( weapon ) & ent->client->ps.stats[ STAT_SLOTS ] )
        return 0;

    //are we /allowed/ to buy this?
    if( !BG_FindPurchasableForWeapon( weapon ) )
        return 0;

    //are we /allowed/ to buy this?
    if( !BG_FindStagesForWeapon( weapon, g_humanStage.integer ) || !BG_WeaponIsAllowed( weapon ) )
        return 0;
    
    //does server allow us to buy this?
    switch(weapon) {
        case WP_MACHINEGUN:
            if(g_bot_rifle.integer == 0)
                return 0;
            break;
        case WP_PAIN_SAW:
            if(g_bot_psaw.integer == 0)
                return 0;
            break;
        case WP_SHOTGUN:
            if(g_bot_shotgun.integer == 0)
                return 0;
            break;
        case WP_LAS_GUN:
        case WP_LOCKBLOB_LAUNCHER:
            if(g_bot_lgun.integer == 0)
                return 0;
            break;
        case WP_MASS_DRIVER:
            if(g_bot_mdriver.integer == 0)
                return 0;
            break;
        case WP_CHAINGUN:
            if(g_bot_chaingun.integer == 0)
                return 0;
            break;
        case WP_PULSE_RIFLE:
            if(g_bot_prifle.integer == 0)
                return 0;
            break;
        case WP_FLAMER:
            if(g_bot_flamer.integer == 0)
                return 0;
            break;
        case WP_LUCIFER_CANNON:
            if(g_bot_lcannon.integer == 0)
                return 0;
            break;
        default: break;
    }
            

    //add to inventory
    BG_AddWeaponToInventory( weapon, ent->client->ps.stats );
    BG_FindAmmoForWeapon( weapon, &maxAmmo, &maxClips );

    BG_PackAmmoArray( weapon, ent->client->ps.ammo, ent->client->ps.powerups,
                      maxAmmo, maxClips );

    G_ForceWeaponChange( ent, weapon );

    //set build delay/pounce etc to 0
    ent->client->ps.stats[ STAT_MISC ] = 0;

    //subtract from funds
    G_AddCreditToClient( ent->client, -(short)BG_FindPriceForWeapon( weapon ), qfalse );


    return 1;

}

int botFindDamagedFriendlyStructure( gentity_t *self )
{
    // The range of our scanning field.
    int vectorRange = MGTURRET_RANGE * 3;
    // vectorRange converted to a vector
    vec3_t range;
    // Lower bound vector
    vec3_t mins;
    // Upper bound vector
    vec3_t maxs;
    // Indexing field
    int i;
    // Entities located in scanning field
    int total_entities;

    // Array which contains the located entities
    int entityList[ MAX_GENTITIES ];
    // Temporary entitiy
    gentity_t *target;
    // Temporary buildable
    buildable_t inspectedBuilding;

    VectorSet( range, vectorRange, vectorRange, vectorRange );
    VectorAdd( self->client->ps.origin, range, maxs );
    VectorSubtract( self->client->ps.origin, range, mins );

    // Fetch all entities in the bounding box and iterate over them
    // to locate the structures that belong to the team of the bot and that
    // are not at full health.
    total_entities = trap_EntitiesInBox(mins, maxs, entityList, MAX_GENTITIES);
    for( i = 0; i < total_entities; ++i )
    {
        target = &g_entities[ entityList[ i ] ];
        inspectedBuilding = BG_FindBuildNumForEntityName( target->classname );
        if(target->s.eType == ET_BUILDABLE &&
           target->biteam == self->client->ps.stats[ STAT_PTEAM ] &&
           target->health <  BG_FindHealthForBuildable( inspectedBuilding ) * BUILDABE_REPAIR_HEALTH &&
           target->health > 0 && target->spawned) {
            return entityList[i];
        }
    }
    //TODO: Continue healing until 100% health
    return ENTITYNUM_NONE;
}
qboolean botStructureIsDamaged(int team)
{
    // Indexing field
    int i;
    // Temporary entitiy
    gentity_t *target;
    // Temporary buildable
    buildable_t inspectedBuilding;
    
    // Fetch all entities and iterate over them
    // to locate the structures that belong to the team and that
    // are not at full health.
    for( i = 0; i < level.num_entities; ++i )
    {
        target = &g_entities[i];
        inspectedBuilding = BG_FindBuildNumForEntityName( target->classname );
        if(target->s.eType == ET_BUILDABLE &&
            target->biteam == team &&
            ( target->health /** ( 1 / BUILDABE_REPAIR_HEALTH ) */) <  BG_FindHealthForBuildable( inspectedBuilding ) &&
            target->health > 0 && target->spawned) {
            return qtrue;
        }
    }
    //TODO: Continue healing until 100% health
    return qfalse;
}

qboolean botWeaponHasLowAmmo(gentity_t *self) {
    int i;
    
    //find our primary weapon
    for( i = WP_NONE + 1; i < WP_NUM_WEAPONS; i++ )
    {
        if( i == WP_BLASTER )
            continue;
        
        if( BG_InventoryContainsWeapon( i, self->client->ps.stats ) )
        {
            return BG_FindPercentAmmo(i, self->client->ps.stats,self->client->ps.ammo,self->client->ps.powerups) < BOT_LOW_AMMO;
        }
    }
    return qtrue;
}
qboolean botNeedsItem(gentity_t *self) {

    //we need more ammo
    if(botWeaponHasLowAmmo(self))
        return qtrue;
    if(BG_InventoryContainsWeapon(WP_HBUILD,self->client->ps.stats))
        return qtrue;

    //see if we can afford lightarmor and we dont have any on currently
    if(g_humanStage.integer == S1 || g_humanStage.integer == S2 || g_humanStage.integer == S3 )
    {
        //70 is the highest minimum amount of credits needed to buy something new
        if((short) self->client->ps.persistant[PERS_CREDIT] > BG_FindPriceForUpgrade(UP_LIGHTARMOUR) && 
        !BG_InventoryContainsUpgrade(UP_LIGHTARMOUR, self->client->ps.stats) && !BG_InventoryContainsUpgrade(UP_BATTLESUIT, self->client->ps.stats))
        if (!BG_InventoryContainsUpgrade(UP_BATTLESUIT, self->client->ps.stats))
            return qtrue;
    }
    //see if we can afford a helmet and we dont have any on currently
    if(g_humanStage.integer == S2 || g_humanStage.integer == S3) {
        if((short) self->client->ps.persistant[PERS_CREDIT] > BG_FindPriceForUpgrade(UP_HELMET) &&
        !BG_InventoryContainsUpgrade(UP_HELMET, self->client->ps.stats))
        if (g_bot_bsuit.integer && !BG_InventoryContainsUpgrade(UP_BATTLESUIT, self->client->ps.stats))
            return qtrue;
    }
    if( g_bot_bsuit.integer == 1 && g_humanStage.integer == S3) {
        if((short) self->client->ps.persistant[PERS_CREDIT] > BG_FindPriceForUpgrade(UP_BATTLESUIT) &&
        !BG_InventoryContainsUpgrade(UP_BATTLESUIT, self->client->ps.stats))
            return qtrue;
    }
    
    return qfalse;
}
qboolean botCanShop(gentity_t *self) {
    //if no powered armoury in range
 //ZdrytchX: FUMA! This isn't powered!
    if(botFindBuilding(self, BA_H_ARMOURY, BOT_ARM_RANGE) == -1 && !G_BuildableRange( self->client->ps.origin, 100, BA_H_ARMOURY ) )
        return qfalse;
    //bot buying is disabled
    if(g_bot_buy.integer == 0)
        return qfalse;
    return qtrue;
}

