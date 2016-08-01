#include<iostream>
#include<fstream>
#include<string>
using namespace std;


char * load_file(string input, int & length){
	ifstream file (input.c_str(), ios::in|ios::binary|ios::ate);
	char * memblock;
	streampos size;  	
	if (file.is_open()){
		size = file.tellg();
		memblock = new char [size];
		file.seekg (0, ios::beg);
   		file.read (memblock, size);
		length = int(size);
   		file.close();
	}else{
		cout << "error opening file" << endl;
	}
	return memblock;
}

bool * char_to_bool(char * input, int char_length, int & bin_length){
	bool * output;
	int char_size = 8;
	output = new bool [char_length * char_size];
	for(int i = 0; i < char_length; i++){
		for(int j = 0; j < char_size; j++){
			output[i*char_size+j] = (input[i] >> j) & 1;
		}
	}
	bin_length = char_length * char_size;
	return output;
}

char * bool_to_char(bool * input, int bin_length, int & char_length){
	char_length = bin_length / 8;	
	char * output = new char [char_length];
	char temp;
	for(int i = 0; i < bin_length; i+=8){
		temp = 0;
		for(int j = 0; j < 8; j++){
			temp << 1;
			if(input[i * 8 + j] == true){
				temp += 1;	
			}			
		}
		output[i] = temp;
	}
	return output;
}
