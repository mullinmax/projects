#include<iostream>
#include<string>
#include<list>
#include"char_to_bool.cpp"
#include"load_save_files.cpp"
#include"add_header.cpp"
#include"loc_char.cpp"

using namespace std;

int main(int argc,char *arg[]){
	if(argc != 3){
		cout << "Please try again with the correct number of arguments\n";
		return 0;
	}


	cout << endl << "----BEGIN RAW FILE----" << endl;
	long char_length = 0;
	list<unsigned char> char_file = load_file(arg[1], char_length);	
	for (list<unsigned char>::iterator it = char_file.begin(); it != char_file.end(); ++it){
    	cout << *it;
	}




	cout << endl << "----BEGIN BINARY FILE----" << endl;
	long bin_length;
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

	cout << "----HEADER ADDED----" << endl;
	add_header(bin_file, char_length);
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
	cout << endl << "----HEADER REMOVED----" << endl;
	int new_bin_length = 0;
	int new_char_length = 0;
	remove_header(bin_file, new_char_length, new_bin_length);
	i = 0;
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



	cout << endl << "----CONVERTED CHAR FILE----" << endl;
	list<unsigned char> converted_char_file = bool_to_char(bin_file, bin_length, char_length);
	/*
	for (list<char>::iterator it = converted_char_file.begin(); it != converted_char_file.end(); ++it){
    	cout << *it;
	}
	*/

	cout << "----SAVING CHAR FILE----" << endl;
	save_file(arg[2], converted_char_file, char_length);

}
