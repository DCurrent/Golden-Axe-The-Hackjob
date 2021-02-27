# DC Instance

Instancing control allows a library to keep several unique configurations at once in a given function. That way you won't need to clog up your functions constantly adjusting the library’s properties back and forth when you need more than one configuration. Just set up your desired configurations one time and then switch between instances as needed.

Prior to 2019-04-10, each of my OpenBOR script libraries had their own instance support functions. Instance support is now migrated to this library, and included by the other libraries for their internal use. To maintain simplicity and consistency, each library defines its own function macros to control instancing. See each library's config.h file for their indivdiual instance control functions.

By default, the active instance is 0. To create more, switch to a new active instance with an ID of your choice, and adjust the other configuration settings as preferred. Your new instance is ready to use.

## Dependencies

None

## Installation

1. Install any listed dependencies. See an individual dependency's readme for specific instructions.
1. Download and unzip the [latest release](../../releases).
1. Place the *dc_instance* folder into your *data/scripts* folder.
1. Add ```#include data/scripts/dc_instance/main.c``` into any other script you would like to add this library’s functionality to. If you are downloading as part of one of my other libraries, they already have this step completed.
1. (Optional) Open *config.h* to modify default values used in the library.

## Use Examples

Note these examples are for the [DC D20 Library](https://github.com/DCurrent/openbor-script-D20). Each library will have its own instance control macros. In most cases it's just the library name as a prefix. See each library's config.h file.

### Local

Standard operation. The library will use these functions to instance its local vars. All functions require base id from the parent library.

Get active instance ID.
```c
char base_id = "parent library base id"; 

int i = dc_d20_get_instance(base_id);
```

Set (switch to) instance with supplied ID. If the requested instance does not exist, it is created first.
```c
char base_id = "parent library base id"; 
int instance_id = {int};

dc_d20_set_instance(base_id, instance_id);
```

Free (destroy) the active instance. All variables are destroyed - meaning the library will now supply default values for any get operation. If not already, you are now at the default instance.
```c
char base_id = "parent library base id"; 

dc_d20_free_instance(base_id);
```

Reset the active instance. Similar to Free, except the instance itself is maintained.
```c
char base_id = "parent library base id"; 

dc_d20_reset_instance(base_id);
```

Dump the active instance. All variables for the active instance are sent to the log for debugging.
```c
char base_id = "parent library base id"; 

dc_d20_reset_instance(base_id);
```

### Global

My series of libraries relies primary on local variables, making them behave almost exactly like class members in object-oriented programing. Local variables are automatically destroyed when the script unloads, eliminating any need for cleanup or possible memory leaks. However, there may be cases where data needs to pass between scripts. In that case, there is no need to muck up a library or script with global variables. Instead, use these export and import functions to package up the entire library's member data and retrieve it elsewhere.

Export the library data. The function builds a global copy of the parent library member variables, identified by the current instance.
```c
char base_id = "parent library base id"; 

dc_d20_export_instance(base_id);
```

Import data from an export instance matching the current instance. Overwrites existing local members. If there is no global copy of the current instance, the current instance will be overwritten with blank values (same effect as an instance reset).
```c
char base_id = "parent library base id"; 

dc_d20_import_instance(base_id);
```

Destroy an export instance matching the current instance. Since global data is never deleted automatically, it is best practice to run this function after you are finished with the export copy.
```c
char base_id = "parent library base id"; 

dc_d20_free_export(base_id);
```
