#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include "deck.cpp"
#include "player.cpp"
using namespace std;

int main(){
	player p1(30);

	cout << endl << "10 drop 2 deck:" << endl;
	deck numbers(10, 2);	
	numbers.print();

	cout << endl << "Sorted:" << endl;
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
	numbers.print();

	return 0;
}
