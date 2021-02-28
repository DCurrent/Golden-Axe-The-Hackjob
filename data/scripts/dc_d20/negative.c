#include    "data/scripts/dc_d20/config.h"

/** Enable/disable negative random output. **/

int dc_d20_get_allow_negative()
{
	int instance;
	instance = dc_d20_get_instance();

	void result = getlocalvar(instance + DC_D20_MEMBER_ALLOW_NEGATIVE);

	if (typeof(result) == openborconstant("VT_EMPTY"))
	{
		result = DC_D20_DEFAULT_ALLOW_NEGATIVE;
	}

	return result;
}

void dc_d20_set_allow_negative(int value)
{
	int instance;
	instance = dc_d20_get_instance();

	if (value == DC_D20_DEFAULT_ALLOW_NEGATIVE)
	{
		value = NULL();
	}

	setlocalvar(instance + DC_D20_MEMBER_ALLOW_NEGATIVE, value);
}