#include "data/scripts/dc_disney/config.h"

/*
* Animation to apply.
*/

void dc_disney_get_member_animation_pass_id()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_ID;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_ID;
	}

	return result;
}

void dc_disney_set_member_animation_pass_id(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_ID;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_ID)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_pass_frame()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_FRAME;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_FRAME;
	}

	return result;
}

void dc_disney_set_member_animation_pass_frame(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_FRAME;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_FRAME)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_pass_method()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_METHOD;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_METHOD;
	}

	return result;
}

void dc_disney_set_member_animation_pass_method(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_METHOD;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_METHOD)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_pass_reset()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_RESET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_RESET;
	}

	return result;
}

void dc_disney_set_member_animation_pass_reset(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_RESET;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_RESET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Animation on condition fail.
*/

void dc_disney_get_member_animation_fail_id()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_ID;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_ID;
	}

	return result;
}

void dc_disney_set_member_animation_fail_id(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_ID;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_ID)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_fail_frame()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_FRAME;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_FRAME;
	}

	return result;
}

void dc_disney_set_member_animation_fail_frame(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_FRAME;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_FRAME)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_fail_method()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_METHOD;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_METHOD;
	}

	return result;
}

void dc_disney_set_member_animation_fail_method(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_METHOD;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_METHOD)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_fail_reset()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_RESET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_RESET;
	}

	return result;
}

void dc_disney_set_member_animation_fail_reset(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_RESET;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_RESET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
