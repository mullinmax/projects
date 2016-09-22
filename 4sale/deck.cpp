#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class deck{
	public:	
		deck(int n, int drop){
			cards.clear();
			for(int i = 0; i < n; ++i){
				cards.push_back(i);
			}
			shuff();
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
			
		}
		void add_cards(vector<int> input){
			while(input.size() > 0){
				cards.push_back(input.back());
				input.pop_back();
			}
		}
	private:
		vector<int> cards;	
};
