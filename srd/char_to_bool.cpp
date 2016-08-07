#ifndef CHAR_TO_BOOL
#define CHAR_TO_BOOL

//CONVERT TO USING STL LINKED LIST
#include<list>

using namespace std;

bool * char_to_bool(list<char> input, int & bin_length){
	bool * output;
	output = new bool [input.size() * 8];
	int i = 0;
	for (list<char>::iterator it = input.begin(); it != input.end(); ++it){
		output[i] = *it;
		i++;
	}
	return output;
}

char * bool_to_char(bool * input, int bin_length, int & char_length){
	char_length = bin_length / 8;	//sets new length
	char * output = new char [char_length];	//declares new array of correct size
	char temp;
	for(int i = 0; i < char_length; i++){
		temp = 0;
		for(int j = 0; j < 8; j++){	//shifts temp one to the left and if nessisarry adds one to the value
			temp = temp << 1;
			if(input[i * 8 + j] == true){
				temp += 1;	
			}			
		}
		output[i] = temp;	//stores the new temp in the char array
	}
	return output;
}

#endif
