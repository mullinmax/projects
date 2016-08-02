using namespace std;

bool * char_to_bool(char * input, int char_length, int & bin_length){
	bool * output;
	int char_size = 8;
	output = new bool [char_length * char_size];
	for(int i = 0; i < char_length; i++){
		for(int j = 0; j < char_size; j++){
			output[i*char_size+j] = (input[i] >> (7-j)) & 1;
		}
	}
	bin_length = char_length * char_size;
	return output;
}

char * bool_to_char(bool * input, int bin_length, int & char_length){
	char_length = bin_length / 8;	
	char * output = new char [char_length];
	char temp;
	for(int i = 0; i < char_length; i++){
		temp = 0;
		for(int j = 0; j < 8; j++){
			temp = temp << 1;
			if(input[i * 8 + j] == true){
				temp += 1;	
			}			
		}
		output[i] = temp;
	}
	return output;
}
