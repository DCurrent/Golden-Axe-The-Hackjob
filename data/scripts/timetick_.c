void main(){

    int iTBug = getlocalvar("time");
    int iTOldBug = getlocalvar("scroll");

    int     iBase   = getglobalvar("switch");
    int     iPal    = openborvariant("current_palette");
    int     iPalCnt = openborvariant("numpalettes");
    int     iTime   = openborvariant("elapsed_time");
    
    if (!iBase){    iBase = 0;  }

    if (iTime >= (iBase + 3000) && iPal < iPalCnt){
        changepalette(iPal + 1);
        setglobalvar("switch", iBase + 3000);        
    }

    setglobalvar("etime", iTime);
    setglobalvar("time1", iTBug);
    setglobalvar("time2", iTOldBug);    

}
