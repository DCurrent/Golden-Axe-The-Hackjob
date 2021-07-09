
#include "data/scripts/dc_spinner/main.c"

void main()
{
	debug_select_screen();
}

void debug_select_screen()
{
	int player_index = getlocalvar("player");
	int key_press = getplayerproperty(player_index, "newkeys");
	int key_hold = getplayerproperty(player_index, "keys");
}



