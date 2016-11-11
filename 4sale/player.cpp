#ifndef PLAYER
#define PLAYER
#include "deck.cpp"

class player{
	public:
		player(){
			coins = 0;
		}
		player(int cash){
			coins = cash;
		}
		
		void print(){
			cout << "coins:  " << coins << endl;
			cout << "houses: ";
			houses.print();
			cout << "cash:   ";
			cash.print();
		}
		unsigned int bid(deck table, deck houses_sold, int bids[], int num_rounds, int round_num, int num_players, int player_num){	
			unsigned int bid;		
			cout << endl << "player number: " << player_num	<< endl;
			cout << "currently for sale: ";
			table.print();
			cout << "amount of money you have left: "	<< coins << endl;
			cout << "your current bid: " << bids[player_num] << endl;
			cout << "how much would you like to add to your bid?" << endl;
			cin >> bid;
			return bid;
		}
		void pay(int amount){
			coins -= amount;
		}
		bool good_for_it(int amount){
			return amount < coins;
		}
		void add_house(vector<int> house){
			houses.add_cards(house);
		}
	private:
		int coins = 0;
		deck houses;
		deck cash;	
};
#endif
