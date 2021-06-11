#include "data/scripts/com/key0004.h"
#include "data/scripts/com/proj0003.h"

void main(){
    
	/*
    Damon Vaughn Caskey
    06/25/2007
    Capture keystrokes and perform actions accordingly.
    */

    int     iPlIndex    = getlocalvar("player");                                    //Player index.
    void    vSelf       = getplayerproperty(iPlIndex, "entity");                    //Get calling entity.
    int     iFlIdle     = getentityproperty(vSelf, "aiflag", "idling");             //Self idling?
    int     iFlAttack   = getentityproperty(vSelf, "aiflag", "attacking");          //Self attacking (freespecial, jumpattack, follow, or attack)?
    int     iFlJump     = getentityproperty(vSelf, "aiflag", "jumping");            //Self jumping?
    int     iUpH        = playerkeys(iPlIndex, 0, "moveup");                        //Hold  "Up".
    int     iDownH      = playerkeys(iPlIndex, 0, "movedown");                      //Hold  "Down".
    int     iLeftH      = playerkeys(iPlIndex, 0, "moveleft");                      //Hold  "Left".
    int     iRightH     = playerkeys(iPlIndex, 0, "moveright");                     //Hold  "Right".
    int     iRight      = playerkeys(iPlIndex, 1, "moveright");                     //Press "Right".
    int     iRightR     = playerkeys(iPlIndex, 2, "moveright");                     //Release "Right".
    int     iUp         = playerkeys(iPlIndex, 1, "moveup");                        //Press "Up".
    int     iDown       = playerkeys(iPlIndex, 1, "movedown");                      //Press "Down".
    int     iSpecial    = playerkeys(iPlIndex, 1, "special");                       //Press "Special".
    int     iJump		= playerkeys(iPlIndex, 1, "jump");							//Press "Jump".
	int     iAttack     = playerkeys(iPlIndex, 1, "attack");                        //Press "Attack".
    int     iAttack3    = playerkeys(iPlIndex, 1, "attack3");                       //Press "Attack3". 
    int     iAttack4    = playerkeys(iPlIndex, 1, "attack4");                       //Press "Attack4".    
	int     iXDir       = getentityproperty(vSelf, "xdir");                         //X velocity.
    int     iTime       = openborvariant("elapsed_time");                           //Current time.
    int     iAni;                                                                   //Current animation.
    int     iFrame;                                                                 //Current animation frame.
    void    vTarget;                                                                //Opponent.    

	log("key");
	iFrame	= getentityproperty(vSelf, "animpos");
    if(iAttack)
    {
		log("attack");
		//Riseattack followup.
		iAni	= getentityproperty(vSelf, "animationid"); 
		iFrame	= getentityproperty(vSelf, "animpos");
		
		if(iAni == openborconstant("ANI_RISEATTACK") && iFrame > 4)
		{        
			changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW2"));
			key0004(vSelf, iLeftH, iRightH);
			changeplayerproperty(vSelf, "playkeys", 0);                         //Clear key event.

		}
		else if(iAni == openborconstant("ANI_FOLLOW5") && iFrame < 12 && !iFlAttack)
		{
			changeentityproperty(vSelf, "aiflag", "attacking", 1);
			eightshot();
			changeplayerproperty(vSelf, "playkeys", 0);                         //Clear key event.
		}
	}
	else if (iJump)
	{
		iAni	= getentityproperty(vSelf, "animationid");
		log("jump");
		if ((iAni == openborconstant("ANI_JUMP") || iAni == openborconstant("ANI_RUNJUMP")) && iFrame == getentityproperty(vSelf, "dropframe", iAni))
		{
			changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW5"));
			tossentity(vSelf, 3.5, iXDir, 0);
		}
	}
}

void eightshot(){

	/*
	eightshot
	Damon Vaughn Caskey
	Perform Joe Musahi's punishing rain attack.
	*/

	int     i;
	void	vModel	= "kuna0001";
	int		iAX		= 10;
	int		iAY		= 30;
	int		iAZ		= -1;
	float   fX      = 2;
	float   fY		= 0;

	proj0003(vModel, iAX, iAY, iAZ, fX, fY, 0, 1, 1, 0, 0);

	for (i=0; i<7; i++)
	{
		fX -= 0.285;
		fY -= 0.485;
		proj0003(vModel, iAX, iAY, iAZ, fX, fY, 0, 1, 1, 0, 0);		
	}

}