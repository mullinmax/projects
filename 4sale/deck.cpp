#ifndef DECK
#define DECK
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class deck{
	public:
		deck(){}
		deck(int n){
			for(int i = 0; i < n; ++i){
				cards.push_back(i);
			}
		}
	
		deck(int n, int drop){
			for(int i = 0; i < n; ++i){
				cards.push_back(i);
			}
			shuff();
			trash(drop);
		}
		
		void shuff(){
		    random_device rd;
		    mt19937 g(rd());
		    shuffle(cards.begin(), cards.end(), g);
		}

		void print(){
			for(unsigned int i = 0 ; i < cards.size(); ++i){
				cout << cards[i] << " ";
			}
			cout << endl;
		}
		
		void trash(int num){
			for(int i = 0; i < num; ++i){
				cards.pop_back();
			}
		}

		void add_cards(vector<int> input){
			cards.insert(cards.end(), input.begin(), input.end());
		}

		vector<int> draw(int num){
			vector<int> output;
			for(int i = 0; i < num && cards.size() > 0; ++i){
				output.push_back(cards.back());
				cards.pop_back();
			}
			return output;
		}

		vector<int> reveal(int num){
			vector<int> output;
			for(int i = 0; i < num && cards.size() > 0; ++i){
				output.push_back(cards.size() - i);
			}
			return output;
		}

		void sort(){
			for(unsigned int i = 0; i < cards.size(); ++i){
				int smallest = i;
				for(unsigned int j = i; j < cards.size(); ++j){
					if(cards[smallest] > cards[j]){
						smallest = j;
					}
				}
				int temp = cards[smallest];
				cards[smallest] = cards[i];
				cards[i] = temp;
			}
		}


		bool empty(){
			return cards.size() == 0;
		}
	private:
		vector<int> cards;	
};

#endif
