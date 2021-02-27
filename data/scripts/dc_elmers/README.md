# DC Elmers
Binding and location syncing control for OpenBOR script. Full Readme in progress.

# Name Origin 
Elmer's glue, what else. :)

## Dependencies

[DC Instance](https://github.com/DCurrent/openbor-script-instance)

[DC Math](https://github.com/DCurrent/openbor-script-math)

## Installation

1. Install any listed dependencies. See an individual dependency's readme for specific instructions.
1. Download and unzip the [latest release](../../releases).
1. Place the *dc_d20* folder into your *data/scripts* folder.
1. Add ```#include data/scripts/dc_d20/main.c``` into any other script you would like to add this library’s functionality to. Note any of the "DC" library series listing this as a dependency will already have this step completed.
1. (Optional) Open *config.h* to modify default values used in the library.

## Use Cases

In progress.

## Double Bind

Double bind is designed to deal with special grapples where we need both the grappled and the grappler entities bound to each other. Think of moves like a swing DDT, the vaulting system from Streets of Rage, or any sort of move where the grappler mounts onto the grappled. 

## Position

Positioning is possible without binding. This is usful when you want to make a quick adjustment to an entity's position or for making effects like Ken's Shinryuken where the opponent is drawn in. The positioning functions can get a bit complicated as they are designed to work just like binding.

