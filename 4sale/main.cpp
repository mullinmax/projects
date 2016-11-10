#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include "deck.cpp"
#include "player.cpp"
using namespace std;

int main(){
	int num_rounds = 15;
	int starting_coins = 30;
	int num_drop = 4;	
	int num_players = 2;
	player players[num_players];
	for(int i = 0 ; i < num_players; i++){
		players[i] = player(starting_coins);
	}
	deck houses(num_rounds * num_players + num_drop, num_drop);	
	deck cash(num_rounds * num_players + num_drop, num_drop);	
	deck table;
	for(int i = 0; i < num_rounds; i++){
		int bids[num_players] = {0};
		d
		
	}





	/*cout << endl << "Sorted:" << endl;
	numbers.sort();
	numbers.print();
	
	cout << endl << "Trash 2:" << endl;
	numbers.trash(2);
	numbers.print();
	
	cout << endl << "Player:" << endl;
	p1.print();

	cout << endl << "Player draws two cards:" << endl;
	p1.draw_houses(2, numbers);
	p1.print();
	cout << "Deck:";
	numbers.print();*/

	return 0;
}
