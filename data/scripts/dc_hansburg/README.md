# Hansburg
This is a comprehensive auxiliary jumping system that will enable any combination of the following features in an OpenBOR module:

* Double Jumping.
  * Vertical. 
  * Horizontal forward. 
  * Horizontal backward.
  * Any combination of the above (i.e. one character in the module might have a single double jump animation for all three types, while another could have a separate animation for
each).
* Obstacle Jumping.
* Wall Jumping.
* Edge (screen boundary) jumping.

## Name Origin
In honor of Hansburg, George B. – Inventor of the modern Pogo Stick design.

## Dependencies
None

## Installation (Under Construction)
1. Install any listed dependencies. See an individual dependency's readme for specific instructions.
1. Download and unzip the [latest release](../../releases).
1. Place the *dc_hansburg* folder into your *data/scripts* folder.
1. Add ```#include data/scripts/dc_hansburg/main.c``` into any other script you would like to add this library’s functionality to.
1. Open *config.h* to modify default values used in the library.

## Use Cases (Under Construction)
### Default Rules
These are the default “rules” of the double jump system. You can modify them if needed.

#### Priority
If character has two or more auxiliary jumping capabilities enabled, the priority is as follows: *Obstacle > Wall > Edge > Double*. For example, if a character has both an edge jump and a double jump, and the player presses the Jump
key while already jumping within range of the screen edge, the character will perform an edge jump rather than a double jump.

#### Limits
* To prevent “flying”, double jumping is not possible during a previous double jump. You can however double jump from any other type of jump, even if you had already double jumped
previously. For example, a character could not double jump twice in a row, but they could double jump to reach a wall, perform a wall jump, and then double jump once more during the wall jump.
* Screen edge, wall, and obstacle jumps can be performed any time.
* To prevent players from chain jumping too far up a wall or edge and getting stuck, the jumping system includes a maximum height feature. If the character is above a designated height the
jumping system will be disabled until the character falls back below set height again. By default, this height is 125% of the vertical screen resolution. This height limit can be adjusted at will during gameplay.
