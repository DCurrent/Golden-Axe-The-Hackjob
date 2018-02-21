#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/soun0004.h"

//cache most often used things here
void main()
{
    setindexedvar(IDXG_INLVL, 1); // in level flag  
   
    setindexedvar(IDXG_ICOJAR, loadsprite("data/sprites/mpicon.gif"));	//Magic jar.
	setindexedvar(IDXG_BLOCBLU, loadsprite("data/sprites/life.png"));	//Life "block" blue.
	setindexedvar(IDXG_BLOCYEL, loadsprite("data/sprites/life2.png"));   //Life "block" yellow.
	setindexedvar(IDXG_BLOCORA, loadsprite("data/sprites/life3.png"));   //Life "block" orange.
	setindexedvar(IDXG_BLOCRED, loadsprite("data/sprites/life4.png"));   //Life "block" red.
    
    soun0004();														//Sound preloader.
}