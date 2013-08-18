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

// g_maprotation.c -- the map rotation system

#include "g_local.h"

mapRotations_t mapRotations;


static qboolean G_GetVotedMap( char *name, int size, int rotation, int map );

/*
===============
G_MapExists

Check if a map exists
===============
*/
qboolean G_MapExists( char *name )
{
  return trap_FS_FOpenFile( va( "maps/%s.bsp", name ), NULL, FS_READ );
}

/*
===============
G_RotationExists

Check if a rotation exists
===============
*/
static qboolean G_RotationExists( char *name )
{
  int i;

  for( i = 0; i < mapRotations.numRotations; i++ )
  {
    if( Q_strncmp( mapRotations.rotations[ i ].name, name, MAX_QPATH ) == 0 )
      return qtrue;
  }

  return qfalse;
}

/*
===============
G_ParseCommandSection

Parse a map rotation command section
===============
*/
static qboolean G_ParseMapCommandSection( mapRotationEntry_t *mre, char **text_p )
{
  char *token;

  // read optional parameters
  while( 1 )
  {
    token = COM_Parse( text_p );

    if( !token )
      break;

    if( !Q_stricmp( token, "" ) )
      return qfalse;

    if( !Q_stricmp( token, "}" ) )
      return qtrue; //reached the end of this command section

    if( !Q_stricmp( token, "layouts" ) )
    {
      token = COM_ParseExt( text_p, qfalse );
      mre->layouts[ 0 ] = '\0';
      while( token && token[ 0 ] != 0 )
      {
        Q_strcat( mre->layouts, sizeof( mre->layouts ), token );
        Q_strcat( mre->layouts, sizeof( mre->layouts ), " " );
        token = COM_ParseExt( text_p, qfalse );
      }
      continue;
    }

    Q_strncpyz( mre->postCmds[ mre->numCmds ], token, sizeof( mre->postCmds[ 0 ] ) );
    Q_strcat( mre->postCmds[ mre->numCmds ], sizeof( mre->postCmds[ 0 ] ), " " );

    token = COM_ParseExt( text_p, qfalse );

    while( token && token[ 0 ] != 0 )
    {
      Q_strcat( mre->postCmds[ mre->numCmds ], sizeof( mre->postCmds[ 0 ] ), token );
      Q_strcat( mre->postCmds[ mre->numCmds ], sizeof( mre->postCmds[ 0 ] ), " " );
      token = COM_ParseExt( text_p, qfalse );
    }

    if( mre->numCmds == MAX_MAP_COMMANDS )
    {
      G_Printf( S_COLOR_RED "ERROR: maximum number of map commands (%d) reached\n",
                MAX_MAP_COMMANDS );
      return qfalse;
    }
    else
      mre->numCmds++;
  }

  return qfalse;
}

/*
===============
G_ParseMapRotation

Parse a map rotation section
===============
*/
static qboolean G_ParseMapRotation( mapRotation_t *mr, char **text_p )
{
  char                    *token;
  qboolean                mnSet = qfalse;
  mapRotationEntry_t      *mre = NULL;
  mapRotationCondition_t  *mrc;

  // read optional parameters
  while( 1 )
  {
    token = COM_Parse( text_p );

    if( !token )
      break;

    if( !Q_stricmp( token, "" ) )
      return qfalse;

    if( !Q_stricmp( token, "{" ) )
    {
      if( !mnSet )
      {
        G_Printf( S_COLOR_RED "ERROR: map settings section with no name\n" );
        return qfalse;
      }

      if( !G_ParseMapCommandSection( mre, text_p ) )
      {
        G_Printf( S_COLOR_RED "ERROR: failed to parse map command section\n" );
        return qfalse;
      }

      mnSet = qfalse;
      continue;
    }
    else if( !Q_stricmp( token, "goto" ) )
    {
      token = COM_Parse( text_p );

      if( !token )
        break;

      mrc = &mre->conditions[ mre->numConditions ];
      mrc->unconditional = qtrue;
      Q_strncpyz( mrc->dest, token, sizeof( mrc->dest ) );

      if( mre->numConditions == MAX_MAP_ROTATION_CONDS )
      {
        G_Printf( S_COLOR_RED "ERROR: maximum number of conditions for one map (%d) reached\n",
                  MAX_MAP_ROTATION_CONDS );
        return qfalse;
      }
      else
        mre->numConditions++;

      continue;
    }
    else if( !Q_stricmp( token, "if" ) )
    {
      token = COM_Parse( text_p );

      if( !token )
        break;

      mrc = &mre->conditions[ mre->numConditions ];

      if( !Q_stricmp( token, "numClients" ) )
      {
        mrc->lhs = MCV_NUMCLIENTS;

        token = COM_Parse( text_p );

        if( !token )
          break;

        if( !Q_stricmp( token, "<" ) )
          mrc->op = MCO_LT;
        else if( !Q_stricmp( token, ">" ) )
          mrc->op = MCO_GT;
        else if( !Q_stricmp( token, "=" ) )
          mrc->op = MCO_EQ;
        else
        {
          G_Printf( S_COLOR_RED "ERROR: invalid operator in expression: %s\n", token );
          return qfalse;
        }

        token = COM_Parse( text_p );

        if( !token )
          break;

        mrc->numClients = atoi( token );
      }
      else if( !Q_stricmp( token, "lastWin" ) )
      {
        mrc->lhs = MCV_LASTWIN;

        token = COM_Parse( text_p );

        if( !token )
          break;

        if( !Q_stricmp( token, "aliens" ) )
          mrc->lastWin = PTE_ALIENS;
        else if( !Q_stricmp( token, "humans" ) )
          mrc->lastWin = PTE_HUMANS;
        else
        {
          G_Printf( S_COLOR_RED "ERROR: invalid right hand side in expression: %s\n", token );
          return qfalse;
        }
      }
      else if( !Q_stricmp( token, "random" ) )
        mrc->lhs = MCV_RANDOM;
      else
      {
        G_Printf( S_COLOR_RED "ERROR: invalid left hand side in expression: %s\n", token );
        return qfalse;
      }

      token = COM_Parse( text_p );

      if( !token )
        break;

      mrc->unconditional = qfalse;
      Q_strncpyz( mrc->dest, token, sizeof( mrc->dest ) );

      if( mre->numConditions == MAX_MAP_ROTATION_CONDS )
      {
        G_Printf( S_COLOR_RED "ERROR: maximum number of conditions for one map (%d) reached\n",
                  MAX_MAP_ROTATION_CONDS );
        return qfalse;
      }
      else
        mre->numConditions++;

      continue;
    }
    else if( !Q_stricmp( token, "*VOTE*" ) )
    {
      if( mr->numMaps == MAX_MAP_ROTATION_MAPS )
      {
        G_Printf( S_COLOR_RED "ERROR: maximum number of maps in one rotation (%d) reached\n",
                  MAX_MAP_ROTATION_MAPS );
        return qfalse;
      }
      mre = &mr->maps[ mr->numMaps ];
      Q_strncpyz( mre->name, token, sizeof( mre->name ) );

      token = COM_Parse( text_p );

      if( !Q_stricmp( token, "{" ) )
      {
        while( 1 )
        {
          token = COM_Parse( text_p );

          if( !token )
            break;

          if( !Q_stricmp( token, "}" ) )
          {
            break;
          }
          else
          {
            if( mre->numConditions < MAX_MAP_ROTATION_CONDS )
            {
              mrc = &mre->conditions[ mre->numConditions ];
              mrc->lhs = MCV_VOTE;
              mrc->unconditional = qfalse;
              Q_strncpyz( mrc->dest, token, sizeof( mrc->dest ) );

              mre->numConditions++;
            }
            else
            {
              G_Printf( S_COLOR_YELLOW "ERROR: maximum number of maps for one vote (%d) reached\n",
                        MAX_MAP_ROTATION_CONDS );
            }
          }
        }
        if( !mre->numConditions )
        {
          G_Printf( S_COLOR_YELLOW "WARNING: no maps in *VOTE* section\n" );
        }
        else
        {
          mr->numMaps++;
          mnSet = qtrue;
        }
      }
      else
      {
        G_Printf( S_COLOR_RED "ERROR: *VOTE* with no section\n" );
        return qfalse;
      }

      continue;
    }
    else if( !Q_stricmp( token, "}" ) )
      return qtrue; //reached the end of this map rotation

    mre = &mr->maps[ mr->numMaps ];

    if( mr->numMaps == MAX_MAP_ROTATION_MAPS )
    {
      G_Printf( S_COLOR_RED "ERROR: maximum number of maps in one rotation (%d) reached\n",
                MAX_MAP_ROTATION_MAPS );
      return qfalse;
    }
    else
      mr->numMaps++;

    Q_strncpyz( mre->name, token, sizeof( mre->name ) );
    mnSet = qtrue;
  }

  return qfalse;
}

/*
===============
G_ParseMapRotationFile

Load the map rotations from a map rotation file
===============
*/
static qboolean G_ParseMapRotationFile( const char *fileName )
{
  char          *text_p;
  int           i, j, k;
  int           len;
  char          *token;
  char          text[ 20000 ];
  char          mrName[ MAX_QPATH ];
  qboolean      mrNameSet = qfalse;
  fileHandle_t  f;

  // load the file
  len = trap_FS_FOpenFile( fileName, &f, FS_READ );
  if( len < 0 )
    return qfalse;

  if( len == 0 || len >= sizeof( text ) - 1 )
  {
    trap_FS_FCloseFile( f );
    G_Printf( S_COLOR_RED "ERROR: map rotation file %s is %s\n", fileName,
      len == 0 ? "empty" : "too long" );
    return qfalse;
  }

  trap_FS_Read( text, len, f );
  text[ len ] = 0;
  trap_FS_FCloseFile( f );

  // parse the text
  text_p = text;

  // read optional parameters
  while( 1 )
  {
    token = COM_Parse( &text_p );

    if( !token )
      break;

    if( !Q_stricmp( token, "" ) )
      break;

    if( !Q_stricmp( token, "{" ) )
    {
      if( mrNameSet )
      {
        //check for name space clashes
        for( i = 0; i < mapRotations.numRotations; i++ )
        {
          if( !Q_stricmp( mapRotations.rotations[ i ].name, mrName ) )
          {
            G_Printf( S_COLOR_RED "ERROR: a map rotation is already named %s\n", mrName );
            return qfalse;
          }
        }

        Q_strncpyz( mapRotations.rotations[ mapRotations.numRotations ].name, mrName, MAX_QPATH );

        if( !G_ParseMapRotation( &mapRotations.rotations[ mapRotations.numRotations ], &text_p ) )
        {
          G_Printf( S_COLOR_RED "ERROR: %s: failed to parse map rotation %s\n", fileName, mrName );
          return qfalse;
        }

        //start parsing map rotations again
        mrNameSet = qfalse;

        if( mapRotations.numRotations == MAX_MAP_ROTATIONS )
        {
          G_Printf( S_COLOR_RED "ERROR: maximum number of map rotations (%d) reached\n",
                    MAX_MAP_ROTATIONS );
          return qfalse;
        }
        else
          mapRotations.numRotations++;

        continue;
      }
      else
      {
        G_Printf( S_COLOR_RED "ERROR: unamed map rotation\n" );
        return qfalse;
      }
    }

    if( !mrNameSet )
    {
      Q_strncpyz( mrName, token, sizeof( mrName ) );
      mrNameSet = qtrue;
    }
    else
    {
      G_Printf( S_COLOR_RED "ERROR: map rotation already named\n" );
      return qfalse;
    }
  }

  for( i = 0; i < mapRotations.numRotations; i++ )
  {
    for( j = 0; j < mapRotations.rotations[ i ].numMaps; j++ )
    {
      if( !G_MapExists( mapRotations.rotations[ i ].maps[ j ].name ) && Q_stricmp( "*VOTE*", mapRotations.rotations[ i ].maps[ j ].name ) )
      {
        G_Printf( S_COLOR_RED "ERROR: map \"%s\" doesn't exist\n",
          mapRotations.rotations[ i ].maps[ j ].name );
        return qfalse;
      }

      for( k = 0; k < mapRotations.rotations[ i ].maps[ j ].numConditions; k++ )
      {
        if( !G_MapExists( mapRotations.rotations[ i ].maps[ j ].conditions[ k ].dest ) &&
            !G_RotationExists( mapRotations.rotations[ i ].maps[ j ].conditions[ k ].dest ) && Q_stricmp( "*VOTE*", mapRotations.rotations[ i ].maps[ j ].name ) )
        {
          G_Printf( S_COLOR_RED "ERROR: conditional destination \"%s\" doesn't exist\n",
            mapRotations.rotations[ i ].maps[ j ].conditions[ k ].dest );
          return qfalse;
        }

      }

    }
  }

  return qtrue;
}

/*
===============
G_PrintRotations

Print the parsed map rotations
===============
*/
void G_PrintRotations( void )
{
  int i, j, k;

  G_Printf( "Map rotations as parsed:\n\n" );

  for( i = 0; i < mapRotations.numRotations; i++ )
  {
    G_Printf( "rotation: %s\n{\n", mapRotations.rotations[ i ].name );

    for( j = 0; j < mapRotations.rotations[ i ].numMaps; j++ )
    {
      G_Printf( "  map: %s\n  {\n", mapRotations.rotations[ i ].maps[ j ].name );

      for( k = 0; k < mapRotations.rotations[ i ].maps[ j ].numCmds; k++ )
      {
        G_Printf( "    command: %s\n",
                  mapRotations.rotations[ i ].maps[ j ].postCmds[ k ] );
      }

      G_Printf( "  }\n" );

      for( k = 0; k < mapRotations.rotations[ i ].maps[ j ].numConditions; k++ )
      {
        G_Printf( "  conditional: %s\n",
                  mapRotations.rotations[ i ].maps[ j ].conditions[ k ].dest );
      }

    }

    G_Printf( "}\n" );
  }

  G_Printf( "Total memory used: %d bytes\n", sizeof( mapRotations ) );
}

/*
===============
G_GetCurrentMapArray

Fill a static array with the current map of each rotation
===============
*/
static int *G_GetCurrentMapArray( void )
{
  static int  currentMap[ MAX_MAP_ROTATIONS ];
  int         i = 0;
  char        text[ MAX_MAP_ROTATIONS * 2 ];
  char        *text_p, *token;

  Q_strncpyz( text, g_currentMap.string, sizeof( text ) );

  text_p = text;

  while( 1 )
  {
    token = COM_Parse( &text_p );

    if( !token )
      break;

    if( !Q_stricmp( token, "" ) )
      break;

    currentMap[ i++ ] = atoi( token );
  }

  return currentMap;
}

/*
===============
G_SetCurrentMap

Set the current map in some rotation
===============
*/
static void G_SetCurrentMap( int currentMap, int rotation )
{
  char  text[ MAX_MAP_ROTATIONS * 2 ] = { 0 };
  int   *p = G_GetCurrentMapArray( );
  int   i;

  p[ rotation ] = currentMap;

  for( i = 0; i < mapRotations.numRotations; i++ )
    Q_strcat( text, sizeof( text ), va( "%d ", p[ i ] ) );

  trap_Cvar_Set( "g_currentMap", text );
  trap_Cvar_Update( &g_currentMap );
}

/*
===============
G_GetCurrentMap

Return the current map in some rotation
===============
*/
int G_GetCurrentMap( int rotation )
{
  int   *p = G_GetCurrentMapArray( );

  return p[ rotation ];
}

/*
===============
G_IssueMapChange

Send commands to the server to actually change the map
===============
*/
static void G_IssueMapChange( int rotation )
{
  int   i;
  int   map = G_GetCurrentMap( rotation );
  char  cmd[ MAX_TOKEN_CHARS ], mapName[MAX_STRING_CHARS];

  Q_strncpyz(mapName, mapRotations.rotations[rotation].maps[map].name, sizeof(mapName));
  if (!Q_stricmp(mapName, "*VOTE*"))
    G_GetVotedMap(mapName, sizeof(mapName), rotation, map );

  // allow a manually defined g_layouts setting to override the maprotation
  if( !g_layouts.string[ 0 ] &&
    mapRotations.rotations[ rotation ].maps[ map ].layouts[ 0 ] )
  {
    trap_Cvar_Set( "g_layouts",
      mapRotations.rotations[ rotation ].maps[ map ].layouts );
  }

  trap_SendConsoleCommand( EXEC_APPEND, va( "map %s\n", mapName ) );

  // load up map defaults if g_mapConfigs is set
  G_MapConfigs( mapRotations.rotations[ rotation ].maps[ map ].name );

  for( i = 0; i < mapRotations.rotations[ rotation ].maps[ map ].numCmds; i++ )
  {
    Q_strncpyz( cmd, mapRotations.rotations[ rotation ].maps[ map ].postCmds[ i ],
                sizeof( cmd ) );
    Q_strcat( cmd, sizeof( cmd ), "\n" );
    trap_SendConsoleCommand( EXEC_APPEND, cmd );
  }
}

/*
===============
G_ResolveConditionDestination

Resolve the destination of some condition
===============
*/
static mapConditionType_t G_ResolveConditionDestination( int *n, char *name )
{
  int i;

  //search the current rotation first...
  for( i = 0; i < mapRotations.rotations[ g_currentMapRotation.integer ].numMaps; i++ )
  {
    if( !Q_stricmp( mapRotations.rotations[ g_currentMapRotation.integer ].maps[ i ].name, name ) )
    {
      *n = i;
      return MCT_MAP;
    }
  }

  //...then search the rotation names
  for( i = 0; i < mapRotations.numRotations; i++ )
  {
    if( !Q_stricmp( mapRotations.rotations[ i ].name, name ) )
    {
      *n = i;
      return MCT_ROTATION;
    }
  }

  return MCT_ERR;
}

/*
===============
G_EvaluateMapCondition

Evaluate a map condition
===============
*/
static qboolean G_EvaluateMapCondition( mapRotationCondition_t *mrc )
{
  switch( mrc->lhs )
  {
    case MCV_RANDOM:
      return rand( ) & 1;
      break;

    case MCV_NUMCLIENTS:
      switch( mrc->op )
      {
        case MCO_LT:
          return level.numConnectedClients < mrc->numClients;
          break;

        case MCO_GT:
          return level.numConnectedClients > mrc->numClients;
          break;

        case MCO_EQ:
          return level.numConnectedClients == mrc->numClients;
          break;
      }
      break;

    case MCV_LASTWIN:
      return level.lastWin == mrc->lastWin;
      break;

    case MCV_VOTE:
      // ignore vote for conditions;
      break;

    default:
    case MCV_ERR:
      G_Printf( S_COLOR_RED "ERROR: malformed map switch condition\n" );
      break;
  }

  return qfalse;
}

/*
===============
G_AdvanceMapRotation

Increment the current map rotation
===============
*/
qboolean G_AdvanceMapRotation( void )
{
  mapRotation_t           *mr;
  mapRotationEntry_t      *mre;
  mapRotationCondition_t  *mrc;
  int                     currentRotation, currentMap, nextMap;
  int                     i, n;
  mapConditionType_t      mct;

  if( ( currentRotation = g_currentMapRotation.integer ) == NOT_ROTATING )
    return qfalse;

  currentMap = G_GetCurrentMap( currentRotation );

  mr = &mapRotations.rotations[ currentRotation ];
  mre = &mr->maps[ currentMap ];
  nextMap = ( currentMap + 1 ) % mr->numMaps;

  for( i = 0; i < mre->numConditions; i++ )
  {
    mrc = &mre->conditions[ i ];

    if( mrc->unconditional || G_EvaluateMapCondition( mrc ) )
    {
      mct = G_ResolveConditionDestination( &n, mrc->dest );

      switch( mct )
      {
        case MCT_MAP:
          nextMap = n;
          break;

        case MCT_ROTATION:
          //need to increment the current map before changing the rotation
          //or you get infinite loops with some conditionals
          G_SetCurrentMap( nextMap, currentRotation );
          G_StartMapRotation( mrc->dest, qtrue );
          return qtrue;
          break;

        default:
        case MCT_ERR:
          G_Printf( S_COLOR_YELLOW "WARNING: map switch destination could not be resolved: %s\n",
                    mrc->dest );
          break;
      }
    }
  }

  G_SetCurrentMap( nextMap, currentRotation );
  G_IssueMapChange( currentRotation );

  return qtrue;
}

/*
===============
G_StartMapRotation

Switch to a new map rotation
===============
*/
qboolean G_StartMapRotation( char *name, qboolean changeMap )
{
  int i;

  for( i = 0; i < mapRotations.numRotations; i++ )
  {
    if( !Q_stricmp( mapRotations.rotations[ i ].name, name ) )
    {
      trap_Cvar_Set( "g_currentMapRotation", va( "%d", i ) );
      trap_Cvar_Update( &g_currentMapRotation );

      if( changeMap )
        G_IssueMapChange( i );
      break;
    }
  }

  if( i == mapRotations.numRotations )
    return qfalse;
  else
    return qtrue;
}

/*
===============
G_StopMapRotation

Stop the current map rotation
===============
*/
void G_StopMapRotation( void )
{
  trap_Cvar_Set( "g_currentMapRotation", va( "%d", NOT_ROTATING ) );
  trap_Cvar_Update( &g_currentMapRotation );
}

/*
===============
G_MapRotationActive

Test if any map rotation is currently active
===============
*/
qboolean G_MapRotationActive( void )
{
  return ( g_currentMapRotation.integer != NOT_ROTATING );
}

/*
===============
G_InitMapRotations

Load and intialise the map rotations
===============
*/
void G_InitMapRotations( void )
{
  const char    *fileName = "maprotation.cfg";

  //load the file if it exists
  if( trap_FS_FOpenFile( fileName, NULL, FS_READ ) )
  {
    if( !G_ParseMapRotationFile( fileName ) )
      G_Printf( S_COLOR_RED "ERROR: failed to parse %s file\n", fileName );
  }
  else
    G_Printf( "%s file not found.\n", fileName );

  if( g_currentMapRotation.integer == NOT_ROTATING )
  {
    if( g_initialMapRotation.string[ 0 ] != 0 )
    {
      G_StartMapRotation( g_initialMapRotation.string, qfalse );

      trap_Cvar_Set( "g_initialMapRotation", "" );
      trap_Cvar_Update( &g_initialMapRotation );
    }
  }
}

static char rotationVoteList[ MAX_MAP_ROTATION_CONDS ][ MAX_QPATH ];
static int rotationVoteLen = 0;

static int rotationVoteClientPosition[ MAX_CLIENTS ];
static int rotationVoteClientSelection[ MAX_CLIENTS ];

/*
===============
G_CheckMapRotationVote
===============
*/
qboolean G_CheckMapRotationVote( void )
{
  mapRotation_t           *mr;
  mapRotationEntry_t      *mre;
  mapRotationCondition_t  *mrc;
  int                     currentRotation, currentMap, nextMap;
  int                     i;

  rotationVoteLen = 0;

  if( g_mapRotationVote.integer < 1 )
    return qfalse;

  if( ( currentRotation = g_currentMapRotation.integer ) == NOT_ROTATING )
    return qfalse;

  currentMap = G_GetCurrentMap( currentRotation );

  mr = &mapRotations.rotations[ currentRotation ];
  nextMap = ( currentMap + 1 ) % mr->numMaps;
  mre = &mr->maps[ nextMap ];

  for( i = 0; i < mre->numConditions; i++ )
  {
    mrc = &mre->conditions[ i ];

    if( mrc->lhs == MCV_VOTE )
    {
      Q_strncpyz( rotationVoteList[ rotationVoteLen ], mrc->dest,
        sizeof(  rotationVoteList[ rotationVoteLen ] ) );
      rotationVoteLen++;
      if( rotationVoteLen >= MAX_MAP_ROTATION_CONDS )
        break;
    }
  }

  if( !rotationVoteLen )
    return qfalse;

  for( i = 0; i < MAX_CLIENTS; i++ )
  {
    rotationVoteClientPosition[ i ] = 0;
    rotationVoteClientSelection[ i ] = -1;
  }

  return qtrue;
}

static int G_GetMapVoteWinner( int *winvotes, int *totalvotes )
{
  int results[ MAX_MAP_ROTATION_CONDS ];
  int winner = 0;
  int wv = 0;
  int tv = 0;
  int i, n;

  memset( results, 0, sizeof( results ));
  for( i = 0; i < MAX_CLIENTS; i++ )
  {
    n = rotationVoteClientSelection[ i ];
    if( n >=0 && n < MAX_MAP_ROTATION_CONDS )
    {
      results[ n ] += 1;
      tv++;
    }
  }

  for( i = 0; i < MAX_MAP_ROTATION_CONDS; i++ )
  {
    if( results[ i ] > wv )
    {
      winner = i;
      wv = results[ i ];
    }
  }

  if( winvotes != NULL )
    *winvotes = wv;
  if( totalvotes != NULL )
    *totalvotes = tv;

  return winner;
}

qboolean G_IntermissionMapVoteWinner( void )
{
  int winner, winvotes, totalvotes;
  int nonvotes;

  winner = G_GetMapVoteWinner( &winvotes, &totalvotes );
  if( winvotes * 2 > level.numConnectedClients )
    return qtrue;
  nonvotes = level.numConnectedClients - totalvotes;
  if( nonvotes < 0 )
    nonvotes = 0;
  if( winvotes > nonvotes + ( totalvotes - winvotes ) )
    return qtrue;

  return qfalse;
}

static qboolean G_GetVotedMap( char *name, int size, int rotation, int map )
{
  mapRotation_t           *mr;
  mapRotationEntry_t      *mre;
  mapRotationCondition_t  *mrc;
  int                     i, n;
  int                     winner;
  qboolean                found = qfalse;

  if( !rotationVoteLen )
    return qfalse;

  winner = G_GetMapVoteWinner( NULL, NULL );

  mr = &mapRotations.rotations[ rotation ];
  mre = &mr->maps[ map ];

  n = 0;
  for( i = 0; i < mre->numConditions && n < rotationVoteLen; i++ )
  {
    mrc = &mre->conditions[ i ];

    if( mrc->lhs == MCV_VOTE )
    {
      if( n == winner )
      {
        Q_strncpyz( name, mrc->dest, size );
        found = qtrue;
        break;
      }
      n++;
    }
  }

  rotationVoteLen = 0;

  return found;
}

static void G_IntermissionMapVoteMessageReal( gentity_t *ent, int winner, int winvotes, int totalvotes )
{
  int  clientNum;
  char string[ MAX_STRING_CHARS ];
  char entry[ MAX_STRING_CHARS ];
  int  len = 0;
  int  index, selection;
  int  i;
  char *color;

  clientNum = ent-g_entities;

  index = rotationVoteClientSelection[ clientNum ];
  selection = rotationVoteClientPosition[ clientNum ];

  if( winner < 0 || winner >= MAX_MAP_ROTATION_CONDS )
    winner = G_GetMapVoteWinner( &winvotes, &totalvotes );

  Q_strncpyz( string, "^7Attack^5=^7Down Repair^5=^7Up ^7F1^5=^7Vote\n\n"
    "^7Map Vote Menu\n"
    "^5+^7------------------^5+\n", sizeof( string ) );
  for( i = 0; i < rotationVoteLen; i++ )
  {
    if( i == index )
      color = "^7";
    else if( i == selection )
      color = "^5";
    else
      color = "^7";

    Com_sprintf( entry, sizeof( entry ), "^7%s%s%s %s %s^7%s\n",
     ( i == index ) ? "^5>>>" : "",
     ( i == selection ) ? "^7(" : " ",
     color,
     rotationVoteList[ i ],
     ( i == selection ) ? "^7)" : " ",
     ( i == index ) ? "^5<<<" : "" );

    Q_strcat( string, sizeof( string ), entry );
    len += strlen( entry );
  }

  Com_sprintf( entry, sizeof( entry ),
    "\n^5+^7----------------^5+\n^7Leader: '^5%s^7' (^5%d ^7of ^5%d^7)\n^7Voters: ^5%d\n^7Time Left: ^5%d",
    rotationVoteList[ winner ],
    winvotes,
    totalvotes,
    totalvotes,
    ( level.mapRotationVoteTime - level.time ) / 1000 );
  Q_strcat( string, sizeof( string ), entry );

  trap_SendServerCommand( ent-g_entities, va( "cp \"%s\"\n", string ) );
}

void G_IntermissionMapVoteMessageAll( void )
{
  int winner;
  int winvotes, totalvotes;
  int i;

  winner = G_GetMapVoteWinner( &winvotes, &totalvotes );
  for( i = 0; i < level.maxclients; i++ )
  {
    if( level.clients[ i ].pers.connected == CON_CONNECTED )
      G_IntermissionMapVoteMessageReal( g_entities + i, winner, winvotes, totalvotes );
  }
}

void G_IntermissionMapVoteMessage( gentity_t *ent )
{
   G_IntermissionMapVoteMessageReal( ent, -1, 0, 0 );
}

void G_IntermissionMapVoteCommand( gentity_t *ent, qboolean next, qboolean choose )
{
  int clientNum;
  int n;

  clientNum = ent-g_entities;

  if( choose )
  {
    rotationVoteClientSelection[ clientNum ] = rotationVoteClientPosition[ clientNum ];
  }
  else
  {
    n = rotationVoteClientPosition[ clientNum ];
    if( next )
      n++;
    else
      n--;

    if( n >= rotationVoteLen )
      n = rotationVoteLen - 1;
    if( n < 0 )
      n = 0;

    rotationVoteClientPosition[ clientNum ] = n;
  }

  G_IntermissionMapVoteMessage( ent );
}

