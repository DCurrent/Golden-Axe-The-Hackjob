//Amazon animations cript.

#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants


#import "data/scripts/com/ani0009.h"        
#import "data/scripts/com/bind0003.h"		//Spawn entity and bind to caller.
#import "data/scripts/com/bind0008.h"		//Spawn and set location to caller and then unbind.
#import "data/scripts/com/bind0010.h"		//http://www.caskeys.com/dc/?p=1314#bind0010
#import "data/scripts/com/bind0014.h"		//Initialize index for binding other entities to self.
#import "data/scripts/com/bind0016.h"		//Warp target. Initialize index for binding other entities to self.
#import "data/scripts/com/bind0018.h"		//Wall failsafe.
#import "data/scripts/com/dama0004.h"		//Damage bound entity by index.
#import "data/scripts/com/draw0003.h"		//Set caller's drawmethod variables.
#import "data/scripts/com/jump0003.h"		// Set flags to jumping status.
#import "data/scripts/com/proj0003.h"		//Basic projectile launcher.

#import "data/scripts/com/seal0001.h"       // Add seal and sealtime to target.
#import "data/scripts/com/stal0001.h"       // Add stalltime to target.

#import "data/scripts/com/soun0005.h"		//Stereo sound handler.
#import "data/scripts/com/wake0001.h"		//Deal with in/out of screen boundry.



#import "data/scripts/com/dc_ai_avoid_jump_attack.c"        //Avoid jump attacks.

#include "data/scripts/dc_disney/main.c"
#include "data/scripts/dc_fidelity/main.c"
