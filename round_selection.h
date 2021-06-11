#pragma once

#include<vector>
#include"Team.h"
#include "I_player.h"
#include "get_player_and_team.h"
#include <algorithm>


void select_players(int user_id, const std::vector<Team> teams, std::vector<I_player> &speed, std::vector<I_player> &technique, std::vector<I_player> &strength);
void const print_available_players(int user_id, std::vector<I_player> defenders, std::string assistant);
void user_select_player(std::vector<I_player> &player, std::string name, int user_id, std::string assistant);
