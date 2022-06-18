#include "game.h"
#include <iostream>

Game::Game()
{

}

Game::Game(int cash)
{
	player_cash = cash;
}

void Game::make_cards()
{
	char cards[13] = { '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A' };
	string masti[4] = { "Boobi", "Chervi", "Kresti", "Piki" };
	for (int i = 0; i < 52; i++) {
		card tmp;
		tmp.mast = masti[i % 4];
		tmp.name = cards[i / 4];
		koloda.push_back(tmp);
	}
}

void Game::give_card(int& sum, bool to_player)
{
	if (to_player) {
		player.push_back(koloda.back());
	}
	else {
		dealer.push_back(koloda.back());
	}
	if ((koloda.back().name >= '2') && koloda.back().name <= '9') sum += koloda.back().name - '0';
	else if (koloda.back().name == 'A') {
		if (sum < 11) sum += 11;
		else sum += 1;
	}
	else sum += 10;
	if (koloda.back().name == '0') cout << "10 " << koloda.back().mast << endl;
	else cout << koloda.back().name << " " << koloda.back().mast << endl;
	koloda.pop_back();
}


void Game::Play()
{
	make_cards();
	int input, bet, sum, sum_dealer;
	while (1 == 1) {
		cout << "Enter 1 to start, 2 to see your cash, 3 to exit" << endl;
		cin >> input;
		if (input == 1) {
			sum = 0;
			sum_dealer = 0;
			cout << "Make tour bet: ";
			cin >> bet;
			if ( (bet > player_cash) || (bet < 0) )
			{
				cout << "Error" << endl;
				continue;
			}
			player_cash -= bet;
			shuffle();
			cout << "Your 2 cards: " << endl;
			give_card(sum, 1);
			give_card(sum, 1);
			cout << "Sum is: " <<sum<< endl;
			for (int j = 0; j < 20; j++)
			{
				cout << "Enter 1 to take another one, enter 2 to stop" << endl;
				cin >> input;
				if (input == 1)
				{
					give_card(sum, 1);
					cout << "Sum is: " << sum << endl;
					if (sum > 21)
					{
						cout << "This is too much" << endl;
						break;
					}
				}
				else break;
			}
			if (sum <= 21)
			{
				cout << "Dealer's 2 cards: " << endl;
				give_card(sum_dealer, 0);
				give_card(sum_dealer, 0);
				cout << "Dealer's Sum is: " << sum_dealer << endl;
				while (sum_dealer < 17)
				{
					give_card(sum_dealer, 0);
					cout << "Dealer's Sum is: " << sum_dealer << endl;
					if (sum_dealer > 21) break;
				}
				if ((sum > sum_dealer) || (sum_dealer > 21))
				{
					cout << "You win!!!" << endl;
					player_cash += bet * 2;
				}
				else if (sum == sum_dealer)
				{
					cout << "Draw" << endl;
					player_cash += bet;
				}
				else cout << "You lose.." << endl;
			}
			else cout << "You lose.." << endl;
			while (player.size() != 0) {
				koloda.push_back(player.back());
				player.pop_back();
			}
			while (dealer.size() != 0) {
				koloda.push_back(dealer.back());
				dealer.pop_back();
			}
		}
		else if (input == 2) cout << "Cash: " << player_cash << endl;
		else if (input == 3) break;
		else cout << "Error" << endl;
	}
}

void Game::shuffle()
{
	for (int i = 0; i < koloda.size(); i++) {
		int j = rand() % 52;
		card tmp = koloda[j];
		koloda[j] = koloda[i];
		koloda[i] = tmp;
	}
}

Game::~Game()
{
}
