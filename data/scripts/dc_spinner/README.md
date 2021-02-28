# Spinner
Spinners are numeric entry elements that allow a user to select number values by clicking buttons for up or down, such as the date of birth yyyy/mm/dd entries in a web form. They usually have some defined limit, and may loop when reaching the limit. This library allows you to add similar behavior to your modules. It is also useful when you need a function to auto increment outside of loops.

## Dependencies

None

## Installation

1. Install any listed dependencies. See an individual dependency's readme for specific instructions.
1. Download and unzip the [latest release](../../releases).
1. Place the *dc_spinner* folder into your *data/scripts* folder.
1. Add ```#include data/scripts/dc_spinner/main.c``` into any other script you would like to add this library’s functionality to.
1. Open *config.h* to modify default values used in the library.

## Use Cases

Increment the spinner value. Increments (or decrements) by adding the current increment value to spinner and returns the new spinner value.
```c
int i;

i = dc_spinner_increment_run();
```

Get current spinner value.
```c
int i;

i = dc_spinner_get_value();
```

Set current spinner value.
```c
int i = {int};

dc_spinner_set_value(i);
```

### Configuration

#### Increments

Value added to spinner when incremented. Use negative values to decrement.

Get current spinner increment.
```c
int i;

i = dc_spinner_get_increment();
```

Set current spinner increment.
```c
int i = {int};

dc_spinner_set_increment(i);
```

#### Steps

Steps are an optional feature to calculate the value of increments needed to go from the minium to maximum range (or max to min) in a given number of steps. This allows you to quickly build spinners with a static number of increments regardless of range.

Get current spinner steps.
```c
int i;

i = dc_spinner_get_steps();
```

Set current spinner steps.
```c
int i = {int};

dc_spinner_set_steps(i);
``` 

Calculate, set, and return increment value based on steps and range properties. For instance, if range is 0 to 100, and steps are 20, then increments will be 5.

```c
int i;

i = dc_spinner_increment_buid()
```

#### Range

Range controls the minimum and maximum values spinner can reach.

Get current lower boundry.
```c
int i;

i = dc_spinner_get_range_min();
```

Get current upper boundry.
```c
int i;

i = dc_spinner_get_range_max();
```

Set a new lower boundry.
```c
int i = {int};

dc_spinner_set_range_min(i);
```

Set a new upper boundry.
```c
int i = {int};

dc_spinner_set_range_max(i);
```

#### Boundary Behavior

The following constants and functions determine how the library behaves when attempting to increment or decrement beyond min or max range.

* DC_SPINNER_RANGE_BOUND_CAP - Increments/decrements beyond range are ignored, the value does not change.
* DC_SPINNER_RANGE_BOUND_LOOP - Increments/decrements roll over to the opposite range.
* DC_SPINNER_RANGE_BOUND_BREAK - Increments/decrements can break range limits.

Get current lower boundry behavior.
```c
int i;

i = dc_spinner_get_range_bound_min();
```

Get current upper boundry behavior.
```c
int i;

i = dc_spinner_get_range_bound_max();
```

Set lower boundry behavior.
```c
int i = {int};

dc_spinner_set_range_bound_min(i);
```

Set upper boundry behavior.
```c
int i = {int};

dc_spinner_set_range_bound_max(i);
```

#### Instance

Instancing allows the library to keep several unique configurations at once in a given function. That way you won't need to clog up your functions constantly adjusting the library’s properties back and forth when you need more than one configuration. Just set up your desired configurations one time and then switch between instances as needed.

By default, the active instance is 0. To create more, switch to a new active instance with an ID of your choice, and adjust the other configuration settings as preferred. Your new instance is ready to use. 

Get active instance ID.
```c
int i;

i = dc_spinner_get_instance();
```

Set (swicth to) active instance.
```c
int i = {int};

dc_spinner_set_instance(i);
```
