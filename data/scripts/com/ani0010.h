
void ani0010(int iAni, int iFrame){

    /*
    ani0010
    Damon Vaughn Caskey
    10262009
    Switch to alternate animation if nearest hostile is in range (of alt).
    */

    void vSelf      = getlocalvar("self");
    
    if (findtarget(vSelf, iAni))
    {    
        changeentityproperty(vSelf, "animation", iAni);
        updateframe(vSelf, iFrame);
    }
    
}
