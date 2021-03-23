#include "data/scripts/dc_fidelity/config.h"

/* 
* Model is the model we search to get sounds.
* We normally get this from the current entity,
* but there are times we will need to set the
* model name manually.
*/

void dc_fidelity_get_member_model_name()
{
	char id;
	void result;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_MODEL_NAME;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_STR"))
	{
		result = DC_FIDELITY_DEFAULT_MODEL_NAME;
	}

	return result;
}

void dc_fidelity_set_member_model_name(char value)
{
	char id;
	
	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_MODEL_NAME;
	
	if (value == DC_FIDELITY_DEFAULT_MODEL_NAME)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}