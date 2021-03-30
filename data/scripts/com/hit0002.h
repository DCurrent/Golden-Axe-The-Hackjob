#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0012.h"
#import "data/scripts/com/hit0001.h"
#import "data/scripts/com/jump0002.h"

void hit0002(){
    
    //Primary didhit function; called by almost all entities when hitting another entity.

    void  vSelf         = getlocalvar("self");                  //Calling entity. 
    void  vDefender;                                            //Defender.  
    int   iType         = getentityvar(vSelf, IDXE_HITTYP);          //On hit flag (type).
    int   iReset        = getentityvar(vSelf, IDXE_HITNOR);          //On hit flag (reset on hit).
    int   iEDamage;                                             //Extra damage flag.
    int   iELethal;                                             //Non leathal damage (damage cannot reduce HP below 1) flag.    
    int   iEDrop;                                               //Extra damage drop flag.
    int   iReset;                                               //No reset flag.
    float fTossX;                                               //Toss X.
    float fTossY;                                               //Toss Y.
    float fTossZ;                                               //Toss Z.
    int   iHeight;                                              //Tagret's height setting.
    int   iDefHP;                                               //Defender's health.    
    int   iDrop;                                                //Attaclk knockdown power.
    int   iKnock;                                               //Defender's kncodkown remaining.

    if (getlocalvar("blocked"))                                 //Attack blocked?
    {     
        if (iType && !iReset)                                   //Hit flag type present but reset flag not? 
        {                               
            hit0001(0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);    //Erase hit flags.
        }
    }
    else                                                        
    {        
        vDefender   = getlocalvar("damagetaker");               //Get defender.        

        if(iType)                                               //Extra damage type not null??
        {            
            //Get remaining hit flags and defender values.
            iEDamage    = getentityvar(vSelf, IDXE_HITDMG);            
            iELethal    = getentityvar(vSelf, IDXE_HITFIN);                    
            iEDrop      = getentityvar(vSelf, IDXE_HITDRP);                        
            fTossX      = getentityvar(vSelf, "dc_next_toss_x");             
            fTossY      = getentityvar(vSelf, "dc_next_toss_y");             
            fTossZ      = getentityvar(vSelf, "dc_next_toss_z");
            iReset      = getentityvar(vSelf, IDXE_HITNOR);
                        
            iDefHP      = getentityproperty(vDefender, "health");                   //Get Defender's health.

            if (iType == -1)                                                        //If -1 passed, use incoming attack type.
            { 
                iType = getlocalvar("attacktype");
            }

            if (!iEDamage)                          { iEDamage = 0;             }   //If NULL(), convert to 0.
            if (!iEDrop)                            { iEDrop   = 0;             }   //If NULL(), convert to 0.
            if (iELethal && (iEDamage >= iDefHP))   { iEDamage  = iDefHP - 1;   }   //If non lethal damage exceeds HP, reduce to remaining HP - 1.
            if (iEDamage >= iDefHP)                 { iEDrop    = 100;          }   //If final value will kill defender, make sure to drop them. Otherwise they will be left on screen in an idle state.
            
            damageentity(vDefender, vSelf, iEDamage, iEDrop, iType);                //Apply final damage values to vDefender.           

            if (fTossX || fTossY || fTossZ)                                         //Toss effect added? Set variables on vDefender to apply in onfallscript.
            { 
                iKnock = getentityproperty(vDefender, "knockdowncount");            //Get defender's remaining knockdown.
                iDrop  = getlocalvar("drop");

                if (iEDrop > iKnock || iDrop > iKnock)                              //Will defender be knocked down?
                {
                    if (getentityproperty(vDefender, "direction"))
                    { 
                        fTossX = -fTossX; 
                    }        
                    tossentity(vDefender, fTossY, fTossX, fTossZ);                  //Toss opponent. 
                    //setentityvar(vDefender, "dc_next_toss_x", fTossX);
                    //setentityvar(vDefender, "dc_next_toss_y", fTossY);
                    //setentityvar(vDefender, "dc_next_toss_z", fTossZ);
                }
            }               

            bind0012(vDefender);                                                    //Run hitwarp.             
        }       

        if (!iReset)                                                                //No reset flag?
        {
            hit0001(0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);                        //Erase hit flags.
        }
    }    
}
