#include	"data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=5059

void jump0005(void vEnt, int iXCon, int iYCon, int iZCon){

	/*
    jump0005							- http://www.caskeys.com/dc/?p=5160
	License (must be included to use)	- http://www.caskeys.com/dc/?p=5067
    Damon Vaughn Caskey
    2010-09-12
	~2013-02-13
	~2013-02-16

    Executes Mario Bros. style jump height control. Previously accomplished using Keyall. Moved to self-contained function
	run during Move A event to enable full compatibility with JUMPDELAY and similar "startup" animations.

	vEnt:	Target entity.
	iXCon:	X axis control toggle.
	iYCon:	Y axis control toggle.
	iZCon:	Z axis control toggle.
	*/

	int		iType;																	//Entity type.
	int		iAni;																	//Animation.
	int		iIndex;																	//Player index.
	float	fVelX;   																//X velocity.
	float	fVelY;  																//Y velocity.
	float	fVelZ;  																//Z velocity.
	int		iKLt;																	//Hold Move Left key.
	int		iKRt;																	//Hold Move Right key.
	int		iKUp;																	//Hold Move Up key.
	int		iKDn;																	//Hold Move Down key.
	int		iKJmp;																	//Hold Jump key.

	/*
	Default to self.
	*/
	vEnt = vEnt ? vEnt : getlocalvar("self");


	iType	= getentityproperty(vEnt, "type");										//Get entity type.

	if (iType == openborconstant("TYPE_PLAYER"))															//Entity is player controlled?
	{
		iAni	= getentityproperty(vEnt, "animationID");							//Get current animation.
		iIndex	= getentityproperty(vEnt, "playerindex");							//Get controlling player.

		/*
		Verify Jump animation.
		*/
		if(iAni == A_JUMP
				|| iAni == A_RUNJUMP
				|| iAni == A_FORWARDJUMP
				|| iAni == AC_DBJMP
				|| iAni == AC_DBJMPB
				|| iAni == AC_DBJMPF
				|| iAni == AC_DBJMPP
				|| iAni == AC_DBJMPW)
		{

			fVelX	= getentityproperty(vEnt, PROP_VELOCITY_X);						//Get X velocity.
			fVelY	= getentityproperty(vEnt, PROP_VELOCITY_Y);						//Get Y velocity.
			fVelZ	= getentityproperty(vEnt, PROP_VELOCITY_Z);						//Get Z velocity.

			/*
			X axis control.
			*/
			if(iXCon == 1)															//X Axis control enabled?
			{
				iKLt	= playerkeys(iIndex, KEY_STAT_PRESS, KEY_MLEFT);			//Left key press status.
				iKRt	= playerkeys(iIndex, KEY_STAT_PRESS, KEY_MRIGHT);			//Right key press status.

				if(!iKLt && !iKRt)													//Not holding Left or Right?
				{
					fVelX *= 0.90;													//Cut X velocity.
				}
				else if(iKLt)														//Left pressed?
				{
					if(fVelX > -1)
					{
						fVelX = -1;													//Set velocity to at least 1 left.
					}

					changeentityproperty(vEnt, PROP_DIRECTION, DIR_LEFT);			//Set facing left.
				}
				else if(iKRt)														//Right pressed?
				{
					if(fVelX < 1)
					{
						fVelX = 1;													//Set velocity to at least 1 right.
					}

					changeentityproperty(vEnt, PROP_DIRECTION, DIR_RIGHT);			//Set facing right.
				}
			}

			/*
			Y axis control.
			*/
			if(iYCon == 1)															//Y Axis control enabled?
			{
				iKJmp	= playerkeys(iIndex, KEY_STAT_PRESS, KEY_JUMP);				//Jump key press status.

				if (!iKJmp)															//Not holding jump?
				{
					if (fVelY > 0)													//Not falling already?
					{
						fVelY *= 0.90;												//Cut Y velcoity.
					}
				}
			}

			/*
			Z axis control.
			*/
			if(iZCon == 1)															//Z Axis control enabled?
			{
				iKUp	= playerkeys(iIndex, KEY_STAT_PRESS, KEY_MDOWN);			//Down key press status.
				iKDn	= playerkeys(iIndex, KEY_STAT_PRESS, KEY_MUP);				//Up key press status.

				if(!iKUp && !iKDn)													//Not holding Up or Down?
				{
					fVelZ *= 0.90;													//Cut Z velocity.
				}
				else if(iKDn)														//Down pressed?
				{
					if(fVelZ > -0.5)
					{
						fVelZ = -0.5;												//Set velocity to at least .5 down.
					}
				}
				else if(iKUp)														//Up pressed?
				{
					if(fVelZ < 0.5)
					{
						fVelZ = 0.5;												//Set velocity to at least .5 up.
					}
				}
			}

			changeentityproperty(vEnt, PROP_VELOCITY_ALL, fVelX, fVelZ, fVelY);		//Apply velocity.
		}
	}
}
