
void main()
{
    int i = 0;
	int player_count = openborvariant("maxplayers");
	void player_entity = NULL();
    void acting_entity = getlocalvar("self");

    for (i = 0; i < player_count; i++)
    {
        /*
        * Get entity for this player index.
        * If there isn't one, just move on.
        */
        player_entity = getplayerproperty(i, "entity");

        if (!player_entity)
        {
            continue;
        }

        float player_pos_x = get_entity_property(player_entity, "position_x");
        float player_pos_y = get_entity_property(player_entity, "position_y");
        float player_pos_z = get_entity_property(player_entity, "position_y");

        player_pos_y += 60;
        player_pos_z += 1;

        set_entity_property(acting_entity, "position_base", player_pos_y);
        set_entity_property(acting_entity, "position_x", player_pos_x);
        set_entity_property(acting_entity, "position_y", player_pos_y);
        set_entity_property(acting_entity, "position_z", player_pos_z);
    }
}
