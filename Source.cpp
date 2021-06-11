#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Team.h"
#include <vector>
#include "averages.h"
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include<ctime>
#include "defender.h"
#include "attacker.h"
#include "I_player.h"
#include "calculate_average.h"
#include "get_player_and_team.h"
#include "assistant.h"
#include "Sorted.h"
#include "round_selection.h"
#include "trade_and_reaction.h"
#include "Print_players.h"
using namespace std;
int main() {
	// Calculate widths, to create algorithm to line things up neatly
	
	const string welcome{ "WELCOME TO THE PREMIER LEAGUE DRAFT FOR 2021/2022" };
	const string sub_title{ "LAST SEASONS TEAM STATS AND AN AVERAGE OF PLAYER STATS" };

	cout << "\n\n";
	cout << setw((full_width - welcome.length()) / 2) << left << "" << welcome << endl;
	cout << setw(full_width) << setfill('-') << "" << endl;
	//reseting setfill method to default-otherwise all spaces would be filled with dashes 
	cout << setfill(' ') << "" << endl;
	//print sub title
	cout << setw((full_width - sub_title.length()) / 2) << left << "" << sub_title << endl << endl;

	//create a vector to store the vetors returned from get_teams function and print out stats
	vector<Team> teams = get_teams();

	
	
	//---------------------------------------------------------------------------------
	const string continue_ = { "Press Enter to keep progressing through the program. " };
	const string seed = { "SEED SELECTION WILL RUN IN REVERSE ORDER. THE NEWLY PROMOTED TEAMS WILL BE CHOOSING FIRST! " };
	const string control = { "PLEASE SELECT THE TEAM THAT YOU WISH TO TAKE CONTROL OF BELOW. " };
	//set width of strings so they are placed in the middle of the screen
	cout << setw((full_width - continue_.length()) / 2) << "" << continue_;
	cin.get();
	cout << "\n\n"<< setw((full_width - seed.length()) / 2) << left << "" << seed;
    cin.get();
	cout << "\n\n" << setw((full_width - control.length()) / 2) << left << "" << control << std::endl;

	//allow user to select a team
	 //recieve ID of the team the user selected
	int user_id = user_team(teams, teams.size());
	//create new object pointer, pointing to the address of the team with user_id
	Team &user = teams[user_id];

	cout << "\n\n";
    const string assistant_msg{ "IT IS NOW TIME TO GO BACK TO YOUR CHANGING ROOMS TO MEET WITH YOUR ASSISTANT MANAGERS. " };
	cout << setw((full_width - assistant_msg.length()) / 2) << left << "" << assistant_msg;
	//std::cin.ignore();
	cin.get();
	cout << "\n\n\n\n\n";
	

 //get season stat averages of all teams into an object. E.G all goals scored divided by 20
	const double goalsf_atr = goalsf_av(teams, teams.size());
	const double goalsa_atr = goalsa_av(teams, teams.size());
	const double speed_atr = speed_av(teams, teams.size());
	const double technique_atr = technique_av(teams, teams.size());
	const double strength_atr = strength_av(teams, teams.size());
	averages average{ goalsf_atr, goalsa_atr, speed_atr, technique_atr, strength_atr}; 




	//calculate and assign each temas biggest weakness
		for (int i{}; i < teams.size(); i++) {
			weakness(teams[i], average);
	}

	//-----------------------------------Assistant manager Advice code----------------------------------------
	cout << setw(full_width) << setfill('-') << "" << endl;
	cout << setfill(' ') << "" << endl;
	//pass in team object named user and averages struct called average
	am_advice(user, average);



	const string assistant = user.get_assistant();
	cout << assistant << ": ";
	int user_weakness = user.get_weakness();
	print_weakness(user_weakness);
	cin.get();
	cout << "\n";

	// set empty spaces to dashes, then assign back to default
	cout << setw(full_width) << setfill('-') << "" << endl << endl;
	cout << setfill(' ') << "" << endl;
	
	const string round1{ "IT IS NOW TIME FOR ROUND 1. BELOW IS A LIST OF ALL DEFENDERS AVAILABLE, ALONG WITH THEIR STATS. " };
	cout << std::setw((full_width - round1.length()) / 2) << "" << round1;
    cin.get();
	cout << "\n\n" << endl;
	cout << setw(full_width) << setfill('-') << "" << endl;
	cout << setfill(' ') << "" << endl;


	// print defenders and place all defenders in a vector
	vector<I_player> defenders = get_defenders();
	print_players(defenders);

	const string selection{ "PLEASE GET YOUR SELECTIONS READY! " };
	cout << setw((full_width - selection.length()) / 2) << "" << selection;
	cin.get();
	cout << "\n\n";
	 
	

	//sort players in vector by stat and return them into a vector
	vector<I_player> sort_by_speed = sort_players(defenders, 1);
	vector<I_player> sort_by_technique = sort_players(defenders, 2);
	vector<I_player> sort_by_strength = sort_players(defenders, 3);





	cout << assistant << ": ";
	//print shortlist of players sorted by user teams biggest weakness
	print_shortlist(user_weakness, sort_by_speed, sort_by_technique, sort_by_strength);
	cout << setw(full_width) << setfill('-') << "" << endl;
	cout << setfill(' ') << "" << endl;
	
	const string round_started = "THE ROUND HAS NOW STARTED. TEAM 20 PLEASE TAKE YOUR PICK";
	cout << setw((full_width - round_started.length()) / 2) << left << "" << round_started << endl;
	cin.get();
	cout << "\n";
	
	//std::cout << "We are seed " << user_id + 1 << " So we are up next. Below is a list of players that have yet to have been picked." << std::endl << std::endl;
	select_players(user_id, teams, sort_by_speed, sort_by_strength, sort_by_technique);


	const string reaction{ "THAT IS THE END OF THE ROUND. IT IS NOW TIME TO HEAD OVER TO GEOFF SHREEVES TO HEAR SOME OF THE PLAYER REACTIONS." };
	cout << setw((full_width - reaction.length()) / 2) << left << "" << reaction;
	cin.get();
	cout << setw(full_width) << setfill('-') << " " << endl;
	cout << setfill(' ');
	cout << "\n\n";

	//create pointer to point to th defender that the user chose
	defender& user_player;
    user_player = get_user_player(defenders, user_id);

	//function to run the post interview
	reaction_(defenders, user.get_name(), user_player->get_name(), user_id, 1);
	cout << setw(full_width) << setfill('-') << " " << endl;
	std::cout << setfill(' ');
	std::cout << "\n\n";

	const string trade{ "IT IS NOW TIME FOR THE ROUND OF TRADES. IF YOU GET 2 TRADES REJECTED, YOU WILL HAVE TO KEEP THE PLAYER. GOOD LUCK! " };
	cout << setw((full_width - trade.length()) / 2) << left << "" << trade;
	cin.get();
	cout << "\n\n";
    
	//function to allow trades
	 make_trade(assistant, user_player, defenders);
	 cin.get();


	cout << "\n\n\n";


	 // Round of defenders finishes. Now moving on to second rounfor attackers. uses the same functions, just with different data
	 //------------------------------------------------------------------------------------------------------------------------------------
	const string round2{ "IT IS NOW TIME FOR ROUND 2. BELOW IS A LIST OF AVAILABLE PLAYERS FOR THIS ROUND" };



	 cout << setw((full_width - round2.length()) / 2) << "" << round2;
	 cin.get();

	 cout << "\n\n";

	 vector<I_player*> attackers = get_attackers();
	 print_players(attackers);
	 cin.get();


	 vector<I_player*> sort_by_speed2 = sort_players(attackers, 1);
	 vector<I_player*> sort_by_technique2 = sort_players(attackers, 2);
	 vector<I_player*> sort_by_strength2 = sort_players(attackers, 3);

	 cout << assistant << ": ";
	 print_shortlist(user_weakness, sort_by_speed2, sort_by_technique2, sort_by_strength2);
	 cout << "\n\n";
	 cout << setw((full_width - round_started.length()) / 2) << "" << round_started;
	 cin.get();
	 cout << "\n\n";
	 select_players(user_id, teams, sort_by_speed2, sort_by_strength2, sort_by_technique2);
	 cout << setw((full_width - reaction.length()) / 2) << left << "" << reaction;
	 cin.get();
	 cout << "\n\n";

	 //pointer to player that user selected
	 I_player* user_player2 = new attacker;
	 user_player2 = get_user_player(attackers, user_id);

	 // function for post interview
	 reaction_(attackers, user.get_name(), user_player2->get_name(), user_id, 2);



	 cout << setw(full_width) << setfill('-') << " " << endl;
	 cout << setfill(' ');
	 cout << "\n\n";
	 cout << setw((full_width - trade.length()) / 2) << left << "" << trade;
	 cin.get();
	 cout << "\n\n";

	 //trade function
	 make_trade(assistant, user_player2, attackers);

	 cin.get();
	 cout << "\n\n\n";
	 const string end{ "THAT IS THE END OF THE DRAFT. " };
	 const string result{ "BELOW ARE THE FINAL RESULTS. " };
	 cout << setw((full_width - end.length()) / 2) << left << "" << end; //end variable
	 cin.get();
	 cout << "\n\n";
	 cout << setw((full_width - result.length()) / 2) << left << "" << result;
	 cin.get();
	 cout << "\n\n";



	 //print final results of all players and their new clubs
	 print_results(defenders, attackers, teams);




	return 0;
}


///---------------------------------------------------end of main---------------------------------------------------------------------------
//


