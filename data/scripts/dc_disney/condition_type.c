#include "data/scripts/dc_disney/config.h"
#include "data/scripts/dc_disney/entity.c"
#include "data/scripts/dc_disney/target_select.c"

/* How acting entity evaluates types. */

int dc_disney_get_member_acting_type_list_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_TYPE_LIST_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_TYPE_LIST_EVAL;
	}

	return result;
}

void dc_disney_set_member_acting_type_list_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_TYPE_LIST_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_TYPE_LIST_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_acting_type_list()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_TYPE_LIST;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_TYPE_LIST;
	}

	return result;
}

void dc_disney_set_member_acting_type_list(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_TYPE_LIST;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_TYPE_LIST)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Toggle single flag in list, then set list. */
int dc_disney_set_member_acting_type_flag(int list_flag, int value)
{
	int list = dc_disney_get_member_acting_type_list();

	/*
	* Set the list flag bit if value is true.
	*
	* Otherwise reset (clear or 0) the bit.
	*/

	if (value)
	{
		list |= list_flag;
	}
	else
	{
		/*
		* Toggle the bit to false if it is true.
		*
		* Normally we'd just do something like this:
		*
		*  list &= ~condition;
		*
		* We use an if statement and toggle because
		* OpenBOR Script doesn't support the ~ operator
		* yet.
		*/

		if (list & list_flag)
		{
			list ^= list_flag;
		}
	}

	/*
	* Save and return the updated list.
	*/

	dc_disney_set_member_acting_type_list(list);

	return list;
}

int dc_disney_get_member_target_type_list_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_TYPE_LIST_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_TYPE_LIST_EVAL;
	}

	return result;
}

void dc_disney_set_member_target_type_list_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_TYPE_LIST_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_TYPE_LIST_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_target_type_list()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_TYPE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_TYPE;
	}

	return result;
}

void dc_disney_set_member_target_type_list(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_TYPE;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_TYPE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Toggle single flag in list, then set list. */
int dc_disney_set_member_target_type_flag(int list_flag, int value)
{
	int list = dc_disney_get_member_target_type_list();

	/*
	* Set the list flag bit if value is true.
	*
	* Otherwise reset (clear or 0) the bit.
	*/

	if (value)
	{
		list |= list_flag;
	}
	else
	{
		/*
		* Toggle the bit to false if it is true.
		*
		* Normally we'd just do something like this:
		*
		*  list &= ~condition;
		*
		* We use an if statement and toggle because
		* OpenBOR Script doesn't support the ~ operator
		* yet.
		*/

		if (list & list_flag)
		{
			list ^= list_flag;
		}
	}

	/*
	* Save and return the updated list.
	*/

	dc_disney_set_member_target_type_list(list);

	return list;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates acting type vs list of types.
*/
int dc_disney_check_condition_acting_type()
{
	void entity = dc_disney_get_member_entity();

	int check_value = dc_disney_get_member_acting_type_list();
	int eval_type = dc_disney_get_member_acting_type_list_eval();

	int check_result = dc_disney_check_type(entity, check_value);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}
	
	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates target type vs list of types.
*/
int dc_disney_check_condition_target_type()
{
	void entity = dc_disney_get_target();

	int check_value = dc_disney_get_member_target_type_list();
	int eval_type = dc_disney_get_member_target_type_list_eval();

	int check_result = dc_disney_check_type(entity, check_value);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}	

	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Return condition of random chance 
* roll.
*/
int dc_disney_check_type(void entity, int check_value)
{
	int type = getentityproperty(entity, "type");

	/* Is Entity's type in the list of check types? */

	if (type & check_value)
	{
		return DC_DISNEY_CONDITION_EVAL_TRUE;
	}
	
	return DC_DISNEY_CONDITION_EVAL_FALSE;	
}
