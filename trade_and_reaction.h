#pragma once
#include "I_player.h"
#include "Team.h"
#include <vector>
#include "Print_players.h"
#include "defender.h"
#include "get_player_and_team.h"
using namespace std;
void reaction_(vector<I_player*> player, string team_name, string player_name, int user_id, int round);
void make_trade(string assistant, I_player* user_player, vector<I_player*> players);
bool check_trade(I_player* user_player, I_player* trade_player);
I_player* get_trade_player(vector<I_player*> players, string name);
string check_input(vector<I_player*> players);
