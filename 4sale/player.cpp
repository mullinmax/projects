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
		
		void draw_houses(int num, deck & source){
			houses.gain(source.draw(num));
		}
		void print(){
			cout << "coins:  " << coins << endl;
			cout << "houses: ";
			houses.print();
			cout << "cash:   ";
			cash.print();
		}
		unsigned int bid(deck table, deck houses_sold, int bids, int num_rounds, int round_num, int num_players, int player_num){	
			return 0;
		}
		void pay(int amount){
			coins -= amount;
		}
		bool good_for_it(int amount){
			return amount < coins;
		}
	private:
		int coins = 0;
		deck houses;
		deck cash;	
};
#endif
