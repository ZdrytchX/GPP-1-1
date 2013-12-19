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


/*
 * ALIEN weapons
 *
 * _REPEAT  - time in msec until the weapon can be used again
 * _DMG     - amount of damage the weapon does
 *
 * ALIEN_WDMG_MODIFIER - overall damage modifier for coarse tuning
 *
 * Knockbacks are currently disabled for claws until i get a compiler working.
 */

#define ALIEN_WDMG_MODIFIER         1.0f
#define ADM(d)                      ((int)((float)d*ALIEN_WDMG_MODIFIER))
#define ALIENREGEN_NOCREEP_MOD      0.7f //out of creep modifier

#define ABUILDER_BUILD_REPEAT       500
#define ABUILDER_CLAW_DMG           ADM(27 + (VAMP_ON * 6))//3 hit headshot kill
#define ABUILDER_CLAW_RANGE         78.0f //64f
#define ABUILDER_CLAW_WIDTH         8.0f //4f
#define ABUILDER_BASE_CLAW_REPEAT   1000
#define ABUILDER_CLAW_REPEAT        900
#define ABUILDER_CLAW_K_SCALE       0.0f


#define ABUILDER_BASE_DELAY         15000
#define ABUILDER_ADV_DELAY          12000
//Added raw value to build timer, total build time must not be smaller than 0
//#define ABUILDER_BUILD_EXTRA        -2000

#define ABUILDER_BLOB_DMG           ADM(4)
#define ABUILDER_BLOB_SPLASH_DMG    ADM(4)
#define ABUILDER_BLOB_K             ADM(90)
#define ABUILDER_BLOB_SPLASH_K      ADM(100/ABUILDER_BLOB_DMG)
#define ABUILDER_BLOB_RADIUS        75
#define ABUILDER_BLOB_REPEAT        1000
#define ABUILDER_BLOB_SPEED         800.0f
#define ABUILDER_BLOB_SPEED_MOD     0.5f
#define ABUILDER_BLOB_LIFETIME      ABUILDER_BLOB_REPEAT*3.5//Auto explodes after this time
#define ABUILDER_BLOB_TIME          5000 //how long a guy gets slowed down

#define LEVEL0_BITE_DMG             ADM(48)//36 + (VAMP_ON * 12))
#define LEVEL0_BITE_RANGE           64.0f
#define LEVEL0_BITE_WIDTH           1.0f //6f
#define LEVEL0_BITE_REPEAT          500
#define LEVEL0_BITE_K_SCALE         1.0f
//Disabled (range), although animation disabled via bg_misc.c
//ignore this, disabled via bg_misc.c
#define LEVEL0_SCRATCH_DMG          ADM(48) //ADM(6 + (VAMP_ON * -3))//dispite this, it is actually almost overpowered.
#define LEVEL0_SCRATCH_REPEAT       0//150
#define LEVEL0_SCRATCH_RANGE        80 //disabled, was 80
#define LEVEL0_SCRATCH_WIDTH        3
//I'm thinking of readding a secondary, but instead of a painsaw-like effect, rather something like a short range projectile with a large splash radius doing minimal damage but provides great knockback, to propell the dretch around to counter the blaster's knockback

#define LEVEL1_CLAW_DMG             ADM(32 + (VAMP_ON * 16))
#define LEVEL1_CLAW_RANGE           80.0f//Take unv's
#define LEVEL1_CLAW_WIDTH           10.0f
#define LEVEL1_CLAW_REPEAT          700
#define LEVEL1_CLAW_U_REPEAT        600
#define LEVEL1_CLAW_K_SCALE         0.0f
#define LEVEL1_CLAW_U_K_SCALE       0.0f
#define LEVEL1_GRAB_RANGE           80.0f//Take unv's
#define LEVEL1_GRAB_TIME            300 //Time for you to re-grab if you mis-aim again
#define LEVEL1_GRAB_U_TIME          450
#define LEVEL1_PCLOUD_DMG           ADM(0 + (VAMP_ON * 5)) //Nay, it still deals 1 dmg.
#define LEVEL1_PCLOUD_RANGE         200.0f //300 //limit troll gassers
#define LEVEL1_PCLOUD_REPEAT        2000
#define LEVEL1_PCLOUD_TIME          10000 //GPP - 2 seconds distortion, 5 seconds slowlock i think
#define LEVEL1_PCLOUD_MOD           0.7f //Speedmod, not too OP
                                          //TODO: Slowlock effect cannot be applied seperately for bsuits
                                          //DONE: Game-specific mod (outside cgames can't predict it)
                                          //TODO: See how W server did theirs

#define LEVEL2_CLAW_DMG             ADM(40 + (VAMP_ON * 8))
#define LEVEL2_CLAW_RANGE           80.0f //unv's
#define LEVEL2_CLAW_WIDTH           12.0f
#define LEVEL2_CLAW_U_WIDTH         14.0f
#define LEVEL2_CLAW_REPEAT          500
#define LEVEL2_CLAW_U_REPEAT        400
//ATTENTION! If you want to disabled the claw knockback only (leave zap knockback on), set CLAW_K_REVERSE to "0"
//If you want the opposite, turn the AREAZAP_K_SCALE to "0", CLAW_(U_)K_SCALE to "0.1" and CLAW_K_REVERSE to "-10.0f" (doesn't completely cancel out the first zap victim's pull effect though, but it shouldn't be noticable)
#define LEVEL2_CLAW_K_SCALE         1.0f //effects first zap victim as well apparently
#define LEVEL2_CLAW_U_K_SCALE       1.0f
#define LEVEL2_CLAW_K_REVERSE       -1.0f//For claws only

#define LEVEL2_AREAZAP_DMG          ADM(70 + (VAMP_ON * 30)) //4 zaps on teslas
#define LEVEL2_AREAZAP_RANGE        200.0f //initiate zap distance
#define LEVEL2_AREAZAP_RANGE_SUSTAIN 400 //Range to allow sustaining the zap
#define LEVEL2_AREAZAP_WIDTH        8.0f
#define LEVEL2_AREAZAP_REPEAT       1500
#define LEVEL2_AREAZAP_TIME         1000  //Divide by 0 fixed
					//TODO: Allow graphics to continue running despite chain cut off early
#define LEVEL2_AREAZAP_MAX_TARGETS  3
#define LEVEL2_WALLJUMP_MAXSPEED    3870.0f //1290.0f //idk, don't really want a max
#define LEVEL2_WALLJUMP_REPEAT      200 //200 - Prevents extreme acceleration, feels buggy with no walljump repeat timer but else stumbles and loses speed when stair climbing
#define LEVEL2_CLIPVELOCITY_TIME    LEVEL2_WALLJUMP_REPEAT //Allows clipping through walls GPP-style
#define LEVEL2_AREAZAP_K_SCALE      -3.0f //Chain-ees get pulled together with this

//Goon modified heavily to get close to gpp values.
#define LEVEL3_CLAW_DMG             ADM(80 + (VAMP_ON * 12))
#define LEVEL3_CLAW_RANGE           80.0f //Unv's
#define LEVEL3_CLAW_WIDTH           12.0f
#define LEVEL3_CLAW_REPEAT          800 //1.1 700 1.2 900
#define LEVEL3_CLAW_K_SCALE         0.8f //effects pounce as well
#define LEVEL3_CLAW_U_REPEAT        700 //600 800
#define LEVEL3_CLAW_U_K_SCALE       0.8f
#define LEVEL3_POUNCE_DMG           ADM(100 + (VAMP_ON * 30)) // -> 115 (bsuits take the same damage as laroured)
					//Armour - 3 hit
					//Helm - 2 hit
					//Larm+Helm -or- bsuit - 4 hit
#define LEVEL3_POUNCE_RANGE         42.0f //No more long range, reaches diagonally towards tip of bbox perfectly
#define LEVEL3_POUNCE_WIDTH         27.0f //default 16. //Widened for 'realism'
#define LEVEL3_POUNCE_SPEED         700 
#define LEVEL3_POUNCE_UPG_SPEED     800 
#define LEVEL3_POUNCE_SPEED_MOD     0.75f 
#define LEVEL3_POUNCE_CHARGE_TIME   700 
#define LEVEL3_POUNCE_TIME          200 + FASTFIRE //400-> 200 delay after touching ground before you can chomp again
#define LEVEL3_BOUNCEBALL_DMG       ADM(115 + (VAMP_ON * 15))

#define LEVEL3_BOUNCEBALL_AMMO      3
#define LEVEL3_BOUNCEBALL_REPEAT    1000
#define LEVEL3_BOUNCEBALL_RECHARGE  18000 //barb regen time
#define LEVEL3_BOUNCEBALL_SPEED     1000.0f
#define LEVEL3_BOUNCEBALL_SPLASH_DMG ADM(110 + (VAMP_ON * 35)) //110 -> 76//Honestly, i don't like the overpowered snipe.
#define LEVEL3_BOUNCEBALL_SPLASH_MOD 0.69f //rounds up to 76 dmg
#define LEVEL3_BOUNCEBALL_SPLASH_RADIUS 92

#define LEVEL4_CLAW_DMG             ADM(100 + (VAMP_ON * 10))
#define LEVEL4_CLAW_RANGE           96.0f //128 //80 feels useless [unv]
#define LEVEL4_CLAW_WIDTH           16.0f
#define LEVEL4_CLAW_REPEAT          750 //750 //keep at 1.1 value, otherwise people will charge-spam only
#define LEVEL4_CLAW_K_SCALE         0.2f //Effects Charge, do NOT put '0' however 0.1 is acceptable and not very noticable.

#define LEVEL4_REGEN_MOD            1.5f //No longer is kept with tyrant, however applies to overminds
#define LEVEL4_CHARGE_SPEED         2.0f //2.5 is easier to move with, reverted for standard client compatibility
#define LEVEL4_CHARGE_TIME          4000 //Leave alone!
#define LEVEL4_CHARGE_CHARGE_TIME   4000 //Trample time
#define LEVEL4_CHARGING_CHARGE_TIME 2000 //Charging up trample
#define LEVEL4_CHARGE_TAKE          100 //Charge taken per decasecond. Default is 100.
#define LEVEL4_TRAMPLE_CHARGE       200 //Charging Charge per decasecond. Default 100.   
#define LEVEL4_MIN_CHARGE_TIME      750
#define LEVEL4_CHARGE_CHARGE_RATIO  (LEVEL4_CHARGE_TIME/LEVEL4_CHARGE_CHARGE_TIME)//JUST LEAVE AS IS (confusing shit)

#define LEVEL4_CHARGE_REPEAT        150 //1000 - repeat rate of hits
                //GPP uses '100', the more lower, the more ping-bias
#define LEVEL4_CHARGE_TIMEOUT       LEVEL4_CHARGE_REPEAT + FASTFIRE //After charge has run out, wait this before you can swipe
#define LEVEL4_CHARGE_DMG           ADM(76 + (VAMP_ON * 35)) //100 (to help with armoured) - DO NOT USE '0'
//Approx. duration to kill from full:
					//0.15  naked
					//0.3s helm
					//0.45s larm
					//0.6s larm+helm [Bsuit not tested, but bsuit should be the same as this]
#define LEVEl4_CHARGE_K_ORIGINAL    85.0f //gpp 111.0f
#define LEVEl4_CHARGE_K_COUNTER     (1/LEVEL4_CLAW_K_SCALE)*(LEVEl4_CHARGE_K_ORIGINAL/LEVEL4_CHARGE_DMG) //counteracts the claw knockback and damage differences between this and LEVEl4_CHARGE_K_ORIGINAL

#define LEVEL4_CHARGE_EXTRA         ADM(15) //Extra damage added to charge so it isnt completely useless when slow

#define LEVEL4_REGEN_RANGE          150.0f //Used for basi, booster and overmind healing, default 200
                                           //rant has no aura now
//Re-added Tyrant Spitbomb
#define LEVEL4_ABLOB_DMG            ADM(210)
#define LEVEL4_ABLOB_DMG_B          0.6f //damage to buildables modifier
#define LEVEL4_ABLOB_RADIUS         200 //200 is more than enough to annoy campers
#define LEVEL4_ABLOB_SPEED          500 //carries own speed too
#define LEVEL4_ABLOB_STUNTIME       1200 //Prevents self from re-attacking immediately
#define LEVEL4_ABLOB_REGEN          60000//limits bomb rushes
#define LEVEL4_ABLOB_LIFETIME       10000 //spitbomb lifetime




/*
 * ALIEN classes
 *
 * _SPEED   - fraction of Q3A run speed the class can move
 * _REGEN   - health per second regained when in creep
 *
 * ALIEN_HLTH_MODIFIER - overall health modifier for coarse tuning
 *
 */

#define ALIEN_HLTH_MODIFIER         1.0f
#define AHM(h)                      ((int)((float)h*ALIEN_HLTH_MODIFIER))

#define ALIEN_VALUE_MODIFIER        1.0f
#define AVM(h)                      ((int)((float)h*ALIEN_VALUE_MODIFIER))

#define ABUILDER_SPEED              0.8f
#define ABUILDER_VALUE              AVM(160) //limit battlegrangers' reward because of newbies
#define ABUILDER_HEALTH             AHM(50 + (VAMP_ON * 10))
#define ABUILDER_REGEN              2
#define ABUILDER_COST               0

#define ABUILDER_UPG_SPEED          1.0f
#define ABUILDER_UPG_VALUE          AVM(220) //limit battlegrangers' reward because of newbies
#define ABUILDER_UPG_HEALTH         AHM(75 + (VAMP_ON * 15))
#define ABUILDER_UPG_REGEN          3
#define ABUILDER_UPG_COST           0

#define LEVEL0_SPEED                1.4f
#define LEVEL0_VALUE                AVM(180)
#define LEVEL0_HEALTH               AHM(25 + (VAMP_ON * 5))
#define LEVEL0_REGEN                1
#define LEVEL0_COST                 0

#define LEVEL1_SPEED                1.25f
#define LEVEL1_VALUE                AVM(260)
#define LEVEL1_HEALTH               AHM(60 + (VAMP_ON * 15))
#define LEVEL1_REGEN                2
#define LEVEL1_COST                 1
#define LEVEL1_REGEN_MOD            2.0f

#define LEVEL1_UPG_SPEED            1.25f
#define LEVEL1_UPG_VALUE            AVM(275)
#define LEVEL1_UPG_HEALTH           AHM(80 + (VAMP_ON * 20))
#define LEVEL1_UPG_REGEN            3
#define LEVEL1_UPG_COST             1
#define LEVEL1_UPG_REGEN_MOD        3.0f

#define LEVEL2_SPEED                1.2f
#define LEVEL2_VALUE                AVM(380)
#define LEVEL2_HEALTH               AHM(150)
#define LEVEL2_REGEN                4
#define LEVEL2_COST                 1

#define LEVEL2_UPG_SPEED            1.2f
#define LEVEL2_UPG_VALUE            AVM(430)
#define LEVEL2_UPG_HEALTH           AHM(175)
#define LEVEL2_UPG_REGEN            5
#define LEVEL2_UPG_COST             1

#define LEVEL3_SPEED                1.1f
#define LEVEL3_VALUE                AVM(575)
#define LEVEL3_HEALTH               AHM(200 + (VAMP_ON * 25))
#define LEVEL3_REGEN                6
#define LEVEL3_COST                 1

#define LEVEL3_UPG_SPEED            1.1f
#define LEVEL3_UPG_VALUE            AVM(650)
#define LEVEL3_UPG_HEALTH           AHM(250 + (VAMP_ON * 25))
#define LEVEL3_UPG_REGEN            7
#define LEVEL3_UPG_COST             1

#define LEVEL4_SPEED                1.2f //1.2f //Switched back from 1.1 to 1.2 because of sprinters
#define LEVEL4_VALUE                AVM(800)
#define LEVEL4_HEALTH               AHM(375 + (VAMP_ON * 45))
#define LEVEL4_REGEN                8
#define LEVEL4_COST                 2

//Basi-Suit
//disabled because this isn't Lolards, just ignore and move along...
#define SPY_SPEED                   1.0f
#define SPY_HEALTH                  150
#define SPY_VALUE                   720
#define SPY_COST                    0 //9
#define SPY_REGEN                   (9 + + (VAMP_ON * -6))

/*
 * ALIEN buildables
 *
 * _BP            - build points required for this buildable
 * _BT            - build time required for this buildable
 * _REGEN         - the amount of health per second regained
 * _SPLASHDAMGE   - the amount of damage caused by this buildable when melting
 * _SPLASHRADIUS  - the radius around which it does this damage
 *
 * CREEP_BASESIZE - the maximum distance a buildable can be from an egg/overmind
 * ALIEN_BHLTH_MODIFIER - overall health modifier for coarse tuning
 *
 */

#define ALIEN_BHLTH_MODIFIER        1.0f
#define ABHM(h)                     ((int)((float)h*ALIEN_BHLTH_MODIFIER))

#define CREEP_BASESIZE              700
#define CREEP_TIMEOUT               1000
#define CREEP_MODIFIER              0.6f
#define CREEP_ARMOUR_MODIFIER       0.75f
#define CREEP_SCALEDOWN_TIME        3000

#define ASPAWN_BP                   10
#define ASPAWN_BT                   12000
#define ASPAWN_HEALTH               ABHM(250)
#define ASPAWN_REGEN                7
#define ASPAWN_SPLASHDAMAGE         60
#define ASPAWN_SPLASHRADIUS         50
#define ASPAWN_CREEPSIZE            120
#define ASPAWN_VALUE                180 //default 150

#define BARRICADE_BP                8
#define BARRICADE_BT                12000
#define BARRICADE_HEALTH            ABHM(500)//Deal with luci spammers more
#define BARRICADE_REGEN             9
#define BARRICADE_SPLASHDAMAGE      150
#define BARRICADE_SPLASHRADIUS      150
#define BARRICADE_CREEPSIZE         240

#define BOOSTER_BP                  12
#define BOOSTER_BT                  15000
#define BOOSTER_HEALTH              ABHM(150)
#define BOOSTER_REGEN               5
#define BOOSTER_SPLASHDAMAGE        50
#define BOOSTER_SPLASHRADIUS        50
#define BOOSTER_CREEPSIZE           120 //regen area = tyrant aura area
#define BOOSTER_INTERVAL            10000 //time in msec between recharges per player
#define BOOSTER_REGEN_MOD           3.0f
#define BOOST_TIME                  30000 //hate gpp values

#define ACIDTUBE_BP                 6     //I don't care about gpp value, tubes are useless.
#define ACIDTUBE_BT                 12000
#define ACIDTUBE_HEALTH             ABHM(125)
#define ACIDTUBE_REGEN              4
#define ACIDTUBE_SPLASHDAMAGE       8 //Don't get confused this with other splash damages, this is the attack damage
#define ACIDTUBE_SPLASHRADIUS       300 //bring higher to near-unite turret range so they're not so shit
#define ACIDTUBE_CREEPSIZE          120
#define ACIDTUBE_RANGE              300.0f //200 //YADAHAHAHAHA I DIDNT HEAR ANYTHING
#define ACIDTUBE_REPEAT             2000 //Re-trigger delay
#define ACIDTUBE_K_SCALE            0.0f //does nothing

#define HIVE_BP                     12
#define HIVE_LIFETIME               12000
#define HIVE_BT                     15000
#define HIVE_HEALTH                 ABHM(150) //default 125 //Urasai urasai urasai! Hives are weaklings!
#define HIVE_REGEN                  5
#define HIVE_SPLASHDAMAGE           30 //Splash damage for insectoid death
#define HIVE_SPLASHRADIUS           100
#define HIVE_CREEPSIZE              120
#define HIVE_RANGE                  1200.0f //300 Higher! Bring em higher!
#define HIVE_REPEAT                 1500 //Insectoid Re-send time //2500 -> 1500 so not so useless close-range
#define HIVE_K_SCALE                -1.0f //Reel 'em in boys!
#define HIVE_DMG                    60
#define HIVE_SPEED                  380.0f //deal with jettards
#define HIVE_DIR_CHANGE_PERIOD      500
#define HIVE_HIVE_STUN              500//Stun time from insectoid death and rebirth

#define TRAPPER_BP                  8
#define TRAPPER_BT                  12000
#define TRAPPER_HEALTH              ABHM(50 + (VAMP_ON * 10))
#define TRAPPER_REGEN               3
#define TRAPPER_SPLASHDAMAGE        50
#define TRAPPER_SPLASHRADIUS        50
#define TRAPPER_CREEPSIZE           30
#define TRAPPER_RANGE               400
#define TRAPPER_REPEAT              1000
#define TRAPPER_K_SCALE             1.0f
#define LOCKBLOB_SPEED              650.0f
#define LOCKBLOB_LOCKTIME           0
#define LOCKBLOB_LIFETIME           6000 //Locktime
#define LOCKBLOB_DOT                0.85f // max angle = acos( LOCKBLOB_DOT )
#define LOCKBLOB_K_SCALE            -1.0f
#define LOCKBLOB_DMG                15
#define LOCKBLOB_SPLASH             10
#define LOCKBLOB_RADIUS             50

#define OVERMIND_BP                 0
#define OVERMIND_BT                 20000
#define OVERMIND_HEALTH             ABHM(780)
#define OVERMIND_REGEN              16
#define OVERMIND_SPLASHDAMAGE       18
#define OVERMIND_SPLASHRADIUS       300
#define OVERMIND_CREEPSIZE          120
#define OVERMIND_ATTACK_RANGE       150.0f
#define OVERMIND_ATTACK_REPEAT      800
#define OVERMIND_VALUE              800

//<3
#define HOVEL_BP                    0
#define HOVEL_BT                    10000 //Fast-home
#define HOVEL_HEALTH                ABHM(500) //370
#define HOVEL_REGEN                 30 //20
#define HOVEL_SPLASHDAMAGE          20
#define HOVEL_SPLASHRADIUS          200
#define HOVEL_CREEPSIZE             120



/*
 * ALIEN misc
 *
 * ALIENSENSE_RANGE - the distance alien sense is useful for
 *
 */

#define ALIENSENSE_RANGE            1000.0f
#define ALIEN_POISON_TIME           8000 //i'm keeping medikit immunity
#define ALIEN_POISON_DMG            5 + VAMP_ON
#define ALIEN_POISON_DIVIDER        (1.0f/1.32f) //about 1.0/(time`th root of damage)[1.0f/1.32f]
#define ALIEN_SPAWN_REPEAT_TIME     12000
#define ALIEN_REGEN_DAMAGE_TIME     3000 //Reduce chances of healing mid-battle

/*
 * HUMAN weapons
 *
 * _REPEAT  - time between firings
 * _RELOAD  - time needed to reload
 * _PRICE   - amount in credits weapon costs
 * _K_SCALE - Knockback scale
 *
 * HUMAN_WDMG_MODIFIER - overall damage modifier for coarse tuning
 *
 */

#define HUMAN_WDMG_MODIFIER         1.0f
#define HDM(d)                      ((int)((float)d*HUMAN_WDMG_MODIFIER))

#define HUMAN_TK_DMG_MOD            2.0f //With Teamkill Mode, apply this modifier

#define BLASTER_REPEAT              750 //+50
#define BLASTER_K_SCALE             3.0f //direct only - Gets overpowered on mid-air shots, use lower value for dretches //6.0f //1.2f
#define BLASTER_K_SCALE_LEVEL0      0.6f //enough to make a dretch hover at g_gravity = 800 ("hovering" damage/s = 160, if 1.0 is hovering then 1.0 = 800 / (dmg * 5))
#define BLASTER_K_SELF_SCALE        (100.0f/BLASTER_PUSH) //gets multiplied for self only (splash)
#define BLASTER_K_LEVEL1_RESISTANCE 0.3f //resistance against basilisks so they can still grab without problems
#define BLASTER_K_LEVEL1_RESISTANCE_SPLASH 0.2f //modifier for splash knockback - 0 = no knockback
#define BLASTER_K_LOCKED_RESISTANCE 0.3f //resistance on self so you can't fly away easily

#define BLASTER_SPREAD              0
#define BLASTER_SPEED               1400
#define BLASTER_DMG                 HDM(9 + VAMP_ON)
#define BLASTER_PUSH                90 //Blasterjump effect, this is the actual splash damage before modding, knockback applies to others from this value
#define BLASTER_DMG_MOD             (8.00f/BLASTER_PUSH) //Modifier for above damage
                                                         //Damage to Self / Raw Damage
#define BLASTER_DMG_TK              ((float)12.5/HUMAN_TK_DMG_MOD) //Damage Modifier from Blaster with teamkill mode - ~50dmg
#define BLASTER_K_TK                ((float)100.0/BLASTER_PUSH)//Overall Knockback Modiier with Teamkill mode
#define BLASTER_RADIUS              100
//Prevent Blaster Spamming
//Recharge rate is set to the g_blasterregen variable
#define BLASTER_CLIPSIZE            6
#define BLASTER_MAXCLIPS            1 //hacky fix for the lakitu7-qvm modded client, any number will do as long as it isn't 0
#define BLASTER_INF_AMMO            qtrue //qtrue
#define BLASTER_K_UP                60//extra upward knockback (direct only)

#define RIFLE_CLIPSIZE              30
#define RIFLE_MAXCLIPS              6
#define RIFLE_REPEAT                90 //use unv's value for tackling bigger aliens quicker
#define RIFLE_K_SCALE               1.0f
#define RIFLE_RELOAD                2000
#define RIFLE_PRICE                 0
#define RIFLE_SPREAD                250//170 -> 250 (unv's value)
#define RIFLE_DMG                   HDM(5 + VAMP_ON) //'6' seems ok on KoRx, although some australians says even the unv balance is overpowered

#define PAINSAW_PRICE               100
#define PAINSAW_REPEAT              65  //1.1 was 75
#define PAINSAW_K_SCALE             1.0f
#define PAINSAW_DAMAGE              HDM(12 + VAMP_ON) //~>185 dmg/s //1.1 was 15 (200dmg/s), gpp was 11 (145 dmg/s)
#define PAINSAW_RANGE               60.0f //enough to touch below feet of a normal human
//Following disabled via bg_misc.c and g_active.c, leave it for now
#define PAINSAW_NODECAY             qtrue //Bleed ammo one per second if nodecay is qfalse
#define PAINSAW_FUEL                0
#define PAINSAW_BATTERIES           0 //not compatable with battery decay system, don't bother
#define PAINSAW_RELOAD              3000

#define GRENADE_PRICE               200
#define GRENADE_REPEAT              0
#define GRENADE_K_SCALE             1.0f
#define GRENADE_DAMAGE              HDM(310)
#define GRENADE_DAMAGE_BUFF         1.5f //Buff up damage if the entity is inside/stepping on nade
#define GRENADE_RANGE               192.0f
#define GRENADE_SPEED               400.0f

#define SHOTGUN_PRICE               150
#define SHOTGUN_SHELLS              8 + (VAMP_ON * -2)
#define SHOTGUN_PELLETS             14 //5 * 11 is gpp, 4 * 14 is 1.1, 7 * 8 is tremfusion
#define SHOTGUN_MAXCLIPS            3 + (VAMP_ON * 2)
#define SHOTGUN_REPEAT              1000 + (VAMP_ON * -200)
#define SHOTGUN_K_SCALE             2.0f
#define SHOTGUN_RELOAD              2000 + (VAMP_ON * 1000) //( SHOTGUN_SHELLS * 400 + 800 )
#define SHOTGUN_SPREAD              900 + (VAMP_ON * 475)
#define SHOTGUN_DMG                 HDM(4 + (VAMP_ON * 2))
#define SHOTGUN_KICKBACK            0//on/off

#define LASGUN_PRICE                250
#define LASGUN_AMMO                 200
#define LASGUN_REPEAT               200
#define LASGUN_MAXCLIPS             0 + VAMP_ON
#define LASGUN_K_SCALE              2.5f
#define LASGUN_RELOAD               3000
#define LASGUN_SPREAD               70 //btw, this actually works, don't tweak it any higher or it'll effect gameplay too much
#define LASGUN_DAMAGE               HDM(9 + VAMP_ON)
#define LASGUN_K_UP                 10 //upward knockback added - 2.5 k_scale + 10 totals about 812 upward vel, allowing people to make others hover in air when aiming directly under them. This value only applies to teammates.

#define MDRIVER_PRICE               350
#define MDRIVER_CLIPSIZE            5
#define MDRIVER_MAXCLIPS            4
#define MDRIVER_DMG                 HDM(40 + (VAMP_ON * 22))
#define MDRIVER_DMG_TK              1.4f//modifier for teamkill mode ~112dmg
#define MDRIVER_REPEAT              1000 + (VAMP_ON * 375)
#define MDRIVER_K_SCALE             1.0f
#define MDRIVER_SPLASH_K_SCALE      3.0f
#define MDRIVER_RELOAD              2000
//bullet physics stuff
#define MDRIVER_SPEED               19200 //Bullet speed 19200 = 600 m/s = 2160 km/h
#define MDRIVER_RADIUS              0 + (VAMP_ON * 60) //explosion radius
#define MDRIVER_SPLASH              0 + (VAMP_ON * 40) //Splash dmg
#define MDRIVER_LAG                 0.35f //Same effect as Flamer_LAG but not as effective
#define MDRIVER_LIFETIME            8000 //It's a pretty fast bullet. Doesn't need a long lifetime

#define CHAINGUN_PRICE              400
#define CHAINGUN_BULLETS            300
#define CHAINGUN_MAXCLIPS           0
#define CHAINGUN_RELOAD             5000
#define CHAINGUN_REPEAT             80 //Single barrel shots
#define CHAINGUN_REPEAT2            100 //tripple shots, total damage per shot stays the same
#define CHAINGUN_K_SCALE            1.0f
#define CHAINGUN_SPREAD             700
#define CHAINGUN_SPREAD2            1200 //Anti-Dretch n00b edition
#define CHAINGUN_DMG                HDM(6 + VAMP_ON)

#define PRIFLE_PRICE                450
#define PRIFLE_CLIPS                50 //love ya 1.1 <3
#define PRIFLE_MAXCLIPS             4
#define PRIFLE_REPEAT               100
#define PRIFLE_K_SCALE              1.0f
#define PRIFLE_RELOAD               2000
#define PRIFLE_DMG                  HDM(9 + VAMP_ON)
#define PRIFLE_SPEED                1400 //1.1 uses 1000, gpp uses blaster speed

//fixed flamer-wall bug from tremulous
#define FLAMER_PRICE                450
#define FLAMER_GAS                  400 //Double fire rate, halve damage.
#define FLAMER_RELOAD               3000
#define FLAMER_REPEAT               100
#define FLAMER_K_SCALE              1.25f
#define FLAMER_DMG                  HDM(10 + (VAMP_ON * 2))
#define FLAMER_RADIUS_MOD           1.65f //radius lifting knockback, don't put 0
#define FLAMER_DMG_MOD              1.00f/FLAMER_RADIUS_MOD //don't touch
#define FLAMER_RADIUS               50
#define FLAMER_LIFETIME             800.0f //Apparently gpp uses 700
#define FLAMER_SPEED                400.0f //1.1 300 (Useless when chasing) gpp 500 (OP) - My custom particle system is sync'd to 400
#define FLAMER_LAG                  0.65f //user's velocity * this value gets added as velocity to flame ball

//Airblast Secondary Fire
#define FLAMER_AIRBLAST_DMG         100//knockback
#define FLAMER_AIRBLAST_REALDMG     0//actual damage dealt
#define FLAMER_AIRBLAST_UP_K        50//additional upward knockback
#define FLAMER_AIRBLAST_UP_K_LVL0   30//additional upward knockback for dretch
#define FLAMER_AIRBLAST_UP          100//shift enemy centerpoint this much up for knockback direction
#define FLAMER_AIRBLAST_REPEAT      600
#define FLAMER_AIRBLAST_AMMO        20//ammo gobbled up
#define FLAMER_AIRBLAST_PERIOD      100 //period the airblast can exist for
#define FLAMER_AIRBLAST_SPEED       400//(50 * 1000 / FLAMER_AIRBLAST_PERIOD)//Speed of particle, first number determines the range before the bubble bursts
#define FLAMER_AIRBLAST_RADIUS      150//Radius of Knockback
#define FLAMER_AIRBLAST_SIZE        16.0f//(Square) Radius Size of particle

#define LCANNON_PRICE               600
#define LCANNON_AMMO                90 + (VAMP_ON * 30)
#define LCANNON_REPEAT              1000 //GPP-like secondary
#define LCANNON_K_SCALE             1.0f
#define LCANNON_CHARGEREPEAT        500 //spam-able but does little damge
#define LCANNON_RELOAD              3000
#define LCANNON_DAMAGE              HDM(256 + (VAMP_ON * 32))
#define LCANNON_RADIUS              150 //does nothing now, dynamic explosion radius
#define LCANNON_MIN_RADIUS          50 //minimum radius for lcannon
#define LCANNON_SECONDARY_DAMAGE    HDM(38 + (VAMP_ON * 10))
#define LCANNON_SECONDARY_RADIUS    75 //still applies to secondary
#define LCANNON_SPEED               400 //see g_missile.c, this is minimum speed (roughly), max is about 3x this
#define LCANNON_SECONDARY_SPEED     1800

#define LCANNON_CHARGE_TIME         2500 //In between gpp and 1.1, gpp too long, 1.1 favours spammers, gpp is retardly almost useless in combat againts skilled rants
#define LCANNON_TOTAL_CHARGE        256
#define LCANNON_MIN_CHARGE          27 //mincharge dmg value [50]
#define LCANNON_MAXCLIPS	          0

//Following are rised from '10' to '11' to counter for its extra 10 ammo from its 1.1 edition
//Lolards had "70" and TAKE to 30 which meant values under 70 would not charge completely, and each full shot uses max 30 ammo
//For default gameplay, leave these two identicle, TAKE is a float for calculations in damage and ammo gets rounded off
#define LCANNON_BATTERY_DECAY       11 //The value by which the luci starts struggling to power a full shot
#define LCANNON_TAKE                11.0f //Maximum ammo that can be eaten by one bullet

#define HBUILD_PRICE                0
#define HBUILD_REPEAT               1000 //1000
#define HBUILD_HEALRATE             18

#define HBUILD2_PRICE               0
#define HBUILD2_REPEAT              800 //1000

#define HBUILD_DELAY                17500
#define HBUILD2_DELAY               15000
//Added raw value to build timer, total build time must not be smaller than 0
//#define HBUILD_EXTRA        1000



/*
 * HUMAN upgrades
 */
#define H_WEAP_SWITCH_DELAY         80 //Default start 200
#define H_WEAP_SWITCH_DELAY_END     120 //end default 250
//TODO: Replace with cvar, bg_pmove and trem.h doesn't know from g_main/g_local.h which poses a problem, same for bunnyhop
#define H_WEAP_SWITCH_BENIFIT       400 //Time taken off firing time if you're switching weaps

//misc
#define FASTFIRE                    0 //Allows a short period of fast fire - includes aliens - pre-august default: 200

#define LIGHTARMOUR_PRICE           70
#define LIGHTARMOUR_POISON_PROTECTION 2

#define HELMET_PRICE                90
#define HELMET_RANGE                1000.0f
#define HELMET_POISON_PROTECTION    1 

#define MEDKIT_PRICE                0

#define BATTPACK_PRICE              100
#define BATTPACK_MODIFIER           1.5f + (VAMP_ON * 0.1f)
//battpack can give non-energy weaps extra ammo packs
#define BATTPACK_MODIFIER_NON_ENERGY 1.51f //round up ammo packs

//Non-stationary Jet
#define JETPACK_PRICE               120 
#define JETPACK_FLOAT_SPEED         128.0f
#define JETPACK_SINK_SPEED          192.0f
#define JETPACK_DISABLE_TIME        1450 //Increased caus' goon knockback pushes you up if hit from underside anyway...
#define JETPACK_DISABLE_CHANCE      0.3f //? - never did work, was here before though
#define JETPACK_ACCELERATE          2.0f //default 4
#define JETPACK_FRICTION            1.8f //default 6 apparently

#define BSUIT_PRICE                 400
#define BSUIT_POISON_PROTECTION     4

#define HUMAN_REGEN                 1 + (VAMP_ON * 1) //int, recommended to stay '1' and modify HUMAN_REGEN_MOD instead
#define HUMAN_REGEN_MOD             1.8f //Modifier for human regen per second at 2 health //Try to keep low

#define MGCLIP_PRICE                0

#define CGAMMO_PRICE                0

#define GAS_PRICE                   0

#define MEDKIT_POISON_IMMUNITY_TIME 10000
#define MEDKIT_STARTUP_TIME         4000
#define MEDKIT_STARTUP_SPEED        5


/*
 * HUMAN buildables
 *
 * _BP            - build points required for this buildable
 * _BT            - build time required for this buildable
 * _SPLASHDAMGE   - the amount of damage caused by this buildable when it blows up
 * _SPLASHRADIUS  - the radius around which it does this damage
 *
 * REACTOR_BASESIZE - the maximum distance a buildable can be from an reactor
 * REPEATER_BASESIZE - the maximum distance a buildable can be from a repeaterabout:startpage
 * HUMAN_BHLTH_MODIFIER - overall health modifier for coarse tuning
 *
 * Buildable regeneration speeds are located in bg_misc.c
 */

#define HUMAN_BHLTH_MODIFIER        1.0f
#define HBHM(h)                     ((int)((float)h*HUMAN_BHLTH_MODIFIER))

#define REACTOR_BASESIZE            1000
#define REPEATER_BASESIZE           500
#define HUMAN_DETONATION_DELAY      3000

#define HSPAWN_BP                   10
#define HSPAWN_BT                   10000
#define HSPAWN_HEALTH               HBHM(310)
#define HSPAWN_SPLASHDAMAGE         60
#define HSPAWN_SPLASHRADIUS         100
#define HSPAWN_VALUE                1

#define MEDISTAT_BP                 6 //With 100 bp, you can build an extra turret.
#define MEDISTAT_BT                 8000
#define MEDISTAT_HEALTH             HBHM(190)
#define MEDISTAT_SPLASHDAMAGE       50
#define MEDISTAT_SPLASHRADIUS       100


//NOTE: MASSIVE CHANGE TO THE MACHINE GUN TURRET!
//no spinup required!
//IMPORTANT: You should change MGTURRET_FIRE_SPEED and MGTURRET_FIRE_DIRECT_SPEED to 1 if you want the turret to be 'normal'.
//It slows down the turning speed of the turret when it fires.
#define MGTURRET_FIRE_SPEED         0.5
// IF it is directly aiming at it, the following speed multiplier will be used instead.
//It gives a more realistic feel.
#define MGTURRET_FIRE_DIRECT_SPEED  0.2

#define MGTURRET_BP                 8
#define MGTURRET_BT                 15000
#define MGTURRET_HEALTH             HBHM(190 + (VAMP_ON * 20))
#define MGTURRET_SPLASHDAMAGE       50
#define MGTURRET_SPLASHRADIUS       100
#define MGTURRET_ANGULARSPEED       6
#define MGTURRET_ACCURACYTOLERANCE  MGTURRET_ANGULARSPEED / 1.5f //1.5 angular difference for turret to fire
#define MGTURRET_VERTICALCAP        30
#define MGTURRET_DROOPSCALE         0.25 //droop displacement per droop when unpowered
#define MGTURRET_DROOPRATE          50 //1000/value = droops per second, as well as a repacement for power refreshment time
#define MGTURRET_REPEAT             100
#define MGTURRET_K_SCALE            1.0f
#define MGTURRET_RANGE              400.0f
#define MGTURRET_SPREAD             600 //200
#define MGTURRET_DMG                HDM(6 + (VAMP_ON * 2)) //total damage per shot, keep value even [not odd - it divides the bullet into two]

#define MGTURRET_DCC_ANGULARSPEED       18 //DCCs are now valuable
#define MGTURRET_DCC_ACCURACYTOLERANCE  MGTURRET_DCC_ANGULARSPEED / 1.5f
#define MGTURRET_GRAB_ANGULARSPEED      3
#define MGTURRET_GRAB_ACCURACYTOLERANCE MGTURRET_GRAB_ANGULARSPEED / 1.5f

//sort of a 'proper' version of accuracy tolerance as the pervious one screws up the turret if you raise it.
//This 'range/spread' is a multiplier for the accuracy tolerance before it fires.
//GPP-1.1 change: Raised so it shoots behind target if the target is moving quickly

//Max angle it can fire at [while turning at MGTURRET_FIRE_SPEED]
#define MGTURRET_ACCURACY_SPREAD        12
//Max angle it can fire at [while turning at MGTURRET_FIRE_DIRECT_SPEED]
#define MGTURRET_DIRECT_ACCURACY_SPREAD 3

//this is a mutliplier for the ratio of how fast the pitch goes compare to normal. "Normal" is the same value as for yaw. Yaw will stay as MGTURRET_ANGULARSPEED or whatever if it is grabbed.
//For example, if normal turning speed is 8 without grab or dcc, therefore:
//*1 = normal = 8
//*2 = Fast rise = 16
//*0 = no rise -> erm...
#define MGTURRET_ACCURACY_PITCH         0.3f


#define TESLAGEN_BP                 10
#define TESLAGEN_BT                 17500
#define TESLAGEN_HEALTH             HBHM(220)
#define TESLAGEN_SPLASHDAMAGE       60
#define TESLAGEN_SPLASHRADIUS       100
//Following has been changed so it maintains its damage/s approximate as well as knockback
#define TESLAGEN_REPEAT             100 // 250
#define TESLAGEN_K_SCALE            -5.0f //4f //higher for lower dmg, be cautious of repeat rates though //6->5 for it sends marauders flying everywhere //Reality electricity pulls 5 -> -5
#define TESLAGEN_RANGE              250 + (VAMP_ON * -25) //default 200
#define TESLAGEN_DMG                HDM(4) //default 9

//DCC no longer powers teslas nor heals - it speeds up turrets dramatically. A highly valued structure honestly, no jokes.
#define DC_BP                       8
#define DC_BT                       10000
#define DC_HEALTH                   HBHM(190)
#define DC_SPLASHDAMAGE             50
#define DC_SPLASHRADIUS             100 

#define ARMOURY_BP                  10
#define ARMOURY_BT                  15000
#define ARMOURY_HEALTH              HBHM(480 + (VAMP_ON * 40)) //380 //420 -> 480 for 5 snipes to kill
#define ARMOURY_SPLASHDAMAGE        50
#define ARMOURY_SPLASHRADIUS        100

#define REACTOR_BP                  0
#define REACTOR_BT                  20000
#define REACTOR_HEALTH              HBHM(930)
#define REACTOR_SPLASHDAMAGE        200
#define REACTOR_SPLASHRADIUS        300
#define REACTOR_ATTACK_RANGE        120.0f
#define REACTOR_ATTACK_REPEAT       250 //1000
#define REACTOR_ATTACK_DAMAGE       8 //30
#define REACTOR_VALUE               4

#define REPEATER_BP                 0
#define REPEATER_BT                 10000
#define REPEATER_HEALTH             HBHM(250)
#define REPEATER_SPLASHDAMAGE       50 + (VAMP_ON * 100) //gimmic for fun
#define REPEATER_SPLASHRADIUS       100 + (VAMP_ON * 200)
#define REPEATER_INACTIVE_TIME      180000 

/*
 * HUMAN misc
 * Usually this: (in order) - 1.2f  1.0f  0.8f  0.9f | 25  15  8  4
 */

#define HUMAN_SPRINT_MODIFIER       1.2f
#define HUMAN_JOG_MODIFIER          1.0f
#define HUMAN_BACK_MODIFIER         0.8f
#define HUMAN_SIDE_MODIFIER         0.9f

#define STAMINA_STOP_RESTORE        25
#define STAMINA_WALK_RESTORE        15
#define STAMINA_RUN_RESTORE         3
#define STAMINA_SPRINT_TAKE         6 //8
#define STAMINA_LARMOUR_TAKE        8 //It replaces sprint_take when having larmour. According to g_active.c default is '4' which makes no sense
#define STAMINA_BSUIT_STOP_RESTORE  30
#define STAMINA_BSUIT_WALK_RESTORE  20
#define STAMINA_JUMP                150 //1.1: 500 Lolards: 300
#define STAMINA_MIN_TO_JUMP         0 //Start jumping lower when below this
#define STAMINA_JUMP_CUTOFF         -800 //Absolute Cuttoff point for not being able to jump

#define HUMAN_SPAWN_REPEAT_TIME     10000

/*
 * Misc
 */

#define MIN_FALL_DISTANCE           30.0f
#define MAX_FALL_DISTANCE           720.0f//240 //changed higher because more damage is delt at maximum damage [now 3x normal health]
#define AVG_FALL_DISTANCE           ((MIN_FALL_DISTANCE+MAX_FALL_DISTANCE)/2.0f)

#define HUMAN_MAXED                 1200   //default 900 //change in according to ALIEN_MAX_SINGLE_KILLS
#define HUMAN_MAX_CREDITS           2000
#define ALIEN_MAX_KILLS             9
#define ALIEN_MAX_SINGLE_KILLS      4 //Max evos earned from HUMAN_MAXED 3->4

#define FREEKILL_PERIOD             90000
#define FREEKILL_ALIEN              1
#define FREEKILL_HUMAN              LEVEL0_VALUE //1 cred given every 0.5 secs
#define FREEKILL_PERIOD_H           90000/FREEKILL_HUMAN //500msec

//Clipping Exploit
//#define PLAYER_CLIP_VEL_TIME        300//time to allow sliding past walls cpm-style

//Raised thresholds
#define DEFAULT_ALIEN_BUILDPOINTS   "140"
#define DEFAULT_ALIEN_STAGE2_THRESH "35"
#define DEFAULT_ALIEN_STAGE3_THRESH "70"
#define DEFAULT_ALIEN_MAX_STAGE     "2"
#define DEFAULT_HUMAN_BUILDPOINTS   "140"
#define DEFAULT_HUMAN_STAGE2_THRESH "35"
#define DEFAULT_HUMAN_STAGE3_THRESH "70"
#define DEFAULT_HUMAN_MAX_STAGE     "2"

#define DAMAGE_FRACTION_FOR_KILL    0.5f

//Vampire mode settings
//see g_combat.c for the equation.
//TODO: Remove VAMP_ON completely from the source, we have g_mode_vampire now

#define VAMP_ON                     0.0f //Used to balance some things above and enables/disables vampire mode
                                      //Use '1.0f' or '0.0f' only, set as a float for misc purpouses

#define VAMP_EXTRA                  50 //extra "health" [before modding] added to self
#define VAMP_TAKE_MULTIPLIER        (1.00f/**(VAMP_ON)*//600) //see g_combat.c why it needs to be a small number
                                    //Do not use floating values when turned off! Use (1.00f*(VAMP_ON)/600) when on.
#define VAMP_DIVIDE                 10   //10 //Confusing, recommended to leave as is.
#define VAMP_TAKE                   6.25 //6.25 //Confusing, recommended to leave as is. Basically at MAX-vamp'd health, you lose 4 times as much as you would with 25% vamp'd health. The higher the value, the less health drained/s.
#define VAMP_INIT_HEALTH            1.00 //Spawn with this health, useful to prevent spawn camping free frags from dragoons
                                         //vq3 default 1.25, promode default 1.00
                                       //Human max extra health is 50, so it takes 8 hp/s at most...
                                       //TODO: Buggy, causes server to freeze upon spawning
                                       //Problem: Code is nearly identicle to Q3's, wth's the problem?
#define MAX_MAX_HEALTH              2.0f//1.0f + (VAMP_ON * 1.0f) //Absolute Max health cap for players, health gets rounded immediately down to this multiplier of their default health

//medkits extras
#define MEDKIT_OVERHEAL             0.9f + (VAMP_ON * 0.1f) //yes > 1.0f | no = 1.0f | L4D-like = 0.8
                                         //note: this value * MAX_MAX_HEALTH * player's max health
#define MEDKIT_EXTRA                10 + (VAMP_ON * 20) //Extra raw health added to medkit.

// g_suddenDeathMode settings
#define SDMODE_BP                   ( REPEATER_BP + ARMOURY_BP + DC_BP + MEDISTAT_BP )
#define SDMODE_NO_BUILD             0
#define SDMODE_SELECTIVE            0
