
#include <iostream>
#include "round_selection.h"
#include <iomanip>
#include <list>

using namespace std;


void select_players(int user_id, vector<Team> teams, vector<I_player> &speed, vector<I_player> &technique, vector<I_player> &strength) {

	const string user_team_name = teams[user_id].get_name();
	const string assistant = teams[user_id].get_assistant();
	int weakness = teams[user_id].get_weakness();
		
		for (int i{19}; i > -1; i--) {
			//when i gets to the same id as user teams id, then allow user to select a player
			if (i == user_id) {
				i--;
				
				switch (weakness) {
				case 1:
					print_available_players(user_id, speed, assistant);
					user_select_player(speed, user_team_name, user_id, assistant);
					break;

				case 2:
					print_available_players(user_id, technique, assistant);
					user_select_player(technique, user_team_name, user_id, assistant);
					break;

				case 3:
					print_available_players(user_id, strength, assistant);
					user_select_player(strength, user_team_name, user_id, assistant);
					break;
					
				}
				//if user team is last pick, then break after selection
				if (i == -1)
					break;
		}
			//get other teams to select a player, based on teams biggest weakness
			// will pick from the top of the sorted vecto e.g "speed" vector
			// Then will check if player has not been selected yet
			//if player has not been selected, change players new team id to match teams[i] id
			if (teams[i].get_weakness() == 1) {
				for (int y{}; y < speed.size(); y++) {
					if (speed[y].is_chosen() == false) {
						speed[y].change_new_team_id(i);
						speed[y].set_chosen();
						cout << teams[i].get_name() << " HAVE SELECTED " << speed[y].get_name() << endl << endl;
						cin.get();
						break;
					}
				}
			}

			else if (teams[i].get_weakness() == 2) {
				for (int y{}; y < technique.size(); y++) {
					if (technique[y].is_chosen() == false) {
						technique[y].change_new_team_id(i);
						technique[y].set_chosen();
						cout << teams[i].get_name() << " HAVE SELECTED " << technique[y].get_name() << endl << endl;
						cin.get();
						break;
					}
				}
			}
			else {
				for (int y{}; y < strength.size(); y++) {
					if (strength[y].is_chosen() == false) {
						strength[y].change_new_team_id(i);
						strength[y].set_chosen();
						cout << teams[i].get_name() << " HAVE SELECTED " << strength[y].get_name() << endl << endl;
						cin.get();
						break;
					}
				}
			}
	}
}



   //print players that have not been picked. 
	const void print_available_players(int user_id, vector<I_player*> players, string assistant) {
	    cout << assistant << ": " << "We are team " << user_id + 1 << " So we are up next. Below is a list of players that have yet to have been picked." << endl;
		cin.get();
		cout << setw(15) << "Name"  << setw(10) << "Speed" << setw(15) << "Technique" <<
		setw(15) << "Strength" << setw(10) << "Value" << endl;
		cout << setw(70) << setfill('-') << " " << endl;
		cout << setfill(' ');
		for (int i{}; i < players.size(); i++) {
			if (players[i]->is_chosen() == false) {
				cout << setw(15) << players[i]->get_name() << setw(10) << players[i]->get_speed() << setw(15) << players[i]->get_technique() <<
					setw(15) << players[i]->get_strength() << char(156) << players[i]->get_value() << ",000,000" << endl;
			}
				
		}
		cin.get();
	
	}

	//allow user to select a player
	void user_select_player(vector<I_player> &player, string team_name, int user_id, string assistant ) {

	cout << "\nPlease enter the name of the player that you to wish join your squad." << endl;
	bool user_input = false;
	//check if user input matches any  of the availble players
	while (user_input == false){
		string selection;
		cin >> selection;
		convertupper(selection);
		cout << "\n";
		for (int i{}; i < player.size(); i++) {
			if (selection == player[i].get_name()) {
				//check if player user selects has no been chosen
				if (player[i].is_chosen() == true) {
					cout << "You have selected a player that has already been picked by another team. Select a different player" << endl;
					cin >> selection;
					convertupper(selection);
				}
				else {
					//change player team id to mach user team id
					player[i].change_new_team_id(user_id);
					player[i].set_chosen();
					cout << team_name << " HAVE SELECTED " << player[i].get_name() << endl << endl;
					cin.ignore();
					cin.get();
					user_input = true;
					break;
				}
			}

		}
	//check if user input matches any  of the availble players
	if (user_input == false) 
		cout << "Incorrect input. Please check spelling." << endl;
	}


	}



	

