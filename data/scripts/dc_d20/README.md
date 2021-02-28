# DC D20
Generate random values in OpenBOR script.

Load this library into your module projects to enable controllable random number generation. 

## Dependencies

[DC Instance](https://github.com/DCurrent/openbor-script-instance)

## Installation

1. Install any listed dependencies. See an individual dependency's readme for specific instructions.
1. Download and unzip the [latest release](../../releases).
1. Place the *dc_d20* folder into your *data/scripts* folder.
1. Add ```#include data/scripts/dc_d20/main.c``` into any other script you would like to add this library’s functionality to. Note any of the "DC" library series listing this as a dependency will already have this step completed.
1. (Optional) Open *config.h* to modify default values used in the library.

## Use Cases

Generate a random integer between lower and upper boundry. If you do not set upper and lower boundries, default values will be used.
```c
int i = dc_d20_int();
```

### Configuration

#### Range

Get current lower boundry for number generation.
```c
int i = dc_d20_get_range_min();
```

Get current upper boundry.
```c
int i = dc_d20_get_range_max();
```

Set a new lower boundry.
```c
int i = {int};

dc_d20_set_range_min(i);
```

Set a new upper boundry.
```c
int i = {int};

dc_d20_set_range_max(i);
```


