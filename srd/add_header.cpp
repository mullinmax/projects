#ifndef ADD_HEADER
#define ADD_HEADER
#include<iostream>
#include<string>
#include<list>
using namespace std;
void add_header(list<bool> &input, int char_length){
	
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

void remove_header(list<bool> &input, int & char_length, int & bin_length){
	int bin_len_len = 0;
	char_length = 0;
	bin_length = 0;
	bool stop = false;
	list<bool>::iterator it = input.begin();
	while(stop == false){
		if(*it){
			bin_len_len++;
		}else{
			stop = true;
		}
		it++;
		input.pop_front();
	}
	bin_length = 0;
	for(int i = 0; i < bin_len_len; i++){
		bin_length = bin_length << 1;		
		if(*it){
			bin_length++;
		}
		it++;
		input.pop_front();
	}
	for(int i = 0; i < bin_len_len; i++){
		char_length = char_length << 1;
		if(*it){
			char_length++;
		}
		it++;
		input.pop_front();
	}
	cout << endl << "char_length is == to:" << char_length << endl;
	cout << endl << "bin length is == to:" << bin_length << endl;
	cout << endl << "bin_len_len is == to:" << bin_len_len << endl;
}

#endif
