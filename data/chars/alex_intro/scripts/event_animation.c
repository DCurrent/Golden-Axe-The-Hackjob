#include "data/scripts/dc_gauntlet/main.c"
#import "data/chars/alex_intro/scripts/dc_get_first_player.c"

/*
* Caskey, Damon V. (based on checktext by Untunnels)
* 2021-06-08
* 
* Control intro dialog between Alex and player
* by spawning and binding textbox dialog entities.
* The controlling entity (Alex) runs this function
* in a looping animation. As the dialog entity
* animations finish, the function spawns next
* dialog and removes the previous.
*/
void dc_run_dialog()
{
    void self = getlocalvar("self");

    /*
    * Entity that talks to acting entity. This was 
    * populated by dc_dialog_setup() function in 
    * event_think script. If there's no value, then
    * an enemy must have killed us first. In that
    * case we'll get the first player here.
    */
    
    void dialog_player_entity = getentityvar(self, "dialog_player_entity");
    
    if (!dialog_player_entity)
    {
        dialog_player_entity = dc_get_first_player(self, -1);
    }

    /* 
    * Dialog entity - it is the text box bound to 
    * the entity that is currently speaking.
    */

    void dialog_entity = getlocalvar("dialog_entity_old");
       
    /*
    * Dialog steps are 0 indexed in order. Each
    * time script runs, we check the step position.
    * Whatever step we are at kills the dialog
    * entity (if any) from previous step. It then
    * spawns a new dialog entity. The new dialog
    * entity is bound to player or acting, and
    * its pointer is recorded so we can kill it 
    * it in next step.
    */

    int dialog_step_position = getlocalvar("dialog_step_position");

    if (!dialog_step_position)
    {
        dialog_step_position = 0;
    }

    if (!dialog_step_position)
    {
       dialog_entity = dc_gauntlet_quick_spawn("alex_intro_dialog_0");

       dc_dialog_bind(dialog_entity, dialog_player_entity);

       dialog_step_position++;       
    }
    else if (dialog_step_position <= 1)
    {       
        /*
        * Only spawn this step's dialog and increment
        * to next step if the previous step's dialog
        * is already spawned AND is finished with
        * its current animation. This allows us to
        * control timing with the dialog's animation
        * delay.
        */

        if(dialog_entity && get_entity_property(dialog_entity, "animation_state") == 0)
        {
            killentity(dialog_entity);
                
            dialog_entity = dc_gauntlet_quick_spawn("alex_intro_dialog_1");
            
            dc_dialog_bind(dialog_entity, self);

            dialog_step_position++;
        }     
    }
    else if (dialog_step_position <= 2)
    {        
        if (dialog_entity && get_entity_property(dialog_entity, "animation_state") == 0)
        {
            killentity(dialog_entity);

            dialog_entity = dc_gauntlet_quick_spawn("alex_intro_dialog_2");

            dc_dialog_bind(dialog_entity, dialog_player_entity);

            dialog_step_position++;
        }

    }
    else
    {        
        /*
        * Previous step was final dialog. Now we
        * need to end the dialog and take final
        * actions.
        */

        if (dialog_entity && get_entity_property(dialog_entity, "animation_state") == 0)
        {
            killentity(dialog_entity);

            /* 
            * The entity's spawn script spawned a
            * dummy enemy to lock scrolling. Kill
            * it here. This will cause engine
            * to fire "go" arrow and let player
            * proceed forward.
            */

            dc_gauntlet_remove_by_name("dummy_enemy");

            dialog_step_position = NULL();
            dialog_entity = NULL();

            updateframe(self, 4);
        }
    }

    /* 
    * Store step position and dialog entitiy
    * pointers for next function run.
    */

    setlocalvar("dialog_step_position", dialog_step_position);
    setlocalvar("dialog_entity_old", dialog_entity);
}


/* Simple wrapper to handle dialog entity binding. */

void dc_dialog_bind(void dialog_entity, void target_entity)
{
    void bind = get_entity_property(dialog_entity, "bind");

    set_bind_property(bind, "target", target_entity);
    set_bind_property(bind, "animation_match", openborconstant("BIND_ANIMATION_NONE"));
    set_bind_property(bind, "direction", openborconstant("DIRECTION_ADJUST_RIGHT"));

    set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
    set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
    set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));

    set_bind_property(bind, "offset_x", 0);
    set_bind_property(bind, "offset_y", 70);
    set_bind_property(bind, "offset_z", 0);

    set_bind_property(bind, "sort_id", 1);
}