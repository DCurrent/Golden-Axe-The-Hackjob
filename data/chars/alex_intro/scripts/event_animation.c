#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_guantlet/main.c"


/* spawn 3 text boxes, in a chain. */
void checktext()
{
    int dialog_step_0 = getlocalvar("dialog_step_0");
    int dialog_step_1 = getlocalvar("dialog_step_1");

    void self = getlocalvar("self");
    
    void dialog_entity_0 = NULL();
    void dialog_entity_1 = NULL();
    void dialog_entity_2 = NULL();

    void bind = NULL();

    if (!dialog_step_0)
    {
        dialog_entity_0 = dc_gauntlet_quick_spawn("alex_intro_dialog_0");

        
       
        setlocalvar("dialog_step_0", 1);
        setlocalvar("alex_intro_dialog_0", dialog_entity_0);
    }
    else if (!dialog_step_1)
    {
        /*
        * If previous dialog is in place, we
        * want to eliminate it and spawn the
        * next dialog model.
        */

        dialog_entity_0 = getlocalvar("alex_intro_dialog_0");

        if (dialog_entity_0 && get_entity_property(text1, "animation_state") == openborconstant("ANIMATING_NONE"))
        {
            killentity(dialog_entity_0);
            setlocalvar("alex_intro_dialog_0", NULL());    
            
            // spawn the text2 that Alex spoke
            dialog_entity_1 = dc_gauntlet_quick_spawn("alex_intro_dialog_1");

            // move the text 53 above Alex's head
            
            setlocalvar("dialog_step_1", 1);
            setlocalvar("alex_intro_dialog_1", dialog_entity_1);
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
        
        if (dialog_entity_1 && get_entity_property(text2, "animation_state") == openborconstant("ANIMATING_NONE"))
        {
            killentity(dialog_entity_1);
            setlocalvar("alex_intro_dialog_1", NULL());
            
            // spawn text3: Alex...
            dialog_entity_2 = dc_gauntlet_quick_spawn("alex_intro_dialog_2");
                        
            changeentityproperty(self, "animation", openborconstant("ANI_DIE10"));
            setlocalvar("alex_intro_dialog_2", dialog_entity_2);
        }
    }// end of if
}

void dc_dialog_bind(void acting_entity, void target_entity)
{
    bind = get_entity_property(bind, dialog_entity_0);

    set_bind_property(bind, "target", self);
    set_bind_property(bind, "animation_match", openborconstant("BIND_ANIMATION_NONE"));
    set_bind_property(bind, "direction", openborconstant("DIRECTION_ADJUST_RIGHT"));
    set_bind_property(bind, "offset_x", 0);
    set_bind_property(bind, "offset_y", 53);
    set_bind_property(bind, "offset_z", 0);

    set_bind_property(bind, "sort_id", 1);
}