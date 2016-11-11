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
	deck houses_sold;


	for(int i = 0; i < num_rounds; i++){
		table.add_cards(houses.draw(num_players));//deal cards to table
		table.sort();
		int bids[num_players] = {0};
		bool new_bid = false;
		unsigned int num_bidders = num_players;
		do{
			new_bid = false;
			for(int p = 0; p < num_players; p++){
				if(bids[p] != -1){	
					if(num_bidders == 1){
						players[p].pay(bids[p]);//pay full price	
					}
					unsigned int current_bid = players[p].bid(table, houses_sold, bids, num_rounds, i, num_players, p);
					//check that the bid is actually larger than the last one
					while(!players[p].good_for_it(bids[p] + current_bid || (current_bid != 0 && current_bid + bids[p] <= max_element(bids, bids + num_players)))){
						cout << "----try again-----" << endl;
						current_bid = players[p].bid(table, houses_sold, bids, num_rounds, i, num_players, p);
					}
					bids[p] += current_bid;
					if(current_bid == 0){
						num_bidders--;
						players[p].pay((bids[p]+1)/2);//takes card and pays half rouded up	
						players[p].add_house(table.reveal(1));
						houses_sold.add_cards(table.draw(1));
						bids[p] = -1;
					}else{
						new_bid = true;
					}
				}
			}
		}while(new_bid);
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
