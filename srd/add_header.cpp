#ifndef ADD_HEADER
#define ADD_HEADER
#include<iostream>
#include<string>
#include<list>
using namespace std;
void add_header(list<bool> &input, unsigned long loc_bits, unsigned long val_bits){//need to pass decompressed length
	
	int bin_length = input.size();	
	int bin_len_len = 0;
	for(;bin_length >> bin_len_len > 0; bin_len_len++){}
	//char_len
	cout << endl << "char len is == to " << char_length << endl;
	for(int i = 0; i < bin_len_len; i++){
		input.push_front((char_length >> i) & 1);	
	}
	
	//bin_len	
	cout << endl << "bin len is == to " << bin_length << endl;
	for(int i = 0; i < bin_len_len; i++){
		input.push_front((bin_length >> i) & 1);	
	}

	//bin_len_len divider
	input.push_front(false);
	
	//bin_len_len
	cout << endl << "bin len len is == to " << bin_len_len << endl;
	for(int i = 0; i < bin_len_len; i++){
		input.push_front(true);
	}
}

void remove_header(list<bool> &input, unsigned long & loc_bits, unsigned char & val_bits){
	int num_bits = 0;
	bool stop = false;
	list<bool>::iterator it = input.begin();
	while(stop == false){
		if(*it){
			num_bits++;
		}else{
			stop = true;
		}
		it++;
		input.pop_front();
	}
	loc_bits = 0;
	for(int i = 0; i < num_bits; i++){
		loc_bits = loc_bits << 1;		
		if(*it){
			loc_bits++;
		}
		it++;
		input.pop_front();
	}
	val_bits = 0;
	for(int i = 0; i < num_bits; i++){
		val_bits = val_bits << 1;
		if(*it){
			val_bits++;
		}
		it++;
		input.pop_front();
	}
}

#endif
