
void stat0002(int iTime, int iBlink, int a, int b, int c){

    /*
    stat0002
    Copied from riseinv by Utunnels.
    
    Set caller's invincibility.
    */

    void self = getlocalvar("self");
	changeentityproperty(self, "invincible", 1);
	changeentityproperty(self, "blink", iBlink);
	changeentityproperty(self, "invinctime", iTime+openborvariant("elapsed_time"));
}
