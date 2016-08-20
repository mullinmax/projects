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


	cout << endl << "----READING FILE----" << endl;
	list<loc_char> char_file = load_file(arg[1]);	
	cout << endl << "----CONVERTING TO BINARY----" << endl;
	list<bool> bin_file = loc_char_to_bool(char_file);
	cout << "----ADDING HEADER----" << endl;
	add_header(bin_file, char_file.size());
	cout << endl << "----REMOVING HEADER----" << endl;
	unsigned long loc_bits;
	unsigned char val_bits;
	remove_header(bin_file, loc_bits, val_bits);
	cout << endl << "----CONVERTING CHAR FILE----" << endl;
	list<unsigned char> converted_char_file = bool_to_char(bin_file);
	cout << "----SAVING CHAR FILE----" << endl;
	save_file(arg[2], converted_char_file, char_length);

}
