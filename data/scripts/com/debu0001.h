#include	"data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0010.h"		//http://www.caskeys.com/dc/?p=1314#bind0010  
#import "data/scripts/com/bind0014.h"  //Grapple bind.
#import "data/scripts/com/key0006.h"   //Selection increment.

void debu0001(void vEnt, int iKUp, int iKDn, int iKLt, int iKRt, int iKAtk, int iKAtk2, int iKAtk3, int iKAtk4, int iKSt, int iKSs, int iKEsc, int iKAtkH, int iKAtk2H, int iKAtk3H, int iKAtk4H, int iKSp, int iJmpH, int iKEscH){

	void	vTarget;
	void	vOpp;
	int     i;                                                                                                              //Counter.
	int		iDebug;
	int		iBM;																											//Bind mode.
	char	cBM;																											//Bind mode string.
	int		iBA;																											//Bind animation.	
	int     iBI;																											//Bind index.
    int     iBP;
    int     iBX;
    int     iBY;
    int     iBZ;
    int     iBD;																											//Bind direction.
	char	cBD;																											//Bind direction text constant.
    int     iBF;
    int     iRB;
	int		iDB1, iDB2;																										//Debug setting placeholders.
	int		iEnt;																											//Entity index.
	int		iECnt;																											//Number of entities in play.
	int		iD;																												//Direction.
	float	fB, fX, fY, fZ;																									//Base, X, Y, and Z locations.
	char	cON			= "NA";                                                                                             //Opponent's default name.
	char	cOA			= "NA";                                                                                             //Opponent's alias.
	char	cName		= "NA";                                                                                             //Default name.
    char	cAlias		= "NA";                                                                                             //Default alias.
   	char    cFrame      = "NA";                                                                                             //Frame.
    char    cMHP        = "NA";                                                                                             //Max health.
    char    cHP         = "NA";                                                                                             //Health.
	char	cAni		= "NA";																								//Bound entity animation.

	if (openborvariant("in_selectscreen")){ return; }

    iDebug = key0006(vEnt, "debug_set", iDebug, 0, NULL(), 10, NULL(), iKEscH, iKUp, iKDn, 1);

    //Clear out text objects.
    for(i=0;i<7;i++)
    {
        cleartextobj(i);
    }

	if(iDebug != NULL())
	{
        settextobj(0, 10, 30, 1, -1, "Debug: " + iDebug);
    }

	if(iDebug == 1)		//General info.
	{

		iEnt	= key0006(vEnt, "debug_bind0010_i1",	iEnt, 0,		NULL(), iECnt,	NULL(), iKAtkH,		iKRt, iKLt, 1);	//Entity index.

		if (!iEnt){	iEnt = 0;	}																							//Null to 0.

		vTarget = getentity(iEnt);																							//Get entity handle.
        iECnt	= openborvariant("ent_max");																				//Get count of entites.

		settextobj(0, 10, 30, 1, -1, "Debug: " + iDebug + ", General Info");
		settextobj(1, 10, 40, 2, -1, "SP: Index: ("+iEnt+"/"+iECnt+")");

        if(vTarget																											//Valid handle?
			&& getentityproperty(vTarget, "exists"))																		//Valid entity?
		{

			cName	= getentityproperty(vTarget, "defaultname");
			cAlias	= getentityproperty(vTarget, "name");
			iD		= getentityproperty(vTarget, "direction");
			fB		= getentityproperty(vTarget, "base");
			fX		= getentityproperty(vTarget, "x");
			fY		= getentityproperty(vTarget, "a");
			fZ		= getentityproperty(vTarget, "z");
			vOpp	= getentityproperty(vTarget, "opponent");
			cMHP    = getentityproperty(vTarget, "maxhealth");
			cHP     = getentityproperty(vTarget, "health");

			if(vOpp)
			{
				cON		= getentityproperty(vOpp, "defaultname");
				cOA		= getentityproperty(vOpp, "name");
			}
			else
			{
				vOpp	= "NA";
				cON		= "NA";
				cOA		= "NA";
			}

			settextobj(3, 10, 50, 2, -1, "Handle: "		+	vTarget	+	", Name: "	+	cName	+	", Alias: "	+	cAlias);
			settextobj(4, 10, 60, 2, -1, "D: "			+	iD		+	", B: "		+	fB		+	", X: "		+	fX	+	", Y: "	+	fY	+	", Z: "	+	fZ);
			settextobj(5, 10, 70, 2, -1, "Opponent: "	+	vOpp	+	", "		+	cON		+	", "		+	cOA);
			settextobj(6, 10, 80, 2, -1, "Health: "	    +	cHP	    +	" of "		+	cMHP);

		}
	}
	else if(iDebug == 2)	//Weapons.
	{
		iEnt	= key0006(vEnt, "debug_bind0010_i1",	iEnt, 0,		NULL(), iECnt,	NULL(), iKAtkH,		iKRt, iKLt, 1);	//Entity index.

		if (!iEnt){	iEnt = 0;	}																							//Null to 0.

		vTarget = getentity(iEnt);																							//Get entity handle.
        iECnt	= openborvariant("ent_max");																				//Get count of entites.

		settextobj(0, 10, 30, 1, -1, "Debug: " + iDebug + ", General Info");
		settextobj(1, 10, 40, 2, -1, "SP: Index: ("+iEnt+"/"+iECnt+")");

        if(vTarget																											//Valid handle?
			&& getentityproperty(vTarget, "exists"))																		//Valid entity?
		{
			iDB1 = key0006(vEnt, "debug_bind0010_i2",	iDB1, 0,		NULL(), 20,		NULL(), iKAtkH,		iKUp, iKDn, 1);	//Weapon select.

			cName	= getentityproperty(vTarget, "defaultname");
			cAlias	= getentityproperty(vTarget, "name");

			settextobj(3, 10, 50, 2, -1, "Handle: "		+	vTarget	+	", Name: "	+	cName	+	", Alias: "	+	cAlias);
			settextobj(4, 10, 60, 2, -1, "Weapon: "		+	iDB1);

			if(iDB1 == 2)
			{
				changeentityproperty(vTarget, "model", "ax_rdrag", 1);
			}
			else
			{
				changeentityproperty(vTarget, "weapon", iDB1);
			}
		}
	}
	else if(iDebug == 3)	//Grappling.
	{
		iDB1	= getindexedvar(CONF_DRAWMODE);																//Get current draw setting.
		iDB1	= key0006(vEnt, "debug_draw0001_imode", iDB1, 0,		NULL(), 1,		NULL(), iKAtkH,		iKRt, iKLt, 1);

		setindexedvar(CONF_DRAWMODE, iDB1);																	//Apply value.

		settextobj(0, 10, 30, 1, -1, "Debug: "			+	iDebug	+	", Draw");						//Show Debug mode.
		settextobj(1, 10, 40, 2, -1, "Mode: "			+	iDB1);										//Show Draw Mode.
	}
	else if(iDebug == 4)
	{
		iBM = key0006(vEnt, "debug_bind0010_iMode",		iBM, 0,			NULL(), 7,		NULL(), iJmpH,		iKRt, iKLt, 1);	//Bind Mode (see bind0010).
		iBA = key0006(vEnt, "debug_bind0010_iAni",		iBA, 0,			NULL(), 1,		NULL(), iJmpH,		iKUp, iKDn, 1);	//Bind Animation (see bind0010).
		iBI = key0006(vEnt, "debug_bind0010_iIndex",	iBI, 0,			NULL(), NULL(),	NULL(), iKAtkH,		iKRt, iKLt, 1);	//Bind index (targeted entity).
	    iBP = key0006(vEnt, "debug_bind0010_iPose",		iBP, 0,			NULL(), 16,		NULL(), iKAtkH,		iKUp, iKDn, 1);	//Bind pose.
		iBX = key0006(vEnt, "debug_bind0010_iX",		iBX, NULL(),	NULL(), NULL(), NULL(), iKAtk2H,	iKRt, iKLt, 1);	//Bind X offset.
		iBY = key0006(vEnt, "debug_bind0010_iY",		iBY, NULL(),	NULL(), NULL(), NULL(), iKAtk2H,	iKUp, iKDn, 1);	//Bind Y offset.
		iBZ = key0006(vEnt, "debug_bind0010_iZ",		iBZ, NULL(),	NULL(), NULL(), NULL(), iKAtk3H,	iKUp, iKDn, 1);	//Bind Z offset.
		iBD = key0006(vEnt, "debug_bind0010_iDir",		iBD, -2,		NULL(), 2,		NULL(), iKAtk3H,	iKRt, iKLt, 1);	//Bind direction set.
		iBF = key0006(vEnt, "debug_bind0010_iFrame",	iBF, 0,			NULL(), NULL(), NULL(), iKAtk4H,	iKRt, iKLt, 1);	//Current frame.
		iRB = key0006(vEnt, "debug_bind0010_Rebind",	iRB, 0,			NULL(), 1,		NULL(), iKAtk4H,	iKUp, iKDn, 1);	//Rebind on each frame change toggle.

		vTarget = getglobalvar(vEnt + ".bind." + iBI);

        if(vTarget)
		{
			cName = getentityproperty(vTarget, "defaultname");
		}
		else
		{
            cName = "None";
        }

		if (!iBM){ iBM = 0; }
		if (!iBA){ iBA = 0; }
        if (!iBI){ iBI = 0; }
        if (!iBP){ iBP = 0; }
        if (!iBX){ iBX = 0; }
        if (!iBY){ iBY = 0; }
        if (!iBZ){ iBZ = 0; }
        if (!iBD){ iBD = 0; }
        if (!iBF){ iBF = 0; }
        if (!iRB){ iRB = 0; }

		/*
		Bind state string conversion
		*/
		//if(iBS == 0){       cBS = "G_STATENOHIT";   }
        //else if(iBS == 1){  cBS = "G_STATEATKBOX";  }
        
		/*
		Bind mode string conversion.
		*/
		cBM = "G_MODE" + iBM;
		
        /*
		Held pose string conversion
		*/
		if(iBP == 0){       cFrame = "G_HELD";   }
        else if(iBP == 1){  cFrame = "G_HELDP";  }
        else if(iBP == 2){  cFrame = "G_HORUP";  }
        else if(iBP == 3){  cFrame = "G_HORDN";  }
        else if(iBP == 4){  cFrame = "G_VERUP";  }
        else if(iBP == 5){  cFrame = "G_VERDN";  }
        else if(iBP == 6){  cFrame = "G_TLTUP";  }
        else if(iBP == 7){  cFrame = "G_TLTDN";  }
        else if(iBP == 8){  cFrame = "G_VERDNP"; }
        else if(iBP == 9){  cFrame = "G_DWNUP";  }
        else if(iBP == 10){ cFrame = "G_DWNUPP"; }
        else if(iBP == 11){ cFrame = "G_FALUP";  }
        else if(iBP == 12){ cFrame = "G_FALUPT"; }
        else if(iBP == 13){ cFrame = "G_HORUPP"; }
        else if(iBP == 14){ cFrame = "G_HELDMP"; }
		else if(iBP == 15){ cFrame = "G_EX1"; }
		else if(iBP == 16){ cFrame = "G_EX2"; }
		
		if(iBA == 0)
		{
			iBA		= openborconstant("ANI_FOLLOW10");
			cAni	= openborconstant("ANI_FOLLOW10");			
		}
		else if(iBA != 1)
		{
			iBA		= A_PAIN;
			cAni	= "A_PAIN";
		}
		
		/* Direction adjustments */
		if(iBD == DIR_ADJ_LEFT){			cBD = "DIR_ADJ_LEFT";	}
		else if(iBD == DIR_ADJ_NONE){		cBD = "DIR_ADJ_NONE";	}
		else if(iBD == DIR_ADJ_OPP){		cBD = "DIR_ADJ_OPP";	}
		else if(iBD == DIR_ADJ_RIGHT){		cBD = "DIR_ADJ_RIGHT";	}
		else if(iBD == DIR_ADJ_SAME){		cBD = "DIR_ADJ_SAME";	}

        settextobj(0, 10, 30, 1, -1, "Debug: "			+	iDebug	+	", Grappling");
		settextobj(1, 10, 40, 2, -1, "JP: Bind Mode("	+	cBM		+	"), Ani("		+	cAni	+	")");
        settextobj(2, 10, 50, 2, -1, "A1: Index("		+	iBI		+	"; "			+	cName	+	"), Pose("	+	iBP	+"; " + cFrame + ")");
        settextobj(3, 10, 60, 2, -1, "A2: X("			+	iBX		+	"), Y("			+	iBY		+	")");
        settextobj(4, 10, 70, 2, -1, "A3: Dir("			+	cBD		+	"), Z("			+	iBZ		+	")");
        settextobj(5, 10, 80, 2, -1, "A4: Frame("		+	iBF		+	"), Rebind("	+	iRB		+	")");
		settextobj(6, 10, 90, 2, -1, "SP: Log binding command.");

        if(vEnt && (iKAtk4H && (iKRt || iKLt)))
        {
            updateframe(vEnt, iBF);
        }

        if(iRB)
		{
            bind0010(iBM, vEnt, iBI, iBX, iBY, iBZ, iBD, iBA, iBP, 0);
        }

		changeentityproperty(vEnt, "tosstime", openborvariant("elapsed_time") + 10000000000);
		changeentityproperty(vEnt, "velocity", 0, 0, 0);

        if(iKSp)
        {
            log("\n Bind Command, frame " + iBF + ": ");
			log("@cmd bind0010 " + cBM + " ENT_SELF " + iBI + " " + iBX + " " + iBY + " " + iBZ);
			log(" " + cBD + " " + cAni + " " + cFrame + " G_STATENOHIT");
        }
	}
}
