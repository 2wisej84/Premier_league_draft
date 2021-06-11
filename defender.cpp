#include "defender.h"


//Assign values past in by program, to attacker object attributes
defender::defender(std::string name, int clean_sheet, int speed, int technique, int strength, int value, int old_team_id, int new_team_id, bool chosen)
	:clean_sheet{ clean_sheet },I_player {name, speed, technique, strength, value, old_team_id, new_team_id, chosen}
{
}



const string defender::get_name() {
	return name;
}

const int defender::get_clean_sheet()
{
	return clean_sheet;
}




const double defender::get_speed()
{
	return speed;
}

const double defender::get_technique()
{
	 return technique;
}


const double defender::get_strength()
{
	return strength;
}

const double defender::get_value()
{
	return value;
}



const int defender::get_old_team_id()
{
	return old_team_id;
}

const int defender::get_new_team_id()
{
	return new_team_id;
}


void defender::change_new_team_id(int a)
{
	new_team_id = a;
}

//Calculate if a player ha been chosen already by another team or not
const bool defender::is_chosen()
{
	if (chosen == false)
		return false;
	else
		return true;
}
//when a team selects a player, set chosen to true, to prevent being picked by another team
void defender::set_chosen()
{
	chosen = true;
}
