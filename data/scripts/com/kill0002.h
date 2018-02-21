void kill0002(int iTarget){

    /*
    kill0002
    Damon Vaughn Caskey
    10262009
    Kill entity in found in designated variable.

    iTarget: Target entity var (by index).    
    */

    void vSelf   = getlocalvar("self");
    void vTarget = getentityvar(vSelf, iTarget);
    
    killentity(vTarget);
}
