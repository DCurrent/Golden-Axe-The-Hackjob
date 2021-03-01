#include "data/scripts/dc_initialize/config.h"

// Which instance is in use?
int dc_initialize_get_instance()
{
	void result = getlocalvar(DC_INITIALIZE_MEMBER_INSTANCE);

	if (!result)
	{
		result = DC_INITIALIZE_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_initialize_set_instance(int value)
{
	setlocalvar(DC_INITIALIZE_MEMBER_INSTANCE, value);
}

// Base entity library functions will act on.
int dc_initialize_get_entity()
{
	void result = getlocalvar(DC_INITIALIZE_MEMBER_ENT);

	if (!result)
	{
		result = DC_INITIALIZE_DEFAULT_ENT;
	}

	return result;
}

void dc_initialize_set_entity(void value)
{
	setlocalvar(DC_INITIALIZE_MEMBER_ENT, value);
}