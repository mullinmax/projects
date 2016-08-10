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
	list<bool> bin_file = char_to_bool(char_file, bin_length);
	int i = 0;
	for (list<bool>::iterator it = bin_file.begin(); it != bin_file.end(); ++it){
    	cout << *it;
		if(i % 8 == 7){
			cout << " ";
		}
		if(i % 64 == 63){
			cout << endl;
		}
		i++;
	}
	cout << "----END BINARY FILE----" << endl;




	cout << endl << "----BEGIN CONVERTED CHAR FILE----" << endl;
	list<char> converted_char_file = bool_to_char(bin_file, bin_length, char_length);
	for (list<char>::iterator it = converted_char_file.begin(); it != converted_char_file.end(); ++it){
    	cout << *it;
	}
	cout << "----END CONVERTED CHAR FILE----" << endl;
	save_file(arg[2], converted_char_file, char_length);
}
