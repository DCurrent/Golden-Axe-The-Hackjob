#include	"data/scripts/vars/constants.h"

#include	"data/scripts/dc_common_source/dc_select_screen/main.c"
#include	"data/scripts/dc_common_source/dc_hud/main.c"
#include    "data/scripts/dc_fidelity/main.c"
#include    "data/scripts/dc_kanga/main.c"



void oncreate()
{
    log("\n\t ...update.c\n");

    dc_preload_hud_sprites();
    dc_select_screen_initialize();
}

void ondestroy()
{
    dc_unload_hud_sprites();
    dc_select_screen_terminate();
}

void main()
{
	//Give Debug text a background.
	if (getglobalvar("debug_set"))
	{
		drawbox(0, 25, 480, 80, openborconstant("FRONTPANEL_Z"), RGB_BLACK, 6);
	}

	//tupdate();
    dc_select_screen_main();

    /* Draw enemy HUD. */
    dc_golden_axe_enemy_hud();

    /* Draw player HUD. */
    dc_module_hud_player_master();

    /*
    * Play any timed delay sounds.
    */
    dc_fidelity_play_timed();

    /* Loop entity collection. */
    int i = 0;
    int ent_count = openborvariant("count_entities");
    void entity_cursor = NULL();

    for (i = 0; i < ent_count; i++)
    {
        entity_cursor = getentity(i);

        /* Execute tint effect on entity. */
        dc_kanga_auto_tint(entity_cursor);

        /* Invisible when knocked down. */
        dc_auto_stealth(entity_cursor);

    }
   
}

// Auto apply stealth.

// Most AI controlled models are set to chase mode to
// emulate how they behaved in the original Golden Axe,
// but we want them to ignore opponents who are
// knocked down.
//
// We'll do this by applying a universal stealth, with
// a couple of exceptions for specific game-play situations.
void dc_auto_stealth(void target)
{
    #define STEALTH_DISABLE     0
    #define STEALTH_ENABLE      1
    #define STEALTH_NO_ACTION   2

    int     exists;             // Entity exists flag.
    int     dead;               // Entity dead flag.
    char    model_name;         // Name of the base model.
    void    owner;              // Entity that spawned the target.
    int     drop;               // Falling (drop) state.
    int     action;             // Stealth setting to apply.
    int     stealth_current;    // Entity's current stealth.
    int     animation;          // target's current animation.


        // Make sure we got a valid target pointer.
        if(!target)
        {
            return;
        }

        // Make sure the entity exists in play. We perform this
        // check because it's possible for an entity to be
        // removed but its pointer is still valid.
        exists  = getentityproperty(target, "exists");

        if(!exists)
        {
            return;
        }

        // We're leaving dead enemies on the screen but
        // don't want to draw their HUD any more. For
        // this purpose the dead flag will work well
        // as a filter.
        dead = getentityproperty(target, "dead");

        if(dead)
        {
            return;
        }

        // Does the entity have an owner? If not, in this module
        // that means it is a projectile or special effect.
        owner = getentityproperty(target, "owner");

        if(owner)
        {
            return;
        }

        // Is the entity in a falling state?
        drop = getentityproperty(target, "aiflag", "drop");

        if(drop)
        {
            // Set stealth so opponents will ignore.
            action = 1;
        }
        else
        {
            // If not in a falling state, then we will default to
            // disabling stealth.
            action = STEALTH_DISABLE;

            // Don't disable stealth if an of the following conditions
            // are met. They are controlling stealth with other
            // functions that we don't want to interfere with.

            // - Yamoto: Joe's dog is an invincible decoration
            // until he specifically becomes part of the action.
            // Therefore he defaults with stealth so opponents
            // won't stupidly attack him.
            if(model_name == "yamoto")
            {
                action = STEALTH_NO_ACTION;
            }

            // - Alex in Riseattack: Alex's rise attack is a feign
            // death move allowing him to gain some space and come
            // up with a delayed attack. It uses stealth to work.
            if(model_name == "alex")
            {
                if(animation == openborconstant("ANI_RISEATTACK"))
                {
                    action = STEALTH_NO_ACTION;
                }
            }

            // - SLEEP animation. This is used for entities that
            // are on screen but not in action yet - like
            // Longmoan stomping on a peasant.
            if(animation == openborconstant("ANI_SLEEP"))
            {
                action = STEALTH_NO_ACTION;
            }
        }

        stealth_current = getentityproperty(target, "stealth");

        // This is where we apply the results of our stealth
        // conditionals. We might want to use stealth for its
        // intended purpose too, so let's accommodate here by only
        // adjusting stealth if it is within 1 of the binary 0/1 range.
        //
        // IOW, if an entity has 5 stealth, then it is clearly
        // meant to be stealthy by design, so don't mess that up
        // here. But if its stealth is only 1, then we can assume
        // it only has stealth because of a temporary condition like
        // falling and we may safely disable.
        switch(action)
        {
            case STEALTH_DISABLE:

                // Only disable stealth if it is
                // enabled but not higher than 1.
                if(stealth_current <= 1 && stealth_current > 0)
                {
                    changeentityproperty(target, "stealth", 0);
                }

                break;

            case STEALTH_ENABLE:

                // Only enable stealth if it is
                // disabled but higher than -1.
                if(stealth_current <= 0 && stealth_current > -1)
                {
                    changeentityproperty(target, "stealth", 1);
                }

                break;

            default:
            case STEALTH_NO_ACTION:
                break;
        }
    

    #undef STEALTH_DISABLE
    #undef STEALTH_ENABLE
    #undef STEALTH_NO_ACTION
}
