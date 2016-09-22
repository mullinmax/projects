#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include "deck.cpp"
using namespace std;

void test();

int main(){
	deck numbers(10, 2);
	numbers.print();
	numbers.shuff();
	numbers.print();
	numbers.trash(3);
	numbers.print();
	
	return 0;
}
