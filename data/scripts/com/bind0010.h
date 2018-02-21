#include	"data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import	"data/scripts/com/ani0009.h"	//http://www.caskeys.com/dc/?p=1314#ani0009
#import	"data/scripts/com/draw0001.h"   //http://www.caskeys.com/dc/?p=1314#draw0001
#import	"data/scripts/com/draw0002.h"   //http://www.caskeys.com/dc/?p=1314#draw0002
#import	"data/scripts/com/bind0021.h"   //http://www.caskeys.com/dc/?p=1314#bind0021
#import	"data/scripts/com/ht0001.h"     //http://www.caskeys.com/dc/?p=1314#ht0001

void bind0010(int iMode, void vEnt, int iIndex, int iX, int iY, int iZ, int iDir, int iAni, int iFrame, int iState){

    /*
    bind0010
    Damon Vaughn Caskey
    2008_12_21
	~2011_06_29

    Grapple binding. Binds and sets target entity into desired pose, or sets position and releases.

	iMode:		Type of bind
					0 = standard
					1 = Bind by self location - height adjustment
					5 = Bind by target location
					6 = Bind by target location using target height
					7 = 6 with tosstime addition to prevent "falling" and premature landframe triggers.
					8 = 7 With entity also frozen in selected frame.
    vEnt:       Anchor entity.
	iIndex:		Entity index. Allows binding of multiple entities.
    iX, iY, iZ: Location offsets.
    iDir:       Direction; 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
    iFrame:		-1 = Release bind, 0+ Animation frame to set.
	iState:		Falling/projectile setup. Needed to ensure proper hit/no hit of opponents or allies.
    */

    void	vTarget;														//Target entity to bind.
    float	fRatio;															//Ratio to apply to bind (accomidates Z based zoom).
    int		iTime;															//OpenBOR elapsed time.
    int		iH;																//Entity height.
	float	fXV, fYV, fZV;													//Entity velocity.
	float	fX, fY, fZ;														//Location.

    if (!vEnt){ vEnt = getlocalvar("self"); }								//If no entity passed, use caller.

    fRatio  = getentityvar(vEnt, IDXE_ADSCALER);                                 //Ent's current scale ratio.
    vTarget = getglobalvar(vEnt + ".bind." + iIndex);                       //Get entity by bind index.

    if (vTarget)                                                            //Make sure there is a legit target.
    {
        iTime   = openborvariant("elapsed_time");                           //Get elapsed time.
        fRatio  = getentityvar(vEnt, IDXE_ADSCALER);                             //Get caller's current scale ratio.

        if (iX){ iX = draw0002(fRatio, iX); }                               //If X adjustment, apply scaling.
        if (iY){ iY = draw0002(fRatio, iY); }                               //If Y adjustment, apply scaling.

		/*
		Modes to deal with alternate binding needs such as binding on Target's location instead of Ent's
		and auto adjusting by height settings to accommodate divergent character sizes.
		*/
		if(iMode == 1)														//Mode 1?
		{
			iH	=	ht0001(vTarget) - ht0001(vEnt);							//Get difference between ent and target's current height.
			iY	+=	iH;														//Add difference to to iY.
		}
		else if(iMode >= 5 && iMode <= 8)									//Mode 5 to 8?
		{
			fX	=   getentityproperty(vTarget, "x");						//Get target X.
			fY	=	getentityproperty(vTarget, "a") - iY;					//Get target Y location with Y adjustment.
			fZ	=	getentityproperty(vTarget, "z") - iZ;					//Get target Z location with Z adjustment.

			if(getentityproperty(vTarget, "direction")==0)
			{
				fX -= iX;													//Get target X location with X adjustment.
			}
			else
			{
				fX	+= iX;													//Get target X location with X adjustment.
			}

			if(iMode >= 6 && iMode <= 8)									//Mode 6 to 8? Apply height adjustments.
			{
				iH	=	ht0001(vTarget) - ht0001(vEnt);						//Get difference between ent and target's current height.
				fY	+=	iH;													//Add height difference to Target location.
				iY	-=	iH;													//Subtract height difference from altitude adjustment.
			}

			changeentityproperty(vEnt, "position", fX, fZ, fY);				//Move ent to target's position.

			if(iMode >= 7 && iMode <= 8)									//Mode 7? Add tosstime.
			{
				changeentityproperty(vEnt, "tosstime", iTime + 10000000);	//Jack up Tosstime (otherwise will "fall" from a Y adjustment).
			}
		}

		
		
		bindentity(vTarget, vEnt, iX, iZ, iY, iDir, 0);						//Bind target to ent.
		changeentityproperty(vTarget, "stalltime", iTime + 10000000);       //Jack up stalltime to disable default special moves.
        bind0021(vEnt, vTarget);											//Wall failsafe (shunt away from a wall if bound entity will be inside of it).
		draw0001(vTarget);                                                  //Refresh draw settings.

		if (iFrame < 0)                                                     //Frame -1? Then let's release bind.
		{
			bindentity(vTarget, NULL());									//Release bind (target from ent).

            if (iFrame == -2)
            {
                setglobalvar(vEnt + ".bind." + iIndex, NULL());             //Remove record of binding from self.
				setentityvar(vTarget, IDXE_BOUNDA, NULL());						//Remove record bound anchor from target.
				setentityvar(vTarget, IDXE_BOUNDI, NULL());						//Remove record bound Index from target.
				setentityvar(vTarget, IDXE_BOUNDX, NULL());						//Remove record bound X from target.
				setentityvar(vTarget, IDXE_BOUNDY, NULL());						//Remove record bound Y from target.
				setentityvar(vTarget, IDXE_BOUNDZ, NULL());						//Remove record bound Z from target.
				setentityvar(vTarget, IDXE_BOUNDD, NULL());						//Remove record bound direction from target.
				setentityvar(vTarget, IDXE_BOUNDF, NULL());						//Remove record bound frame from target.
			}

			if(iMode == 8)													//Mode 8? Freeze time in place.
			{
				changeentityproperty(vEnt, "frozen", 0);					//Turn off freeze.
				changeentityproperty(vEnt, "freezetime", 0);				//Reset freezetime.
			}
		}
		else
		{
			setglobalvar(vEnt + ".bind." + iIndex, vTarget);                //Make record of binding.
			setentityvar(vTarget, IDXE_BOUNDA, vEnt);							//Record bound anchor on target.
			setentityvar(vTarget, IDXE_BOUNDI, iIndex);							//Record bound index on target.
			setentityvar(vTarget, IDXE_BOUNDX, iX);								//Record bound X on target.
			setentityvar(vTarget, IDXE_BOUNDY, iY);								//Record bound Y on target.
			setentityvar(vTarget, IDXE_BOUNDZ, iZ);								//Record bound Z on target.
			setentityvar(vTarget, IDXE_BOUNDD, iDir);							//Record bound direction on target.
			setentityvar(vTarget, IDXE_BOUNDF, iFrame);							//Record bound frame on target.

			performattack(vTarget, iAni, 1);								//Set defense pose.
			changeentityproperty(vTarget, "animpos", iFrame);               //Set frame.

			if(iMode == 8)													//Mode 8? Freeze time in place.
			{
				changeentityproperty(vEnt, "frozen", 1);					//Turn on freeze.
				changeentityproperty(vEnt, "freezetime", iTime + 10000000);	//Jack up freezetime.
			}

		}
		
		/*
		Falling and projectile status.
		*/
		if(!iState)
		{	
			//Falling. Cannot hit.

			changeentityproperty(vTarget, "aiflag", "drop", 1);
			changeentityproperty(vTarget, "aiflag", "falling", 1);
			changeentityproperty(vTarget, "aiflag", "projectile", 0);			
		}
		else if(iState==1)
		{

			//Falling. Hit according to attackbox & projectilehit settings.

			changeentityproperty(vTarget, "aiflag", "drop", 1);
			changeentityproperty(vTarget, "aiflag", "falling", 1);
			changeentityproperty(vTarget, "aiflag", "projectile", 1);
		}
		
		/*
        Reset engine's lasthit variants. Otherwise, target will assume sweep values when
        knocked down if last normal attack hit low.
        */
        changeopenborvariant("lasthitx", NULL());							//Last hit X.
        changeopenborvariant("lasthita", NULL());							//Last hit Y.
        changeopenborvariant("lasthitz", NULL());							//Last hit Z.
        changeopenborvariant("lasthitt", NULL());							//Last hit type.
    }
}


