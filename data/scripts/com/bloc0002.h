void bloc0002(void other, float spd)
{

    /*
    bloc0002
    Copied of "Knockback" by Utunnels
    Unknown date.

    Pushes self backward when blocking an attack.
    */

    if(getentityproperty(other, "direction")==1) {spd = -spd;}
    changeentityproperty(other, "velocity", spd, 0, 0);
}
