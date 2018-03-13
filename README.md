# Golden-Axe-The-Hackjob
An OpenBOR module recreating Sega's orginal Golden Axe.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=JossdCHwwIw
" target="_blank"><img src="http://img.youtube.com/vi/JossdCHwwIw/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

<a href="http://www.youtube.com/watch?feature=player_embedded&v=lNcoVQhhITI
" target="_blank"><img src="http://img.youtube.com/vi/lNcoVQhhITI/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

<a href="http://www.youtube.com/watch?feature=player_embedded&v=XWtCEdRZnJI
" target="_blank"><img src="http://img.youtube.com/vi/XWtCEdRZnJI/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

# Legacy Work Log

## 2010_07_12

*   Start of work log. I cannot recall all of the changes I made today, thus the point.
*   How To Play revamped. I'm not really satisfied due to limitations of the feature and preferably would remove it outright in favor of an in game replacement. Unfortunately the option itself is hard coded into engine's start menu. Having it do nothing or lead to a blank file would be too unprofessional.
*   Ax's piledriver damage is now 30% of opponents remaining health + 5 (similar to Mike Haggar in Final Fight). This will make move useful for causing heavy damage to strong enemies without being the end all be all technique of choice.
*   Ax's powerbomb damaged reduced to 8 from 12.

## 2010_07_15

*   All remnants of legacy sound players (soun0001(), soun0002()) removed from module and replaced with soun0005.

## 2010_08_07

*   [New select screen completed.](../../../../../?p=487)

## 2010_09_18

*   [Hit while bound added.](../../../../../?p=615)

## 2011_02_13

*   Name based model switching on spawn application in progress. This is to combine NPC, Enemy, and Player versions of a character into a single central model.
*   Work Log separated from Bug & To Do List.

## 2011_02_20

*   Fixed [bflash](../../../../../../arc/games/openbor/wiki/index.php?title=Bflash) for Ax Battler.
*   Switched log dates to Big Endian form.

## 2011_02_21

*   Removed all instances of "loop 0".
*   Defense pose moved from follow10 to follow51 to comply with standard from my other modules.
*   RUNJUMP and range settings for JUMP added to ax.txt.

## 2011_02_22

*   Ax's sidestep is now a roll instead of a jump.
*   Added [dust](../../../../../../arc/games/openbor/wiki/index.php?title=Dust) setting to ac_pc staging model.
*   Added extra frame to Ax's rise animation.

## 2011_02_23

*   Ax Battler:
    *   Removed Lateral High Jump from all models.
    *   Added jumpmove 0 1 to all models.
    *   Removed "Stats" entry.

## 2011_03_27

*   ai0002
*   ani0001
*   Longmoan
    *   Successfully integrated single model concept. Longmoan is now player type in model sheet and selectable at start screen, but behaves like enemy as a level spawn.
*   common/attack.h rolled into enemy.h
*   Merging of animation scripts to enemy.c (enemy.c is to be moved and renamed).

## 2011_03_28

*   enemy.h rolled into z_ani.c
*   All slide {x} calls replaced with [velo0001 {x} {y} {z}](http://www.caskeys.com/dc/?p=1314#velo0001). Slide.h removed.

## 2011_03_29

*   All remaining scripts from common folder removed. Some functions copied directly to _z_ani.c_ and still need to be given individual files.
*   _bgs2_ folder renamed to _bgs_, old _bgs_ removed.
*   _scenes2_ folder renamed to _scenes_, old _scenes_ removed.
*   _levels_ folder renamed to _levels_.
*   Individual constant lists consolidated.

## 2011_05_16

*   Multiple enemy lifebar and icon display now takes advantage of [sprite array feature](http://lavalit.com:8080/index.php/topic,5668.0.html). This solves issue of integration with conflict with player icons and also allows enemy icons to reflect status. Icons added to individual model sets:
    *   Amazon
    *   Bitter
    *   Henninger
    *   Longmoan
    *   Skeleton

## 2011_05_17

*   Removed all instances of entity vars ADBLEND and ADREMAP. They are no longer needed for passing blend and map respectively to [draw0001()](http://www.caskeys.com/dc/?p=1314#draw0001 "Script Catalog").
*   Upgrade following effect models to [Fatal Fury Chronicles](http://www.caskeys.com/dc/?cat=6 "Fatal Fury Chronicles")folder layout.
    *   flash

## 2011_05_20

*   All flash models now moved to _->misc->effects->models->flash->folder_ layout.
*   Flash models now run _spawn0002.c_, with _spawn0012_ eliminated.
*   Flash bugs (wrong size, palette, alpha) fixed and accurate effects added (sword vs. hand vs. blunt, etc.) as part of reorganization.

## 2011_05_24

*   Fix complete for [bind0023](http://www.caskeys.com/dc/?p=1314#bind0023 "Script Catalog"); dragon throws now use Defender's custom flash if it has one.
*   Bad Brother's flat fall and fall on head added.

## 2011_05_25

*   Menu text added.
*   Backstep now mapped to Down + Defend (formerly Attack2). This cuts total action keys to four (Attack, Jump, Defend, Magic).
*   Magic fail moved to keyall.c with generic code to work with all characters.

## 2011_05_27

*   Resolved issue with Ax Battler's Piledriver and Jump throw knocking himself down. Caused by _landframe_ call being incompatible with engine's updated landframe array.
*   Added Ax battler's "Second Strike" general purpose follow up swing to be canceled from several other animations. Still needs motion blur.

## 2011_05_29

*   Completed Ax Battler's Second Strike.
    *   Motion blur.
    *   Cancels.
        *   Backattack
        *   Riseattack
        *   Sidestep
        *   Power Swing
*   Replaced all "switch_combo" calls to [ani0012](http://www.caskeys.com/dc/?p=1314#ani0012 "Script Catalog").
*   Removed unused functions from z_ani.
    *   adjust_ftoss
    *   adjust_ftoss2
    *   ftoss
    *   ftoss2
    *   change_slam1
    *   change_slam2
    *   change_slam3
*   Bone break medium sound (253_0) and model added (bonem).

## 2011_05_30

*   See [Heartland](http://www.caskeys.com/dc/?p=3071#2011_05_30 "Bad Brother").

## 2011_05_31

*   See [Heartland](http://www.caskeys.com/dc/?p=3071#2011_05_31 "Bad Brother").

## 2011_06_02

*   See [Heartland](../../../../../?p=3071#2011_06_02 "Heartland")

## 2011_06_03

*   Resolved issue with draw0001 crashing game on certain stages when an entity touched Z boundary. A simple typo was setting both the fMinZ and fMaxZ to = minimum Z boundary instead of min/max respectively.
*   See [Heartland](http://www.caskeys.com/dc/?p=3071#2011_06_03 "Heartland").

## 2011_06_08

*   Resolved issue with revive on spot system (see [bind0017](http://www.caskeys.com/dc/?p=1314#bind0017 "Script Catalog")) when player lost lost all lives and continued with different character (thus leaving original character's corpse behind). If any player later selected the left behind character, script would attempt to warp them to off screen corpse.
*   See [Heartland](http://www.caskeys.com/dc/?p=3071#2011_06_08 "Heartland").

## 2011_06_13

*   See [Bitter](http://www.caskeys.com/dc/?p=3194#2011_06_13 "Models – Bitter").

## 2011_06_14

*   Removed script functions/files:
    *   scripts\drain.c
        *   Used to gradually remove life when playing skeleton mode in GA Remake. Skeleton will be playable as normal bonus character without drain effect.
    *   data\levels\duel\sleep.c
        *   Cause crowd to attack by setting "sleep" global var to NULL(). A validation in each individual model's looping SLEEP animation would then set model's animation to IDLE and _stealth_ property to 0.
    *   data\chars\skeleton\scripts\npc_ani.c
        *   Rolled into data\scripts\ z_ani.c
*   Removed global variants.
    *   countdown
    *   cstring
        *   Support for drain.c.
    *   levelmaxz
    *   levelmaxz
        *   Replaced with _openborvariant()_ calls.
    *   inscreen
    *   sleep
        *   See sleep.c above.
*   Removed models.
    *   data\chars\gilius\g_npc.txt
    *   data\chars\tyris\t_npc.txt
        *   All versions (NPC/PC/ENEMY) to be rolled into single model.

## 2011_06_27

*   Holdblock capable characters no longer use special unless they are actually in pain (see z-spawn and keyall).
*   See [Ax Battler](http://www.caskeys.com/dc/?p=3272 "Models – Ax Battler").

## <a name="2011_07_26"></a>2011_07_26

*   Several minor script updates and fixes.
*   See [Ax Battler](http://www.caskeys.com/dc/?p=3272#2011_07_26 "Models – Ax Battler").

## <a name="2011_07_31"></a>2011_07_31

*   Added EX1 and EX2 defense poses to several models (will complete during individual model phases) to accommodate Golden Axe's odd offsets when binding self to target instead of target to self.
*   See [Ax Battler](http://www.caskeys.com/dc/?p=3272#2011_07_31 "Models – Ax Battler").

## <a name="2011_07_26"></a>2011_07_26

*   Several minor script updates and fixes.
*   See [Ax Battler](http://www.caskeys.com/dc/?p=3272#2011_07_26 "Models – Ax Battler").

## <a name="2011_07_31"></a>2011_07_31

*   See [Ax Battler](http://www.caskeys.com/dc/?p=3272#2011_08_07 "Models – Ax Battler").

## <a name="2011_08_31"></a>2011_08_31

*   See [Tyris Flare](http://www.caskeys.com/dc/?p=3845#2011_08_31 "Models – Tyris Flare").

## <a name="2011_09_01"></a>2011_09_01

*   See [Tyris Flare](http://www.caskeys.com/dc/?p=3845#2011_09_01 "Models – Tyris Flare").

## <a name="2011_09_06"></a>2011_09_06

*   See [Tyris Flare](http://www.caskeys.com/dc/?p=3845#2011_09_06 "Models – Tyris Flare").

## <a name="2011_09_07"></a>2011_09_07

*   See [Tyris Flare](http://www.caskeys.com/dc/?p=3845#2011_09_07 "Models – Tyris Flare").

## <a name="2011_09_19"></a>2011_09_19

*   See [Tyris Flare](http://www.caskeys.com/dc/?p=3845#2011_09_19 "Models – Tyris Flare").

## <a name="2011_10_19"></a>2011_10_19

*   Fixed wall0001 function.
*   Replaced TLTDN with proper Tilted Down sprite for all characters. Old TLTDN (custom lift pose for Golden Axe) moved to EX3.

## <a name="2012_01_11"></a>2012_01_11

*   See [Tyris Flare](http://www.caskeys.com/dc/?p=3845#2012_01_11 "Models – Tyris Flare").

## <a name="2012_02_07"></a>2012_02_07

*   z_hit now calls function function [hit0004](http://www.caskeys.com/dc/?p=1314#hit0004 "Script Catalog"), made from z_hit's original code.
*   [soun0005](http://www.caskeys.com/dc/?p=1314#soun0005 "Script Catalog") now includes a final entity check. This fixes bug where entity killed with _killentity()_ would still send call to soun0005, which would then result in empty string call, and ultimately a shutdown by string functions.
*   See [Tyris Flare](http://www.caskeys.com/dc/?p=3845#2012_02_07 "Models – Tyris Flare").

## <a name="2012_08_21"></a>2012_08_21

*   Chicken now releases opponent in FALL7 (Fall on head) pose.
*   See [Ax Battler](http://www.caskeys.com/dc/?p=3272#2012_08_21 "Models – Ax Battler").
*   All remaining known instances of "openborconstant" in chars folder replaced with preprocessed constants from constans.h.
