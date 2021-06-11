#include <iostream>
#include "assistant.h"
#include <iomanip>
#include <vector>
using namespace std;


//-------------------Assistant manager advice -------------------------------------------
const void am_advice(Team team, averages average) {
	cout << "\n\n";

	//print our user teams average for each stat, up against the average of the whole league
	//calculate whether team stats are higher or lower than average.
	cout << team.get_assistant() << ": Hello Boss! I am your assistant.  I have gathered some data for us to look at. I have also attached my opinion regarding the importance of each stat." << endl;
	cin.get();
	
	cout << setw(18) << left << "Stat" << setw(20) << left << team.get_name() << setw(30) << left
		<< "League Average" << "Comments" << endl;
    cout << setw(160) << setfill('-') << "" << endl;
	cout << setfill(' ') << "";

	cout << setw(18) << left << "Goals Scored" << setw(20) << left << team.get_goalsf() << setw(30) << left
		<< average.get_goalsf() << comment(team.get_goalsf(), average.get_goalsf(), 1, 1) << endl << endl;

    cout << std::setw(18) << left << "Goals conceded" << setw(20) << left << team.get_goalsa() <<setw(30) << left
		<< average.get_goalsa() << comment(team.get_goalsa(), average.get_goalsa(), 2, 1) << endl << endl;

	cout << setw(18) << left << "Speed" << setw(20) << left << team.get_speed() << setw(30) << left
		<< setprecision(3) << average.get_speed() << comment(team.get_speed(), average.get_speed(), 1, 2) << endl << endl;

	cout << setw(18) << left << "Technique" << setw(20) << left << team.get_technique()<< setw(30) << left
		<< setprecision(3) << average.get_technique() << comment(team.get_technique(), average.get_technique(), 1, 3) << endl << endl;

	cout << setw(18) << left << "Strength" << setw(20) << left << team.get_strength() << setw(30) << left
		<< setprecision(3) << average.get_strength() << comment(team.get_strength(), average.get_strength(), 1, 4) << endl << endl;
	cin.get();

}


const string comment(double user, double average, int x, int i) {

	//int i{};
	//srand(time(0));
	//i = 1 + (rand() % 4);
	// kept producing the same number for i as build was moving quicker that the srand function
	

	//pass in different number for i, so different string is produced each time
	if (x == 1) {
		if (user > average)
			switch (i) {
			case 1:
				return "We are above average on this stat so no need to concentrate on it too much.";
				break;
			case 2:
				return "We are comfortable in this area. I dont think adding to this area would be beneficial.";
				break;
			case 3:
				return "No need to worry getting someone in here. We were above average last season.";
				break;
			case 4:
				return "The squad looks fine in this area.";
				break;
			}
		else
			switch (i) {
			case 1:
				return "We are below on this one. We should maybe think about adding some value in this area.";
				break;
			case 2:
				return "I think it would be a good idea to add some value in this area. We struggle here.";
				break;
			case 3:
				return "The squad could definitely do with some depth in this area. ";
				break;
			case 4:
				return "Definitely something to be aware of. We may need some help in this area";
			}
	}
	else {
		//someitmes a stat is better if they are lower E.G goals conceded. So we need different logic
		if (user < average)
			return "We look good here. This shouldnt be a priority";
		else
			return "This could be an area of priority. We were below the average last season.";
	}
}


//calculate each teams weakness
void weakness(Team &teams, averages average) {
	
	


	double speed_pctg = percentages(teams.get_speed(), average.get_speed());
	double technique_pctg = percentages(teams.get_technique(), average.get_technique());
	double strength_pctg = percentages(teams.get_strength(), average.get_strength());


	if (speed_pctg < technique_pctg && speed_pctg < strength_pctg)
		teams.set_weakness(1);
	

	else if (technique_pctg < speed_pctg && technique_pctg < strength_pctg)
		teams.set_weakness(2);
		
	else
		teams.set_weakness(3);
		

}

double percentages(double user, double average) {
	//calculate the percentage difference between team stat and league stat average
	double change = user - average;
	double percentage = (change / average) * 100;
	return percentage;


}

// whichever user team weakness is, print relevant message
void print_weakness(int weakness) {
	// Key
	//1:speed, 2: technique, 3: strength
	
	switch (weakness) {
	case 1:
		cout << "The data suggests that our main weakness compared to the rest of the league is speed. I will provide a shortlist of all players sorted by speed.";
		break;

	case 2:
		cout << "The data suggest that our main weakness compared to the rest of the league is technique. I will provide a shortlist of all players sorted by technique.";
		break;

	case 3:
	   cout << "The data suggest that our main weakness compared to the rest of the league is strength. I will provide a shortlist of all players sorted by strength. ";
		break;
	}

}


//print players sorted by weakness stat. each vector is a list of all plaers sorted by speed or strength or technique
const void print_shortlist(int user_weakness, vector<I_player*> speed, vector<I_player*> technique, vector<I_player*> strength) {


	switch (user_weakness) {
	case 1:
		cout << "I have sorted the list of available players by speed, gaffer. This should help you to choose the right player for the squad." << endl;
		cin.get();
		cout << setw(15) << "Name" << "Speed" << endl;
		for (int i{}; i < speed.size(); i++)
			cout << setw(15) << speed[i]->get_name() << speed[i]->get_speed() << endl;

		break;
	case 2:
		cout << "I have sorted the list of available players by technique, gaffer. This should help you to choose the right player for the squad." << endl;
		cin.get();
		cout << setw(15) << "Name" << "Technique" << endl;
		for (int i{}; i < speed.size(); i++)
			cout << setw(15) << technique[i]->get_name() << technique[i]->get_technique() << endl;

		break;

	case 3:
		cout << "I have sorted the list of available players by strength, gaffer. This should help you to choose the right player for the squad." << endl;
		cin.get();
		cout << setw(15) << "Name" << "Strength" << endl;
		for (int i{}; i < speed.size(); i++)
			cout << setw(15) << strength[i]->get_name() << strength[i]->get_strength() << endl;

		break;
	}
	}



