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
#define ALIENREGEN_NOCREEP_MOD      0.5f //out of creep modifier

#define ABUILDER_BUILD_REPEAT       500
#define ABUILDER_CLAW_DMG           ADM(20 + (VAMP_ON * 10)) //20) //still 3 hit kill with new armour system... (head mod = 1.8)
#define ABUILDER_CLAW_RANGE         78.0f //64f
#define ABUILDER_CLAW_WIDTH         4.0f //4f
#define ABUILDER_CLAW_REPEAT        1000
#define ABUILDER_BASE_CLAW_REPEAT   1000
#define ABUILDER_CLAW_K_SCALE       0.0f
#define ABUILDER_BASE_DELAY         15000 //17000
#define ABUILDER_ADV_DELAY          12000 //12000 //8000->10000 to fix build timer vs build time of overmind

#define ABUILDER_BLOB_DMG           ADM(4)//4 -> 6
#define ABUILDER_BLOB_SPLASH_DMG    ADM(4)//Explosion damage //15
#define ABUILDER_BLOB_RADIUS        75     //explosion radius //75
#define ABUILDER_BLOB_REPEAT        1000 //500->800
#define ABUILDER_BLOB_SPEED         780.0f //800 -> 780 to match grenade
#define ABUILDER_BLOB_SPEED_MOD     0.5f
#define ABUILDER_BLOB_LIFETIME      ABUILDER_BLOB_REPEAT*3.5//Blob lifetime before exploding on its own; default is 5000 seconds, but you dont want a minefield of them because they get OP againts big guys
#define ABUILDER_BLOB_TIME          5000 //5000 how long a guy gets slowed down //5000 -> 8000

#define LEVEL0_BITE_DMG             ADM(36)
#define LEVEL0_BITE_RANGE           64.0f
#define LEVEL0_BITE_WIDTH           1.0f //6f
#define LEVEL0_BITE_REPEAT          500 //500 //333 makes stronger againts stationary camptards
#define LEVEL0_BITE_K_SCALE         1.0f
//Disabled (range), although animation still runs [and stuns the user]
//ignore this, disabled via bg_misc.c
#define LEVEL0_SCRATCH_DMG          ADM(48) //ADM(6 + (VAMP_ON * -3))//dispite this, it is actually almost overpowered.
#define LEVEL0_SCRATCH_REPEAT       0//150
#define LEVEL0_SCRATCH_RANGE        80 //disabled, was 80
#define LEVEL0_SCRATCH_WIDTH        3

#define LEVEL1_CLAW_DMG             ADM(32 + (VAMP_ON * 5))
#define LEVEL1_CLAW_RANGE           80.0f//Take unv's
#define LEVEL1_CLAW_WIDTH           10.0f
#define LEVEL1_CLAW_REPEAT          700
#define LEVEL1_CLAW_U_REPEAT        600
#define LEVEL1_CLAW_K_SCALE         0.0f
#define LEVEL1_CLAW_U_K_SCALE       0.0f
#define LEVEL1_GRAB_RANGE           80.0f//Take unv's
#define LEVEL1_GRAB_TIME            300 //Time for you to re-grab if you mis-aim again
#define LEVEL1_GRAB_U_TIME          450
#define LEVEL1_PCLOUD_DMG           ADM(0 + (VAMP_ON * 5)) //Nay, it still deals 1 dmg. Oh well, it isn't that significant.
#define LEVEL1_PCLOUD_RANGE         200.0f //300 //limit troll gassers
#define LEVEL1_PCLOUD_REPEAT        2000
#define LEVEL1_PCLOUD_TIME          10000 //GPP - 2 seconds distortion, 5 seconds slowlock i think
                                          //TODO: Slowlock effect cannot be applied at the same time

#define LEVEL2_CLAW_DMG             ADM(40)
#define LEVEL2_CLAW_RANGE           80.0f //96 //longest range, since mar is glass cannon
#define LEVEL2_CLAW_WIDTH           12.0f //Normal mara is hard to use
#define LEVEL2_CLAW_U_WIDTH         14.0f //
#define LEVEL2_CLAW_REPEAT          500 //
#define LEVEL2_CLAW_U_REPEAT        400 //
//ATTENTION! If you want to disabled the claw knockback only (leave zap knockback on), set CLAW_K_REVERSE to "0"
//If you want the opposite, turn the AREAZAP_K_SCALE to "0", CLAW_(U_)K_SCALE to "0.1" and CLAW_K_REVERSE to "-10.0f" (doesn't completely cancel out the first zap victim's pull effect though, but it shouldn't be noticable)
#define LEVEL2_CLAW_K_SCALE         1.0f //effects first zap victim as well apparently
#define LEVEL2_CLAW_U_K_SCALE       1.0f
#define LEVEL2_CLAW_K_REVERSE       -1.0f//For claws only

//Note: Full dmg depends on sv_fps if LEVEL2_AREAZAP_TIME > 1
#define LEVEL2_AREAZAP_DMG          ADM(70 + (VAMP_ON * 20)) //4 zaps on teslas
#define LEVEL2_AREAZAP_RANGE        200.0f //initiate zap distance
#define LEVEL2_AREAZAP_RANGE_SUSTAIN 400 //Range to allow sustaining the zap
#define LEVEL2_AREAZAP_WIDTH        8.0f //harder to zap around corners
#define LEVEL2_AREAZAP_REPEAT       1500
#define LEVEL2_AREAZAP_TIME         1000  //Divide by 0 fixed
					//TODO: Allow graphics to continue running despite chain cut off early
#define LEVEL2_AREAZAP_MAX_TARGETS  5
#define LEVEL2_WALLJUMP_MAXSPEED    90000.0f //1290.0f //idk, don't really want a max
#define LEVEL2_AREAZAP_K_SCALE      -3.5f //Chain-ees get pulled together with this

//Goon modified heavily to get close to gpp values.
#define LEVEL3_CLAW_DMG             ADM(80 + (VAMP_ON * 10))
#define LEVEL3_CLAW_RANGE           80.0f //Unv's
#define LEVEL3_CLAW_WIDTH           12.0f
#define LEVEL3_CLAW_REPEAT          800 //1.1 700 1.2 900 //'Unv's value is more stable
#define LEVEL3_CLAW_K_SCALE         0.8f //effects pounce as well
#define LEVEL3_CLAW_U_REPEAT        700 //600 800 //'Unv's value is more stable
#define LEVEL3_CLAW_U_K_SCALE       0.8f
#define LEVEL3_POUNCE_DMG           ADM(115 + (VAMP_ON * 20)) // -> 115 (bsuits take the same damage as laroured)
					//Armour - 3 hit
					//Helm - 2 hit
					//Larm+Helm -or- bsuit - 5 hit
#define LEVEL3_POUNCE_RANGE         42.0f //No more long range, reaches diagonally towards tip of bbox perfectly
#define LEVEL3_POUNCE_WIDTH         27.0f //default 16. //Widened for realism
#define LEVEL3_POUNCE_SPEED         700 
#define LEVEL3_POUNCE_UPG_SPEED     800 
#define LEVEL3_POUNCE_SPEED_MOD     0.75f 
#define LEVEL3_POUNCE_CHARGE_TIME   700 
#define LEVEL3_POUNCE_TIME          400 //delay after touching ground?!?
#define LEVEL3_BOUNCEBALL_DMG       ADM(110)

#define LEVEL3_BOUNCEBALL_AMMO      3
#define LEVEL3_BOUNCEBALL_REPEAT    1000
#define LEVEL3_BOUNCEBALL_SPEED     1000.0f
#define LEVEL3_BOUNCEBALL_SPLASH_DMG  76 //Honestly, i don't like the overpowered snipe. 110 -> 76
#define LEVEL3_BOUNCEBALL_SPLASH_RADIUS 92 //Splash radius. Helps with sniping. //Rememeber that reload time is 10 seconds. You don't want it overpowered.  //TODO: Reload up to 20 seconds

#define LEVEL4_CLAW_DMG             ADM(100)
#define LEVEL4_CLAW_RANGE           96.0f //128 //80 feels useless [unv]
#define LEVEL4_CLAW_WIDTH           16.0f //20 //18
#define LEVEL4_CLAW_REPEAT          750 //750 //keep at 1.1 value, otherwise people will charge-spam only
#define LEVEL4_CLAW_K_SCALE         0.8f //
#define LEVEL4_REGEN_RANGE          200.0f //usually goes unnoticed, left default
#define LEVEL4_REGEN_MOD            1.5f //No more hall camping hopefully. I've swapped boosting priorities so rants should benifit from boosters
#define LEVEL4_CHARGE_SPEED         2.0f //2.5 is easier to move with
#define LEVEL4_CHARGE_TIME          4000 //2000 
#define LEVEL4_CHARGE_CHARGE_TIME   4000 //1500 
#define LEVEL4_CHARGING_CHARGE_TIME   2000 //Okay, this is fucked up.
#define LEVEL4_CHARGE_TAKE          100 //Charge taken per decasecond. Default is 100.
#define LEVEL4_TRAMPLE_CHARGE       200//Charging Charge per decasecond. Default 100.   
#define LEVEL4_MIN_CHARGE_TIME      750
#define LEVEL4_CHARGE_CHARGE_RATIO  (LEVEL4_CHARGE_TIME/LEVEL4_CHARGE_CHARGE_TIME)//(LEVEL4_CHARGE_CHARGE_TIME/LEVEL4_CHARGE_TIME)//(LEVEL4_CHARGE_TIME/LEVEL4_CHARGE_CHARGE_TIME) //confusing shit, it's an interger so below 1 and it's fked

#define LEVEL4_CHARGE_REPEAT        150 //1000 //GPP uses '100', the more lower, the more ping-bias
#define LEVEL4_CHARGE_DMG           ADM(56 + (VAMP_ON * 35)) //100 (to help with armoured)
					//0.2s naked
					//~0.4s helm
					//~0.6s larm
					//~0.9s larm+helm [Bsuit not tested, but bsuit should be the same as this]
//Removed tyrant spit bomb

#define LEVEL4_CHARGE_EXTRA         ADM(15) //Extra damage added to charge so it isnt completely useless when slow
#define LEVEL4_TRAMPLE_DMG_B        (0.35f * (VAMP_ON * 0.85)) //Dmg multiplier to buildables    


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
#define ABUILDER_HEALTH             AHM(50)
#define ABUILDER_REGEN              2
#define ABUILDER_COST               0

#define ABUILDER_UPG_SPEED          1.0f
#define ABUILDER_UPG_VALUE          AVM(220) //limit battlegrangers' reward because of newbies
#define ABUILDER_UPG_HEALTH         AHM(75)
#define ABUILDER_UPG_REGEN          3
#define ABUILDER_UPG_COST           0

#define LEVEL0_SPEED                1.4f
#define LEVEL0_VALUE                AVM(180)
#define LEVEL0_HEALTH               AHM(25)
#define LEVEL0_REGEN                1
#define LEVEL0_COST                 0

#define LEVEL1_SPEED                1.2f
#define LEVEL1_VALUE                AVM(260)
#define LEVEL1_HEALTH               AHM(60)
#define LEVEL1_REGEN                2
#define LEVEL1_COST                 1
#define LEVEL1_REGEN_MOD            2.0f

#define LEVEL1_UPG_SPEED            1.2f
#define LEVEL1_UPG_VALUE            AVM(275)
#define LEVEL1_UPG_HEALTH           AHM(80)
#define LEVEL1_UPG_REGEN            3
#define LEVEL1_UPG_COST             1
#define LEVEL1_UPG_REGEN_MOD        3.0f

#define LEVEL2_SPEED                1.2f
#define LEVEL2_VALUE                AVM(380)
#define LEVEL2_HEALTH               AHM(150)
#define LEVEL2_REGEN                4
#define LEVEL2_COST                 1

#define LEVEL2_UPG_SPEED            1.3f
#define LEVEL2_UPG_VALUE            AVM(430)
#define LEVEL2_UPG_HEALTH           AHM(175)
#define LEVEL2_UPG_REGEN            5
#define LEVEL2_UPG_COST             1

#define LEVEL3_SPEED                1.1f
#define LEVEL3_VALUE                AVM(575)
#define LEVEL3_HEALTH               AHM(200)
#define LEVEL3_REGEN                6
#define LEVEL3_COST                 1

#define LEVEL3_UPG_SPEED            1.1f
#define LEVEL3_UPG_VALUE            AVM(650)
#define LEVEL3_UPG_HEALTH           AHM(250)
#define LEVEL3_UPG_REGEN            7
#define LEVEL3_UPG_COST             1

#define LEVEL4_SPEED                1.1f //1.2f
#define LEVEL4_VALUE                AVM(800)
#define LEVEL4_HEALTH               AHM(375)
#define LEVEL4_REGEN                8
#define LEVEL4_COST                 2

//Basi-Suit
//disabled because this isn't Lolards
#define SPY_SPEED                   1.0f //human sprinting speed //1.0 is really hard to get to a human with quietly, but 1.3f won't override for client, reverted
#define SPY_HEALTH                  300 //still OP unless you happen to get head-shotted by a luci
#define SPY_VALUE                   720
#define SPY_COST                    9
#define SPY_REGEN                   (9 + + (VAMP_ON * -6)) //only regen 3 hp/s with vampire mode on

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
#define BOOSTER_CREEPSIZE           120 //also the size of the area it heals players
#define BOOSTER_INTERVAL            10000 //time in msec between recharges per player
#define BOOSTER_REGEN_MOD           3.0f //2 - > 3 Make boosted healing more noticable
#define BOOST_TIME                  30000 //Default - 30000, gpp - 20000 but hate gpp values

#define ACIDTUBE_BP                 6     //I don't fucking care about gpp value, these tubes are useless.
#define ACIDTUBE_BT                 12000
#define ACIDTUBE_HEALTH             ABHM(125) //default 125
#define ACIDTUBE_REGEN              4
#define ACIDTUBE_SPLASHDAMAGE       8 //Don't get confused this with other splash damages, the others apply to exploding...
#define ACIDTUBE_SPLASHRADIUS       400 //bring higher to near-unite turret range so they're not so shit
#define ACIDTUBE_CREEPSIZE          120
#define ACIDTUBE_RANGE              350.0f //200 //YADAHAHAHAHA I DIDNT HEAR ANYTHING
#define ACIDTUBE_REPEAT             2000 //Re-trigger delay
#define ACIDTUBE_K_SCALE            0.1f //1f //Nay, does not work.

#define HIVE_BP                     12
#define HIVE_LIFETIME               12000
#define HIVE_BT                     15000
#define HIVE_HEALTH                 ABHM(150) //default 125 //Urasai urasai urasai! Hives are weaklings!
#define HIVE_REGEN                  5
#define HIVE_SPLASHDAMAGE           0 //Splash damage for insectoid death
#define HIVE_SPLASHRADIUS           0 //Disabled
#define HIVE_CREEPSIZE              120
#define HIVE_RANGE                  900.0f //300 Higher! Bring em higher! The only structure to shoot such long range!
#define HIVE_REPEAT                 1500 //Insectoid Re-send time //2500 -> 1500 so not so useless close-range
#define HIVE_K_SCALE                -1.0f //Reel 'em in boys!
#define HIVE_DMG                    80
#define HIVE_SPEED                  380.0f //deal with jettards and sprinters
#define HIVE_DIR_CHANGE_PERIOD      500
#define HIVE_HIVE_STUN              500//Stun time from insectoid death and rebirth

#define TRAPPER_BP                  8
#define TRAPPER_BT                  12000
#define TRAPPER_HEALTH              ABHM(50)
#define TRAPPER_REGEN               3
#define TRAPPER_SPLASHDAMAGE        50
#define TRAPPER_SPLASHRADIUS        50
#define TRAPPER_CREEPSIZE           30
#define TRAPPER_RANGE               300
#define TRAPPER_REPEAT              1000
#define TRAPPER_K_SCALE             1.0f
#define LOCKBLOB_SPEED              650.0f
#define LOCKBLOB_LOCKTIME           0 // /d/hc will complain
#define LOCKBLOB_LIFETIME           6000 //Locktime
#define LOCKBLOB_DOT                0.85f // max angle = acos( LOCKBLOB_DOT )
#define LOCKBLOB_K_SCALE            -1.0f
#define LOCKBLOB_DMG                0 //Don't. /d/hc will complain.

#define OVERMIND_BP                 0
#define OVERMIND_BT                 20000
#define OVERMIND_HEALTH             ABHM(780)
#define OVERMIND_REGEN              16 //Chill bro. Not too fast.
#define OVERMIND_SPLASHDAMAGE       18
#define OVERMIND_SPLASHRADIUS       300
#define OVERMIND_CREEPSIZE          120
#define OVERMIND_ATTACK_RANGE       150.0f
#define OVERMIND_ATTACK_REPEAT      800 //OM on Steroids
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
#define ALIEN_POISON_DMG            5
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

#define BLASTER_REPEAT              700
#define BLASTER_K_SCALE             1.0f 
#define BLASTER_SPREAD              0
#define BLASTER_SPEED               1400
#define BLASTER_DMG                 HDM(9)
#define BLASTER_PUSH                100//Blasterjump effect, this is the actual damage before modding
#define BLASTER_DMG_MOD             0.08f //Modifier for above damage
#define BLASTER_RADIUS              100
//Ignnore this, disabled via bg_misc.c
#define BLASTER_MELEE               18 //not too high because it would be overpowered
#define BLASTER_MELLEE_REPEAT       0//700 //mellee rate
#define BLASTER_MELEE_RANGE         60 //enough for combat
//Prevent Blaster Spamming
#define BLASTER_CLIPSIZE            6
#define BLASTER_MAXCLIPS            0
#define BLASTER_INF_AMMO            qtrue //qtrue

#define RIFLE_CLIPSIZE              30
#define RIFLE_MAXCLIPS              6
#define RIFLE_REPEAT                90 //use unv's value for tackling bigger aliens quicker
#define RIFLE_K_SCALE               1.0f
#define RIFLE_RELOAD                2000
#define RIFLE_PRICE                 0
#define RIFLE_SPREAD                170
#define RIFLE_DMG                   HDM(5) //'6' seems ok, although some australians say it is overepowered

#define PAINSAW_PRICE               100
#define PAINSAW_REPEAT              65 
#define PAINSAW_K_SCALE             1.0f
#define PAINSAW_DAMAGE              HDM(12) //~>185 dmg/s
#define PAINSAW_RANGE               60.0f //enough to touch below feet of a normal human without being OP [unlike gpp]
//Following disabled via bg_misc.c
#define PAINSAW_NODECAY             qtrue //Bleed ammo one per second if nodecay is qfalse
#define PAINSAW_FUEL                0
#define PAINSAW_BATTERIES           0 //not compatable with battery decay system, don't bother
#define PAINSAW_RELOAD              3000

#define GRENADE_PRICE               200
#define GRENADE_REPEAT              0
#define GRENADE_K_SCALE             1.0f
#define GRENADE_DAMAGE              HDM(310)
#define GRENADE_RANGE               192.0f
#define GRENADE_SPEED               400.0f

#define SHOTGUN_PRICE               150
#define SHOTGUN_SHELLS              8
#define SHOTGUN_PELLETS             8 //5 * 11 is gpp, 4 * 14 is 1.1, 7 * 8 is tremfusion
#define SHOTGUN_MAXCLIPS            3
#define SHOTGUN_REPEAT              1000
#define SHOTGUN_K_SCALE             2.0f
#define SHOTGUN_RELOAD              2000 //( SHOTGUN_SHELLS * 400 + 800 )
#define SHOTGUN_SPREAD              900
#define SHOTGUN_DMG                 HDM(7) //4 per dretch

//Stuns the player a little, yet more "accurate" for mid ranges
//Disabled via bg_misc.c
#define SHOTGUN_BLAST               38
#define SHOTGUN_BLAST_RANGE         350
#define SHOTGUN_BLAST_REPEAT        0//1500
//#define SHOTGUN_BLAST_PELLETS       SHOTGUN_SHELLS  //Number of shells per clip, since if i use shells * pellets, the client would fk up
#define SHOTGUN_BLAST_PELLET_DMG    3
#define SHOTGUN_BLAST_SPREAD        500

#define LASGUN_PRICE                250
#define LASGUN_AMMO                 200
#define LASGUN_REPEAT               200
#define LASGUN_MAXCLIPS             0
#define LASGUN_K_SCALE              1.0f
#define LASGUN_RELOAD               3000
#define LASGUN_SPREAD               100 //btw, this actually works, don't tweak it any higher or it'll effect gameplay too much
#define LASGUN_DAMAGE               HDM(9)

#define MDRIVER_PRICE               350
#define MDRIVER_CLIPSIZE            5
#define MDRIVER_MAXCLIPS            4
#define MDRIVER_DMG                 HDM(40)
#define MDRIVER_REPEAT              1000
#define MDRIVER_K_SCALE             1.0f
#define MDRIVER_RELOAD              2000
//bullet physics stuff
#define MDRIVER_SPEED               19200 //Bullet speed 19200 = 600 m/s
#define MDRIVER_RADIUS              0 //explosion radius
#define MDRIVER_SPLASH              0 //Splash dmg
#define MDRIVER_LAG                 0.35f //Same effect as Flamer_LAG but not as effective
#define MDRIVER_LIFETIME            8000 //It's a pretty fast bullet. Doesn't need a long lifetime

#define CHAINGUN_PRICE              400
#define CHAINGUN_BULLETS            300
#define CHAINGUN_MAXCLIPS           0
#define CHAINGUN_RELOAD             5000
#define CHAINGUN_REPEAT             80 //Single barrel shots
#define CHAINGUN_REPEAT2            100 //tripple shots [TF2-like], total damage per shot stays the same
#define CHAINGUN_K_SCALE            1.0f
#define CHAINGUN_SPREAD             700
#define CHAINGUN_SPREAD2            1200 //Anti-Dretch n00b edition
#define CHAINGUN_DMG                HDM(6)

#define PRIFLE_PRICE                450
#define PRIFLE_CLIPS                50 //love ya 1.1 <3
#define PRIFLE_MAXCLIPS             4
#define PRIFLE_REPEAT               90
#define PRIFLE_K_SCALE              1.0f
#define PRIFLE_RELOAD               2000
#define PRIFLE_DMG                  HDM(9)
#define PRIFLE_SPEED                1400 //1.1 uses 1000, gpp uses blaster speed

//fixed flamer-wall bug from tremulous
#define FLAMER_PRICE                450
#define FLAMER_GAS                  400 //Double fire rate, halve damage.
#define FLAMER_RELOAD               3000
#define FLAMER_REPEAT               100 //Let's be realistic here.
#define FLAMER_K_SCALE              2.0f //gpp says, not me
#define FLAMER_DMG                  HDM(10) //^^
#define FLAMER_DMG_MOD              0.5f//Same deal as blaster, this one allows wall climbing.
#define FLAMER_RADIUS_MOD           2.0f //splash damage mod //Previous variable cancels out this one
#define FLAMER_RADIUS               50
#define FLAMER_LIFETIME             800.0f //Apparently gpp uses 700 and double knockback...
#define FLAMER_SPEED                400.0f
#define FLAMER_LAG                  0.65f

#define LCANNON_PRICE               600
#define LCANNON_AMMO                90
#define LCANNON_REPEAT              1000 //GPP-like secondary
#define LCANNON_K_SCALE             1.0f
#define LCANNON_CHARGEREPEAT        500 //spam-able but does little damge
#define LCANNON_RELOAD              3000
#define LCANNON_DAMAGE              HDM(256)
#define LCANNON_RADIUS              150 //does nothing now, dynamic explosion radius
#define LCANNON_SECONDARY_DAMAGE    HDM(38)
#define LCANNON_SECONDARY_RADIUS    75 //still applies to secondary
#define LCANNON_SPEED               400 //see g_missile.c, this is minimum speed, max is about 3x this
#define LCANNON_SECONDARY_SPEED     1800

#define LCANNON_CHARGE_TIME         2500 //In between gpp and 1.1, gpp too long, 1.1 favours spammers, gpp is retardly almost useless in combat againts rants
#define LCANNON_TOTAL_CHARGE        256
#define LCANNON_MIN_CHARGE          27 //mincharge dmg value [50]
#define LCANNON_MAXCLIPS	    0

//Following are rised from '10' to '11' to counter for its extra 10 ammo from its 1.1 edition
#define LCANNON_BATTERY_DECAY       11 //The value by which the luci starts struggling to power a full shot
#define LCANNON_TAKE                11.0f //Maximum ammo that can be eaten by one bullet

//Lockblob Launcher
//Disabled cause this aint lolards
#define LOCKBLOB_AMMO               12
#define LOCKBLOB_MAXCLIPS           9
#define LOCKBLOB_NUKE_REPEAT        2500 //Primary is declared in the alien buildable section for trapper
#define AUTOSHOTTY_REPEAT           200
#define AUTOSHOTTY_PELLET1          5   //Dmg for pellet '1', most accurate
#define AUTOSHOTTY_PELLET2          3   //Dmg for pellet '2', inaccurate accurate
#define AUTOSHOTTY_PELLET3          1   //Dmg for pellet '1', most inaccurate accurate

#define HBUILD_PRICE                0
#define HBUILD_REPEAT               1000 //1000
#define HBUILD_DELAY                17500 //17500
#define HBUILD_HEALRATE             18

#define HBUILD2_PRICE               0
#define HBUILD2_REPEAT              800 //1000
#define HBUILD2_DELAY               15000 //15000


/*
 * HUMAN upgrades
 */
#define H_WEAP_SWITCH_DELAY         50//Default 200 //Allow weapon combos
//TODO: Replace with cvar, g_pmove and trem.h doesn't know from g_main/g_local.h which poses a problem, same for bunnyhop
#define BUNNYHOP_TRUE               1 //Off = 0 on == 1

#define LIGHTARMOUR_PRICE           70
#define LIGHTARMOUR_POISON_PROTECTION 2

#define HELMET_PRICE                90
#define HELMET_RANGE                1000.0f
#define HELMET_POISON_PROTECTION    1 

//medkit price
#define MEDKIT_PRICE                0

#define BATTPACK_PRICE              100
#define BATTPACK_MODIFIER           1.5f

//Non-stationary Jet
#define JETPACK_PRICE               120 
#define JETPACK_FLOAT_SPEED         128.0f
#define JETPACK_SINK_SPEED          192.0f
#define JETPACK_DISABLE_TIME        1250 //Increased to 1250 caus' goon knockback pushes you up if hit from underside anyway...
#define JETPACK_DISABLE_CHANCE      0.3f //? - doesn't work
#define JETPACK_ACCELERATE          2.00f
#define JETPACK_FRICTION            1.8f

#define BSUIT_PRICE                 400
#define BSUIT_POISON_PROTECTION     4
#define HUMAN_REGEN                 1 //int (per ALIENREGEN_NOCREEP_MOD) per second

#define MGCLIP_PRICE                0

#define CGAMMO_PRICE                0

#define GAS_PRICE                   0

#define MEDKIT_POISON_IMMUNITY_TIME 5000
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
#define MGTURRET_FIRE_SPEED         0.6
// IF it is directly aiming at it, the following speed multiplier will be used instead.
//It gives a more realistic feel.
#define MGTURRET_FIRE_DIRECT_SPEED  0.3

#define MGTURRET_BP                 8
#define MGTURRET_BT                 10000
#define MGTURRET_HEALTH             HBHM(190)
#define MGTURRET_SPLASHDAMAGE       50 //50
#define MGTURRET_SPLASHRADIUS       100
#define MGTURRET_ANGULARSPEED       5
#define MGTURRET_ACCURACYTOLERANCE  MGTURRET_ANGULARSPEED / 1.5f //1.5 angular difference for turret to fire
#define MGTURRET_VERTICALCAP        30
#define MGTURRET_DROOPSCALE         0.25 //droop displacement per droop when unpowered
#define MGTURRET_DROOPRATE          50 //1000/value = droops per second, as well as a repacement for power refreshment time
#define MGTURRET_REPEAT             100
#define MGTURRET_K_SCALE            1.0f
#define MGTURRET_RANGE              400.0f
#define MGTURRET_SPREAD             600 //200 is aimbot
#define MGTURRET_DMG                HDM(8) //total damage per shot, keep value even [not odd]
#define MGTURRET_DCC_ANGULARSPEED       13 //DCCs are now valuable
#define MGTURRET_DCC_ACCURACYTOLERANCE  MGTURRET_DCC_ANGULARSPEED / 1.5f
#define MGTURRET_GRAB_ANGULARSPEED      3
#define MGTURRET_GRAB_ACCURACYTOLERANCE MGTURRET_GRAB_ANGULARSPEED / 1.5f

//sort of a 'proper' version of accuracy tolerance as the pervious one screws up the turret if you raise it.
//This 'range/spread' is a multiplier for the accuracy tolerance before it fires.
//GPP-1.1 change: Raised so it shoots behind target if the target is moving quickly

//Max angle it can fire at [while turning at MGTURRET_FIRE_SPEED]
#define MGTURRET_ACCURACY_SPREAD        12 //8
//Max angle it can fire at [while turning at MGTURRET_FIRE_DIRECT_SPEED]
#define MGTURRET_DIRECT_ACCURACY_SPREAD 5  //3

//this is a mutliplier for the ratio of how fast the pitch goes compare to normal. "Normal" is the same value as for yaw. Yaw will stay as MGTURRET_ANGULARSPEED or whatever if it is grabbed.
//For example, normal turning speed is 8 without grab or dcc, therefore:
//*1 = normal = 8
//*2 = Fast rise = 16
//*0 = no rise -> erm...
#define MGTURRET_ACCURACY_PITCH         0.5f //Old Lolards - 0.8


#define TESLAGEN_BP                 10
#define TESLAGEN_BT                 17500
#define TESLAGEN_HEALTH             HBHM(220)
#define TESLAGEN_SPLASHDAMAGE       60
#define TESLAGEN_SPLASHRADIUS       100
//Following has been changed so it maintains its damage/s approximate as well as knockback
#define TESLAGEN_REPEAT             100 // 250
#define TESLAGEN_K_SCALE            5.0f //4f //higher for lower dmg, be cautious of repeat rates though //6->5 for it sends marauders flying everywhere
#define TESLAGEN_RANGE              280 //default 200
#define TESLAGEN_DMG                HDM(4) //default 9

//DCC no longer powers teslas nor heals - it speeds up turrets dramatically. A highly valued structure honestly, no jokes.
#define DC_BP                       8
#define DC_BT                       10000
#define DC_HEALTH                   HBHM(190)
#define DC_SPLASHDAMAGE             50
#define DC_SPLASHRADIUS             100 

#define ARMOURY_BP                  10
#define ARMOURY_BT                  15000
#define ARMOURY_HEALTH              HBHM(480) //380 //420 -> 480 for 4 snipes to kill
#define ARMOURY_SPLASHDAMAGE        50
#define ARMOURY_SPLASHRADIUS        100

#define REACTOR_BP                  0
#define REACTOR_BT                  20000
#define REACTOR_HEALTH              HBHM(930)
#define REACTOR_SPLASHDAMAGE        200
#define REACTOR_SPLASHRADIUS        300
#define REACTOR_ATTACK_RANGE        120.0f
#define REACTOR_ATTACK_REPEAT       125 //1000
#define REACTOR_ATTACK_DAMAGE       6 //30
#define REACTOR_VALUE               4

#define REPEATER_BP                 0
#define REPEATER_BT                 10000
#define REPEATER_HEALTH             HBHM(250)
#define REPEATER_SPLASHDAMAGE       50
#define REPEATER_SPLASHRADIUS       100
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
#define STAMINA_SPRINT_TAKE         8
#define STAMINA_LARMOUR_TAKE        8 //It replaces sprint_take when having larmour. According to g_active.c default is '4' which makes no sense

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
#define ALIEN_MAX_SINGLE_KILLS      4 //Max evos earned from HUMAN_MAXED i guess... i never looked into this //3->4

#define FREEKILL_PERIOD             90000
#define FREEKILL_ALIEN              1
#define FREEKILL_HUMAN              LEVEL0_VALUE

//Raised thresholds
#define DEFAULT_ALIEN_BUILDPOINTS   "150"
#define DEFAULT_ALIEN_STAGE2_THRESH "35"
#define DEFAULT_ALIEN_STAGE3_THRESH "90"
#define DEFAULT_ALIEN_MAX_STAGE     "2"
#define DEFAULT_HUMAN_BUILDPOINTS   "100"
#define DEFAULT_HUMAN_STAGE2_THRESH "35"
#define DEFAULT_HUMAN_STAGE3_THRESH "90"
#define DEFAULT_HUMAN_MAX_STAGE     "2"

#define DAMAGE_FRACTION_FOR_KILL    0.5f

//Vampire mode settings
//see g_combat.c for the equation.

#define VAMP_ON                     0 //Used to balance some things above and enables/disables vampire mode
                                      //Use '1' or '0' only

#define VAMP_EXTRA                  50 //extra "health" [before modding] added to self
#define VAMP_TAKE_MULTIPLIER        (1.00f*(VAMP_ON)/600) //see g_combat.c why it needs to be a small number
                                    //Do not use floating values when turned off! Use (1.00f*(VAMP_ON)/600) when on.
#define VAMP_DIVIDE                 10   //
#define VAMP_TAKE                   6.25 //6.25 //Confusing, recommended to leave as is. Basically at MAX-vamp'd health, you lose 4 times as much as you would with 25% vamp'd health
                                       //Human max extra health is 50, so it takes 8 hp/s at most...
#define MAX_MAX_HEALTH              1.0f //Max health for players * this = Max vamped health, in this case its 1+(if vamp is on/off [1/0]*0.5) = 1.5x normal max health
//medkits extras
#define MEDKIT_OVERHEAL             1.0f //yes > 1.0f | no = 1.0f | little = 1.2f | L4D-like = 0.8
                                         //note: this value * MAX_MAX_HEALTH * player's max health
#define MEDKIT_EXTRA                0 //Extra raw health added to medkit.

// g_suddenDeathMode settings
#define SDMODE_BP                   ( REPEATER_BP + ARMOURY_BP + DC_BP + MEDISTAT_BP )
#define SDMODE_NO_BUILD             0
#define SDMODE_SELECTIVE            0
