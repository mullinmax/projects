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
	int num_players = 6;
	player players[num_players];
	for(int i = 0 ; i < num_players; i++){
		players[i] = player(starting_coins);
	}
	deck houses(num_rounds * num_players + num_drop, num_drop);	
	deck cash(num_rounds * num_players + num_drop, num_drop);	
	deck table;
	deck houses_sold;

	srand (time(NULL));
	int leader = rand()%num_players;
	for(int i = 0; i < num_rounds; i++){
		table.add_cards(houses.draw(num_players));//deal cards to table
		table.sort();
		int bids[num_players] = {0};
		unsigned int num_bidders = num_players;
		unsigned int highest_bid = 0;
		int p = leader;
		do{
			if(bids[p] != -1){	
				if(num_bidders == 1){
					num_bidders--;
					players[p].pay(bids[p]);//takes card and pays full amount	
					players[p].add_house(table.reveal(1));
					houses_sold.add_cards(table.draw(1));
					bids[p] = -1;
					leader = p; //becomes new leader	
				}else{
					unsigned int current_bid = players[p].bid(table, houses_sold, bids, num_rounds, i, num_players, p);
					//check that the bid is legit
					while(current_bid != 0 && (!players[p].good_for_it(bids[p] + current_bid) || current_bid + bids[p] < highest_bid)){
						cout << endl << "----try again-----" << endl << endl;
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
						highest_bid = bids[p];
					}
				}
			}
			p++;
			p = p % num_players;
		}while(num_bidders > 0);
	}
	return 0;
}
