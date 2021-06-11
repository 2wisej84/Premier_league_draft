#pragma once
#include <iostream>
#include "Team.h"
#include <vector>
#include <algorithm>
#include <numeric>

const double goalsf_av(std::vector<Team> team, size_t size);
const double goalsa_av(std::vector<Team> team, size_t size);
const double speed_av(std::vector<Team> team, size_t size);
const double technique_av(std::vector<Team> team, size_t size);
const double strength_av(std::vector<Team> team, size_t size);