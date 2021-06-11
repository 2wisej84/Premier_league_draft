
#include"Print_players.h"
#include <iostream>
#include <iomanip>

using namespace std;
//print all players
const void print_players(std::vector<I_player*> player) {
	int margin = (full_width - 85) / 2;
	if (player[0]->get_clean_sheet() != -1) {
		std::cout << std::setw(margin) << std::left << " "
			<< setw(20) << left << "Name"
			<< setw(15) << left << "Clean sheet"
			<< setw(10) << left << "Speed"
			<< setw(15) << left << "Technique"
			<< setw(15) << left << "Strength"
			<< setw(10) << left << "Value" << endl << endl << endl;
	
		for (auto players : player) {
			std::cout << setw(margin) << left << " "
				<< setw(20) << left << players->get_name()
			    << setw(15) << left << players->get_clean_sheet()
				<< setw(10) << left << players->get_speed()
				<< setw(15) << left << players->get_technique()
				<< setw(15) << left << players->get_strength()
				<< char(156) << players->get_value() << ",000,000" << endl << endl << endl;
		}
	}

	else
	{
		std::cout << std::setw(margin) << std::left << " "
			<< setw(20) << left << "Name"
			<< setw(15) << left << "GOALS"
			<< setw(10) << left << "Speed"
			<< setw(15) << left << "Technique"
			<< setw(15) << left << "Strength"
			<< setw(10) << left << "Value" << endl << endl << endl;
		//for (int i{}; i < player.size(); i++) 
		for (auto players : player) {
			std::cout << setw(margin) << left << " "
				<< setw(20) << left << players->get_name()
				<< setw(15) << left << players->get_goals()
				<< setw(10) << left << players->get_speed()
				<< setw(15) << left << players->get_technique()
				<< setw(15) << left << players->get_strength()
				<< char(156) << players->get_value() << ",000,000" << endl << endl << endl;
		}
	}
}



//print final results of all players and their new teams
const void print_results(std::vector<I_player*> defenders, std::vector<I_player*> attackers, std::vector <Team> teams) {
	int margin = (full_width - 85) / 2;

	cout << setw(margin) << left << " "
		<< setw(30) << left << "Team"
		<< setw(30) << left << "First pick"
		<< setw(30) << left << "Second pick" << endl;
	cout << setw(full_width) << std::setfill('-') << " " << endl;
	cout << setfill(' ');


	//if defnder[y] and attacker[j] have the same team id as team[i], print our players.
	for (int i{}; i < teams.size(); i++) {
		cout << setw(margin) << left << " "
			<< setw(30) << left << teams[i].get_name();
		for (int y{}; y < defenders.size(); y++) {
			if (defenders[y]->get_new_team_id() == i)
				cout << std::setw(30) << left << defenders[y]->get_name();
		}
		for (int j{}; j < attackers.size(); j++) {
			if (attackers[j]->get_new_team_id() == i)
				cout << setw(30) << left << attackers[j]->get_name();
		}
		cout << "\n\n";
	}
}