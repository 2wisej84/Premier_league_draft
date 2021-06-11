#pragma once
#include <iostream>
#include "Team.h"
#include "averages.h"
#include <vector>
#include "I_player.h"


const void am_advice(Team team, averages average);
const std::string comment(double user, double average, int x, int i);
double percentages(double user, double average);
void weakness(Team &teams, averages average);
void print_weakness(int weakness);
const void print_shortlist(int user_weakness, std::vector<I_player> speed, std::vector<I_player> technique, std::vector<I_player> strength);