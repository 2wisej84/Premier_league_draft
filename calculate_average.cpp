#include "calculate_average.h"
#include <iostream>
#include <utility>

using namespace std;

//calculate averages of stats and atrributes for each team
//average of goals scored 
const double goalsf_av(std::vector<Team> team, size_t size) {
	

	auto sum = std::accumulate(team.begin(), team.end(), 0, [](int i, Team team) { return i + team.get_goalsf(); });
	double average = static_cast<double>(sum / static_cast<int>(size));
	return average;
}



//average of goals conceded 
const double goalsa_av(std::vector<Team> team, size_t size) {
	auto sum = std::accumulate(team.begin(), team.end(), 0, [](int i, Team team) { return i + team.get_goalsa(); });
	double average = static_cast<double>(sum / static_cast<int>(size));
	return average;
}

//average of speed
const double speed_av(std::vector<Team> team, size_t size) {
	auto sum = std::accumulate(team.begin(), team.end(), 0, [](int i, Team team) { return i + team.get_speed(); });
	double average = static_cast<double>(sum / static_cast<int>(size));
	return average;
}


//average of techniques
const double technique_av(std::vector<Team> team, size_t size) {
	auto sum = std::accumulate(team.begin(), team.end(), 0, [](int i, Team team) { return i + team.get_technique(); });
	double average = static_cast<double>(sum / static_cast<int>(size));
	return average;

}

//average of strength 
const double strength_av(std::vector<Team> team, size_t size) {
	auto sum = std::accumulate(team.begin(), team.end(), 0, [](int i, Team team) { return i + team.get_strength(); });
	double average = static_cast<double>(sum / static_cast<int>(size));
	return average;
}
