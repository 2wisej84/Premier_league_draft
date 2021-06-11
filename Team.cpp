#pragma once
#include "Team.h"
#include <iostream>

Team::Team(std::string name, int points, int goalsf, int goalsa, double speed, double technique, double strength, std::string assistant, int id, int weakness)
	:name{ name }, points{ points }, goalsf{ goalsf }, goalsa{ goalsa }, speed{ speed }, technique{ technique }, strength{ strength }, assistant{ assistant }, id{ id }, weakness{weakness}
{

}




void Team::get_data()
{
	std::cout << name << " " << points << " " << goalsf << " " << goalsa << " " << speed << " " << technique << " " << strength << " " << assistant << " "<< id << " " << weakness << std::endl;
}

std::string Team::get_name()
{
	return name;
}

int Team::get_goalsf()
{
	return goalsf;
}

int Team::get_goalsa()
{
	return goalsa;
}

double Team::get_speed()
{
	return speed;
}


double Team::get_technique()
{
	return technique;
}

double Team::get_strength()
{
	return strength;
}

std::string Team::get_assistant() {
	return assistant;
}

int Team::get_id() {
	return id;
}

int Team::get_weakness()
{
	return weakness;
}

void Team::set_weakness(int weakness_)
{
	weakness = weakness_;
}





