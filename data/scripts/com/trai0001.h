#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void trai0001()
{
    /*
    trai0001
    Utunnels 
    Unknown Date (Converted to Hungarian Notation by Damon Vaughn Caskey 10262009)
    
    Parses artificial array (created by numerically sequenced global vars) and displays stored sprite
    depending on stored settings.
    */

	int     i;                                                  //Counting placeholder.
	void    vSprite;                                            //Sprite to display.
	int     iDir;                                               //Facing.
    int     cd;                                                 //Expire time.
    void    vMap;                                               //Color map.
	float   fY, fZ, fX;                                         //Location.
    float   fScale;                                             //draw scale.

	for(i=1; i<=CONF_TRAILMAX; i++)                                  //Loop trailer slots.
	{
		vSprite = getglobalvar("trailer"+i+".s");               //Get sprite.
		if(vSprite)                                             //Sprite found?
		{
			cd = getglobalvar("trailer"+i+".c");                //Get expire time.
			if(!cd)                                             //No expire time or decremented to 0?
			{
				setglobalvar("trailer"+i+".c", NULL());         //Clear expire time.
				setglobalvar("trailer"+i+".s", NULL());         //Clear sprite.
				setglobalvar("trailer"+i+".x", NULL());         //Clear X
				setglobalvar("trailer"+i+".z", NULL());         //Clear Y
				setglobalvar("trailer"+i+".a", NULL());         //Clear Z
                setglobalvar("trailer"+i+".m", NULL());         //Clear map.
                setglobalvar("trailer"+i+".r", NULL());         //Clear scale ratio.
			}
			else
			{
				if(openborvariant("game_paused")==0)            //Game active (not paused)?
				{   
					setglobalvar("trailer"+i+".c", cd-1);       //Decrement expire time.
				}
                
				fX      = getglobalvar("trailer"+i+".x");       //Get stored X.
				fZ      = getglobalvar("trailer"+i+".z");       //Get stored Z.
				fY      = getglobalvar("trailer"+i+".a");       //Get stored Y.
				iDir    = getglobalvar("trailer"+i+".f");       //Get stored facing.
                vMap    = getglobalvar("trailer"+i+".m");       //Get stored map.
                fScale  = 256 * getglobalvar("trailer"+i+".r"); //Get scale ratio.
                
				setdrawmethod(NULL(), 1, fScale, fScale, iDir, 0, 0, 6, 0, 0, 0, 0, 0, vMap);           //Set global draw method.                                                  
				drawsprite(vSprite, fX-openborvariant("xpos"), fZ-fY-openborvariant("ypos"), fZ-i, 0);  //Draw stored sprite.
				setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0, 0);                                   //Clear global drawmethod.
			}
		}
	}    
}
