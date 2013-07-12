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

int G_BotEvolveToClass( gentity_t *ent, char *classname, usercmd_t *botCmdBuffer)
{
    int clientNum;
    int i;
    vec3_t infestOrigin;
    pClass_t currentClass = ent->client->pers.classSelection;
    pClass_t newClass;
    int numLevels;
    int entityList[ MAX_GENTITIES ];
    vec3_t range = { AS_OVER_RT3, AS_OVER_RT3, AS_OVER_RT3 };
    vec3_t mins, maxs;
    int num;
    gentity_t *other;


    if( ent->client->ps.stats[ STAT_HEALTH ] <= 0 )
        return 0;
   
    botCmdBuffer->upmove = 0;

    clientNum = ent->client - level.clients;

    newClass = BG_FindClassNumForName( classname );
    
    switch(newClass){
        case PCL_ALIEN_LEVEL1:
            if(g_bot_level1.integer == 0)
                return 0;
            break;
        case PCL_ALIEN_LEVEL1_UPG:
        case PCL_HUMAN_BSUIT:
            if(g_bot_level1upg.integer == 0)
                return 0;
            break;
        case PCL_ALIEN_LEVEL2:
            if(g_bot_level2.integer == 0)
                return 0;
            break;
        case PCL_ALIEN_LEVEL2_UPG:
            if(g_bot_level2upg.integer == 0)
                return 0;
            break;
        case PCL_ALIEN_LEVEL3:
            if(g_bot_level3.integer == 0)
                return 0;
            break;
        case PCL_ALIEN_LEVEL3_UPG:
            if(g_bot_level3upg.integer == 0)
                return 0;
            break;
        case PCL_ALIEN_LEVEL4:
            if(g_bot_level4.integer == 0)
                return 0;
            break;
        default:
            break;
    }

    //if we are not currently spectating, we are attempting evolution
    if( ent->client->pers.classSelection != PCL_NONE )
    {
        if( ( ent->client->ps.stats[ STAT_STATE ] & SS_WALLCLIMBING ) ||
            ( ent->client->ps.stats[ STAT_STATE ] & SS_WALLCLIMBINGCEILING ) )
            return 0;

        //check there are no humans nearby
        VectorAdd( ent->client->ps.origin, range, maxs );
        VectorSubtract( ent->client->ps.origin, range, mins );

        num = trap_EntitiesInBox( mins, maxs, entityList, MAX_GENTITIES );
        for( i = 0; i < num; i++ )
        {
            other = &g_entities[ entityList[ i ] ];

            if( ( other->client && other->client->ps.stats[ STAT_PTEAM ] == PTE_HUMANS ) ||
                ( other->s.eType == ET_BUILDABLE && other->biteam == BIT_HUMANS ) )
                return 0;
        }

        if( !level.overmindPresent )
            return 0;

        numLevels = BG_ClassCanEvolveFromTo( currentClass,
                                             newClass,
                                             (short)ent->client->ps.persistant[ PERS_CREDIT ], 0 );

        if( G_RoomForClassChange( ent, newClass, infestOrigin ) )
        {
            //...check we can evolve to that class
            if( numLevels >= 0 &&
                BG_FindStagesForClass( newClass, g_alienStage.integer ) &&
                BG_ClassIsAllowed( newClass ) )
            {

                ent->client->pers.evolveHealthFraction = (float)ent->client->ps.stats[ STAT_HEALTH ] /
                                                         (float)BG_FindHealthForClass( currentClass );

                if( ent->client->pers.evolveHealthFraction < 0.0f )
                    ent->client->pers.evolveHealthFraction = 0.0f;
                else if( ent->client->pers.evolveHealthFraction > 1.5f )
                    ent->client->pers.evolveHealthFraction = 1.5f;

                //remove credit
                G_AddCreditToClient( ent->client, -(short)numLevels, qtrue );
                ent->client->pers.classSelection = newClass;
                ClientUserinfoChanged( clientNum );
                VectorCopy( infestOrigin, ent->s.pos.trBase );
                ClientSpawn( ent, ent, ent->s.pos.trBase, ent->s.apos.trBase );

                //trap_SendServerCommand( -1, va( "print \"evolved to %s\n\"", classname) );

                return 1;
            }
            else
                //trap_SendServerCommand( -1, va( "print \"Not enough evos to evolve to %s\n\"", classname) );
                return 0;
        }
        else
            return 0;
    }
    return 0;
}

