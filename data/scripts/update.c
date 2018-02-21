#include	"data/scripts/vars/constants.h"

#import	"data/scripts/traileru.c"		//Shadow trails.
//#import	"data/scripts/com/ani0013.h"	//Jump animation if steping off an edge.

void main()
{
    void    vEnt;                                                                           //Entity placeholder.
    void    vMap;                                                                           //Color array placeholder.
    char    cName;                                                                          //Entity default name.
    int     iAni;                                                                           //Animations.
	int		iLiv    = -1;                                                                   //Living enemies.
	int		iKMap;                                                                          //KO map.
    int     iType;                                                                          //Entity type.
    int     iVRes   = openborvariant("vresolution");                                        //Current vertical resolution.
    int     iECnt   = openborvariant("ent_max");                                            //Current # of entities in play.
	int		iIndex;                                                                         //Player index.
    int     iEnt;                                                                           //Entity counter.
    int     iHSpr;                                                                          //Sprite index.
    float   fCnt    = 0.0;                                                                  //General counter.
    float   fJar;                                                                           //Mp Jar count.
    float   health;                                                                         //Current health
    float   fHPer;                                                                          //HP % of max.
    float   fFron   = 0.0;                                                                  //Front percentage (top 1/4 of HP)
    int     iDrop;                                                                          //Falling/Fallen AI flag.


	//Give Debug text a background.
	if (getglobalvar("debug_set"))
	{
		drawbox(0, 25, 480, 80, SYS_FRONTZ, RGB_BLACK, 6);
	}

	//tupdate();

	for(iEnt=0; iEnt<iECnt; iEnt++)                                                         //Loop entity collection.
	{

		vEnt = getentity(iEnt);                                                             //Get entity handle.

		if(vEnt                                                                             //Valid handle?
            && getentityproperty(vEnt, "exists")                                            //Valid entity?
            && !getentityproperty(vEnt, "dead"))                                            //Alive?
		{

            // Experiment to disable movement. Does not work.
			//changeplayerproperty(vEnt, "playkeys", FLAG_NONE);

			iDrop   = getentityproperty(vEnt, "aiflag", "drop");                            //Drop status.
            iType   = getentityproperty(vEnt, "type");                                      //Get type.
            iAni    = getentityproperty(vEnt, "animationid");                               //Get current animation.

            if(getentityproperty(vEnt, "owner")== NULL())                                    //Not projectile?
            {
			    if(iDrop)																	//Falling?
			    {
				    changeentityproperty(vEnt, "stealth", 1);								//Set stealth.
			    }
			    else
                {
                    cName   = getentityproperty(vEnt, "defaultname");                       //Get default name.

                    if(cName != "yamoto"                                                    //Not Yamoto?
                        &&  !(cName == "Alex" && iAni == A_RISEATK)							//Not Alex doing a rise attack?
                        &&  iAni != A_SLEEP)												//Not in sleep ani?
			        {
				        changeentityproperty(vEnt, "stealth", 0);                           //Turn stealth off.
                    }

				    //ani0013(vEnt, iAni, 0);                                                 //Auto jump from platforms.
                }
            }

		    if ((iType && iType == TYPE_PLAYER))												//Player type?
		    {
				iIndex	= getentityproperty(vEnt, "playerindex");                           //Get player index.
				fJar	= getentityproperty(vEnt, "mp")/10;                                 //MP jar count.
				fHPer   = 4 * (0.0 + (hlife(vEnt)));                                        //Get life % in quarters.
				iHSpr   = getindexedvar(IDXG_ICOJAR);                                            //Get magic jar sprite.

				for(fCnt=0; fCnt<fJar; fCnt++)                                              //Loop jar count.
				{
					drawsprite(iHSpr, iIndex*160+55+fCnt*11, iVRes-20, SYS_FRONTZ+18001);     //Draw magic jars
				}

				for(fCnt=0.0; fCnt<fHPer; fCnt++)                                           //Loop each quater of life.
				{
					fFron   = fHPer - fCnt;
                    iHSpr   = getindexedvar(lblock(fFron));                                 //Get life block sprite.

					drawsprite(iHSpr, iIndex*160+53+fCnt*26, iVRes-31, SYS_FRONTZ+18001);     //Draw life block.
				}
		    }
			else
			{
			    if(iDrop || getentityproperty(vEnt, "aiflag", "inpain") || iAni == AC_DEFPOSE) //Getting ass kicked?
			    {
                    iHSpr	= getentityproperty(vEnt, "spritea", "sprite", AC_ICONS, ICON_AIPAIN);    //Get AI pain icon.
			    }
                else
                {
                    iHSpr	= getentityproperty(vEnt, "spritea", "sprite", AC_ICONS, ICON_AI);    //Get AI normal icon.
                }

                if(iHSpr)																	//Sprite valid?
                {
                    fHPer   = hlife(vEnt);                                                  //Get life block sprite.
                    vMap    = getentityproperty(vEnt, "colourmap");
                    ++iLiv;                                                                 //Increment "living" index.

                    setdrawmethod(NULL(), 1, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, vMap);    //Set global draw method.
                    drawsprite(iHSpr, (iLiv*41), 4, SYS_FRONTZ+18000);                        //Draw icon.
                    setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL());  //Restore global draw defaults.

                    iHSpr   = getindexedvar(lblock(fHPer));                                 //Get life block sprite.
                    drawsprite(iHSpr, 16+(iLiv*41), 8, SYS_FRONTZ+18000);						//Draw life block.
                }
			}
        }
	}
}

float hlife(void vEnt)
{
	float fHP	= 0.0 + getentityproperty(vEnt, "health");
	float fMHP	= 0.0 + getentityproperty(vEnt, "maxhealth");

	return fHP/fMHP;
}

int lblock(float fPer){

    int iHSpr;

    if (fPer >= 0.75)
    {
        iHSpr = IDXG_BLOCBLU;  //Blue
    }
    else if (fPer >= 0.50)
    {
        iHSpr = IDXG_BLOCYEL;  //Yellow
    }
    else if (fPer >= 0.25)
    {
        iHSpr = IDXG_BLOCORA;  //Orange
    }
    else
    {
        iHSpr = IDXG_BLOCRED;  //Red
    }

    return iHSpr;
}
