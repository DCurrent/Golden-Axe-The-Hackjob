//Animation script for riding an animal in Golden Axe.

#include "data/scripts/vars/constants.h"

#import "data/scripts/com/ai0002.h"        //Avoid jump attacks by walking laterally.
#import "data/scripts/com/ai0003.h"        //Stay in screen while walking.
#import "data/scripts/com/ani0001.h"       //Conditional animation switch.
#import "data/scripts/com/ani0009.h"       //Conditional animation switch.
#import "data/scripts/com/ani0012.h"	    //Switch animation when height is < 70% of target.
#import "data/scripts/com/ani0013.h"	    //Switch to jump if stepping off platform.
#import "data/scripts/com/ani0016.h"	    //Alt animation if opponent rising.
#import "data/scripts/com/seal0001.h"      //Turn off target specials.
#import "data/scripts/com/stal0001.h"      //Apply stalltime.
#import "data/scripts/com/bind0002.h"      //Syncronize location; no bind..
#import "data/scripts/com/bind0003.h"      //Spawn entity and bind to caller.
#import "data/scripts/com/bind0008.h"      //Spawn and set location to caller and then unbind.
#import "data/scripts/com/bind0010.h"      //Bind prexisting entity to self by index; primarly grappling.
#import "data/scripts/com/bind0014.h"      //Initialize index for binding other entities to self.
#import "data/scripts/com/bind0018.h"      //Wall failsafe.
#import "data/scripts/com/dama0001.h"      //Damage target.
#import "data/scripts/com/dama0004.h"      //Damage bound entity by index.
#import "data/scripts/com/dir0001.h"       //Change direction.
#import "data/scripts/com/jump0003.h"      //Change current animation to a real "jump".
#import "data/scripts/common/mp.h"			//MP functions by Utunnels.
#import "data/scripts/com/mode0001.h"		//Weapon/model switch.
#import "data/scripts/com/proj0003.h"      //Basic projectile launcher.
#import "data/scripts/com/scre0001.h"		//In screen check.
#import "data/scripts/com/soun0005.h"      //Stereo sound handler.
#import "data/scripts/com/stat0001.h"      //Change MP or HP level of target.
#import "data/scripts/com/stat0003.h"      //Save MP.
#import "data/scripts/com/wake0001.h"      //Deal with in/out of screen boundry.
#import "data/scripts/common/slide.h"		//X only velocity function.
#import "data/scripts/com/velo0001.h"      //Velocity control.
