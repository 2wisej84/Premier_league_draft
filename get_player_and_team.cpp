#include <iostream>
#include "get_player_and_team.h"

using namespace std;

//convert string to upper case
string convertupper(string& s) {

	std::transform(s.begin(), s.end(), s.begin(),
		[](char c) { return std::toupper(c); });

	return s;
}

//convert string to lower case. start i at 1 so the first letter can still be in capitals
string convertlower(string& s) {
	for (int i = 1; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}
     return s;
}





int user_team(std::vector <Team> teams, size_t size) {

	string incorrect_input = "Incorrect input. Please check spelling.";
	bool user_input = false;
	//error checking if user input matches an available team name
	while (user_input == false) {
		string selection;
		cout << std::setw((full_width / 2) - 3) << left << "";
		//allow user to select a team
		getline(cin,selection);
		convertupper(selection);
		for (int i = 0; i < size; i++) {
			if (selection == teams[i].get_name()) {
				user_input = true;
				return teams[i].get_id();
			}
		}
		//error checking if user input matches an available team name
		if (user_input == false)
			cout << setw((full_width - incorrect_input.length()) / 2) << left << "" << incorrect_input << endl;
	
	}
}




std::vector<Team> get_teams() {

	//create file object
	ifstream in_file;
	in_file.open("Text.txt");
	if (!in_file) 
	  cerr << "problem opening file" << endl;

	string name;
	int points;
	int goalsf;
	int goalsa;
	double speed;
	double technique;
	double strength;
	string assistant;
	int id;
	int weakness;


	int margin = (full_width - 85) / 2;
	std::cout << std::setw(margin) << std::left << " "
		<< setw(20) << left << "Name"
		<< setw(15) << left << "Points"
		<< setw(10) << left << "GF"
		<< setw(10) << left << "GA"
		<< setw(10) << left << "Speed"
		<< setw(15) << left << "Technique"
		<< setw(10) << left << "Strength" << endl << endl << endl;

	std::string pointsstring, goalsfstring, goalsastring, speedstring, techniquestring, strengthstring, idstring, weaknessstring, chosenstring;
	std::string line;

	std::vector<Team> teams; 
	//read in data from in_file(Text.txt) and put each element into a string variable
	while (getline(in_file, line)) {
		stringstream ss(line);
		getline(ss, name, ',');
		getline(ss, pointsstring, ',');
		getline(ss, goalsfstring, ',');
		getline(ss, goalsastring, ',');
		getline(ss, speedstring, ',');
		getline(ss, techniquestring, ',');
		getline(ss, strengthstring, ',');
		getline(ss, assistant, ',');
		getline(ss, idstring, ',');
		getline(ss, weaknessstring);

		//convert string variables into integers or doubles
		points = stoi(pointsstring);
		goalsf = stoi(goalsfstring);
		goalsa = stoi(goalsastring);
		speed = stod(speedstring);
		technique = stod(techniquestring);
		strength = stod(strengthstring);
		id = stoi(idstring);
		weakness = stoi(weaknessstring);

		//print out each variable
		cout << setw(margin) << left << " "
			<< setw(20) << left << name
			<< setw(15) << left << points
			<< setw(10) << left << goalsf
			<< setw(10) << left << goalsa
			<< setw(10) << left << speed
			<< setw(15) << left << technique
			<< setw(10) << left << strength << endl << endl << endl;

		//create object of which contains each element in each line of the text file and then add object to a vector
		Team team = {name, points, goalsf, goalsa, speed, technique, strength, assistant, id, weakness};
		teams.push_back(team);
	

	}
	//close text file
	in_file.close();
	//return vectors
	return teams;

	
}





	std::vector<I_player> get_defenders() {
		//create file object
		ifstream defenders_file;
		defenders_file.open("defender.txt");


		if (!defenders_file) {
			cerr << "problem opening file" << endl;
			//return 1;
		}

		string name;
		int clean_sheet;
		int speed;
		int technique;
		int strength;
		int value;
		int old_team_id;
		int new_team_id;
		bool chosen;


		vector<I_player> defenders;
		//read in each line from in_file(defender.txt)
		while (defenders_file >> name >> clean_sheet >> speed >> technique >> strength >> value >> old_team_id >> new_team_id >> chosen) {
			//create object and add each element read from file into object
			defender Defender = { name, clean_sheet, speed, technique, strength, value, old_team_id, new_team_id, chosen };
			//add object into vector
			defenders.push_back(Defender);

		}

		return defenders;
		defenders_file.close();
	}





	vector<I_player*> get_attackers() {
		//create file object
		ifstream attackers_file;
		attackers_file.open("attacker.txt");


		if (!attackers_file) {
			cerr << "problem opening file" << std::endl;
			//return 1;
		}


		string name;
		int goals;
		int speed;
		int technique;
		int strength;
		int value;
		int old_team_id;
		int new_team_id;
		bool chosen;


		vector<I_player*> attackers;
		//read in data from in_file(Txt.txt)
		while (attackers_file >> name >> goals >> speed >> technique >> strength >> value >> old_team_id >> new_team_id >> chosen) {
			I_player* attackerpointer = new attacker(name, goals, speed, technique, strength, value, old_team_id, new_team_id, chosen);
			attackers.push_back(attackerpointer);

		}
		return attackers;
		attackers_file.close();
	}





//track down player that the user selected and return as pointer
I_player get_user_player(vector<I_player> &players, int user_id) {


	for (int i{}; i < players.size(); i++) {
		if (players[i]->get_new_team_id() == user_id) {
			I_player* user_player = players[i];
			return user_player;
			break;
		}
	}

}



