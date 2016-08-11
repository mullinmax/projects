#ifndef CHAR_TO_BOOL
#define CHAR_TO_BOOL
#include<list>

using namespace std;

list<bool> char_to_bool(list<char> input, int & bin_length){
	list<bool> output;
	bin_length = input.size() * 8;
	int offset;
	for (list<char>::iterator it = input.begin(); it != input.end(); ++it){		
		for(offset = 0; offset < 8; offset++){		
			output.push_back((*it >> (7-offset)) & 1);
		}
	}
	return output;
}

list<char> bool_to_char(list<bool> input, int bin_length, int & char_length){
	list<char> output;	
	char temp;
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
