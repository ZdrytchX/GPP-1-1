/*
============================================================
This file contains code that was retreived and modified from
http://games.linuxdude.com/tamaps/archive/cpm1_dev_docs.zip
============================================================
*/
void CPM_UpdateSettings(int num);
void CPM_PM_Aircontrol ( pmove_t *pm, vec3_t wishdir, float wishspeed );

#define CS_PRO_MODE 16
#define CPM_ON 1

extern float  cpm_pm_jump_z;
//extern float  pm_jumpheight;//height at which one jumps at if stamina < allowable
// Physics
extern float	cpm_pm_cliptime;
extern float	cpm_pm_airstopaccelerate;
extern float	cpm_pm_aircontrol;
extern float	cpm_pm_strafeaccelerate;
extern float	cpm_pm_wishspeed;
extern float  cpm_pm_aircontrolmod;
extern qboolean  cpm_pm_aircontrolmoding;

extern float	pm_accelerate; // located in bg_pmove.c
extern float	pm_friction; // located in bg_pmove.c

extern qboolean  pm_autojump;
extern float  pm_bunnyhopspeedcap; //bunnyhop
extern float  pm_bunnyhopaccel; //acceleration for bhop

extern int    pm_rampjump; //0, 1, 2 only
extern qboolean pm_doublejump_wsw_style; //slide on stairs
extern qboolean pm_q1rampslide;//qw style
extern qboolean pm_q1rampslip;//qw style
extern qboolean pm_q1strafe; //Quake 1 style strafes (i.e. all direction cpm strafe)
extern qboolean pm_q3strafe; //Adds on top if it should allow q3 strafe on sides or not
extern qboolean pm_aircontrol_alldir; //Allows air control in all directions
//TFC Style Settings
extern float  pm_groundspeedcap;
extern float  pm_groundspeedcapfriction; //groundspeed instantaneous speed multiplier (TFC)
extern float  pm_groundspeedcaplimit; //TF2 Style Hard cap
