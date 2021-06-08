#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_gauntlet/main.c"


/* spawn 3 text boxes, in a chain. */
void dc_run_dialog()
{
    int dialog_step_0 = getlocalvar("dialog_step_0");
    int dialog_step_1 = getlocalvar("dialog_step_1");

    void self = getlocalvar("self");
    
    /* 
    * Entity that talks to Alex. This was populated 
    * by dc_dialog_setup() function in event_think.
    */
    void dialog_player_entity = getentityvar(self, "dialog_player_entity");
    
    void dialog_entity_0 = NULL();
    void dialog_entity_1 = NULL();
    void dialog_entity_2 = NULL();
       
    if (!dialog_step_0)
    {
        dialog_entity_0 = dc_gauntlet_quick_spawn("alex_intro_dialog_0");

        dc_dialog_bind(dialog_entity_0, dialog_player_entity);
       
        setlocalvar("dialog_step_0", 1);
        setlocalvar("alex_intro_dialog_0", dialog_entity_0);

        log("\n step 0");
    }
    else if (!dialog_step_1)
    {
        /*
        * If previous dialog is in place, we
        * want to eliminate it and spawn the
        * next dialog model.
        */

        log("\n step 1");

        dialog_entity_0 = getlocalvar("alex_intro_dialog_0");

        if(dialog_entity_0) 
        {
            if(get_entity_property(dialog_entity_0, "animation_state") == 0)
            {
                killentity(dialog_entity_0);
                setlocalvar("alex_intro_dialog_0", NULL());

                // spawn the text2 that Alex spoke
                dialog_entity_1 = dc_gauntlet_quick_spawn("alex_intro_dialog_1");

                // move the text above Alex's head
                dc_dialog_bind(dialog_entity_0, self);

                setlocalvar("dialog_step_1", 1);
                setlocalvar("alex_intro_dialog_1", dialog_entity_1);
            }
        }
    }
    else if (dialog_step_1)
    {

        /*
        * If previous dialog is in place, we 
        * want to eliminate it and spawn the 
        * next dialog model.
        */

        dialog_entity_1 = getlocalvar("alex_intro_dialog_1");
        
        if (dialog_entity_1)
        {
            if (get_entity_property(dialog_step_1, "animation_state") == 0)
            {
                killentity(dialog_entity_1);
                setlocalvar("alex_intro_dialog_1", NULL());

                // spawn text3: Alex...
                dialog_entity_2 = dc_gauntlet_quick_spawn("alex_intro_dialog_2");

                changeentityproperty(self, "animation", openborconstant("ANI_DIE10"));
                setlocalvar("alex_intro_dialog_2", dialog_entity_2);
            }
        }
    }
}

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