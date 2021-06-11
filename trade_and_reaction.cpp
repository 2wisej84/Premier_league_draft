
#include <iostream>
#include "trade_and_reaction.h"




void reaction_(vector<I_player*> player, string team_name, string player_name, int user_id, int round) {

	string interview{ "Geoff Shreeves" };


	int old_team_id{};
	for (int i{}; i < player.size(); i++) {
		if (player[i]->get_new_team_id() == user_id) {
			old_team_id = player[i]->get_old_team_id();
		}
	}

	cout << interview << " is with " << convertlower(player_name) << " to get his thoughts on his move to " << convertlower(team_name) << ". ";
	cin.get();
	cout << "\n";
	int lower = user_id - old_team_id;
	int higher = old_team_id - user_id;
	if (round == 1) {
		if (old_team_id > user_id) {
			if (higher == 1) {
				cout << interview << ": So let us know your feelings from the draft. You have joined a team who finished " << higher << " position higher in the league than your old team did last season." << endl;
			}
			
			else {
				cout << interview << ": So let us know your feelings from the draft. You have joined a team who finished " << higher << " positions higher in the league than your old team did last season." << endl;
			}
			cout << "Do you think that you are good enough to get into this starting line up? ";
			cin.get();
			cout << "\n" << convertlower(player_name) << ": Yes i feel very confident making the step up. I believe this is my level and i plan to prove it.";
			cin.get();
			cout << "\n" << interview << ": Great. its always nice to hear a player with confidence. What about your new manager then? " <<
				"He is yet to manage a team in the Premier League. Is he the man to push this team up the table? ";
			cin.get();
			cout << "\n" << convertlower(player_name) << ": I believe he can. We will just have to wait and see. " <<
				"Hopefully he can bring in some more quality in the next round of the draft, which will give us an even better chance at succeeding.";
			cin.get();

		}


		else if (old_team_id < user_id) {
			if (lower == 1) {
				cout << interview << ": You have joined a team who finished " << lower << " position lower in the league than your old team did last season" << endl;
			}
			else {
				cout << interview << ": You have joined a team who finished " << lower << " positions lower in the league than your old team did last season" << endl;
			}

			cout << interview << ": I can imagine that you may be frustrated with this result. ";
		    cin.get();
			cout << "\n" << player_name << ": That is the nature of the draft, anything can happen. But i believe i have the ability to push the team up the league. ";
			cin.get();
			cout << "\n" << interview << " Great. its always nice to hear a player with confidence. What about your new manager then? " << endl;
			cout << interview << ": He is yet to manage a team in the Premier League. Is he the man to bring success to " << team_name << "? ";
		    cin.get();
			cout << "\n" << player_name << ": He has a great team to work with, so i am sure we will be successful this Season. " <<
				"Hopefully he can bring in some more quality in the next round of the draft, which will give us an even better chance.";
			cin.get();

		}

		else {
			cout << interview << ": How are you feeling after the draft? You have been selected by your old team.";
			cout << " Were you excited to make a change or are you relieved to be back at " << team_name << "? " << endl;
			cin.get();
			cout << "\n" << player_name << ": I am over the moon to be back at " << team_name << ".";
			cout << " I have built a strong bond with the fans and my team mates here, so i cant imagine playing for anyone else at this stage. ";
			cin.get();
			cout << "\n" << interview << ": You finished at position  " << user_id + 1 << " in the league last season. Surely you will need some new players to have a better finish for this season? ";
			cin.get();
			cout << "\n" << player_name << ": Yes, it would be great to get some new players in. There are still more rounds in the draft so hopefully the manager can get in the players he wants. ";
			cin.get();


		}
	}


	else if (round == 2) {
		if (old_team_id > user_id) {
			cout << interview << ": How are you feeling after your transfer to " <<  team_name <<  "?. They performed better than your old team did last season." << endl;
			cout << "Are you ready for this new challenge? ";
			cin.get();
			cout << "\n" << convertlower(player_name) << ": Yes i feel ready to make this move. I have been eager to make the step up, so i am grateful for the opportunity.";
			cin.get();
			cout << "\n" << interview << ": Your new team finished at position " << user_id + 1 << " in the league last season. Do you think you can better that this season? ";
			cin.get();
			cout << "\n" << convertlower(player_name) << ": I believe we can. We will just have to wait and see. " <<
				"But for now, im very grateful to be given this opportunity to show that im capable playing for a team higher up in this league.";
			cin.get();

		}


		else if (old_team_id < user_id) {

			cout << interview << ": You have joined a team who finished lower in the league than your old team did last season. Let us know your thoughts on this move" << endl;
			cin.get();
			cout << "\n" << player_name << ": I am ready for the challenge. I beleive i can help the team push forward this season. ";
			cin.get();
			cout << "\n" << interview << " Great. What about your new maanger then? " << endl;
			cout << interview << ": " << team_name << " finished at position " << user_id + 1 << " last season. Can he guide the team to new heights this season?";
			cin.get();
			cout << "\n" << player_name << ": I believe he can. We will just have to wait and see. " <<
				"He has shown faith in me, so i plan to do my best for him and the team.";
			cin.get();

		}

		else {
			cout << interview << ": So let us know your thoughts on rejoining your old team.";
			cout << " Were you excited to make a change or are you relieved to be back at " << team_name << "? " << endl;
			cin.get();
			cout << "\n" << player_name << ": Yes, I am very pleased to be back at " << team_name << ".";
			cout << " I feel very comfortable at this club and plan to stay here for many more years. ";
			cin.get();
			cout << "\n" << interview << ": That is what i expected. You finished at position " << user_id + 1 << " in the league last season. Is there a belief in the camp that you can push on this season? ";
			cin.get();
			cout << "\n" << player_name << ": Yes, for sure. We all had an honest conversation about targets and expectations for this season. So im happy i can be apart of it! ";
			cin.get();


		}
	}


}



void make_trade(string assistant, I_player* user_player, vector<I_player*> players) {


	std::cout << assistant << ": Boss, below is a reminder of all the player stats.";
	std::cin.get();
	print_players(players);
	std::string user_player_name = user_player->get_name();

	std::cout << "\n" << assistant << ": Do you want to try and trade " << convertlower(user_player_name) << " for another player? ";
	std::string trade;
	bool user_input = false;
	while (user_input == false) {
		std::cout << "yes/no" << std::endl;
		std::cin >> trade;
		convertupper(trade);
		if (trade == "YES" || trade == "NO")
			user_input = true;
		else
			std::cout << "Incorrect input" << std::endl;
	}

	std::cin.ignore();
	std::cout << "\n";
	int count{};

	while (trade == "YES") {
	
		std::cout << assistant << ": OK. let me know which player you want to trade in, so i can get the offer sent in an email to the premier league. " << endl;
		std::string trade_player_name;
		trade_player_name = check_input(players);
		

		while (trade_player_name == user_player->get_name()) {
		std::cout << "This player is already apart of your squad. Choose a different player." << endl;
		trade_player_name = check_input(players);
		
		}

		
	

		cout << "\n";
		//create object of player pointing to the selected player  address
		I_player* trade_player = new defender;
		trade_player = get_trade_player(players, trade_player_name);

		if (check_trade(user_player, trade_player) == true) {
			cout << assistant << ": Great news, our trade has been accepted and " << convertlower(trade_player_name) << " will be joining our club." << endl;
			break;
			//trade = "no";
		}

		else {
			cout << assistant << ": Unfortunately our trade was not accepted for " << convertlower(trade_player_name) << ". His club replied stating that " << trade_player_name << " is more valuable than " << convertlower(user_player_name) << endl;
			count++;
			if (count == 2)
				break;
			cout << "Do you wish to attempt another trade" << std::endl;
			bool user_input = false;
			while (user_input == false) {
				cout << "yes/no" << std::endl;
			    cin >> trade;
				convertupper(trade);
				if (trade == "YES" || trade == "NO")
					user_input = true;
				else
					cout << "Incorrect input" << endl;
			}
		
		}
		
	}

	if (trade == "NO") {
		cout << "\n";
		cout <<assistant << ": OK. i will let the premier league know that we are happy with " << convertlower(user_player_name) << ". ";
	}
}







bool check_trade(I_player *user_player, I_player *trade_player) {


	if (user_player->get_value() > trade_player->get_value()) {
		int temp = user_player->get_new_team_id();
		user_player->change_new_team_id(trade_player->get_new_team_id());
		trade_player->change_new_team_id(temp);
		
		return true;
	}

		

	else
		return false;

}



I_player* get_trade_player(vector<I_player*> players, string name) {


	for (int i{}; i < players.size(); i++) {
		if (players[i]->get_name() == name) {
			I_player* user_player = players[i];
			return user_player;
			break;
		}
	}

}




string check_input(std::vector<I_player*> players) {
	string trade_player_name;

	bool user_input = false;
	while (user_input == false) {
		std::cout << "Enter name of player: ";
		std::cin >> trade_player_name;
		convertupper(trade_player_name);
		for (int i = 0; i < players.size(); i++) {
			if (trade_player_name == players[i]->get_name()) {
				user_input = true;
				return trade_player_name;
				
			}
		}
		if (user_input == false) {
			cout << "Incorrect input. Please check spelling" << endl;
		}

	}
}