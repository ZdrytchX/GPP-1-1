export CG_UpdateEntityPositions
code
proc CG_UpdateEntityPositions 16 0
ADDRLP4 0
CNSTP4 0
ASGNP4
ADDRGP4 cg+107636+184+32
INDIRI4
CNSTI4 2
NEI4 $100
ADDRGP4 entityPositions+30224
INDIRI4
CNSTI4 700
ADDI4
ADDRGP4 cg+107604
INDIRI4
LEI4 $105
ADDRGP4 $99
JUMPV
LABELV $105
LABELV $100
ADDRGP4 entityPositions+30228
ADDRGP4 cg+110060+24
INDIRB
ASGNB 12
ADDRGP4 entityPositions+30240
ADDRGP4 cg+110428
INDIRB
ASGNB 12
ADDRGP4 entityPositions+30224
ADDRGP4 cg+107604
INDIRI4
ASGNI4
ADDRGP4 entityPositions+16384
CNSTI4 0
ASGNI4
ADDRGP4 entityPositions+28676
CNSTI4 0
ASGNI4
ADDRGP4 entityPositions+29448
CNSTI4 0
ASGNI4
ADDRGP4 entityPositions+30220
CNSTI4 0
ASGNI4
ADDRLP4 4
CNSTI4 0
ASGNI4
ADDRGP4 $123
JUMPV
LABELV $120
ADDRLP4 0
CNSTI4 1740
CNSTI4 208
ADDRLP4 4
INDIRI4
MULI4
ADDRGP4 cg+36
INDIRP4
CNSTI4 516
ADDP4
ADDP4
INDIRI4
MULI4
ADDRGP4 cg_entities
ADDP4
ASGNP4
ADDRLP4 0
INDIRP4
CNSTI4 4
ADDP4
INDIRI4
CNSTI4 3
NEI4 $126
ADDRLP4 0
INDIRP4
CNSTI4 164
ADDP4
INDIRI4
CNSTI4 1
NEI4 $128
CNSTI4 12
ADDRGP4 entityPositions+16384
INDIRI4
MULI4
ADDRGP4 entityPositions
ADDP4
ADDRLP4 0
INDIRP4
CNSTI4 1556
ADDP4
INDIRB
ASGNB 12
ADDRGP4 entityPositions+16384
INDIRI4
CNSTI4 2
LSHI4
ADDRGP4 entityPositions+12288
ADDP4
ADDRLP4 0
INDIRP4
CNSTI4 452
ADDP4
INDIRI4
ASGNI4
ADDRGP4 entityPositions+16384
INDIRI4
CNSTI4 1024
GEI4 $127
ADDRLP4 8
ADDRGP4 entityPositions+16384
ASGNP4
ADDRLP4 8
INDIRP4
ADDRLP4 8
INDIRP4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
ADDRGP4 $127
JUMPV
LABELV $128
ADDRLP4 0
INDIRP4
CNSTI4 164
ADDP4
INDIRI4
CNSTI4 2
NEI4 $127
CNSTI4 12
ADDRGP4 entityPositions+28676
INDIRI4
MULI4
ADDRGP4 entityPositions+16388
ADDP4
ADDRLP4 0
INDIRP4
CNSTI4 1556
ADDP4
INDIRB
ASGNB 12
ADDRGP4 entityPositions+28676
INDIRI4
CNSTI4 1024
GEI4 $127
ADDRLP4 8
ADDRGP4 entityPositions+28676
ASGNP4
ADDRLP4 8
INDIRP4
ADDRLP4 8
INDIRP4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
ADDRGP4 $127
JUMPV
LABELV $126
ADDRLP4 0
INDIRP4
CNSTI4 4
ADDP4
INDIRI4
CNSTI4 1
NEI4 $145
ADDRLP4 8
ADDRLP4 0
INDIRP4
CNSTI4 188
ADDP4
INDIRI4
CNSTI4 255
BANDI4
ASGNI4
ADDRLP4 8
INDIRI4
CNSTI4 1
NEI4 $147
CNSTI4 12
ADDRGP4 entityPositions+29448
INDIRI4
MULI4
ADDRGP4 entityPositions+28680
ADDP4
ADDRLP4 0
INDIRP4
CNSTI4 1556
ADDP4
INDIRB
ASGNB 12
ADDRGP4 entityPositions+29448
INDIRI4
CNSTI4 64
GEI4 $148
ADDRLP4 12
ADDRGP4 entityPositions+29448
ASGNP4
ADDRLP4 12
INDIRP4
ADDRLP4 12
INDIRP4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
ADDRGP4 $148
JUMPV
LABELV $147
ADDRLP4 8
INDIRI4
CNSTI4 2
NEI4 $155
CNSTI4 12
ADDRGP4 entityPositions+30220
INDIRI4
MULI4
ADDRGP4 entityPositions+29452
ADDP4
ADDRLP4 0
INDIRP4
CNSTI4 1556
ADDP4
INDIRB
ASGNB 12
ADDRGP4 entityPositions+30220
INDIRI4
CNSTI4 64
GEI4 $159
ADDRLP4 12
ADDRGP4 entityPositions+30220
ASGNP4
ADDRLP4 12
INDIRP4
ADDRLP4 12
INDIRP4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $159
LABELV $155
LABELV $148
LABELV $145
LABELV $127
LABELV $121
ADDRLP4 4
ADDRLP4 4
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $123
ADDRLP4 4
INDIRI4
ADDRGP4 cg+36
INDIRP4
CNSTI4 512
ADDP4
INDIRI4
LTI4 $120
LABELV $99
endproc CG_UpdateEntityPositions 16 0
lit
align 4
LABELV $164
byte 4 0
byte 4 0
byte 4 1065353216
code
proc CG_DrawBlips 96 20
ADDRFP4 0
ADDRFP4 0
INDIRP4
ASGNP4
ADDRFP4 8
ADDRFP4 8
INDIRP4
ASGNP4
ADDRLP4 32
ADDRGP4 $164
INDIRB
ASGNB 12
ADDRLP4 28
CNSTF4 1065353216
ASGNF4
ADDRLP4 44
CNSTF4 1065353216
ADDRGP4 cg+107604
INDIRI4
ADDRGP4 entityPositions+30224
INDIRI4
SUBI4
CVIF4 4
CNSTF4 1143930880
DIVF4
SUBF4
ASGNF4
ADDRLP4 12
ADDRFP4 8
INDIRP4
INDIRF4
ASGNF4
ADDRLP4 12+4
ADDRFP4 8
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ASGNF4
ADDRLP4 12+8
ADDRFP4 8
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ASGNF4
ADDRLP4 12+12
ADDRFP4 8
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 32
ARGP4
ADDRFP4 4
INDIRP4
ARGP4
ADDRGP4 entityPositions+30240+4
INDIRF4
NEGF4
CNSTF4 1119092736
SUBF4
ARGF4
ADDRGP4 RotatePointAroundVector
CALLV
pop
ADDRLP4 52
CNSTF4 1157234688
ASGNF4
ADDRLP4 0
ADDRLP4 0
INDIRF4
ADDRLP4 52
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
DIVF4
DIVF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 0+4
INDIRF4
ADDRLP4 52
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
DIVF4
DIVF4
ASGNF4
ADDRLP4 0+8
ADDRLP4 0+8
INDIRF4
CNSTF4 1157234688
ADDRFP4 0
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
DIVF4
DIVF4
ASGNF4
ADDRLP4 60
ADDRFP4 0
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ASGNF4
ADDRLP4 28
CNSTF4 1053609165
ADDRLP4 0+4
INDIRF4
ADDRLP4 60
INDIRF4
CNSTF4 1073741824
DIVF4
ADDF4
ADDRLP4 60
INDIRF4
DIVF4
MULF4
CNSTF4 1061997773
ADDF4
ASGNF4
ADDRLP4 12+12
ADDRLP4 12+12
INDIRF4
ADDRLP4 28
INDIRF4
MULF4
ASGNF4
ADDRLP4 64
CNSTF4 1056964608
ASGNF4
ADDRLP4 12+12
ADDRLP4 12+12
INDIRF4
ADDRLP4 64
INDIRF4
ADDRLP4 44
INDIRF4
MULF4
ADDRLP4 64
INDIRF4
ADDF4
MULF4
ASGNF4
ADDRLP4 12+12
INDIRF4
CNSTF4 1065353216
LEF4 $177
ADDRLP4 12+12
CNSTF4 1065353216
ASGNF4
ADDRGP4 $178
JUMPV
LABELV $177
ADDRLP4 12+12
INDIRF4
CNSTF4 0
GEF4 $181
ADDRLP4 12+12
CNSTF4 0
ASGNF4
LABELV $181
LABELV $178
ADDRLP4 12
ARGP4
ADDRGP4 trap_R_SetColor
CALLV
pop
ADDRLP4 0+8
INDIRF4
CNSTF4 0
LEF4 $185
ADDRLP4 72
CNSTF4 1073741824
ASGNF4
ADDRFP4 0
INDIRP4
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ADDRLP4 72
INDIRF4
DIVF4
ADDF4
CNSTF4 1065353216
SUBF4
ADDRLP4 0
INDIRF4
SUBF4
ARGF4
ADDRFP4 0
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ADDRLP4 72
INDIRF4
DIVF4
ADDF4
ADDRLP4 0+4
INDIRF4
ADDF4
ADDRLP4 0+8
INDIRF4
SUBF4
ARGF4
ADDRLP4 72
INDIRF4
ARGF4
ADDRLP4 0+8
INDIRF4
ARGF4
ADDRGP4 cgs+257288+160
INDIRI4
ARGI4
ADDRGP4 CG_DrawPic
CALLV
pop
ADDRGP4 $186
JUMPV
LABELV $185
ADDRLP4 80
CNSTF4 1073741824
ASGNF4
ADDRFP4 0
INDIRP4
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ADDRLP4 80
INDIRF4
DIVF4
ADDF4
CNSTF4 1065353216
SUBF4
ADDRLP4 0
INDIRF4
SUBF4
ARGF4
ADDRFP4 0
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ADDRLP4 80
INDIRF4
DIVF4
ADDF4
ADDRLP4 0+4
INDIRF4
ADDF4
ARGF4
ADDRLP4 80
INDIRF4
ARGF4
ADDRLP4 0+8
INDIRF4
NEGF4
ARGF4
ADDRGP4 cgs+257288+160
INDIRI4
ARGI4
ADDRGP4 CG_DrawPic
CALLV
pop
LABELV $186
ADDRLP4 88
CNSTF4 1073741824
ASGNF4
ADDRLP4 92
CNSTF4 1090519040
ASGNF4
ADDRFP4 0
INDIRP4
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ADDRLP4 88
INDIRF4
DIVF4
ADDF4
ADDRLP4 92
INDIRF4
SUBF4
ADDRLP4 0
INDIRF4
SUBF4
ARGF4
ADDRFP4 0
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ADDRFP4 0
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ADDRLP4 88
INDIRF4
DIVF4
ADDF4
CNSTF4 1082130432
SUBF4
ADDRLP4 0+4
INDIRF4
ADDF4
ADDRLP4 0+8
INDIRF4
SUBF4
ARGF4
CNSTF4 1098907648
ARGF4
ADDRLP4 92
INDIRF4
ARGF4
ADDRGP4 cgs+257288+156
INDIRI4
ARGI4
ADDRGP4 CG_DrawPic
CALLV
pop
CNSTP4 0
ARGP4
ADDRGP4 trap_R_SetColor
CALLV
pop
LABELV $163
endproc CG_DrawBlips 96 20
lit
align 4
LABELV $202
byte 4 0
byte 4 0
byte 4 1065353216
align 4
LABELV $203
byte 4 0
byte 4 3212836864
byte 4 0
code
proc CG_DrawDir 156 20
ADDRFP4 0
ADDRFP4 0
INDIRP4
ASGNP4
ADDRLP4 92
ADDRGP4 $202
INDIRB
ASGNB 12
ADDRLP4 104
ADDRGP4 $203
INDIRB
ASGNB 12
ADDRLP4 76
ADDRGP4 cg+36
INDIRP4
CNSTI4 44
ADDP4
ASGNP4
ADDRLP4 76
INDIRP4
CNSTI4 224
ADDP4
INDIRI4
CNSTI4 1
BANDI4
CNSTI4 0
EQI4 $205
ADDRLP4 76
INDIRP4
CNSTI4 224
ADDP4
INDIRI4
CNSTI4 2
BANDI4
CNSTI4 0
EQI4 $207
ADDRLP4 116
CNSTF4 0
ASGNF4
ADDRLP4 0
ADDRLP4 116
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 116
INDIRF4
ASGNF4
ADDRLP4 0+8
CNSTF4 3212836864
ASGNF4
ADDRGP4 $206
JUMPV
LABELV $207
ADDRLP4 0
ADDRLP4 76
INDIRP4
CNSTI4 92
ADDP4
INDIRB
ASGNB 12
ADDRGP4 $206
JUMPV
LABELV $205
ADDRLP4 116
CNSTF4 0
ASGNF4
ADDRLP4 0
ADDRLP4 116
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 116
INDIRF4
ASGNF4
ADDRLP4 0+8
CNSTF4 1065353216
ASGNF4
LABELV $206
ADDRGP4 entityPositions+30240
ARGP4
ADDRLP4 80
ARGP4
ADDRLP4 120
CNSTP4 0
ASGNP4
ADDRLP4 120
INDIRP4
ARGP4
ADDRLP4 120
INDIRP4
ARGP4
ADDRGP4 AngleVectors
CALLV
pop
ADDRLP4 12
ARGP4
ADDRFP4 4
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRGP4 ProjectPointOnPlane
CALLV
pop
ADDRLP4 24
ARGP4
ADDRLP4 80
ARGP4
ADDRLP4 0
ARGP4
ADDRGP4 ProjectPointOnPlane
CALLV
pop
ADDRLP4 12
ARGP4
ADDRGP4 VectorNormalize
CALLF4
pop
ADDRLP4 24
ARGP4
ADDRGP4 VectorNormalize
CALLF4
pop
ADDRLP4 12
INDIRF4
ADDRLP4 24
INDIRF4
MULF4
ADDRLP4 12+4
INDIRF4
ADDRLP4 24+4
INDIRF4
MULF4
ADDF4
ADDRLP4 12+8
INDIRF4
ADDRLP4 24+8
INDIRF4
MULF4
ADDF4
ARGF4
ADDRLP4 124
ADDRGP4 acos
CALLF4
ASGNF4
ADDRLP4 72
CNSTF4 1127481344
ADDRLP4 124
INDIRF4
MULF4
CNSTF4 1078530011
DIVF4
ASGNF4
ADDRLP4 12
ARGP4
ADDRLP4 24
ARGP4
ADDRLP4 36
ARGP4
ADDRGP4 CrossProduct
CALLV
pop
ADDRLP4 36
ARGP4
ADDRGP4 VectorNormalize
CALLF4
pop
ADDRLP4 48
ADDRLP4 0
INDIRF4
ADDRLP4 36
INDIRF4
SUBF4
ASGNF4
ADDRLP4 48+4
ADDRLP4 0+4
INDIRF4
ADDRLP4 36+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 48+8
ADDRLP4 0+8
INDIRF4
ADDRLP4 36+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 48
ARGP4
ADDRLP4 128
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 128
INDIRF4
CNSTF4 1065353216
GEF4 $224
ADDRLP4 72
CNSTF4 1135869952
ADDRLP4 72
INDIRF4
SUBF4
ASGNF4
LABELV $224
ADDRLP4 60
ARGP4
ADDRLP4 92
ARGP4
ADDRLP4 104
ARGP4
ADDRLP4 72
INDIRF4
ARGF4
ADDRGP4 RotatePointAroundVector
CALLV
pop
ADDRFP4 8
INDIRP4
ARGP4
ADDRGP4 trap_R_SetColor
CALLV
pop
ADDRLP4 136
CNSTF4 1073741824
ASGNF4
ADDRLP4 140
ADDRFP4 0
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ADDRLP4 136
INDIRF4
DIVF4
ASGNF4
ADDRLP4 144
CNSTF4 1094713344
ASGNF4
ADDRFP4 0
INDIRP4
INDIRF4
ADDRLP4 140
INDIRF4
ADDF4
ADDRLP4 144
INDIRF4
SUBF4
ADDRLP4 60
INDIRF4
ADDRLP4 140
INDIRF4
MULF4
SUBF4
ARGF4
ADDRLP4 148
ADDRFP4 0
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ADDRLP4 136
INDIRF4
DIVF4
ASGNF4
ADDRFP4 0
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ADDRLP4 148
INDIRF4
ADDF4
ADDRLP4 144
INDIRF4
SUBF4
ADDRLP4 60+4
INDIRF4
ADDRLP4 148
INDIRF4
MULF4
ADDF4
ARGF4
ADDRLP4 152
CNSTF4 1103101952
ASGNF4
ADDRLP4 152
INDIRF4
ARGF4
ADDRLP4 152
INDIRF4
ARGF4
ADDRGP4 cgs+257288+156
INDIRI4
ARGI4
ADDRGP4 CG_DrawPic
CALLV
pop
CNSTP4 0
ARGP4
ADDRGP4 trap_R_SetColor
CALLV
pop
LABELV $201
endproc CG_DrawDir 156 20
lit
align 4
LABELV $230
byte 4 1065353216
byte 4 0
byte 4 0
byte 4 1060320051
align 4
LABELV $231
byte 4 0
byte 4 0
byte 4 1065353216
byte 4 1060320051
align 4
LABELV $232
byte 4 0
byte 4 1065353216
byte 4 0
byte 4 1060320051
align 4
LABELV $233
byte 4 1065353216
byte 4 1065353216
byte 4 0
byte 4 1060320051
export CG_AlienSense
code
proc CG_AlienSense 104 12
ADDRFP4 0
ADDRFP4 0
INDIRP4
ASGNP4
ADDRLP4 28
ADDRGP4 $230
INDIRB
ASGNB 16
ADDRLP4 44
ADDRGP4 $231
INDIRB
ASGNB 16
ADDRLP4 60
ADDRGP4 $232
INDIRB
ASGNB 16
ADDRLP4 76
ADDRGP4 $233
INDIRB
ASGNB 16
ADDRLP4 16
ADDRGP4 entityPositions+30228
INDIRB
ASGNB 12
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $238
JUMPV
LABELV $235
ADDRLP4 92
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 96
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions+16388
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions+16388+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+16388+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 100
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 100
INDIRF4
CNSTF4 1148846080
GEF4 $251
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 28
ARGP4
ADDRGP4 CG_DrawDir
CALLV
pop
LABELV $251
LABELV $236
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $238
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+28676
INDIRI4
LTI4 $235
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $256
JUMPV
LABELV $253
ADDRLP4 92
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 96
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 100
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 100
INDIRF4
CNSTF4 1148846080
GEF4 $266
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 76
ARGP4
ADDRGP4 CG_DrawDir
CALLV
pop
LABELV $266
LABELV $254
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $256
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+16384
INDIRI4
LTI4 $253
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $271
JUMPV
LABELV $268
ADDRLP4 92
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 96
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions+29452
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions+29452+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+29452+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 100
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 100
INDIRF4
CNSTF4 1148846080
GEF4 $284
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 44
ARGP4
ADDRGP4 CG_DrawDir
CALLV
pop
LABELV $284
LABELV $269
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $271
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+30220
INDIRI4
LTI4 $268
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $289
JUMPV
LABELV $286
ADDRLP4 92
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 92
INDIRF4
ASGNF4
ADDRLP4 96
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions+28680
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 96
INDIRI4
ADDRGP4 entityPositions+28680+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+28680+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 100
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 100
INDIRF4
CNSTF4 1148846080
GEF4 $302
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 60
ARGP4
ADDRGP4 CG_DrawDir
CALLV
pop
LABELV $302
LABELV $287
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $289
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+29448
INDIRI4
LTI4 $286
LABELV $229
endproc CG_AlienSense 104 12
lit
align 4
LABELV $305
byte 4 1065353216
byte 4 0
byte 4 0
byte 4 1061158912
align 4
LABELV $306
byte 4 1065353216
byte 4 0
byte 4 0
byte 4 1056964608
export CG_Scanner
code
proc CG_Scanner 112 20
ADDRFP4 0
ADDRFP4 0
INDIRP4
ASGNP4
ADDRFP4 8
ADDRFP4 8
INDIRP4
ASGNP4
ADDRLP4 60
ADDRGP4 $305
INDIRB
ASGNB 16
ADDRLP4 76
ADDRGP4 $306
INDIRB
ASGNB 16
ADDRLP4 28
ADDRFP4 8
INDIRP4
INDIRF4
ASGNF4
ADDRLP4 28+4
ADDRFP4 8
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ASGNF4
ADDRLP4 28+8
ADDRFP4 8
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ASGNF4
ADDRLP4 28+12
ADDRFP4 8
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ASGNF4
ADDRLP4 28+12
CNSTF4 1069547520
ADDRLP4 28+12
INDIRF4
MULF4
ASGNF4
ADDRLP4 44
ADDRFP4 8
INDIRP4
INDIRF4
ASGNF4
ADDRLP4 44+4
ADDRFP4 8
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ASGNF4
ADDRLP4 44+8
ADDRFP4 8
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ASGNF4
ADDRLP4 44+12
ADDRFP4 8
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ASGNF4
ADDRLP4 16
ADDRGP4 entityPositions+30228
INDIRB
ASGNB 12
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $318
JUMPV
LABELV $315
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+16388
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+16388+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+16388+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $331
ADDRLP4 0+8
INDIRF4
CNSTF4 0
GEF4 $331
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 44
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $331
LABELV $316
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $318
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+28676
INDIRI4
LTI4 $315
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $337
JUMPV
LABELV $334
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $347
ADDRLP4 0+8
INDIRF4
CNSTF4 0
GEF4 $347
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 76
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $347
LABELV $335
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $337
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+16384
INDIRI4
LTI4 $334
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $353
JUMPV
LABELV $350
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+29452
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+29452+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+29452+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $366
ADDRLP4 0+8
INDIRF4
CNSTF4 0
GEF4 $366
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 44
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $366
LABELV $351
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $353
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+30220
INDIRI4
LTI4 $350
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $372
JUMPV
LABELV $369
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+28680
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+28680+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+28680+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $385
ADDRLP4 0+8
INDIRF4
CNSTF4 0
GEF4 $385
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 76
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $385
LABELV $370
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $372
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+29448
INDIRI4
LTI4 $369
ADDRGP4 cg_disableScannerPlane+12
INDIRI4
CNSTI4 0
NEI4 $388
ADDRFP4 8
INDIRP4
ARGP4
ADDRGP4 trap_R_SetColor
CALLV
pop
ADDRFP4 0
INDIRP4
INDIRF4
ARGF4
ADDRFP4 0
INDIRP4
CNSTI4 4
ADDP4
INDIRF4
ARGF4
ADDRFP4 0
INDIRP4
CNSTI4 8
ADDP4
INDIRF4
ARGF4
ADDRFP4 0
INDIRP4
CNSTI4 12
ADDP4
INDIRF4
ARGF4
ADDRFP4 4
INDIRI4
ARGI4
ADDRGP4 CG_DrawPic
CALLV
pop
CNSTP4 0
ARGP4
ADDRGP4 trap_R_SetColor
CALLV
pop
LABELV $388
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $394
JUMPV
LABELV $391
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+16388
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+16388+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+16388+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $407
ADDRLP4 0+8
INDIRF4
CNSTF4 0
LEF4 $407
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 28
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $407
LABELV $392
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $394
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+28676
INDIRI4
LTI4 $391
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $413
JUMPV
LABELV $410
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $423
ADDRLP4 0+8
INDIRF4
CNSTF4 0
LEF4 $423
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 60
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $423
LABELV $411
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $413
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+16384
INDIRI4
LTI4 $410
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $429
JUMPV
LABELV $426
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+29452
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+29452+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+29452+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $442
ADDRLP4 0+8
INDIRF4
CNSTF4 0
LEF4 $442
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 28
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $442
LABELV $427
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $429
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+30220
INDIRI4
LTI4 $426
ADDRLP4 12
CNSTI4 0
ASGNI4
ADDRGP4 $448
JUMPV
LABELV $445
ADDRLP4 100
CNSTF4 0
ASGNF4
ADDRLP4 0+8
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 0
ADDRLP4 100
INDIRF4
ASGNF4
ADDRLP4 104
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ASGNI4
ADDRLP4 0
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+28680
ADDP4
INDIRF4
ADDRLP4 16
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+4
ADDRLP4 104
INDIRI4
ADDRGP4 entityPositions+28680+4
ADDP4
INDIRF4
ADDRLP4 16+4
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0+8
CNSTI4 12
ADDRLP4 12
INDIRI4
MULI4
ADDRGP4 entityPositions+28680+8
ADDP4
INDIRF4
ADDRLP4 16+8
INDIRF4
SUBF4
ASGNF4
ADDRLP4 0
ARGP4
ADDRLP4 108
ADDRGP4 VectorLength
CALLF4
ASGNF4
ADDRLP4 108
INDIRF4
CNSTF4 1148846080
GEF4 $461
ADDRLP4 0+8
INDIRF4
CNSTF4 0
LEF4 $461
ADDRFP4 0
INDIRP4
ARGP4
ADDRLP4 0
ARGP4
ADDRLP4 60
ARGP4
ADDRGP4 CG_DrawBlips
CALLV
pop
LABELV $461
LABELV $446
ADDRLP4 12
ADDRLP4 12
INDIRI4
CNSTI4 1
ADDI4
ASGNI4
LABELV $448
ADDRLP4 12
INDIRI4
ADDRGP4 entityPositions+29448
INDIRI4
LTI4 $445
LABELV $304
endproc CG_Scanner 112 20
bss
align 4
LABELV entityPositions
skip 30252
import trap_GetDemoName
import trap_GetDemoPos
import trap_GetDemoState
import trap_GetEntityToken
import trap_getCameraInfo
import trap_startCamera
import trap_loadCamera
import trap_RealTime
import trap_SnapVector
import trap_CIN_SetExtents
import trap_CIN_DrawCinematic
import trap_CIN_RunCinematic
import trap_CIN_StopCinematic
import trap_CIN_PlayCinematic
import trap_Key_SetBinding
import trap_Key_GetBindingBuf
import trap_Key_KeynumToStringBuf
import trap_Key_GetKey
import trap_Key_SetCatcher
import trap_Key_GetCatcher
import trap_Key_IsDown
import trap_R_RegisterFont
import trap_MemoryRemaining
import testPrintFloat
import testPrintInt
import trap_SetUserCmdValue
import trap_GetUserCmd
import trap_GetCurrentCmdNumber
import trap_GetServerCommand
import trap_GetSnapshot
import trap_GetCurrentSnapshotNumber
import trap_GetGameState
import trap_GetGlconfig
import trap_R_RemapShader
import trap_R_LerpTag
import trap_R_ModelBounds
import trap_R_DrawStretchPic
import trap_R_SetColor
import trap_R_RenderScene
import trap_R_LightForPoint
import trap_R_AddAdditiveLightToScene
import trap_R_AddLightToScene
import trap_R_AddPolysToScene
import trap_R_AddPolyToScene
import trap_R_AddRefEntityToScene
import trap_R_ClearScene
import trap_R_RegisterShaderNoMip
import trap_R_RegisterShader
import trap_R_RegisterSkin
import trap_R_RegisterModel
import trap_R_LoadWorldMap
import trap_S_StopBackgroundTrack
import trap_S_StartBackgroundTrack
import trap_S_RegisterSound
import trap_S_Respatialize
import trap_S_UpdateEntityPosition
import trap_S_AddRealLoopingSound
import trap_S_AddLoopingSound
import trap_S_ClearLoopingSounds
import trap_S_StartLocalSound
import trap_S_StopLoopingSound
import trap_S_StartSound
import trap_CM_MarkFragments
import trap_CM_TransformedBiSphereTrace
import trap_CM_BiSphereTrace
import trap_CM_TransformedCapsuleTrace
import trap_CM_CapsuleTrace
import trap_CM_TransformedBoxTrace
import trap_CM_BoxTrace
import trap_CM_TransformedPointContents
import trap_CM_PointContents
import trap_CM_TempBoxModel
import trap_CM_InlineModel
import trap_CM_NumInlineModels
import trap_CM_LoadMap
import trap_UpdateScreen
import trap_SendClientCommand
import trap_AddCommand
import trap_SendConsoleCommand
import trap_FS_GetFileList
import trap_FS_Seek
import trap_FS_FCloseFile
import trap_FS_Write
import trap_FS_Read
import trap_FS_FOpenFile
import trap_LiteralArgs
import trap_Args
import trap_Argv
import trap_Argc
import trap_Cvar_VariableStringBuffer
import trap_Cvar_Set
import trap_Cvar_Update
import trap_Cvar_Register
import trap_Milliseconds
import trap_Error
import trap_Print
import CG_TutorialText
import CG_WritePTRCode
import CG_ReadPTRCode
import CG_DestroyTestTS_f
import CG_TestTS_f
import CG_AddTrails
import CG_IsTrailSystemValid
import CG_DestroyTrailSystem
import CG_SpawnNewTrailSystem
import CG_RegisterTrailSystem
import CG_LoadTrailSystems
import CG_DestroyTestPS_f
import CG_TestPS_f
import CG_ParticleSystemEntity
import CG_AddParticles
import CG_SetParticleSystemNormal
import CG_IsParticleSystemValid
import CG_IsParticleSystemInfinite
import CG_DestroyParticleSystem
import CG_SpawnNewParticleSystem
import CG_RegisterParticleSystem
import CG_LoadParticleSystems
import CG_SetAttachmentOffset
import CG_SetAttachmentParticle
import CG_SetAttachmentTag
import CG_SetAttachmentCent
import CG_SetAttachmentPoint
import CG_AttachToParticle
import CG_AttachToTag
import CG_AttachToCent
import CG_AttachToPoint
import CG_Attached
import CG_AttachmentCentNum
import CG_AttachmentVelocity
import CG_AttachmentAxis
import CG_AttachmentDir
import CG_AttachmentPoint
import CG_DefragmentMemory
import CG_Free
import CG_Alloc
import CG_InitMemory
import CG_CheckChangedPredictableEvents
import CG_TransitionPlayerState
import CG_Respawn
import CG_ShaderStateChanged
import CG_SetConfigValues
import CG_ParseServerinfo
import CG_ExecuteNewServerCommands
import CG_RequestScores
import CG_InitConsoleCommands
import CG_ConsoleCommand
import CG_ProcessSnapshots
import CG_ImpactMark
import CG_AddMarks
import CG_InitMarkPolys
import CG_DrawItemSelectText
import CG_DrawItemSelect
import CG_AddPlayerWeapon
import CG_AddViewWeapon
import CG_ShotgunFire
import CG_Bullet
import CG_MissileHitPlayer
import CG_MissileHitWall
import CG_FireWeapon
import CG_RegisterWeapon
import CG_InitWeapons
import CG_RegisterUpgrade
import CG_InitUpgrades
import CG_Weapon_f
import CG_PrevWeapon_f
import CG_NextWeapon_f
import CG_PositionRotatedEntityOnTag
import CG_PositionEntityOnTag
import CG_AdjustPositionForMover
import CG_Beam
import CG_AddPacketEntities
import CG_SetEntitySoundPosition
import CG_DrawBoundingBox
import CG_PainEvent
import CG_EntityEvent
import CG_CheckEvents
import CG_PredictPlayerState
import CG_BiSphereTrace
import CG_CapTrace
import CG_Trace
import CG_PointContents
import CG_BuildSolidList
import CG_ModelDoor
import CG_AnimMapObj
import CG_RunLerpFrame
import CG_AlienBuildableExplosion
import CG_HumanBuildableExplosion
import CG_InitBuildables
import CG_DrawBuildableStatus
import CG_BuildableStatusParse
import CG_Buildable
import CG_GhostBuildable
import CG_AtHighestClass
import CG_Bleed
import CG_PlayerDisconnect
import CG_CustomSound
import CG_PrecacheClientInfo
import CG_NewClientInfo
import CG_AddRefEntityWithPowerups
import CG_ResetPlayerEntity
import CG_Corpse
import CG_Player
import CG_DrawField
import CG_ResetPainBlend
import CG_UpdateMediaFraction
import CG_DrawLoadingScreen
import CG_Text_PaintChar
import CG_GetKillerText
import CG_GetTeamColor
import CG_SetPrintString
import CG_RunMenuScript
import CG_GetValue
import CG_Text_Height
import CG_Text_Width
import CG_Text_Paint
import CG_OwnerDraw
import CG_DrawActive
import CG_CenterPrint
import CG_AddLagometerSnapshotInfo
import CG_AddLagometerFrameInfo
import numSortedTeamPlayers
import sortedTeamPlayers
import CG_KeyBinding
import CG_WorldToScreen
import CG_DrawTopBottom
import CG_DrawSides
import CG_DrawRect
import CG_GetColorForHealth
import CG_ColorForHealth
import CG_TileClear
import CG_FadeColor
import CG_DrawStrlen
import CG_DrawFadePic
import CG_DrawPic
import CG_FillRect
import CG_AdjustFrom640
import CG_DrawPlane
import CG_DrawActiveFrame
import CG_AddBufferedSound
import CG_TestModelPrevSkin_f
import CG_TestModelNextSkin_f
import CG_TestModelPrevFrame_f
import CG_TestModelNextFrame_f
import CG_TestGun_f
import CG_TestModel_f
import CG_addSmoothOp
import CG_AddNotifyText
import CG_RemoveNotifyLine
import CG_FileExists
import CG_BuildSpectatorString
import CG_SetScoreSelection
import CG_EventHandling
import CG_MouseEvent
import CG_KeyEvent
import CG_LoadMenus
import CG_LastAttacker
import CG_CrosshairPlayer
import CG_UpdateCvars
import CG_PlayerCount
import CG_StartMusic
import CG_Error
import CG_Printf
import CG_Argv
import CG_ConfigString
import cg_unlagged
import cg_projectileNudge
import cg_optimizePrediction
import cg_debugRandom
import ui_humanTeamVoteActive
import ui_alienTeamVoteActive
import ui_voteActive
import ui_loading
import ui_dialog
import ui_stages
import ui_carriage
import ui_currentClass
import cg_painBlendZoom
import cg_painBlendScale
import cg_painBlendMax
import cg_painBlendDownRate
import cg_painBlendUpRate
import cg_tutorial
import cg_disableScannerPlane
import cg_disableWarningDialogs
import cg_debugPVS
import cg_debugTrails
import cg_debugParticles
import cg_lightFlare
import cg_consoleLatency
import cg_bounceParticles
import cg_depthSortParticles
import cg_wwToggle
import cg_wwFollow
import cg_wwSmoothTime
import cg_debugAlloc
import cg_drawBBOX
import cg_drawSurfNormal
import cg_creepRes
import cg_trueLightning
import cg_oldPlasma
import cg_oldRocket
import cg_oldRail
import cg_noProjectileTrail
import cg_noTaunt
import cg_bigFont
import cg_smallFont
import cg_cameraMode
import cg_timescale
import cg_timescaleFadeSpeed
import cg_timescaleFadeEnd
import cg_cameraOrbitDelay
import cg_cameraOrbit
import pmove_msec
import pmove_fixed
import cg_smoothClients
import cg_scorePlum
import cg_noVoiceText
import cg_noVoiceChats
import cg_teamChatsOnly
import cg_drawFriend
import cg_deferPlayers
import cg_predictItems
import cg_blood
import cg_paused
import cg_buildScript
import cg_forceModel
import cg_stats
import cg_synchronousClients
import cg_drawAttacker
import cg_lagometer
import cg_stereoSeparation
import cg_thirdPerson
import cg_thirdPersonAngle
import cg_thirdPersonRange
import cg_zoomFov
import cg_fov
import cg_simpleItems
import cg_ignore
import cg_autoswitch
import cg_tracerLength
import cg_tracerWidth
import cg_tracerChance
import cg_viewsize
import cg_drawGun
import cg_gun_z
import cg_gun_y
import cg_gun_x
import cg_gun_frame
import cg_brassTime
import cg_addMarks
import cg_footsteps
import cg_showmiss
import cg_noPlayerAnims
import cg_debugMove
import cg_nopredict
import cg_errorDecay
import cg_railTrailTime
import cg_teslaTrailTime
import cg_debugEvents
import cg_debugPosition
import cg_debugAnim
import cg_animSpeed
import cg_draw2D
import cg_drawStatus
import cg_crosshairY
import cg_crosshairX
import cg_teamOverlayUserinfo
import cg_drawTeamOverlay
import cg_drawRewards
import cg_drawCrosshairNames
import cg_drawCrosshair
import cg_drawAmmoWarning
import cg_drawIcons
import cg_draw3dIcons
import cg_drawSnapshot
import cg_drawDemoState
import cg_drawFPS
import cg_drawClock
import cg_drawTimer
import cg_gibs
import cg_shadows
import cg_swingSpeed
import cg_bobroll
import cg_bobpitch
import cg_bobup
import cg_runroll
import cg_runpitch
import cg_centertime
import cg_markPolys
import cg_buildables
import cg_upgrades
import cg_weapons
import cg_entities
import cg
import cgs
import g_nameBind2
import g_nameBind1
import BindingFromName
import trap_Parse_SourceFileAndLine
import trap_Parse_ReadToken
import trap_Parse_FreeSource
import trap_Parse_LoadSource
import trap_Parse_AddGlobalDefine
import Item_Text_AutoWrapped_Paint
import Controls_SetDefaults
import Controls_SetConfig
import Controls_GetConfig
import UI_OutOfMemory
import UI_InitMemory
import UI_Alloc
import Display_CacheAll
import Menu_SetFeederSelection
import Menu_Paint
import Menus_CloseAll
import LerpColor
import Display_HandleKey
import Menus_CloseByName
import Menus_ShowByName
import Menus_FindByName
import Menus_OpenByName
import Display_KeyBindPending
import Display_CursorType
import Display_MouseMove
import Display_CaptureItem
import Display_GetContext
import Menus_Activate
import Menus_AnyFullScreenVisible
import Menu_Reset
import Menus_ActivateByName
import Menu_PaintAll
import Menu_New
import Menu_Count
import PC_Script_Parse
import PC_String_Parse
import PC_Rect_Parse
import PC_Int_Parse
import PC_Color_Parse
import PC_Float_Parse
import Script_Parse
import String_Parse
import Rect_Parse
import Int_Parse
import Color_Parse
import Float_Parse
import Menu_ScrollFeeder
import Menu_HandleMouseMove
import Menu_HandleKey
import Menu_GetFocused
import Menu_PostParse
import Item_Init
import Menu_Init
import Display_ExpandMacros
import Init_Display
import String_Report
import String_Init
import String_Alloc
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
