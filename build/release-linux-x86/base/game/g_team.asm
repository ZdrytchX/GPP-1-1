export PrintMsg
code
proc PrintMsg 1048 12
ADDRLP4 1028
ADDRFP4 4+4
ASGNP4
ADDRLP4 4
ARGP4
ADDRFP4 4
INDIRP4
ARGP4
ADDRLP4 1028
INDIRP4
ARGP4
ADDRLP4 1032
ADDRGP4 vsprintf
CALLI4
ASGNI4
ADDRLP4 1032
INDIRI4
CVIU4 4
CNSTU4 1024
LEU4 $90
ADDRGP4 $92
ARGP4
ADDRGP4 G_Error
CALLV
pop
LABELV $90
ADDRLP4 1028
CNSTP4 0
ASGNP4
ADDRGP4 $94
JUMPV
LABELV $93
ADDRLP4 0
INDIRP4
CNSTI1 39
ASGNI1
LABELV $94
ADDRLP4 4
ARGP4
CNSTI4 34
ARGI4
ADDRLP4 1036
ADDRGP4 strchr
CALLP4
ASGNP4
ADDRLP4 0
ADDRLP4 1036
INDIRP4
ASGNP4
ADDRLP4 1036
INDIRP4
CVPU4 4
CNSTU4 0
NEU4 $93
ADDRGP4 $97
ARGP4
ADDRLP4 4
ARGP4
ADDRLP4 1044
ADDRGP4 va
CALLP4
ASGNP4
ADDRFP4 0
INDIRP4
CVPU4 4
CNSTU4 0
NEU4 $98
ADDRLP4 1040
CNSTI4 -1
ASGNI4
ADDRGP4 $99
JUMPV
LABELV $98
ADDRLP4 1040
ADDRFP4 0
INDIRP4
CVPU4 4
ADDRGP4 g_entities
CVPU4 4
SUBU4
CVUI4 4
CNSTI4 1828
DIVI4
ASGNI4
LABELV $99
ADDRLP4 1040
INDIRI4
ARGI4
ADDRLP4 1044
INDIRP4
ARGP4
ADDRGP4 trap_SendServerCommand
CALLV
pop
LABELV $88
endproc PrintMsg 1048 12
export OnSameTeam
proc OnSameTeam 16 0
ADDRLP4 0
CNSTI4 516
ASGNI4
ADDRLP4 4
CNSTU4 0
ASGNU4
ADDRFP4 0
INDIRP4
ADDRLP4 0
INDIRI4
ADDP4
INDIRP4
CVPU4 4
ADDRLP4 4
INDIRU4
EQU4 $103
ADDRFP4 4
INDIRP4
ADDRLP4 0
INDIRI4
ADDP4
INDIRP4
CVPU4 4
ADDRLP4 4
INDIRU4
NEU4 $101
LABELV $103
CNSTI4 0
RETI4
ADDRGP4 $100
JUMPV
LABELV $101
ADDRLP4 8
CNSTI4 516
ASGNI4
ADDRLP4 12
CNSTI4 664
ASGNI4
ADDRFP4 0
INDIRP4
ADDRLP4 8
INDIRI4
ADDP4
INDIRP4
ADDRLP4 12
INDIRI4
ADDP4
INDIRI4
ADDRFP4 4
INDIRP4
ADDRLP4 8
INDIRI4
ADDP4
INDIRP4
ADDRLP4 12
INDIRI4
ADDP4
INDIRI4
NEI4 $104
CNSTI4 1
RETI4
ADDRGP4 $100
JUMPV
LABELV $104
CNSTI4 0
RETI4
LABELV $100
endproc OnSameTeam 16 0
export Team_GetLocation
proc Team_GetLocation 48 8
ADDRLP4 24
CNSTP4 0
ASGNP4
ADDRLP4 20
CNSTF4 1296039936
ASGNF4
ADDRLP4 4
ADDRFP4 0
INDIRP4
CNSTI4 488
ADDP4
INDIRB
ASGNB 12
ADDRLP4 0
ADDRGP4 level+11208
INDIRP4
ASGNP4
ADDRGP4 $110
JUMPV
LABELV $107
ADDRLP4 32
ADDRLP4 4
INDIRF4
ADDRLP4 0
INDIRP4
CNSTI4 488
ADDP4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 36
ADDRLP4 0
INDIRP4
CNSTI4 492
ADDP4
INDIRF4
ASGNF4
ADDRLP4 40
ADDRLP4 0
INDIRP4
CNSTI4 496
ADDP4
INDIRF4
ASGNF4
ADDRLP4 16
ADDRLP4 32
INDIRF4
ADDRLP4 32
INDIRF4
MULF4
ADDRLP4 4+4
INDIRF4
ADDRLP4 36
INDIRF4
SUBF4
ADDRLP4 4+4
INDIRF4
ADDRLP4 36
INDIRF4
SUBF4
MULF4
ADDF4
ADDRLP4 4+8
INDIRF4
ADDRLP4 40
INDIRF4
SUBF4
ADDRLP4 4+8
INDIRF4
ADDRLP4 40
INDIRF4
SUBF4
MULF4
ADDF4
ASGNF4
ADDRLP4 16
INDIRF4
ADDRLP4 20
INDIRF4
LEF4 $116
ADDRGP4 $108
JUMPV
LABELV $116
ADDRLP4 4
ARGP4
ADDRLP4 0
INDIRP4
CNSTI4 488
ADDP4
ARGP4
ADDRLP4 44
ADDRGP4 trap_InPVS
CALLI4
ASGNI4
ADDRLP4 44
INDIRI4
CNSTI4 0
NEI4 $118
ADDRGP4 $108
JUMPV
LABELV $118
ADDRLP4 20
ADDRLP4 16
INDIRF4
ASGNF4
ADDRLP4 24
ADDRLP4 0
INDIRP4
ASGNP4
LABELV $108
ADDRLP4 0
ADDRLP4 0
INDIRP4
CNSTI4 604
ADDP4
INDIRP4
ASGNP4
LABELV $110
ADDRLP4 0
INDIRP4
CVPU4 4
CNSTU4 0
NEU4 $107
ADDRLP4 24
INDIRP4
RETP4
LABELV $106
endproc Team_GetLocation 48 8
export Team_GetLocationMsg
proc Team_GetLocationMsg 12 24
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 4
ADDRGP4 Team_GetLocation
CALLP4
ASGNP4
ADDRLP4 0
ADDRLP4 4
INDIRP4
ASGNP4
ADDRLP4 0
INDIRP4
CVPU4 4
CNSTU4 0
NEU4 $121
CNSTI4 0
RETI4
ADDRGP4 $120
JUMPV
LABELV $121
ADDRLP4 0
INDIRP4
CNSTI4 832
ADDP4
INDIRI4
CNSTI4 0
EQI4 $123
ADDRLP4 0
INDIRP4
CNSTI4 832
ADDP4
INDIRI4
CNSTI4 0
GEI4 $125
ADDRLP4 0
INDIRP4
CNSTI4 832
ADDP4
CNSTI4 0
ASGNI4
LABELV $125
ADDRLP4 0
INDIRP4
CNSTI4 832
ADDP4
INDIRI4
CNSTI4 7
LEI4 $127
ADDRLP4 0
INDIRP4
CNSTI4 832
ADDP4
CNSTI4 7
ASGNI4
LABELV $127
ADDRFP4 4
INDIRP4
ARGP4
ADDRFP4 8
INDIRI4
ARGI4
ADDRGP4 $129
ARGP4
CNSTI4 94
ARGI4
ADDRLP4 0
INDIRP4
CNSTI4 832
ADDP4
INDIRI4
CNSTI4 48
ADDI4
ARGI4
ADDRLP4 0
INDIRP4
CNSTI4 644
ADDP4
INDIRP4
ARGP4
ADDRGP4 Com_sprintf
CALLV
pop
ADDRGP4 $124
JUMPV
LABELV $123
ADDRFP4 4
INDIRP4
ARGP4
ADDRFP4 8
INDIRI4
ARGI4
ADDRGP4 $130
ARGP4
ADDRLP4 0
INDIRP4
CNSTI4 644
ADDP4
INDIRP4
ARGP4
ADDRGP4 Com_sprintf
CALLV
pop
LABELV $124
CNSTI4 1
RETI4
LABELV $120
endproc Team_GetLocationMsg 12 24
proc SortClients 0 0
ADDRFP4 0
INDIRP4
INDIRI4
ADDRFP4 4
INDIRP4
INDIRI4
SUBI4
RETI4
LABELV $131
endproc SortClients 0 0
export TeamplayInfoMessage
proc TeamplayInfoMessage 9404 36
ADDRFP4 0
ADDRFP4 0
INDIRP4
ASGNP4
ADDRLP4 9368
CNSTI4 0
ASGNI4
ADDRFP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 648
ADDP4
INDIRI4
CNSTI4 0
NEI4 $133
ADDRGP4 $132
JUMPV
LABELV $133
ADDRLP4 9372
CNSTI4 0
ASGNI4
ADDRLP4 4
ADDRLP4 9372
INDIRI4
ASGNI4
ADDRLP4 8
ADDRLP4 9372
INDIRI4
ASGNI4
ADDRGP4 $138
JUMPV
LABELV $135
ADDRLP4 0
CNSTI4 1828
ADDRLP4 4
INDIRI4
CNSTI4 2
LSHI4
ADDRGP4 level+76
ADDP4
INDIRI4
MULI4
ADDRGP4 g_entities
ADDP4
ASGNP4
ADDRLP4 0
INDIRP4
CNSTI4 520
ADDP4
INDIRI4
CNSTI4 0
EQI4 $141
ADDRLP4 9380
CNSTI4 516
ASGNI4
ADDRLP4 9384
CNSTI4 936
ASGNI4
ADDRLP4 0
INDIRP4
ADDRLP4 9380
INDIRI4
ADDP4
INDIRP4
ADDRLP4 9384
INDIRI4
ADDP4
INDIRI4
ADDRFP4 0
INDIRP4
ADDRLP4 9380
INDIRI4
ADDP4
INDIRP4
ADDRLP4 9384
INDIRI4
ADDP4
INDIRI4
NEI4 $141
ADDRLP4 9388
ADDRLP4 8
INDIRI4
ASGNI4
ADDRLP4 8
ADDRLP4 9388
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
ADDRLP4 9392
CNSTI4 2
ASGNI4
ADDRLP4 9388
INDIRI4
ADDRLP4 9392
INDIRI4
LSHI4
ADDRLP4 9240
ADDP4
ADDRLP4 4
INDIRI4
ADDRLP4 9392
INDIRI4
LSHI4
ADDRGP4 level+76
ADDP4
INDIRI4
ASGNI4
LABELV $141
LABELV $136
ADDRLP4 4
ADDRLP4 4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $138
ADDRLP4 4
INDIRI4
ADDRGP4 g_maxclients+12
INDIRI4
GEI4 $144
ADDRLP4 8
INDIRI4
CNSTI4 32
LTI4 $135
LABELV $144
ADDRLP4 9240
ARGP4
ADDRLP4 8
INDIRI4
ARGI4
CNSTI4 4
ARGI4
ADDRGP4 SortClients
ARGP4
ADDRGP4 qsort
CALLV
pop
ADDRLP4 1048
CNSTI1 0
ASGNI1
ADDRLP4 9376
CNSTI4 0
ASGNI4
ADDRLP4 1040
ADDRLP4 9376
INDIRI4
ASGNI4
ADDRLP4 4
ADDRLP4 9376
INDIRI4
ASGNI4
ADDRLP4 8
ADDRLP4 9376
INDIRI4
ASGNI4
ADDRGP4 $148
JUMPV
LABELV $145
ADDRLP4 0
CNSTI4 1828
ADDRLP4 4
INDIRI4
MULI4
ADDRGP4 g_entities
ADDP4
ASGNP4
ADDRLP4 0
INDIRP4
CNSTI4 520
ADDP4
INDIRI4
CNSTI4 0
EQI4 $150
ADDRLP4 9384
CNSTI4 516
ASGNI4
ADDRLP4 9388
CNSTI4 936
ASGNI4
ADDRLP4 0
INDIRP4
ADDRLP4 9384
INDIRI4
ADDP4
INDIRP4
ADDRLP4 9388
INDIRI4
ADDP4
INDIRI4
ADDRFP4 0
INDIRP4
ADDRLP4 9384
INDIRI4
ADDP4
INDIRP4
ADDRLP4 9388
INDIRI4
ADDP4
INDIRI4
NEI4 $150
ADDRLP4 1036
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 184
ADDP4
INDIRI4
ASGNI4
ADDRLP4 1036
INDIRI4
CNSTI4 0
GEI4 $152
ADDRLP4 1036
CNSTI4 0
ASGNI4
LABELV $152
ADDRLP4 12
ARGP4
CNSTI4 1024
ARGI4
ADDRGP4 $154
ARGP4
ADDRLP4 4
INDIRI4
ARGI4
ADDRLP4 9396
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
ASGNP4
ADDRLP4 9396
INDIRP4
CNSTI4 600
ADDP4
INDIRI4
ARGI4
ADDRLP4 1036
INDIRI4
ARGI4
ADDRLP4 9368
INDIRI4
ARGI4
ADDRLP4 9396
INDIRP4
CNSTI4 144
ADDP4
INDIRI4
ARGI4
ADDRLP4 0
INDIRP4
CNSTI4 188
ADDP4
INDIRI4
ARGI4
ADDRGP4 Com_sprintf
CALLV
pop
ADDRLP4 12
ARGP4
ADDRLP4 9400
ADDRGP4 strlen
CALLI4
ASGNI4
ADDRLP4 1044
ADDRLP4 9400
INDIRI4
ASGNI4
ADDRLP4 1040
INDIRI4
ADDRLP4 1044
INDIRI4
ADDI4
CVIU4 4
CNSTU4 8192
LEU4 $155
ADDRGP4 $147
JUMPV
LABELV $155
ADDRLP4 1040
INDIRI4
ADDRLP4 1048
ADDP4
ARGP4
ADDRLP4 12
ARGP4
ADDRGP4 strcpy
CALLP4
pop
ADDRLP4 1040
ADDRLP4 1040
INDIRI4
ADDRLP4 1044
INDIRI4
ADDI4
ASGNI4
ADDRLP4 8
ADDRLP4 8
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $150
LABELV $146
ADDRLP4 4
ADDRLP4 4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $148
ADDRLP4 4
INDIRI4
ADDRGP4 g_maxclients+12
INDIRI4
GEI4 $157
ADDRLP4 8
INDIRI4
CNSTI4 32
LTI4 $145
LABELV $157
LABELV $147
ADDRGP4 $158
ARGP4
ADDRLP4 8
INDIRI4
ARGI4
ADDRLP4 1048
ARGP4
ADDRLP4 9380
ADDRGP4 va
CALLP4
ASGNP4
ADDRFP4 0
INDIRP4
CVPU4 4
ADDRGP4 g_entities
CVPU4 4
SUBU4
CVUI4 4
CNSTI4 1828
DIVI4
ARGI4
ADDRLP4 9380
INDIRP4
ARGP4
ADDRGP4 trap_SendServerCommand
CALLV
pop
LABELV $132
endproc TeamplayInfoMessage 9404 36
export CheckTeamStatus
proc CheckTeamStatus 24 8
ADDRGP4 level+28
INDIRI4
ADDRGP4 level+52
INDIRI4
SUBI4
CNSTI4 1000
LEI4 $160
ADDRGP4 level+52
ADDRGP4 level+28
INDIRI4
ASGNI4
ADDRLP4 4
CNSTI4 0
ASGNI4
ADDRGP4 $169
JUMPV
LABELV $166
ADDRLP4 0
CNSTI4 1828
ADDRLP4 4
INDIRI4
MULI4
ADDRGP4 g_entities
ADDP4
ASGNP4
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 508
ADDP4
INDIRI4
CNSTI4 2
EQI4 $171
ADDRGP4 $167
JUMPV
LABELV $171
ADDRLP4 0
INDIRP4
CNSTI4 520
ADDP4
INDIRI4
CNSTI4 0
EQI4 $173
ADDRLP4 16
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 216
ADDP4
INDIRI4
ASGNI4
ADDRLP4 16
INDIRI4
CNSTI4 2
EQI4 $175
ADDRLP4 16
INDIRI4
CNSTI4 1
NEI4 $173
LABELV $175
ADDRLP4 0
INDIRP4
ARGP4
ADDRLP4 20
ADDRGP4 Team_GetLocation
CALLP4
ASGNP4
ADDRLP4 8
ADDRLP4 20
INDIRP4
ASGNP4
ADDRLP4 8
INDIRP4
CVPU4 4
CNSTU4 0
EQU4 $176
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 600
ADDP4
ADDRLP4 8
INDIRP4
CNSTI4 796
ADDP4
INDIRI4
ASGNI4
ADDRGP4 $177
JUMPV
LABELV $176
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 600
ADDP4
CNSTI4 0
ASGNI4
LABELV $177
LABELV $173
LABELV $167
ADDRLP4 4
ADDRLP4 4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $169
ADDRLP4 4
INDIRI4
ADDRGP4 g_maxclients+12
INDIRI4
LTI4 $166
ADDRLP4 4
CNSTI4 0
ASGNI4
ADDRGP4 $181
JUMPV
LABELV $178
ADDRLP4 0
CNSTI4 1828
ADDRLP4 4
INDIRI4
MULI4
ADDRGP4 g_entities
ADDP4
ASGNP4
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 508
ADDP4
INDIRI4
CNSTI4 2
EQI4 $183
ADDRGP4 $179
JUMPV
LABELV $183
ADDRLP4 0
INDIRP4
CNSTI4 520
ADDP4
INDIRI4
CNSTI4 0
EQI4 $185
ADDRLP4 16
ADDRLP4 0
INDIRP4
CNSTI4 516
ADDP4
INDIRP4
CNSTI4 216
ADDP4
INDIRI4
ASGNI4
ADDRLP4 16
INDIRI4
CNSTI4 2
EQI4 $187
ADDRLP4 16
INDIRI4
CNSTI4 1
NEI4 $185
LABELV $187
ADDRLP4 0
INDIRP4
ARGP4
ADDRGP4 TeamplayInfoMessage
CALLV
pop
LABELV $185
LABELV $179
ADDRLP4 4
ADDRLP4 4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $181
ADDRLP4 4
INDIRI4
ADDRGP4 g_maxclients+12
INDIRI4
LTI4 $178
LABELV $160
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 g_teamImbalanceWarnings+12
INDIRI4
ADDRLP4 12
INDIRI4
EQI4 $188
ADDRGP4 level+11164
INDIRI4
ADDRLP4 12
INDIRI4
NEI4 $188
ADDRGP4 level+28
INDIRI4
ADDRGP4 level+16104
INDIRI4
SUBI4
CNSTI4 1000
ADDRGP4 g_teamImbalanceWarnings+12
INDIRI4
MULI4
LEI4 $188
ADDRGP4 level+16108
INDIRI4
CNSTI4 3
GEI4 $188
ADDRGP4 level+16104
ADDRGP4 level+28
INDIRI4
ASGNI4
ADDRGP4 level+11212
INDIRI4
CNSTI4 0
LEI4 $198
ADDRGP4 level+11224
INDIRI4
ADDRGP4 level+11220
INDIRI4
SUBI4
CNSTI4 2
LEI4 $198
CNSTI4 -1
ARGI4
ADDRGP4 $203
ARGP4
ADDRGP4 trap_SendServerCommand
CALLV
pop
ADDRLP4 16
ADDRGP4 level+16108
ASGNP4
ADDRLP4 16
INDIRP4
ADDRLP4 16
INDIRP4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
ADDRGP4 $199
JUMPV
LABELV $198
ADDRGP4 level+11216
INDIRI4
CNSTI4 0
LEI4 $205
ADDRGP4 level+11220
INDIRI4
ADDRGP4 level+11224
INDIRI4
SUBI4
CNSTI4 2
LEI4 $205
CNSTI4 -1
ARGI4
ADDRGP4 $210
ARGP4
ADDRGP4 trap_SendServerCommand
CALLV
pop
ADDRLP4 16
ADDRGP4 level+16108
ASGNP4
ADDRLP4 16
INDIRP4
ADDRLP4 16
INDIRP4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
ADDRGP4 $206
JUMPV
LABELV $205
ADDRGP4 level+16108
CNSTI4 0
ASGNI4
LABELV $206
LABELV $199
LABELV $188
LABELV $159
endproc CheckTeamStatus 24 8
import DrawNodes
import nodethink
import spawnnode
import trap_DemoCommand
import trap_SendGameStat
import trap_SnapVector
import trap_GetEntityToken
import trap_GetUsercmd
import trap_BotFreeClient
import trap_BotAllocateClient
import trap_EntityContact
import trap_EntitiesInBox
import trap_UnlinkEntity
import trap_LinkEntity
import trap_AreasConnected
import trap_AdjustAreaPortalState
import trap_InPVSIgnorePortals
import trap_InPVS
import trap_PointContents
import trap_Trace
import trap_SetBrushModel
import trap_GetServerinfo
import trap_SetUserinfo
import trap_GetUserinfo
import trap_GetConfigstring
import trap_SetConfigstring
import trap_SendServerCommand
import trap_DropClient
import trap_LocateGameData
import trap_Cvar_VariableStringBuffer
import trap_Cvar_VariableValue
import trap_Cvar_VariableIntegerValue
import trap_Cvar_Set
import trap_Cvar_Update
import trap_Cvar_Register
import trap_SendConsoleCommand
import trap_FS_Seek
import trap_FS_GetFileList
import trap_FS_FCloseFile
import trap_FS_Write
import trap_FS_Read
import trap_FS_FOpenFile
import trap_Args
import trap_Argv
import trap_Argc
import trap_RealTime
import trap_Milliseconds
import trap_Error
import trap_Printf
import g_allowBlackInNames
import g_teamStatusTime
import g_teamStatus
import g_bot_ping
import g_bot_dodge_crouch
import g_bot_dodge_jump
import g_bot_granger
import g_blaster_ammoregen
import g_weapswitchtime
import g_vampirebuildables_take
import g_vampirebuildables
import g_vampiremode
import g_connectedStripPrcnt
import g_strip_StructDmgPrcnt_def
import g_strip_StructDmgPrcnt
import g_strip_PlayerDmgPrcnt_def
import g_strip_PlayerDmgPrcnt
import g_lesson_BlockEqStr
import g_lesson
import g_ShowKillerHealth
import g_StructNoDmg
import g_StripEqChange_def
import g_StripEqChange
import IsStringListMember
import g_AutoStrip_NotInLesson
import g_AutoStrip_kpmTreshold
import g_AutoStrip_kpmAllowed
import g_AutoStrip_KillingSpreeStageDif
import g_AutoStrip_KillingSpreePerStage
import g_AutoStrip_KillingSpreeLvl
import g_AutoStrip_DebugMsg
import g_AutoStrip_BetterThanEnemy
import g_AutoStrip_BetterThanTeam
import g_AutoStrip_KillsPerStage
import g_AutoStrip_MinKills
import g_AutoStrip_MinKillToFeed
import g_AutoStrip
import g_ReservedNameMinLev
import g_ReservedNameMatch
import g_lesson_NoVotes
import g_DebugMsg
import g_pathediting
import g_bot_teamkill
import g_bot_wave_interval
import g_bot_survival
import g_bot_infinite_funds
import g_bot_roam
import g_bot_attackStruct
import g_bot_tyrant
import g_bot_advgoon
import g_bot_goon
import g_bot_advmara
import g_bot_mara
import g_bot_advbasi
import g_bot_basi
import g_bot_evolve
import g_bot_luci
import g_bot_flamer
import g_bot_pulse
import g_bot_chain
import g_bot_mass
import g_bot_las
import g_bot_shotgun
import g_bot_psaw
import g_bot_rifle
import g_bot_buy
import g_buildLogMaxLength
import g_msgTime
import g_msg
import g_mapvoteMaxTime
import g_voteMinTime
import g_devmapNoStructDmg
import g_devmapNoGod
import g_dretchPunt
import g_hiddenClients
import g_antiSpawnBlock
import g_myStats
import g_publicSayadmins
import g_decolourLogfiles
import g_privateMessages
import g_devmapKillerHP
import g_feedingSpree
import g_killingSpree
import g_adminLeaveMsg
import g_banNotice
import g_minLevelToSpecMM1
import g_forceAutoSelect
import g_minLevelToJoinTeam
import g_adminMapLog
import g_adminMaxBan
import g_adminTempBan
import g_adminNameProtect
import g_adminSayFilter
import g_adminParseSay
import g_adminLog
import g_admin
import g_layoutAuto
import g_layouts
import g_mapConfigs
import g_shove
import g_floodMinTime
import g_floodMaxDemerits
import g_actionPrefix
import g_chatTeamPrefix
import g_initialMapRotation
import g_nextMap
import g_currentMap
import g_currentMapRotation
import g_debugMapRotation
import g_deconDead
import g_markDeconstruct
import g_disabledBuildables
import g_disabledClasses
import g_disabledEquipment
import g_unlagged
import g_teamImbalanceWarnings
import g_alienStage3Threshold
import g_alienStage2Threshold
import g_alienMaxStage
import g_alienKills
import g_alienStage
import g_humanStage3Threshold
import g_humanStage2Threshold
import g_humanMaxStage
import g_humanKills
import g_humanStage
import g_alienBuildPoints
import g_humanBuildPoints
import g_singlePlayer
import g_enableBreath
import g_enableDust
import g_allowShare
import g_rankings
import pmove_msec
import pmove_fixed
import g_clientUpgradeNotice
import g_smoothClients
import g_filterBan
import g_banIPs
import g_teamForceBalance
import g_teamAutoJoin
import g_designateVotes
import g_mapVotesPercent
import g_suddenDeathVoteDelay
import g_suddenDeathVotePercent
import g_voteLimit
import g_requireVoteReasons
import g_allowVote
import g_blood
import g_doWarmup
import g_warmupMode
import g_warmup
import g_motd
import g_synchronousClients
import g_weaponTeamRespawn
import g_weaponRespawn
import g_debugDamage
import g_debugAlloc
import g_debugMove
import g_inactivity
import g_quadfactor
import g_knockback
import g_speed
import g_gravity
import g_needpass
import g_password
import g_friendlyBuildableFire
import g_friendlyFireMovementAttacks
import g_retribution
import g_friendlyFireAliens
import g_friendlyFireHumans
import g_friendlyFire
import g_suddenDeathMode
import g_suddenDeath
import g_suddenDeathTime
import g_timelimit
import g_newbieDenyBuild
import g_newbieNamePrefix
import g_newbieNumbering
import g_maxNameChanges
import g_minNameChangePeriod
import g_minCommandPeriod
import g_lockTeamsAtStart
import g_restarted
import g_maxGameClients
import g_maxclients
import g_cheats
import g_dedicated
import g_entities
import level
import G_FindConnectionForCode
import G_ResetPTRConnections
import G_GenerateNewConnection
import G_UpdatePTRConnection
import G_GetCurrentMap
import G_MapExists
import G_InitMapRotations
import G_MapRotationActive
import G_StopMapRotation
import G_StartMapRotation
import G_AdvanceMapRotation
import G_PrintRotations
import G_WriteSessionData
import G_InitSessionData
import G_ReadSessionData
import Svcmd_GameMem_f
import G_DefragmentMemory
import G_Free
import G_InitMemory
import G_Alloc
import G_RunClient
import ClientEndFrame
import ClientThink
import G_UnlaggedOff
import G_UnlaggedOn
import G_UnlaggedCalc
import G_UnlaggedClear
import G_UnlaggedStore
import ClientCommand
import ClientBegin
import ClientDisconnect
import ClientUserinfoChanged
import ClientConnect
import G_Flood_Limited
import CheckMsgTimer
import G_TimeTilSuddenDeath
import G_DemoCommand
import LogExit
import CheckTeamVote
import CheckVote
import G_Error
import G_Printf
import SendScoreboardMessageToAllClients
import G_AdminsPrintf
import G_LogOnlyPrintf
import G_LogPrintfColoured
import G_LogPrintf
import G_RunThink
import FindIntermissionPoint
import CalculateRanks
import G_MapConfigs
import MoveClientToIntermission
import ScoreboardMessage
import FireWeapon3
import FireWeapon2
import FireWeapon
import G_FilterPacket
import G_ProcessIPBans
import ConsoleCommand
import G_IsUnnamed
import G_NextNewbieName
import SpotWouldTelefrag
import player_die
import ClientSpawn
import BeginIntermission
import respawn
import SpawnCorpse
import G_SelectHumanLockSpawnPoint
import G_SelectAlienLockSpawnPoint
import G_SelectSpawnPoint
import G_SelectTremulousSpawnPoint
import G_SetClientViewAngle
import TeamCount
import G_AddCreditToClient
import G_UpdateZaps
import ChargeAttack
import CheckPounceAttack
import CheckGrabAttack
import CheckVenomAttack
import SnapVectorTowards
import CalcMuzzlePoint
import G_GiveClientMaxAmmo
import G_ForceWeaponChange
import ShineTorch
import TeleportPlayer
import G_Checktrigger_stages
import trigger_teleporter_touch
import manualTriggerSpectator
import Touch_DoorTrigger
import G_RunMover
import fire_mdriver
import launch_grenade
import fire_hive
import fire_bounceBall
import fire_slowBlob
import fire_paraLockBlob
import fire_lockblob
import fire_luciferCannon
import fire_pulseRifle
import fire_blaster
import fire_flamer
import G_RunMissile
import G_InitDamageLocations
import AddScore
import body_die
import G_SelectiveRadiusDamage
import G_RadiusDamage
import G_SelectiveDamage
import G_Damage
import CanDamage
import G_ClosestEnt
import G_Visible
import G_CloseMenus
import G_TriggerMenu
import G_ClientIsLagging
import BuildShaderStateConfig
import AddRemap
import G_SetOrigin
import G_BroadcastEvent
import G_AddEvent
import G_AddPredictableEvent
import vectoyaw
import vtos
import tv
import G_TouchSolids
import G_TouchTriggers
import G_EntitiesFree
import G_FreeEntity
import G_Sound
import G_TempEntity
import G_Spawn
import G_InitGentity
import G_SetMovedir
import G_UseTargets
import G_PickTarget
import G_Find
import G_KillBox
import G_TeamCommand
import G_SoundIndex
import G_ModelIndex
import G_ShaderIndex
import G_ParticleSystemIndex
import G_FindBuildLogName
import G_CountBuildLog
import G_LogBuild
import G_RevertCanFit
import G_CommitRevertedBuildable
import G_SpawnRevertedBuildable
import G_InstantBuild
import G_BaseSelfDestruct
import G_LayoutLoad
import G_LayoutSelect
import G_LayoutList
import G_LayoutSave
import G_CheckDBProtection
import FinishSpawningBuildable
import G_SpawnBuildable
import G_SetIdleBuildableAnim
import G_SetBuildableAnim
import G_BuildIfValid
import G_BuildingExists
import G_CanBuild
import G_BuildableRange
import G_BuildableThink
import G_IsOvermindBuilt
import G_IsDCCBuilt
import G_IsPowered
import G_CheckSpawnPoint
import AHovel_Blocked
import G_Physics
import OverrideNakedStage
import G_RoomForClassChange
import G_CP
import G_WordWrap
import Cmd_Builder_f
import Cmd_TeamVote_f
import Cmd_Donate_f
import Cmd_Share_f
import G_statsString
import G_PrivateMessage
import G_SanitiseString
import G_ChangeTeam
import G_LeaveTeam
import G_ParseEscapedString
import G_DecolorString
import G_SayConcatArgs
import G_SayArgv
import G_SayArgc
import G_Say
import G_ClientNumbersFromString
import G_MatchOnePlayer
import G_ToggleFollow
import G_FollowNewClient
import G_StopFollowing
import G_StopFromFollowing
import Cmd_Score_f
import G_BotIntermissionThink
import G_BotSpectatorThink
import G_BotThink
import G_BotCmd
import G_BotDel
import G_BotAdd
import G_NewString
import G_SpawnEntitiesFromString
import G_SpawnVector
import G_SpawnInt
import G_SpawnFloat
import G_SpawnString
import G_GetPosInSpawnQueue
import G_RemoveFromSpawnQueue
import G_PushSpawnQueue
import G_SearchSpawnQueue
import G_PeekSpawnQueue
import G_PopSpawnQueue
import G_GetSpawnQueueLength
import G_InitSpawnQueue
import G_admin_namelog_cleanup
import G_admin_cleanup
import G_admin_duration
import G_admin_buffer_end
import G_admin_buffer_begin
import G_admin_buffer_print
import G_admin_print
import G_admin_leave
import G_admin_cp
import G_admin_naked
import G_admin_designate
import G_admin_warn
import G_admin_putmespec
import G_admin_L1
import G_admin_L0
import G_admin_pause
import G_admin_revert
import G_admin_buildlog
import G_admin_info
import G_admin_unlock
import G_admin_lock
import G_admin_namelog
import G_admin_nextmap
import G_admin_restart
import G_admin_rename
import G_admin_register
import G_admin_spec999
import G_admin_passvote
import G_admin_cancelvote
import G_admin_allready
import G_admin_admintest
import G_admin_help
import G_admin_showbans
import G_admin_showlongstrips
import G_admin_checkname
import G_admin_denybuild
import G_admin_mute
import G_admin_layoutsave
import G_admin_maplog
import G_admin_maplog_update
import G_admin_devmap
import G_admin_map
import G_admin_listrotation
import G_admin_listmaps
import G_admin_listplayers
import G_admin_listlayouts
import G_admin_listadmins
import G_admin_putteam
import G_admin_unban
import G_admin_ban
import G_admin_unlongstrip
import G_admin_longstrip
import G_admin_subnetstrip
import G_admin_subnetban
import G_admin_adjustban
import G_admin_kick
import G_admin_loadlayout
import G_admin_loadrotation
import G_admin_setlevel
import G_admin_time
import G_drawnodes
import G_admin_botcfg
import G_admin_botset
import G_admin_botcmd
import G_admin_bot
import G_admin_adminPrintName
import G_admin_set_adminname
import G_admin_level
import G_admin_maplog_result
import G_admin_namelog_update
import G_admin_name_check
import G_admin_permission_guid
import G_admin_permission
import G_admin_readconfig
import G_admin_cmd_check
import G_admin_ban_check
import G_admin_longstrip_check
import BG_ClientListParse
import BG_ClientListString
import BG_ClientListRemove
import BG_ClientListAdd
import BG_ClientListTest
import BG_UpgradeClassAvailable
import BG_BuildableIsAllowed
import BG_ClassIsAllowed
import BG_UpgradeIsAllowed
import BG_WeaponIsAllowed
import BG_InitAllowedGameElements
import BG_ParseCSVBuildableList
import BG_ParseCSVClassList
import BG_ParseCSVEquipmentList
import atoi_neg
import atof_neg
import BG_PlayerTouchesItem
import BG_PlayerStateToEntityStateExtraPolate
import BG_PlayerStateToEntityState
import BG_AddPredictableEventToPlayerstate
import BG_EvaluateTrajectoryDelta
import BG_EvaluateTrajectory
import BG_FindTeamForUpgrade
import BG_FindUsableForUpgrade
import BG_FindPurchasableForUpgrade
import BG_FindIconForUpgrade
import BG_FindHumanNameForUpgrade
import BG_FindUpgradeNumForName
import BG_FindNameForUpgrade
import BG_FindSlotsForUpgrade
import BG_FindNakedStagesForUpgrade
import BG_FindStagesForUpgrade
import BG_FindPriceForUpgrade
import BG_FindTeamForWeapon
import BG_FindBuildDelayForWeapon
import BG_FindLongRangedForWeapon
import BG_FindPurchasableForWeapon
import BG_FindZoomFovForWeapon
import BG_WeaponCanZoom
import BG_WeaponHasThirdMode
import BG_WeaponHasAltMode
import BG_FindKnockbackScaleForWeapon
import BG_FindReloadTimeForWeapon
import BG_FindRepeatRate3ForWeapon
import BG_FindRepeatRate2ForWeapon
import BG_FindRepeatRate1ForWeapon
import BG_FindUsesEnergyForWeapon
import BG_FindInfinteAmmoForWeapon
import BG_FindAmmoForWeapon
import BG_FindCrosshairSizeForWeapon
import BG_FindCrosshairForWeapon
import BG_FindIconForWeapon
import BG_FindModelsForWeapon
import BG_FindHumanNameForWeapon
import BG_FindWeaponNumForName
import BG_FindNameForWeapon
import BG_FindSlotsForWeapon
import BG_FindNakedStagesForWeapon
import BG_FindStagesForWeapon
import BG_FindPriceForWeapon
import BG_InitClassOverrides
import BG_FindValueOfClass
import BG_FindCostOfClass
import BG_ClassCanEvolveFromTo
import BG_FindBuildDistForClass
import BG_FindStartWeaponForClass
import BG_ClassHasAbility
import BG_FindSteptimeForClass
import BG_FindKnockbackScaleForClass
import BG_FindJumpMagnitudeForClass
import BG_FindStopSpeedForClass
import BG_FindFrictionForClass
import BG_FindAirAccelerationForClass
import BG_FindAccelerationForClass
import BG_FindSpeedForClass
import BG_FindBobCycleForClass
import BG_FindBobForClass
import BG_FindFovForClass
import BG_FindRegenRateForClass
import BG_FindFallDamageForClass
import BG_FindHealthForClass
import BG_FindViewheightForClass
import BG_FindZOffsetForClass
import BG_FindBBoxForClass
import BG_FindNakedStagesForClass
import BG_FindStagesForClass
import BG_FindHudNameForClass
import BG_FindShadowScaleForClass
import BG_FindSkinNameForClass
import BG_FindModelScaleForClass
import BG_FindModelNameForClass
import BG_FindHumanNameForClassNum
import BG_FindNameForClassNum
import BG_FindClassNumForName
import BG_InitBuildableOverrides
import BG_FindTransparentTestForBuildable
import BG_FindReplaceableTestForBuildable
import BG_FindUniqueTestForBuildable
import BG_FindDCCTestForBuildable
import BG_FindCreepSizeForBuildable
import BG_FindCreepTestForBuildable
import BG_FindInvertNormalForBuildable
import BG_FindMinNormalForBuildable
import BG_FindProjTypeForBuildable
import BG_FindFireSpeedForBuildable
import BG_FindRangeForBuildable
import BG_FindUsableForBuildable
import BG_FindBuildTimeForBuildable
import BG_FindNextThinkForBuildable
import BG_FindAnimForBuildable
import BG_FindBuildWeaponForBuildable
import BG_FindTeamForBuildable
import BG_FindMODForBuildable
import BG_FindSplashRadiusForBuildable
import BG_FindSplashDamageForBuildable
import BG_FindStagesForBuildable
import BG_FindBuildPointsForBuildable
import BG_FindBounceForBuildable
import BG_FindTrajectoryForBuildable
import BG_FindRegenRateForBuildable
import BG_FindHealthForBuildable
import BG_FindZOffsetForBuildable
import BG_FindBBoxForBuildable
import BG_FindModelScaleForBuildable
import BG_FindModelsForBuildable
import BG_FindEntityNameForBuildable
import BG_FindHumanNameForBuildable
import BG_FindNameForBuildable
import BG_FindBuildNumForEntityName
import BG_FindBuildNumForName
import BG_GetValueOfEquipment
import BG_GetValueOfHuman
import BG_PositionBuildableRelativeToPlayer
import BG_RotateAxis
import BG_UpgradeIsActive
import BG_DeactivateUpgrade
import BG_ActivateUpgrade
import BG_InventoryContainsUpgrade
import BG_RemoveUpgradeFromInventory
import BG_AddUpgradeToInventory
import BG_InventoryContainsWeapon
import BG_RemoveWeaponFromInventory
import BG_AddWeaponToInventory
import BG_FindPercentAmmo
import BG_WeaponIsEmpty
import BG_WeaponIsFull
import BG_PackAmmoArray
import BG_UnpackAmmoArray
import Pmove
import PM_UpdateViewAngles
import Com_Printf
import Com_Error
import Info_NextPair
import Info_Validate
import Info_SetValueForKey_Big
import Info_SetValueForKey
import Info_RemoveKey_big
import Info_RemoveKey
import Info_ValueForKey
import Com_TruncateLongString
import va
import Q_CleanStr
import Q_PrintStrlen
import Q_strcat
import Q_strncpyz
import Q_strrchr
import Q_strupr
import Q_strlwr
import Q_stricmpn
import Q_strncmp
import Q_stricmp
import Q_isdigit
import Q_isalpha
import Q_isupper
import Q_islower
import Q_isprint
import Com_RandomBytes
import Com_SkipCharset
import Com_SkipTokens
import Com_sprintf
import Parse3DMatrix
import Parse2DMatrix
import Parse1DMatrix
import SkipRestOfLine
import SkipBracedSection
import COM_MatchToken
import COM_ParseWarning
import COM_ParseError
import COM_Compress
import COM_ParseExt
import COM_Parse
import COM_GetCurrentParseLine
import COM_BeginParseSession
import COM_DefaultExtension
import COM_StripExtension
import COM_SkipPath
import Com_Clamp
import DistanceBetweenLineSegments
import DistanceBetweenLineSegmentsSquared
import VectorMaxComponent
import VectorMinComponent
import pointToLineDistance
import VectorDistance
import ProjectPointOntoVector
import GetPerpendicularViewVector
import Q_isnan
import PerpendicularVector
import AngleVectors
import VectorMatrixMultiply
import MatrixMultiply
import MakeNormalVectors
import RotateAroundDirection
import RotatePointAroundVector
import ProjectPointOnPlane
import PlaneFromPoints
import AngleDelta
import AngleNormalize180
import AngleNormalize360
import AnglesSubtract
import AngleSubtract
import LerpAngle
import AngleMod
import BoxOnPlaneSide
import SetPlaneSignbits
import AxisCopy
import AxisClear
import AxisToAngles
import AnglesToAxis
import vectoangles
import Q_crandom
import Q_random
import Q_rand
import Q_acos
import Q_log2
import VectorRotate
import Vector4Scale
import VectorNormalize2
import VectorNormalize
import CrossProduct
import VectorInverse
import VectorNormalizeFast
import DistanceSquared
import Distance
import VectorLengthSquared
import VectorLength
import VectorCompare
import AddPointToBounds
import ClearBounds
import RadiusFromBounds
import NormalizeColor
import ColorBytes4
import ColorBytes3
import _VectorMA
import _VectorScale
import _VectorCopy
import _VectorAdd
import _VectorSubtract
import _DotProduct
import ByteToDir
import DirToByte
import ClampShort
import ClampChar
import Q_rsqrt
import Q_fabs
import axisDefault
import vec3_origin
import g_color_table
import colorDkGrey
import colorMdGrey
import colorLtGrey
import colorWhite
import colorCyan
import colorMagenta
import colorYellow
import colorBlue
import colorGreen
import colorRed
import colorBlack
import bytedirs
import Hunk_Alloc
import FloatSwap
import LongSwap
import ShortSwap
import rint
import pow
import acos
import fabs
import abs
import tan
import atan2
import cos
import sin
import sqrt
import floor
import ceil
import memcpy
import memset
import memmove
import sscanf
import vsprintf
import _atoi
import atoi
import _atof
import atof
import toupper
import tolower
import strncpy
import strstr
import strrchr
import strchr
import strcmp
import strcpy
import strcat
import strlen
import rand
import srand
import qsort
lit
align 1
LABELV $210
byte 1 112
byte 1 114
byte 1 105
byte 1 110
byte 1 116
byte 1 32
byte 1 34
byte 1 84
byte 1 101
byte 1 97
byte 1 109
byte 1 115
byte 1 32
byte 1 97
byte 1 114
byte 1 101
byte 1 32
byte 1 117
byte 1 110
byte 1 98
byte 1 97
byte 1 108
byte 1 97
byte 1 110
byte 1 99
byte 1 101
byte 1 100
byte 1 46
byte 1 32
byte 1 65
byte 1 108
byte 1 105
byte 1 101
byte 1 110
byte 1 115
byte 1 32
byte 1 104
byte 1 97
byte 1 118
byte 1 101
byte 1 32
byte 1 109
byte 1 111
byte 1 114
byte 1 101
byte 1 32
byte 1 112
byte 1 108
byte 1 97
byte 1 121
byte 1 101
byte 1 114
byte 1 115
byte 1 46
byte 1 10
byte 1 32
byte 1 65
byte 1 108
byte 1 105
byte 1 101
byte 1 110
byte 1 115
byte 1 32
byte 1 119
byte 1 105
byte 1 108
byte 1 108
byte 1 32
byte 1 107
byte 1 101
byte 1 101
byte 1 112
byte 1 32
byte 1 116
byte 1 104
byte 1 101
byte 1 105
byte 1 114
byte 1 32
byte 1 112
byte 1 111
byte 1 105
byte 1 110
byte 1 116
byte 1 115
byte 1 32
byte 1 119
byte 1 104
byte 1 101
byte 1 110
byte 1 32
byte 1 115
byte 1 119
byte 1 105
byte 1 116
byte 1 99
byte 1 104
byte 1 105
byte 1 110
byte 1 103
byte 1 32
byte 1 116
byte 1 101
byte 1 97
byte 1 109
byte 1 115
byte 1 46
byte 1 10
byte 1 34
byte 1 0
align 1
LABELV $203
byte 1 112
byte 1 114
byte 1 105
byte 1 110
byte 1 116
byte 1 32
byte 1 34
byte 1 84
byte 1 101
byte 1 97
byte 1 109
byte 1 115
byte 1 32
byte 1 97
byte 1 114
byte 1 101
byte 1 32
byte 1 117
byte 1 110
byte 1 98
byte 1 97
byte 1 108
byte 1 97
byte 1 110
byte 1 99
byte 1 101
byte 1 100
byte 1 46
byte 1 32
byte 1 72
byte 1 117
byte 1 109
byte 1 97
byte 1 110
byte 1 115
byte 1 32
byte 1 104
byte 1 97
byte 1 118
byte 1 101
byte 1 32
byte 1 109
byte 1 111
byte 1 114
byte 1 101
byte 1 32
byte 1 112
byte 1 108
byte 1 97
byte 1 121
byte 1 101
byte 1 114
byte 1 115
byte 1 46
byte 1 10
byte 1 32
byte 1 72
byte 1 117
byte 1 109
byte 1 97
byte 1 110
byte 1 115
byte 1 32
byte 1 119
byte 1 105
byte 1 108
byte 1 108
byte 1 32
byte 1 107
byte 1 101
byte 1 101
byte 1 112
byte 1 32
byte 1 116
byte 1 104
byte 1 101
byte 1 105
byte 1 114
byte 1 32
byte 1 112
byte 1 111
byte 1 105
byte 1 110
byte 1 116
byte 1 115
byte 1 32
byte 1 119
byte 1 104
byte 1 101
byte 1 110
byte 1 32
byte 1 115
byte 1 119
byte 1 105
byte 1 116
byte 1 99
byte 1 104
byte 1 105
byte 1 110
byte 1 103
byte 1 32
byte 1 116
byte 1 101
byte 1 97
byte 1 109
byte 1 115
byte 1 46
byte 1 10
byte 1 34
byte 1 0
align 1
LABELV $158
byte 1 116
byte 1 105
byte 1 110
byte 1 102
byte 1 111
byte 1 32
byte 1 37
byte 1 105
byte 1 32
byte 1 37
byte 1 115
byte 1 0
align 1
LABELV $154
byte 1 32
byte 1 37
byte 1 105
byte 1 32
byte 1 37
byte 1 105
byte 1 32
byte 1 37
byte 1 105
byte 1 32
byte 1 37
byte 1 105
byte 1 32
byte 1 37
byte 1 105
byte 1 32
byte 1 37
byte 1 105
byte 1 0
align 1
LABELV $130
byte 1 37
byte 1 115
byte 1 0
align 1
LABELV $129
byte 1 37
byte 1 99
byte 1 37
byte 1 99
byte 1 37
byte 1 115
byte 1 94
byte 1 55
byte 1 0
align 1
LABELV $97
byte 1 112
byte 1 114
byte 1 105
byte 1 110
byte 1 116
byte 1 32
byte 1 34
byte 1 37
byte 1 115
byte 1 34
byte 1 0
align 1
LABELV $92
byte 1 80
byte 1 114
byte 1 105
byte 1 110
byte 1 116
byte 1 77
byte 1 115
byte 1 103
byte 1 32
byte 1 111
byte 1 118
byte 1 101
byte 1 114
byte 1 114
byte 1 117
byte 1 110
byte 1 0
