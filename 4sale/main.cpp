#include <iostream>
//include <random>
#include <algorithm>
//include <iterator>
#include "deck.cpp"
#include "player.cpp"
using namespace std;

int main(){
	int num_rounds = 3;
	int starting_coins = 10;
	int num_drop = 4;	
	int num_players = 3;
	player players[num_players];
	for(int i = 0 ; i < num_players; i++){
		players[i] = player(starting_coins);
	}
	deck houses(num_rounds * num_players + num_drop, num_drop);	
	deck cash(num_rounds * num_players + num_drop, num_drop);	
	deck table;
	deck houses_bought;

//BUYING HOUSES

	srand (time(NULL));
	int leader = rand()%num_players;
	for(int r = 0; r < num_rounds; r++){
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
					houses_bought.add_cards(table.draw(1));
					bids[p] = -1;
					leader = p; //becomes new leader	
				}else{
					unsigned int current_bid = players[p].bid(table, houses_bought, bids, num_rounds, r, num_players, p);
					//check that the bid is legit
					while(current_bid != 0 && (!players[p].good_for_it(bids[p] + current_bid) || current_bid + bids[p] < highest_bid)){
						cout << endl << "----try again-----" << endl << endl;
						current_bid = players[p].bid(table, houses_bought, bids, num_rounds, r, num_players, p);
					}
					bids[p] += current_bid;
					if(current_bid == 0){
						num_bidders--;
						players[p].pay((bids[p]+1)/2);//takes card and pays half rouded up	
						players[p].add_house(table.reveal(1));
						houses_bought.add_cards(table.draw(1));
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

	
//SELLING HOUSES	
	for(int r = 0; r < num_rounds; r++){	
		unsigned int bids[num_players] = {0};
		table.add_cards(cash.draw(num_players));
		table.sort();
		for(int p = 0; p < num_players; p++){
			bids[p] = players[p].sell_house(table);
		}
		for(int i = 0; i < num_players; i++){
			int index_max = 0;
			for(int p = 0; p < num_players;	p++){
				if(bids[p] > bids[index_max]){
					index_max = p;
				}
				players[p].add_cash(table.draw(1));
				players[p].remove_house(bids[p]);
				bids[p] = -1;
			}
		}
	}
}














