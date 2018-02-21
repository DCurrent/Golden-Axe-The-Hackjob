#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/ani0009.h"

void z_block(void vEnt){
    
	/*
	z_block
	Damon Vaughn Caskey
	2010_07_31
	~2011_02_25
	
	Universal blocking function.

	vEnt:	Calling entity.
	*/

    void vAttacker  = getlocalvar("attacker");                                              //Attacking entity.
    int  iHeight;                                                                           //Caller height.            
    int  iHitY;                                                                             //Last hit Y.    
    int  iAni;																				//Caller animation.
    int  fY;                                                                                //Attacker Y location.
    int  iBase;                                                                             //Attacker base Y.
    int  iBlockAni;                                                                         //Final block animation.
    int  iTime		= openborvariant("elapsed_time");                                       //Elapsed game time.
    int  iKeylst;																			//Time of last Special press.
	
	if(!vEnt){	vEnt = getlocalvar("self");	}

	iAni		=	getentityproperty(vEnt, "animationid");									//Get caller animation.
	iKeylst		=	getentityvar(vEnt, IDXE_KEY1SP);												//Get last time Special Key was pressed.

    //Fatal Fury style proximity blocking. If entity is blocking (not an attack with autoblock), 
    //switch to the appropriate block animation based on height of incomming attack.
    if (iAni == A_BLOCK																		//In block animation? 
        || iAni == AC_BLOCKNOR
        || iAni == AC_BLOCKLOW
        || iAni == AC_BLOCKMID
        || iAni == AC_BLOCKHIGH)
    {
        iHeight = getentityproperty(vEnt, "height") + getentityproperty(vEnt, "base");		//Get current height + base.
        iHitY   = openborvariant("lasthita");                                               //Get Y axis of last hit.
    
        if (iHitY < iHeight * 0.3)                                                          //Below 30% of height?
        {
            iBlockAni = AC_BLOCKLOW;                                                           //Low block.
        }
        else if (iHitY < iHeight * 0.75)                                                    //Below 75% of height?
        {
            iBlockAni = AC_BLOCKMID;                                                           //Middle block.
        }
        else                                                                                //Attack is at or above 75% of height.
        {
            fY          = getentityproperty(vAttacker, "a");                                //Get attacker height.
            iBase       = getentityproperty(vAttacker, "base");                             //Get attacker base.

            if ((fY - iBase) > 1)                                                           //Attacker airborne?
            {
                iBlockAni = AC_BLOCKHIGH;                                                      //High block.
            }
            else
            {
                iBlockAni = AC_BLOCKNOR;                                                       //Normal block (BLOCKPAIN).                
            }
        }
        
        ani0009(vEnt, iBlockAni, -1);														//Apply block animation.
    }        
}
