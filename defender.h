#pragma once
#include <iostream>
#include "I_player.h"
using namespace std;
class defender final: public I_player
{
private:
	int clean_sheet;
public:
	defender(string name, int clean_sheet, int speed, int technique, int strength, int value, int old_team_id, int new_team_id, bool chosen);
	defender() = default;
	const string get_name() override;
	const int get_clean_sheet() override;
	const double get_speed() override;
	const double get_technique() override;
	const double get_strength() override;
	const double get_value() override;
	const int get_old_team_id() override;
	const int get_new_team_id() override;
	const bool is_chosen() override;
	void change_new_team_id(int a) override;
	void set_chosen() override;
	const int get_goals() override { return -1; };
	~defender() = default;



	
};

//int get_clean_sheet() override;