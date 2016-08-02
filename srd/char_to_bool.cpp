//CONVERT TO USING STL LINKED LIST
#include<STL>

using namespace std;

bool * char_to_bool(char * input, int char_length, int & bin_length){
	bool * output;
	int char_size = 8;
	output = new bool [char_length * char_size];
	for(int i = 0; i < char_length; i++){	//loops over each char
		for(int j = 0; j < char_size; j++){	//within each char this reads each binary digit
			output[i*char_size+j] = (input[i] >> (7-j)) & 1;	
		}
	}
	bin_length = char_length * char_size;	//sets new size
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
