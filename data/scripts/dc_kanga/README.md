# Kanga
Libraries for map index and color control.

## Name Origin
Kanga is the Inuit word for "color".

## Dependencies

* [D20](https://github.com/DCurrent/openbor-script-D20)

## Installation

1. Install any listed dependencies. See an individual dependency's readme for specific instructions.
1. Download and unzip the [latest release](../../releases).
1. Place the *dc_kanga* folder into your *data/scripts* folder.
1. Add ```#include data/scripts/dc_kanga/main.c``` into any other script you would like to add this library’s functionality to.
1. Open *config.h* to modify default values used in the library.

## Use Cases

Select and apply a random index from target entity model's available map indexes, excluding hidden map range.
```c
void self;  // Calling entity.
    
// Get calling entity.
self = getlocalvar("self");

// Set calling entity as target.
setlocalvar(DC_KANGA_KEY_TARGET, self);

// Apply a random choice from the entity 
// model's available map indexes.
dc_kanga_random_index();
```

Increment to and apply the next choice in a continuous loop from an entity model's available palette indexes. Click the image below to see an example video, and note the neon marquee sign.
```c
void self;  // Calling entity.
    
// Get calling entity.
self = getlocalvar("self");

// Set calling entity as target.
setlocalvar(DC_KANGA_KEY_TARGET, self);

// Increment to next entry in the entity 
// model's available map indexes.
dc_kanga_rotate_index();
```
[![Example](https://img.youtube.com/vi/RqpOnhQo8uI/0.jpg)](https://www.youtube.com/watch?v=RqpOnhQo8uI)

Increment to the next global palette index (if avaialble). Click the image below to see an example video - note the stage graduating from dusk to night over time as the global palette increments from first index to last.
```c
int i = dc_kanga_increment_global_index();
```
[![Example](https://img.youtube.com/vi/RqpOnhQo8uI/0.jpg)](https://www.youtube.com/watch?v=RqpOnhQo8uI)
