#include "attacker.h"




//Assign values past in by program, to attacker object attributes
attacker::attacker(string name, int goals, int speed, int technique, int strength, int value, int old_team_id, int new_team_id, bool chosen)
	:goals{goals}, I_player{ name, speed, technique, strength, value, old_team_id, new_team_id, chosen }
{
}


const string attacker::get_name() {
	return name;
}

const int attacker::get_goals()
{
	return goals;
}




const double attacker::get_speed()
{
	return speed;
}

const double attacker::get_technique()
{
	return technique;
}


const double attacker::get_strength()
{
	return strength;
}

const double attacker::get_value()
{
	return value;
}



const int attacker::get_old_team_id()
{
	return old_team_id;
}

const int attacker::get_new_team_id()
{
	return new_team_id;
}


void attacker::change_new_team_id(int a)
{
	new_team_id = a;
}

//Calculate if a player ha been chosen already by another team or not
const bool attacker::is_chosen()
{
	if (chosen == false)
		return false;
	else
		return true;
}

//when a team selects a player, set chosen to true, to prevent being picked by another team
void attacker::set_chosen()
{
	chosen = true;
}
