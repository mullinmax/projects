#ifndef CHAR_TO_BOOL
#define CHAR_TO_BOOL
#include<list>
#include"loc_char.cpp"
using namespace std;
list<bool> loc_char_to_bool(list<loc_char> input, long & bin_length){
	list<bool> output;
	long max_loc_dif;
	unsigned char max_val_dif;
	list<loc_char>::iterator next = input.begin();
	next++;
	for(list<loc_char>::iterator cur = input.begin(); cur != input.end() && next != input.end(); cur++){
		/*if(*next.loc - *cur.loc > max_loc_dif){
			max_loc_dif = *next.loc - *cur.loc;
		}
		if(*next.val - *cur.val > max_val_dif){
			max_val_dif = *next.val - *cur.val;
		}
		next++:*/
	}
	long num_loc_head;
	unsigned char num_val_head;
	for (list<loc_char>::iterator it = input.begin(); it != input.end(); ++it){
		
	}
}
list<bool> char_to_bool(list<unsigned char> input, long & bin_length){
	list<bool> output;
	bin_length = input.size() * 8;
	int offset;
	for (list<unsigned char>::iterator it = input.begin(); it != input.end(); ++it){		
		for(offset = 0; offset < 8; offset++){		
			output.push_back((*it >> (7-offset)) & 1);
		}
	}
	return output;
}

list<unsigned char> bool_to_char(list<bool> input, long bin_length, long & char_length){
	list<unsigned char> output;	
	unsigned char temp;
	int count = 0;
	for (list<bool>::iterator it = input.begin(); it != input.end(); ++it){
		temp = temp << 1;		
		if(*it == true){
			temp += 1;
		}		
		if(count % 8 == 7){
			output.push_back(temp);
			temp = 0;
		}
		count++;
	}
	return output;
}

#endif
