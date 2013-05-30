//Following was retreived from http://games.linuxdude.com/tamaps/archive/cpm1_dev_docs.zip
void CPM_UpdateSettings(int num);
void CPM_PM_Aircontrol ( pmove_t *pm, vec3_t wishdir, float wishspeed );

#define CS_PRO_MODE 16
#define CPM_ON 1

extern float cpm_pm_jump_z;

// Physics
extern float	cpm_pm_airstopaccelerate;
extern float	cpm_pm_aircontrol;
extern float	cpm_pm_strafeaccelerate;
extern float	cpm_pm_wishspeed;
extern float	pm_accelerate; // located in bg_pmove.c
extern float	pm_friction; // located in bg_pmove.c
extern float  pm_bunnyhopspeedcap; //zdrytchx's bunnyhop
extern float  pm_bunnyhopaccel; //zdrytchx's acceleration
