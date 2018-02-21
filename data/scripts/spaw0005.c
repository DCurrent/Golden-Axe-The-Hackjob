##include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

//Non moving, non draw entity spawn.

void main(){

    void    vSelf   = getlocalvar("self");
    int     iCount;
    int     iMaxVar = openborvariant("maxentityvars");

    for (iCount = 0; iCount <= iMaxVar; iCount++)
    {
         setentityvar(vSelf, iCount, NULL());
    }    

    ////Initialize new variables.////
    //Entity counter/artificial handle.
    
    int  iList      = getindexedvar(0);                     //Entity counter.
    if (!iList)
    {    
        iList = 0;  //Count not initalized, set to 0.
    }
    else
    {
        iList += 1; //Count initalized, increment by 1.
    }
    
	setentityvar(vSelf, IDXE_ADSCALER, 1);										  //Set scale ratio 9bind functions need this even if item won't use draw).
    setentityvar(vSelf, IDXE_ENTID, iList);                                        //Set artificial handle.
    setindexedvar(0, iList);                                                  //Set entity counter.    
    
}