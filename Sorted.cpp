#include "Sorted.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool sort_player_by_speed(I_player *a, I_player *b)
{    
	
	return a->get_speed() > b->get_speed();
}

bool sort_player_by_technique(I_player* a, I_player* b)
{
	return a->get_technique() > b->get_technique();
}

bool sort_player_by_strength( I_player* a, I_player* b)
{
	return a->get_strength() > b->get_strength();
}



std::vector<I_player*> sort_players(std::vector<I_player*> players, int weakness) {
	if (weakness == 1) {
		sort(players.begin(), players.end(), [](I_player* player_a, I_player* player_b) { 	return player_a->get_speed() > player_b->get_speed(); });
		return players;
	}

	else if (weakness == 2) {
		sort(players.begin(), players.end(), [](I_player* player_a, I_player* player_b) { 	return player_a->get_technique() > player_b->get_technique(); });
			return players;
		}

	else {
		sort(players.begin(), players.end(), [](I_player* player_a, I_player* player_b) { 	return player_a->get_strength() > player_b->get_strength(); });
		return players;
		}

	}

