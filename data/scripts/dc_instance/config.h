#ifndef DC_INSTANCE_CONFIG

#define DC_INSTANCE_CONFIG 1

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_INSTANCE_BASE_ID	"dcins"

/*
* Added to base ID from parent library to build a variable
* key name for the localvar that stores current instance ID.
*/
#define DC_INSTANCE_DEFAULT_INSTANCE_MEMBER_KEY "i"

#define DC_INSTANCE_DEFAULT_INSTANCE 0


#endif // !DC_INSTANCE_CONFIG
