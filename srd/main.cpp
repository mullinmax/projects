#include<iostream>
#include<string>
#include"char_to_bool.cpp"
#include"load_save_files.cpp"


using namespace std;

int main(int argc,char *arg[]){
	if(argc != 3){
		cout << "Please try again with the correct number of arguments\n";
		return 0;
	}


	cout << endl << "----BEGIN RAW FILE----" << endl;
	int char_length = 0;
	list<char> char_file = load_file(arg[1], char_length);
	for (list<char>::iterator it = char_file.begin(); it != char_file.end(); ++it){
    	cout << *it;
	}
	cout << "----END RAW FILE----" << endl;




	cout << endl << "----BEGIN BINARY FILE----" << endl;
	int bin_length;
	bool * bin_file = char_to_bool(char_file, bin_length);
	for(int i = 0; i < bin_length; i++){
		cout << bin_file[i];
		if(i % 8 == 7){
			cout << " ";
		}
		if(i % 64 == 63){
			cout << endl;
		}
	}
	cout << "----END BINARY FILE----" << endl;




	cout << endl << "----BEGIN CONVERTED CHAR FILE----" << endl;
	char * converted_char_file = bool_to_char(bin_file, bin_length, char_length);
	for(int i = 0; i < char_length; i++){
		cout << converted_char_file[i];
	}
	cout << "----END CONVERTED CHAR FILE----" << endl;
	save_file(arg[2], converted_char_file, char_length);
}
