#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

int key0006(void vEnt, char cVar, float fVal, int iMin, int iMinL, int iMax, int iMaxL, int iKHold, int iKIncr, int iKDecr, float fQnt){
     
	/*
	vEnt:	Target for keycalls.
	cVar:	If passed, global var name to store selected value.
	fVal:	Initial value (overidden by cVar if passed).
	iMin:	Minimum selectable value. NULL() = No minimum.
	iMinL:	0 = Ignore decrement request if at minimum. 1 = Loop to maximum.
	iMin:	Maximum selectable value. NULL() = No maximum.
	iMinL:	0 = Ignore increment request if at maximum. 1 = Loop to minimum.
	iKHold:	Optional key that must be active ("held") when increment/decrement key is pressed.
	iKIncr:	Increment key.
	iKDecr:	Decrement key.
	fQnt:	Quantity to increment or decrement.
	*/

    if ((iKHold || iKHold == NULL()) && (iKIncr || iKDecr))		//Hold key value not 0 and decrement/increment key pressed?
	{   
        if(cVar)												//Name for global var passed?
        {
            fVal == getglobalvar(cVar);							//Get initial value from global var.
            
            if(!fVal && fVal != 0)								//Initial value is 0?
            {                     
                 fVal = NULL();									//Set value to NULL().
            }
        }        
       
        changeplayerproperty(vEnt, "playkeys", FLAG_NONE);		//Clear player key events.
                                 
        if(iKIncr)												//Increment?
        {   
            fVal += fQnt;										//Increment value.
    
            if(fVal == NULL())									//Value is NULL()?
            {
                if(iMin != NULL())								//Minimum passed?
                {
                    fVal = iMin;								//Set value to minimum.
                }
                else											//No minimum passed.
                {
                    fVal = 0;									//Set value to 0.
                }
            }
            
            if(iMax != NULL() && fVal>iMax)						//Max passed and value over it?        
            {             
                if(iMaxL == NULL())								//Max parameter is NULL()?
                {
                    fVal = NULL();								//Set value to NULL().
                }
                else if(iMaxL)									//Max loop.
                {
                    fVal = iMin;								//Set value to minimum.
                }
                else											//NO max loop.
                {
                    fVal = iMax;								//Set value to maximum.
                }
            }
        }
        else if(iKDecr)
        {
            fVal -= fQnt;
            
            if(fVal == NULL())
            {
                if(iMax != NULL())
                {
                    fVal = iMax;
                }
                else
                {
                    fVal = 0;
                }
            }
            
            if(iMin != NULL() && fVal<iMin)         
            {             
                if(iMinL == NULL())
                {
                    fVal = NULL();
                }
                else if(iMinL)
                {
                    fVal = iMax;
                }
                else
                {
                    fVal = iMin;
                }
            }                                  
        }        
        
        if(cVar)
        {
            setglobalvar(cVar, fVal);
        }
        
        return fVal;       
	}	
}
