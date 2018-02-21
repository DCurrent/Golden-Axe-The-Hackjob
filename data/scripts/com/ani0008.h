
void ani0008(int iTarget, int iMap, int iAni, int iFrame, int iKill, int A, int B, int C, int E, int F){

    /*
    ani0008
    Damon Vaughn Caskey
    10262009
    Change properties of entity in found in designated variable.

    iTarget:    Target entity var (by index).    
    iMap:       Remap.
    iAni:       Animation.
    iFrame:     Animation frame.
    iKill:      Autokill property.
    */

    void vSelf   = getlocalvar("self");
    void vTarget = getentityvar(vSelf, iTarget);
    
    changeentityproperty(vTarget, "animation", iAni);
    changeentityproperty(vTarget, "autokill", iKill);
}