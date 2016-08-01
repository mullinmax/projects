#include<iostream>
#include<string>
#include"bit_reader.cpp"


using namespace std;

int main(){
	int char_length = 0;
	char * char_file = load_file("test.txt", char_length);
	cout << "----BEGIN RAW FILE----" << endl;
	for(int i = 0; i < char_length; i++){
		cout << char_file[i];
	}
	cout << "----END RAW FILE----" << endl;

	int bin_length;
	bool * bin_file = char_to_bool(char_file, char_length, bin_length);
	cout << "----BEGIN BINARY FILE----" << endl;
	for(int i = 0; i < bin_length; i++){
		cout << bin_file[i];
		if(i % 8 == 7){
			cout << " ";
		}
	}
	cout << endl <<"----END BINARY FILE----" << endl;
}
