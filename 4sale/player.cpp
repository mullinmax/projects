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
		int bid(){
			return 0;
		}
		void pay(){
			return;
		}
	private:
		int coins = 0;
		deck houses;
		deck cash;	
};
#endif
