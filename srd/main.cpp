#include<iostream>
#include<string>
#include"bit_reader.cpp"
#include"load_save_files.cpp"


using namespace std;

int main(){
	int char_length = 0;
	cout << endl << "----LOADING FILE----" << endl;
	char * char_file = load_file("test.txt", char_length);
	cout << endl << "----BEGIN RAW FILE----" << endl;
	for(int i = 0; i < char_length; i++){
		cout << char_file[i];
	}
	cout << endl << "----END RAW FILE----" << endl;


	cout << endl << "----BEGIN BINARY FILE----" << endl;
	int bin_length;
	bool * bin_file = char_to_bool(char_file, char_length, bin_length);
	for(int i = 0; i < bin_length; i++){
		cout << bin_file[i];
		if(i % 8 == 7){
			cout << " ";
		}
	}
	cout << endl << "----END BINARY FILE----" << endl;


	cout << endl << "----BEGIN CONVERTED CHAR FILE----" << endl;
	char * converted_char_file = bool_to_char(bin_file, bin_length, char_length);
	for(int i = 0; i < char_length; i++){
		cout << converted_char_file[i];
	}
	cout << endl << "----END CONVERTED CHAR FILE----" << endl;
	cout << endl << "----SAVING FILE----" << endl;
	save_file("output.txt", converted_char_file, char_length);
}
