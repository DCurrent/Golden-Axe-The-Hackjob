#import "data/scripts/com/targ0001.h"

void dama0001(void vTar, int iHP, int iDrop, void vType, int iDir, float fY, float fX, float fZ, int iDOL, int iAttacking, int iProj){

     /*
     dama0004
     Damon Vaughn Caskey
     04/02/2008
     Damage caller's target.

     vTar:          Target entity. See targ0001 function.
     iHP:           Amount of damage to apply.
     iDrop:         Knockdown.
     vType:         Attack type.
     iDir:          Force direction.
     fX/fY/fZ:      Toss entity parameters.
     iDOL:          Damage on landing.
     iAttacking:    Attacking flag.
     iProj:         Projectile flag.
     */

     void vSelf   = getlocalvar("self");                        //Calling entity.
     void vTarget = targ0001(vTar, vSelf);                      //Target entity.
     int  iSDir   = getentityproperty(vSelf, "direction");      //Calling entity facing.
     int  iTDir   = getentityproperty(vTarget, "direction");    //Target entity facing.
     int  iType   = openborconstant(vType + "");                //Attack type.

     /*
     Quick and dirty fix. As of version 2.1954, openborconstant returns empty value for "ATK_NORMAL# > 10".

     ATK_NORMAL	   0
     ATK_NORMAL2   1
     ATK_NORMAL3   2
     ATK_NORMAL4   3
     ATK_BLAST	   4
     openborconstant("ATK_BURN")	   5
     ATK_FREEZE	   6
     ATK_SHOCK	   7
     ATK_STEAL     8
     ATK_NORMAL5   9
     ATK_NORMAL6  10
     ATK_NORMAL7  11
     ATK_NORMAL8  12
     ATK_NORMAL9  13
     ATK_NORMAL10 14
     ATK_ITEM	  15
     */
     if (!iType && vType != "ATK_NORMAL"){ iType = vType; }

     changeentityproperty(vTarget, "dead", 0);
     damageentity(vTarget, vSelf, iHP, iDrop, iType);                       //Apply attack/damage.
     changeentityproperty(vTarget, "damage_on_landing", iDOL);              //Set damage on landing flag.
     changeentityproperty(vTarget, "attacking",         iAttacking);        //Set attacking flag.
     changeentityproperty(vTarget, "projectile",        iProj);             //Set "hit others" flag.

         if (iDir == 1)
         {
             iTDir = iSDir;                                                 //Same as self.
         }
         else if (iDir == 2)												//Right.
         {
             iTDir = 1;
         }
         else if (iDir == -1)												//Opposite of self.
         {
             if (iSDir)
             {
                 iTDir = 0;
             }
             else
             {
                 iTDir = 1;
             }
         }
         else if (iDir == -2)												//Left.
         {
             iTDir = 0;
         }

     if (!iSDir){ fX = -fX; }

     if (fY || fX || fZ) { tossentity(vTarget, fY, fX, fZ); }               //If velocity provided, toss em'.
     changeentityproperty(vTarget,"direction", iTDir);                      //Change direction.

}
