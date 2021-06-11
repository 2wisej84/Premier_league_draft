#pragma once
#include<iostream>
#include <vector>
#include "Team.h"
#include "I_player.h"
#include "defender.h"
#include "attacker.h"
#include "Print_players.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>


std::string convertupper(std::string& s);
std::string convertlower(std::string& s);
int user_team(std::vector <Team> teams, size_t size);
std::vector<Team> get_teams();
std::vector<I_player> get_defenders();
std::vector<I_player*> get_attackers();
I_player get_user_player(std::vector<I_player> &players, int user_id);
I_player* get_trade_player(std::vector<I_player*> players, std::string name);
