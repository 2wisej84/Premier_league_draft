#pragma once

#include "I_player.h"
#include "defender.h"
#include "attacker.h"
#include <vector>
#include "Team.h"

const int full_width = 211;
const void print_players(std::vector<I_player> player);
const void print_results(std::vector<I_player*> defenders, vector<I_player*> attackers, const std::vector <Team> teams);