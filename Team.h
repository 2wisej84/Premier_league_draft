#pragma once
#include <iostream>
class Team
{
private:

	std::string name;
	int points;
	int goalsf;
	int goalsa;
	double speed;
	double technique;
	double strength;
	std::string assistant;
	int id;
	int weakness;

public:
	Team(std::string name, int points, int goalsf, int goalsa, double speed, double technique, double strength, std::string assistant, int id, int weakness);
	~Team() = default;
	
	void get_data();
	std::string get_name();
	int get_goalsf();
	int get_goalsa();
	double get_speed();
	double get_technique();
	double get_strength();
	std::string get_assistant();
	int get_id();
	int get_weakness();
	void set_weakness(int weakness_);


};


