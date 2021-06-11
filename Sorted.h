#pragma once

#include <vector>
#include "defender.h"
#include "I_player.h"


bool sort_player_by_speed(I_player* a,  I_player* b);
bool sort_player_by_technique(I_player* a, I_player* b);
bool sort_player_by_strength(I_player* a, I_player* b);
std::vector<I_player> sort_players(std::vector<I_player> players, int weakness);
