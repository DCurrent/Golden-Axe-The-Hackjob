/*
	Defined Constants					- http://www.caskeys.com/dc/?p=5059
	License (must be included to use)	- http://www.caskeys.com/dc/?p=5067
	Damon V. Caskey
	2011_03_29 (consolidated from multiple lists)
	~2011-06-19
	~2011-10-11
	~2012-08-21
	~2013-01-26
	~2013-02-01
	~2013-02-13
	~2013-02-16

	This list is continually updated. Be sure to check the link above to ensure you have most up to date version.
*/

#ifndef DEFINED
#define DEFINED						1

/******Adjustments and Settings******/
#define CONF_DRAWMODE				1										//Draw scaling modes: 0 = SNK Style, 1 = Capcom style
#define CONF_SETBLOCK				1                                       //1 = Automatically set blocking animation based on hit height.
#define CONF_SETPAIN				0                                       //1 = Automatically set pain animation based on hit height.
#define CONF_JUMPCON_X				0										//1 = Left/Right keys alter X plane veolcity during jump.
#define CONF_JUMPCON_Y				1										//1 = Release of Jump key halts Y velocity during jump (i.e. Mario Bros style jump height control).
#define CONF_JUMPCON_Z				0										//1 = Up/Down keys alter X plane velocity during jump.

/******AI Modes******/
#define AI_CHASE					openborconstant("AIMOVE1_CHASE")		//Always move toward target.
#define AI_NOMOVE					openborconstant("AIMOVE1_NOMOVE")		//No movement.

/******Animations, custom ID)******/
#define AC_AIRBLOCK					openborconstant("ANI_FOLLOW8")0								//Air block.
#define AC_AIRBACK					openborconstant("ANI_FOLLOW8")1								//Air back attack.
#define AC_AIRJ2AL					openborconstant("ANI_FOLLOW8")9								//Alternate Jumpattack2 (when not moving).
#define AC_AIRJ3AL					openborconstant("ANI_FOLLOW9")0								//Alternate Jumpattack3 (when not moving).
#define AC_ATKDOWN					openborconstant("ANI_FOLLOW8")2								//Down attack.
#define AC_BACKSTEP					A_FSPECIAL2								//Backward dash.
#define AC_BLOCKBRK					20										//Guard or attack broken.
#define AC_BLOCKNOR					A_BLOCKP								//Default guard.
#define AC_BLOCKMID					A_BLOCKP2								//Middle guard.
#define AC_BLOCKLOW					A_BLOCKP3								//Low guard.
#define AC_BLOCKHIGH				A_BLOCKP4								//High guard.
#define AC_BLOCKPAR					openborconstant("ANI_FOLLOW9")1								//Parry/Just defense animation.
#define AC_BLOCKPARA				openborconstant("ANI_FOLLOW9")2								//Air Parry/Just defense animation.
#define AC_CLIMBUPB					openborconstant("ANI_FOLLOW9")5								//Climb up (wall/object is toward background on Z).
#define AC_CLIMBDNB					openborconstant("ANI_FOLLOW9")6								//Climb down (wall/object is toward background on Z).
#define AC_CLIMBUP					openborconstant("ANI_FOLLOW9")7								//Climb up (wall/object is toward foreground on Z).
#define AC_CLIMBDN					openborconstant("ANI_FOLLOW9")8								//Climb down (wall/object is toward foreground on Z).
#define AC_COLLAPSE					A_FALL2									//Collapse
#define AC_DBJMP					A_FOLLOW54								//Double jump, Vertical or generic.
#define AC_DBJMPB					A_FOLLOW55								//Double jump, backward.
#define AC_DBJMPF					A_FOLLOW56								//Double jump, forward.
#define AC_DBJMPP					A_FOLLOW57								//Double jump, pogo.
#define AC_DBJMPW					A_FOLLOW58								//Double jump, wall.
#define AC_DIZZY					A_FOLLOW50								//Dizzy.
#define AC_DODATK					openborconstant("ANI_FOLLOW8")3								//Dodge attack.
#define AC_DODATKU					openborconstant("ANI_FOLLOW8")4								//Dodge up attack.
#define AC_DODATKD					openborconstant("ANI_FOLLOW8")5								//Dodge down attack.
#define AC_DODATKSD					openborconstant("ANI_FOLLOW8")6								//Dodge attack step down.
#define AC_DODATKSU					openborconstant("ANI_FOLLOW8")7								//Dodge attack step down.
#define AC_EIMPS					A_FOLLOW1								//Impact effect: Small.
#define AC_EIMPM					A_FOLLOW2								//Impact effect: Medium.
#define AC_EIMPL					A_FOLLOW3								//Impact effect: Large.
#define AC_ESPLA					A_FOLLOW4								//Impact effect: Splash.
#define AC_FFORE					A_FOLLOW52								//Fatality: Fly into foreground.
#define AC_FWATER					A_FOLLOW53								//Fatality: Fall into background water.
#define	AC_SCENENAP					A_GET									//Taking a nap (ex. Golden Axe bonus stage)
#define	AC_SCENESTOMP				openborconstant("ANI_ATTACK4")									//Stomping/kicking innocents (ex. Golden Axe Longmoan stomping peasents)
#define AC_PAINNOR					A_PAIN								    //Default pain.
#define AC_PAINMID					A_PAIN2								    //Middle pain.
#define AC_PAINLOW					A_PAIN								    //Low pain.
#define AC_PAINHIGH					A_PAIN								    //High pain.
#define AC_POWUP					openborconstant("ANI_FOLLOW9")			//Power up animation.
#define AC_SPLAT					A_FALL8									//Thrown hard onto head.
#define AC_SWEPT					A_FALL3									//Foot sweep.
#define AC_TEAM1					openborconstant("ANI_FOLLOW8")			//Team call pose.
#define AC_TOSS						openborconstant("ANI_FALL5")			//Thrown.

/******Animations, engine defined******/
#define A_ATKUP						openborconstant("ANI_ATTACKUP")
#define A_BLOCK						openborconstant("ANI_BLOCK")
#define A_BLOCKP					openborconstant("ANI_BLOCKPAIN")
#define A_BLOCKP2					openborconstant("ANI_BLOCKPAIN2")
#define A_BLOCKP3					openborconstant("ANI_BLOCKPAIN3")
#define A_BLOCKP4					openborconstant("ANI_BLOCKPAIN4")
#define A_BLOCKP5					openborconstant("ANI_BLOCKPAIN5")
#define A_BURN						openborconstant("ANI_BURN")
#define A_BURNDIE					openborconstant("ANI_BURNDIE")
#define A_BURNPAIN					openborconstant("ANI_BURNPAIN")
#define A_CHARGEATK					openborconstant("ANI_CHARGEATTACK")
#define A_DEATH						openborconstant("ANI_DIE")
#define A_DEATH2					openborconstant("ANI_DIE2")
#define A_DEATH3					openborconstant("ANI_DIE3")
#define A_DEATH4					openborconstant("ANI_DIE4")
#define A_DEATH5					openborconstant("ANI_DIE5")
#define A_DEATH6					openborconstant("ANI_DIE6")
#define A_DEATH7					openborconstant("ANI_DIE7")
#define A_DEATH8					openborconstant("ANI_DIE8")
#define A_DEATH9					openborconstant("ANI_DIE9")
#define A_DEATH10					openborconstant("ANI_DIE10")
#define A_DOWN						openborconstant("ANI_DOWN")
#define A_FALL2						openborconstant("ANI_FALL2")
#define A_FALL3						openborconstant("ANI_FALL3")
#define A_FALL4						openborconstant("ANI_FALL4")
#define A_FALL6						openborconstant("ANI_FALL6")
#define A_FALL7						openborconstant("ANI_FALL7")
#define A_FALL8						openborconstant("ANI_FALL8")
#define A_FALL9						openborconstant("ANI_FALL9")
#define A_FALL10					openborconstant("ANI_FALL10")
#define A_FOLLOW1					openborconstant("ANI_FOLLOW1")
#define A_FOLLOW2					openborconstant("ANI_FOLLOW2")
#define A_FOLLOW3					openborconstant("ANI_FOLLOW3")
#define A_FOLLOW4					openborconstant("ANI_FOLLOW4")
#define A_FOLLOW5					openborconstant("ANI_FOLLOW5")
#define A_FOLLOW6					openborconstant("ANI_FOLLOW6")
#define A_FOLLOW10					openborconstant("ANI_FOLLOW10")
#define A_FOLLOW11					openborconstant("ANI_FOLLOW11")
#define A_FOLLOW14					openborconstant("ANI_FOLLOW14")
#define A_FOLLOW16					openborconstant("ANI_FOLLOW16")
#define A_FOLLOW17					openborconstant("ANI_FOLLOW17")
#define A_FOLLOW19					openborconstant("ANI_FOLLOW19")
#define A_FOLLOW20					openborconstant("ANI_FOLLOW20")
#define A_FOLLOW21					openborconstant("ANI_FOLLOW21")
#define A_FOLLOW22					openborconstant("ANI_FOLLOW22")
#define A_FOLLOW23					openborconstant("ANI_FOLLOW23")
#define A_FOLLOW24					openborconstant("ANI_FOLLOW24")
#define A_FOLLOW25					openborconstant("ANI_FOLLOW25")
#define A_FOLLOW26					openborconstant("ANI_FOLLOW26")
#define A_FOLLOW27					openborconstant("ANI_FOLLOW27")
#define A_FOLLOW28					openborconstant("ANI_FOLLOW28")
#define A_FOLLOW29					openborconstant("ANI_FOLLOW29")
#define A_FOLLOW30					openborconstant("ANI_FOLLOW30")
#define A_FOLLOW31					openborconstant("ANI_FOLLOW31")
#define A_FOLLOW32					openborconstant("ANI_FOLLOW32")
#define A_FOLLOW33					openborconstant("ANI_FOLLOW33")
#define A_FOLLOW34					openborconstant("ANI_FOLLOW34")
#define A_FOLLOW35					openborconstant("ANI_FOLLOW35")
#define A_FOLLOW36					openborconstant("ANI_FOLLOW36")
#define A_FOLLOW37					openborconstant("ANI_FOLLOW37")
#define A_FOLLOW38					openborconstant("ANI_FOLLOW38")
#define A_FOLLOW39					openborconstant("ANI_FOLLOW39")
#define A_FOLLOW40					openborconstant("ANI_FOLLOW40")
#define A_FOLLOW41					openborconstant("ANI_FOLLOW41")
#define A_FOLLOW42					openborconstant("ANI_FOLLOW42")
#define A_FOLLOW43					openborconstant("ANI_FOLLOW43")
#define A_FOLLOW44					openborconstant("ANI_FOLLOW44")
#define A_FOLLOW45					openborconstant("ANI_FOLLOW45")
#define A_FOLLOW46					openborconstant("ANI_FOLLOW46")
#define A_FOLLOW47					openborconstant("ANI_FOLLOW47")
#define A_FOLLOW48					openborconstant("ANI_FOLLOW48")
#define A_FOLLOW49					openborconstant("ANI_FOLLOW49")
#define A_FOLLOW50					openborconstant("ANI_FOLLOW50")
#define A_FOLLOW51					openborconstant("ANI_FOLLOW51")
#define A_FOLLOW52					openborconstant("ANI_FOLLOW52")
#define A_FOLLOW53					openborconstant("ANI_FOLLOW53")
#define A_FOLLOW54					openborconstant("ANI_FOLLOW54")
#define A_FOLLOW55					openborconstant("ANI_FOLLOW55")
#define A_FOLLOW56					openborconstant("ANI_FOLLOW56")
#define A_FOLLOW57					openborconstant("ANI_FOLLOW57")
#define A_FOLLOW58					openborconstant("ANI_FOLLOW58")
#define A_FOLLOW59					openborconstant("ANI_FOLLOW59")
#define A_FOLLOW60					openborconstant("ANI_FOLLOW60")
#define A_FOLLOW61					openborconstant("ANI_FOLLOW61")
#define A_FOLLOW62					openborconstant("ANI_FOLLOW62")
#define A_FOLLOW63					openborconstant("ANI_FOLLOW63")
#define A_FOLLOW64					openborconstant("ANI_FOLLOW64")
#define A_FOLLOW65					openborconstant("ANI_FOLLOW65")
#define A_FOLLOW66					openborconstant("ANI_FOLLOW66")
#define A_FOLLOW67					openborconstant("ANI_FOLLOW67")
#define A_FOLLOW68					openborconstant("ANI_FOLLOW68")
#define A_FOLLOW69					openborconstant("ANI_FOLLOW69")
#define A_FOLLOW70					openborconstant("ANI_FOLLOW70")
#define A_FOLLOW71					openborconstant("ANI_FOLLOW71")
#define A_FOLLOW72					openborconstant("ANI_FOLLOW72")
#define A_FOLLOW73					openborconstant("ANI_FOLLOW73")
#define A_FOLLOW74					openborconstant("ANI_FOLLOW74")
#define A_FOLLOW75					openborconstant("ANI_FOLLOW75")
#define A_FOLLOW76					openborconstant("ANI_FOLLOW76")
#define A_FOLLOW77					openborconstant("ANI_FOLLOW77")
#define A_FOLLOW78					openborconstant("ANI_FOLLOW78")
#define A_FOLLOW79					openborconstant("ANI_FOLLOW79")
#define A_FOLLOW100					openborconstant("ANI_FOLLOW100")
#define A_FORWARDJUMP				openborconstant("ANI_FORWARDJUMP")
#define A_FSPECIAL					openborconstant("ANI_FREESPECIAL")
#define A_FSPECIAL2					openborconstant("ANI_FREESPECIAL2")
#define A_FSPECIAL3					openborconstant("ANI_FREESPECIAL3")
#define A_FSPECIAL4					openborconstant("ANI_FREESPECIAL4")
#define A_FSPECIAL5					openborconstant("ANI_FREESPECIAL5")
#define A_FSPECIAL6					openborconstant("ANI_FREESPECIAL6")
#define A_FSPECIAL7					openborconstant("ANI_FREESPECIAL7")
#define A_FSPECIAL8					openborconstant("ANI_FREESPECIAL8")
#define A_FSPECIAL9					openborconstant("ANI_FREESPECIAL9")
#define A_FSPECIAL10				openborconstant("ANI_FREESPECIAL10")
#define A_FSPECIAL12				openborconstant("ANI_FREESPECIAL12")
#define A_FSPECIAL13				openborconstant("ANI_FREESPECIAL13")
#define A_FSPECIAL14				openborconstant("ANI_FREESPECIAL14")
#define A_FSPECIAL15				openborconstant("ANI_FREESPECIAL15")
#define A_GET						openborconstant("ANI_GET")
#define A_GRABATK2					openborconstant("ANI_GRABATTACK2")
#define A_GRABBACK					openborconstant("ANI_GRABBACKWARD")
#define A_GRABBED					openborconstant("ANI_GRABBED")
#define A_IDLE						openborconstant("ANI_IDLE")
#define A_JUMPATK2					openborconstant("ANI_JUMPATTACK2")
#define A_JUMPATK3					openborconstant("ANI_JUMPATTACK3")
#define A_JUMPLAND					openborconstant("ANI_JUMPLAND")
#define A_PAIN						openborconstant("ANI_PAIN")
#define A_PAIN2						openborconstant("ANI_PAIN2")
#define A_PAIN3						openborconstant("ANI_PAIN3")
#define A_PAIN4						openborconstant("ANI_PAIN4")
#define A_PAIN5						openborconstant("ANI_PAIN5")
#define A_PAIN6						openborconstant("ANI_PAIN6")
#define A_PAIN7						openborconstant("ANI_PAIN7")
#define A_PAIN8						openborconstant("ANI_PAIN8")
#define A_PAIN9						openborconstant("ANI_PAIN9")
#define A_PAIN10					openborconstant("ANI_PAIN10")
#define A_RESPAWN					openborconstant("ANI_RESPAWN")
#define A_SHOCKDIE					openborconstant("ANI_SHOCKDIE")
#define A_SHOCKPAIN					openborconstant("ANI_SHOCKPAIN")
#define A_SLEEP						openborconstant("ANI_SLEEP")
#define A_SPECIAL					openborconstant("ANI_SPECIAL")
#define A_SPECIAL2					openborconstant("ANI_SPECIAL2")
#define A_UP						openborconstant("ANI_UP")
#define A_WALK						openborconstant("ANI_WALK")
#define A_WALKOFF					openborconstant("ANI_WALKOFF")

/*****Color Maps*****/
#define MAP_KO						1										//KO.
#define MAP_BURN					2										//Burn.
#define MAP_SHOCK					3										//Shock.
#define MAP_FREEZE					4										//Freeze.
#define MAP_POISON					5										//Poison.

/******Color RGB, common******/
#define RGB_BLACK					rgbcolor(0, 0, 0)						//Black.
#define RGB_BLUE					rgbcolor(0, 0, 255)						//Blue.
#define RGB_GRAY					rgbcolor(128, 128, 128)					//Gray
#define RGB_GREEN					rgbcolor(0, 255, 0)						//Green.
#define RGB_RED						rgbcolor(255, 0, 0)						//Red.
#define RGB_ORANGE					rgbcolor(255, 69, 0)					//Orange.
#define RGB_VIOLET					rgbcolor(51, 0, 51)						//Deep Purple/Violet
#define RGB_WHITE					rgbcolor(255, 255, 255)					//White.
#define RGB_YELLOW					rgbcolor(255, 255, 0)					//Yellow.

/******Color RGB, special*****/
#define RGB_BURN					RGB_ORANGE								//Burn tint.
#define RGB_POISON					RGB_GREEN								//Poison tint.
#define RGB_SHOCK					RGB_WHITE								//Shock tint.

/******Direction, absolute)******/
#define DIR_LEFT					0										//Facing left.
#define DIR_RIGHT					1										//Facing right.

/******Direction, adjustment)******/
#define DIR_ADJ_LEFT				-2										//Force target to face left.
#define DIR_ADJ_NONE				0										//Do not change target facing.
#define DIR_ADJ_OPP					-1										//Force target to face opposite direction of designated anchor.
#define DIR_ADJ_RIGHT				2										//Force target to face right.
#define DIR_ADJ_SAME				1										//Force target to face same direction as designated anchor.

/******Entity Index******/
#define ENT_INDEX_0					0
#define ENT_INDEX_1					1
#define ENT_INDEX_2					2
#define ENT_INDEX_3					3
#define ENT_INDEX_4					4
#define ENT_INDEX_5					5

/******Entity Reference******/
#define ENT_SELF					0

/******Entity Types*******/
#define TYPE_ITEM					openborconstant("TYPE_ITEM")
#define TYPE_NPC					openborconstant("TYPE_NPC")
#define TYPE_NONE					openborconstant("TYPE_NONE")
#define TYPE_OBSTACLE				openborconstant("TYPE_OBSTACLE")
#define TYPE_PLAYER					openborconstant("TYPE_PLAYER")

/******Flags, general use******/
#define FLAG_NONE					0

#define FLAG_MODE_0					0
#define FLAG_MODE_1					1
#define FLAG_MODE_2					2
#define FLAG_MODE_3					3
#define FLAG_MODE_4					4
#define FLAG_MODE_5					5
#define FLAG_MODE_6					6
#define FLAG_MODE_7					7
#define FLAG_MODE_8					8
#define FLAG_MODE_9					9
#define FLAG_MODE_10				10

/******Flags, specfic settings******/
#define SOUND_PLAY_100				1										//Always play sound.
#define SOUND_FILE_RAND				-1										//Choose random file from sound group.
#define SOUND_DELAY_DEF				0										//In progress - avoid playing certain sounds in quick succession.
#define SOUND_SUB_NONE				0

/******Indexedvar IDs, entity******/
#define IDXE_ENTID					0										//ID number given during spawn script.
#define IDXE_VITNAME				1										//Full Name.
#define IDXE_VITRACE				2										//Race (Human, Elf, Dwarf, etc.).
#define IDXE_VITGEND				3										//Gender (0 Male, 1 female)
#define IDXE_VITHEIG				4										//Height (cm).
#define IDXE_VITWEIG				5										//Weight (kg).
#define IDXE_VITDOB					6										//Date of birth.
#define IDXE_VITAGE					7										//Age.
#define IDXE_VITPOB					8										//Place of birth.
#define IDXE_VITALIG				9										//Alignment.
#define IDXE_VITSTR					10										//Strength.
#define IDXE_VITDEX					11										//Dexterity.
#define IDXE_VITCON					12										//Constitution.
#define IDXE_VITINT					13										//Intellegence.
#define IDXE_VITWIS					14										//Wisdom.
#define IDXE_VITCHR					15										//Charisma.
#define IDXE_VITCLAS				16										//Class (Barbarian, Cleric, Fighter, etc.).
#define IDXE_VITEXP					17										//Experience total.
#define IDXE_STUNV					18										//Stun value built up by incoming attacks.
#define IDXE_STUNT					19										//Gametime threshold to reduce/remove stun value.
#define IDXE_BIND					20										//Primary bind for grappling moves.
#define IDXE_NEXTANI2				22										//Animation to be activated in future by another event or script.
#define IDXE_NEXTANI3				23										//Animation to be activated in future by another event or script.
#define IDXE_NEXTANI4				24										//Animation to be activated in future by another event or script.
#define IDXE_NEXTANI5				25										//Animation to be activated in future by another event or script.
#define IDXE_NEXTSPW				26										//Model to be spawned in future by another event or script.
#define IDXE_NEXTSPA				27										//Alias of IDXE_NEXTSPW.
#define IDXE_NEXTSPM				28										//Map of IDXE_NEXTSPW.
#define IDXE_NEXTSPB				29										//Blend setting of IDXE_NEXTSPW.
#define IDXE_NEXTSPX				30										//X location (or adjustment) of IDXE_NEXTSPW.
#define IDXE_NEXTSPY				31										//Y location (or adjustment) of IDXE_NEXTSPW.
#define IDXE_NEXTSPZ				32										//Z location (or adjustment) of IDXE_NEXTSPW.
#define IDXE_NEXTSPD				33										//Direction setting of IDXE_NEXTSPW.
#define IDXE_NEXTSPF				34										//Animation flag for binding IDXE_NEXTSPW.
#define IDXE_OGMAP					35										//Orginal map. This is the remap entity starts with so it may be restored later if needed.
#define IDXE_SPAWN					36										//Entity var slot used to store new spawns.
#define IDXE_ADSCALEX				37										//draw scale X adjustment.
#define IDXE_ADSCALEY				38										//draw scale Y adjustment.
#define IDXE_ADFLIPX				39										//draw flip X setting.
#define IDXE_ADFLIPY				40										//draw flip Y setting.
#define IDXE_ADSHIFTX				41										//draw shift X setting.
//#define IDXE_ADBLEND				42										//draw blend setting.
//#define IDXE_ADREMAP				43										//draw remap setting.
#define IDXE_ADFILL					44										//draw fill setting.
#define IDXE_ADROTATE				45										//draw static rotate setting.
#define IDXE_ADAROTAT				46										//draw auto rotation setting.
#define IDXE_ADSCALER				47										//draw, last scale ratio applied to sprite.
#define IDXE_ADSKIP					48										//draw toggle flag.
#define IDXE_SHFLAG					49										//Shadow toggle and mode flag.
#define IDXE_SHMODEL				50										//Shadow trail model.
#define IDXE_SHALIAS				51										//Shadow model alias.
#define IDXE_SHDELAY				52										//Shadow, delay between individual shadow entity spawns.
#define IDXE_SHETIME				53										//Shadow, elapsed game time next shadow trail entity will be spawned.
#define IDXE_SHREMAP				54										//Shadow, remap applied to shadow trail.
#define IDXE_SHBLEND				55										//Shadow, blend mode applied to shadow trail.
#define IDXE_DTOSSX					59										//X velocity for toss effect.
#define IDXE_DTOSSY					60										//Y velocity for toss effect.
#define IDXE_DTOSSZ					61										//Z velocity for toss effect.
#define IDXE_WARPX					62										//X location adjust for self to attacker when hit.
#define IDXE_WARPY					63										//Y location adjust for self to attacker when hit.
#define IDXE_WARPZ					64										//Z location adjust for self to attacker when hit.
#define IDXE_WARPT					65										//Condition for location adjust self to attacker when hit (0/NULL Any hit, 1 Pain or fall, 2 Fall only).
#define IDXE_HITDMG					66										//Extra damage to apply to target during didhitscript.
#define IDXE_HITFIN					67										//Extra damage lethal flag (1 damage cannot reduce HP to < 1).
#define IDXE_HITTYP					68										//Extra damage attack type.
#define IDXE_HITDRP					69										//Extra damage drop power.
#define IDXE_HITNOR					70										//Extra damage no reset on hit flag.
#define IDXE_HITWRX					71										//Extra damage X location force.
#define IDXE_HITWRY					72										//Extra damage Y location force.
#define IDXE_HITWRZ					73										//Extra damage Z location force.
#define IDXE_HITWRT					74										//Extra damage location force condition (0 always, 1 pain/knockdown, 2 knockdown).
#define IDXE_HITLVL					75										//Force hit level flag (0 Normal, 1 Middle, 2 Low, 3 High).
#define IDXE_HITFLS					76										//Extra damage hitflash.
#define IDXE_BINDHE					77										//Bound hit effect entity.
#define IDXE_BINDE					78										//Bound special effect.
#define IDXE_KEY1SP					79										//Last time special key was pressed.
#define IDXE_KEY1AT					80										//Last time attack key was pressed.
#define IDXE_STATUS					81										//Special states (power up, etc.).
#define IDXE_BOUNDM					82										//Bind mode used on this entity.
#define IDXE_BOUNDA					83										//Anchor entity this entity is bound to.
#define IDXE_BOUNDI					84										//Index this entity is bound with.
#define IDXE_BOUNDX					85										//X this entity is bound to.
#define IDXE_BOUNDY					86										//Y this entity is bound to.
#define IDXE_BOUNDZ					87										//Z this entity is bound to.
#define	IDXE_BOUNDD					88										//Dir this entity is bound to.
#define	IDXE_BOUNDF					89										//Frame entity is set to during grapple bind.
#define	IDXE_MAXHP					90										//Maximum Health (to reset when damaged as workaround for weapon bug).
#define IDXE_MAXMP					91										//Maximum MP (to reset when damaged as workaround for weapon bug).
#define IDXE_AGGRO					92										//Aggression (to reset when damaged as workaround for weapon bug).
#define IDXE_APUSHX					93                                      //Resistance to environment push X.
#define IDXE_APUSHY					94                                      //Resistance to environment push Y.
#define IDXE_APUSHZ					95                                      //Resistance to environment push Z.
#define IDXE_ASLIDEX				96                                      //Resistance to environment slide X.
#define IDXE_ASLIDEY				97                                      //Resistance to environment slide Y.
#define IDXE_ASLIDEZ				98                                      //Resistance to environment slide Z.

/******Indexedvar IDs, global******/
#define IDXG_ECOUNT					0										//Entity's spawned counter.
#define IDXG_MINZADJ				1										//Minimum Z adjustment.
#define IDXG_MAXZADJ				2										//Maximum Z adjustment.
#define IDXG_MAXYADJ				3										//Maximum level height adjustment.
#define IDXG_GPAUSE					4										//Global pause.
#define IDXG_TNAMES					5										//Index for opening name text file.
#define IDXG_ICOJAR					7										//Magic jar.
#define IDXG_BLOCBLU				8										//Life block, blue.
#define IDXG_BLOCYEL				9										//Life block, yellow.
#define IDXG_BLOCORA				10										//Life block, orange.
#define IDXG_BLOCRED				11										//Life block, red.
#define IDXG_SND_LSTI				12										//Last sound played (by index).
#define IDXG_SND_LSTT				13										//Time last sound was played.
#define IDXG_SND_LSTE				14										//Entity last sound was played "on".
#define IDXG_TMUSIC					15										//Index for opening music text file.
#define IDXG_DEBUG					16										//Debug mode.
#define IDXG_SCREEN					17										//Screen 1 handle.

/******Grapple Settings, bound entity hit state******/
#define G_STATE_ATKBOX				1
#define G_STATE_NOHIT				0

/******Grapple settings, pose frames)******/
#define G_RELEASE					-1										//Release bind.
#define G_HELD						0										//Grabbed.
#define G_HELDP						1										//Grabbed pain.
#define G_HORUP						2										//Horizontal up.
#define G_HORDN						3										//Horizontal down.
#define G_VERUP						4										//Vertical up.
#define G_VERDN						5										//Vertical Down.
#define G_TLTUP						6										//Tilt up.
#define G_TLTDN						7										//Tilt down.
#define G_VERDNP					8										//Vertical down pain.
#define G_DWNUP						9										//Laying down face up.
#define G_DWNUPP					10										//Laying down face up in pain.
#define G_FALUP						11										//Falling face up.
#define G_FALUPT					12										//Falling face up tilted.
#define G_HORUPP					13										//Horiztonal face up pain.
#define G_HELDMP					14										//Held middle pain.
#define G_EX1						15
#define G_EX2						16
#define G_EX3						17
#define G_EX4						18
#define G_EX5						19
#define G_EX6						20

/******Keys (ID)******/
#define KEY_ANY						"anybutton"								//Any key.
#define KEY_ATK1					"attack"								//Attack 1.
#define KEY_ATK2					"attack2"								//Attack 2.
#define KEY_ATK3					"attack3"								//Attack 3.
#define KEY_ATK4					"attack4"								//Attack 4.
#define KEY_ESC						"esc"									//Escape.
#define KEY_JUMP					"jump"									//Jump.
#define KEY_MDOWN					"movedown"								//Move down.
#define KEY_MLEFT					"moveleft"								//Move left.
#define KEY_MRIGHT					"moveright"								//Move right.
#define KEY_MUP						"moveup"								//Move up.
#define KEY_SCREENSHOT				"screenshot"							//Screenshot.
#define KEY_SPECIAL					"special"								//Special.
#define KEY_START					"start"									//Start.

/******Keys (Status)******/
#define KEY_STAT_DOWN				1										//Initial key trigger.
#define KEY_STAT_PRESS				0										//Key being held.
#define KEY_STAT_UP					2										//Key release.

/******Models******/
#define MODEL_EFFECT				"effe0001"								//General effect model.
#define MODEL_EFFATAL				"fata0001"								//Fatality.
#define MODEL_FLLAND				"jump_land"									//Land dust; medium.
#define MODEL_FLLAND2				"slam_heavy"									//Impact dust; medium.

/******Properties, engine defined)******/
#define PROP_DIRECTION				"direction"								//X axis facing.
#define PROP_VELOCITY_ALL			"velocity"								//Movement speed.
#define PROP_VELOCITY_X				"xdir"									//X axis movement speed.
#define PROP_VELOCITY_Y				"tossv"									//Y axis movement speed.
#define PROP_VELOCITY_Z				"zdir"									//Z axis movement speed.

/******Properties (sub), engine defined******/

/******Sound groups******/
#define VOI_ATK						0										//Attack grunt, generic.
#define VOI_BTL						1										//Battle cry (when knocking opponent down).
#define VOI_DYN						2										//Low health.
#define VOI_DIE						3										//KO.
#define VOI_GO						4										//Attack command.
#define VOI_CNT						5										//Can't do that.
#define VOI_HA						6										//Laugh.
#define VOI_PN						7										//Getting hit, generic.
#define VOI_AID						8										//Help call.
#define VOI_BOR						9										//Bored.
#define VOI_CHN						10										//Spell chanting.
#define VOI_HI						11										//Spawn greeting.
#define VOI_SPF						12										//Magic fail.
#define VOI_SPO						13										//Enemy spotted.
#define VOI_BLO						14										//Incoming attack blocked.
#define VOI_PIT						15										//Falling in pit.
#define VOI_BRN						16										//Burned.
#define VOI_SHO						17										//Shocked.
#define VOI_POI						18										//Poison.
#define VOI_FRE						19										//Freeze.
#define VOI_BYE						20										//Bye.
#define VOI_ATF						21										//Attack fail.
#define VOI_TAU						22										//Taunt.
#define VOI_YES						23										//Yes (good idea).
#define VOI_VIC						24										//Victory.
#define VOI_ATKL					25										//Attack grunt, light.
#define VOI_ATKM					26										//Attack grunt, medium.
#define VOI_ATKH					27										//Attack grunt, heavy.
#define VOI_ATKS					28										//Attack grunt, max.
#define VOI_POWL					29										//Power up, light.
#define VOI_POWM					30										//Power up, meduium.
#define VOI_POWH					31										//Power up, heavy.
#define VOI_POWS					32										//Power up, max.
#define VOI_S0						100										//Specific 0.
#define VOI_S1						101										//Specific 1.
#define VOI_S2						102										//Specific 2.
#define VOI_S3						103										//Specific 3.
#define VOI_S4						104										//Specific 4.
#define VOI_S5						105										//Specific 5.
#define VOI_S6						106										//Specific 6.
#define VOI_S7						107										//Specific 7.
#define VOI_S8						108										//Specific 8.
#define VOI_S9						109										//Specific 9.
#define VOI_S10						110										//Specific 10.
#define VOI_S11						111										//Specific 11.
#define VOI_S12						112										//Specific 12.
#define VOI_S13						113										//Specific 13.
#define VOI_S14						114										//Specific 14.
#define VOI_S15						115										//Specific 15.
#define VOI_S16						116										//Specific 16.
#define VOI_S17						117										//Specific 17.
#define VOI_S18						118										//Specific 18.
#define VOI_S19						119										//Specific 19.
#define VOI_S20						120										//Specific 20.

#define SND_WIFFL					200										//Whiff, Light.
#define SND_WIFFM					201										//Whiff, Medium.
#define SND_WIFFH					202										//Whiff, heavy.
#define SND_JUMPL					203										//Jump, light.
#define SND_JUMPM					204										//Jump, medium.
#define SND_JUMPH					205										//Jump, heavy.
#define SND_LANDL					206										//Land, light.
#define SND_LANDM					207										//Land, medium.
#define SND_LANDH					208										//Land, heavy.
#define SND_HITL					209										//Hit, light.
#define SND_HITM					210										//Hit, medium.
#define SND_HITH					211										//Hit, heavy.
#define SND_CUTL					212										//Hit w/edged weapon, light.
#define SND_CUTM					213										//Hit w/edged weapon, medium.
#define SND_flash_cut_vertical_knockdown					214										//Hit w/edged weapon, heavy.
#define SND_BLOIL					215										//Block Impact, light.
#define SND_BLOIM					216										//Block Impact, medium.
#define SND_BLOIH					217										//Block Impact, heavy.
#define SND_BLOCL					218										//Block cut, light.
#define SND_BLOCM					219										//Block cut, medium.
#define SND_BLOCH					220										//Block cut, heavy.
#define SND_IDIRL					221										//Indirect, light.
#define SND_IDIRM					222										//Indirect, medium.
#define SND_IDIRH					223										//Indirect, heavy.
#define SND_FALLL					224										//Fall land, light.
#define SND_FALLM					225										//Fall land, medium.
#define SND_FALLH					226										//Fall land, heavy.
#define SND_FALLML					227										//Fall land metalic, light.
#define SND_FALLMM					228										//Fall land metalic, medium.
#define SND_FALLMH					229										//Fall land metalic, heavy.
#define SND_IMPL					230										//Ground impact, light.
#define SND_IMPM					231										//Ground impact, medium.
#define SND_IMPH					232										//Ground impact, heavy.
#define SND_BITEL					233										//Bite, light.
#define SND_BITEM					234										//Bite, medium.
#define SND_BITEH					235										//Bite, heavy.
#define SND_HITBL					237										//Hit w/blunt weapon, light.
#define SND_HITBM					238										//Hit w/blunt weapon, medium.
#define SND_HITBH					239										//Hit w/blunt weapon, heavy.
#define SND_HITFIL					240										//Hit w/fire, light.
#define SND_HITFIM					241										//Hit w/fire, medium.
#define SND_HITFIH					242										//Hit w/fire, heavy.
#define SND_HITFRL					243										//Hit w/freeze, light.
#define SND_HITFRM					244										//Hit w/freeze, medium.
#define SND_HITFRH					245										//Hit w/freeze, heavy.
#define SND_HITACL					246										//Hit w/acid, light.
#define SND_HITACM					247										//Hit w/acid, medium.
#define SND_HITACH					248										//Hit w/acid, heavy.
#define SND_HITELL					249										//Hit w/elec, light.
#define SND_HITELM					250										//Hit w/elec, medium.
#define SND_HITELH					251										//Hit w/elec, heavy.
#define SND_HITBOL					252										//Hit w/bone break light.
#define SND_HITBOM					253										//Hit w/bone break medium.
#define SND_HITBOH					254										//Hit w/bone break heavy.
#define SND_HITWAL					255										//Hit/Fall w/water light.
#define SND_HITWAM					256										//Hit/Fall w/water medium.
#define SND_HITWAH					257										//Hit/Fall w/water heavy.
#define SND_PULLL					258										//Pull or stangle, light.
#define SND_PULLM					259										//Pull or stangle, medium.
#define SND_PULLH					260										//Pull or stangle, heavy.
#define SND_SCORL					261										//Score, small.
#define SND_SCORM					262										//Score, medium.
#define SND_SCORH					263										//Score, big.
#define SND_SLAML					264										//Body slam, light.
#define SND_SLAMM					265										//Body slam, medium.
#define SND_SLAMH					266										//Body slam, heavy.
#define SND_SLAMS					267										//Body slam, massive.
#define SND_SLAPL					268										//Bitch slap, light.
#define SND_SLAPM					269										//Bitch slap, medium.
#define SND_SLAPH					270										//Bitch slap, heavy.
#define SND_SKEL					271										//Hit, skeleton, light.
#define SND_SKEM					272										//Hit, skeleton, medium.
#define SND_SKEH					273										//Hit, skeleton, heavy.
#define SND_EFF0					1000									//GA red dragon, fireball.
#define SND_EFF1					1001									//GA red dragon, fireball hit.
#define SND_EFF2					1002									//GA blue dragon, fire breath.
#define SND_EFF3					1003									//GA blue dragon, fire stream.
#define SND_EFF4					1004									//Neo Geo Super start up.
#define SND_EFF5					1005									//Orginal BOR punch whiff.
#define SND_EFF6					1006									//Mortal Kombat Raiden warp.
#define SND_EFF7					1007									//KOF 99-2002 Andy Bogard, Hishoken.
#define SND_EFF8					1008									//KOF 99-2002 Andy Bogard, Geki Hishoken.
#define SND_EFF9					1009									//KOF 99-2002 Andy Bogard, Ku Ha Dan.
#define SND_EFF10					1010									//KOF 99-2002 Andy Bogard, Dark Rain Kick.
#define SND_EFF11					1011									//KOF 99-2002 Andy Bogard, Cho Reppa Dan startup.
#define SND_EFF12					1012									//KOF 99-2002 Andy Bogard, Cho Reppa Dan.
#define SND_EFF13					1013									//KOF 99-2002 Andy Bogard, ??.
#define SND_EFF14					1014									//KOF 99-2002 Andy Bogard, ??.
#define SND_EFF15					1015									//Unkown high pitched power burst used for Andy Bogard Bakushin.
#define SND_EFF16					1016									//Unkown massive impact used for Andy Bogard Bakushin finish.
#define SND_EFF17					1017									//KOF "clasp/grab" sound.
#define SND_EFF18					1018									//Beats of Rage "Bike" sound.
#define SND_EFF19					1019									//Streets of Rage "gulp" sound.
#define SND_EFF20					1020									//Horse galloping repeat a few times and fade.
#define SND_EFF21					1021									//NGBC cursor move beep.
#define SND_EFF22					1022									//NGBC menu selection confirmed.
#define SND_EFF23					1023									//Word Hereos Perfect Hanzou/Fuuma slide dash.
#define SND_EFF24					1024									//Revenge Of Shinobi box break.
#define SND_EFF25					1025									//Lightning strike I (unknown source).
#define SND_EFF26					1026									//Liquid spray (unknown source).
#define SND_EFF27					1027									//NGBC super startup.
#define SND_EFF28					1028									//NGBC Hanzou/Fumma Rekkozan star.
#define SND_EFF29					1029									//Lightning strike II (unknown source).
#define SND_EFF30					1030									//Electrocution (unknown source).
#define SND_EFF31					1031									//NGBC hard whoosh.
#define SND_EFF32					1032									//Muffled low whiff (unknown source).
#define SND_EFF33					1033									//KOF series Ryo Sakazaki Zanrestuken whiffs.
#define SND_EFF34					1034									//KOF 99-2002 super startup.
#define SND_EFF35					1035									//Streets Of Rage metal clang.
#define SND_EFF36					1036									//Quick machine whir, like a drill or winch (unknown source).
//#define SND_EFF37					1037									//Open.
#define SND_EFF38					1038									//GA Remake skeleton walking.
#define SND_EFF39					1039									//GA Remake skeleton fall.
#define SND_EFF40					1040									//GA Remake skeleton rise.
#define SND_EFF41					1041									//GA Remake skeleton stand up.

/******System Constants******/
#define SYS_FRONTZ					openborconstant("FRONTPANEL_Z")

#endif
