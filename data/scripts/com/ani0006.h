
void ani0006(int iSkip, int iReps){
     
     /*
     ani0006
     Damon Vaughn Caskey
     05/11/2008
     Skip back or forward to specified frame.
     
     iSkip: Number of frames to fall back (or forward).
     iReps: How many times to skip or fall back. 0 = Infinity.
     */
     
     void vSelf = getlocalvar("self");                  //Calling entity.
     int iFrame = getentityproperty(vSelf, "animpos");  //Caller's frame.
     
     updateframe(vSelf, iFrame + iSkip);                     //Switch to desired frame.
     
}