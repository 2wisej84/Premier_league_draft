#pragma once
//interface class
#include <iostream>
using namespace std;
//abstract base class
class I_player
{
protected:
	string name;
	int speed;
	int technique;
	int strength;
	int value;
	int old_team_id;
	int new_team_id;
	bool chosen;
public:
	
	I_player(string name, int speed, int technique, int strength, int value, int old_team_id, int new_team_id, bool chosen);
	I_player() = default;
	virtual const string get_name()= 0 {};
	virtual const int get_clean_sheet() = 0;
	virtual const int get_goals() = 0;
	virtual const  double get_speed() = 0 {};
	virtual const double get_technique() = 0{};
	virtual const double get_strength() = 0 {};
	virtual const double get_value() = 0 {};
	virtual const int get_old_team_id() = 0 {};
	virtual const int get_new_team_id() = 0{};
	virtual void change_new_team_id(int a) = 0;
	virtual const bool is_chosen() =0;
	virtual void set_chosen() = 0{};
	virtual ~I_player() = default;
  
};

