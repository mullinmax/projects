#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void load_tests(string file, vector<string> &tests, vector<string> &expected);
void run_tests(vector<string> &tests, vector<string> &expected);

int main(int argc, char *argv[]){
	string file;	
	if(argc == 1){
		cin >> file;
	} else if (argc == 2){
		file = argv[1];
	} else {
		cout << " Too many arguments " << endl;
		return 0;
	}
	vector<string> tests;
	vector<string> expected;
	load_tests(file, tests, expected);
	run_tests(tests, expected);	
}

void load_tests(string file, vector<string> &tests, vector<string> &expected){
	ifstream fin;
	fin.open(file);
	vector<string> lines;
	string temp;
	while(!fin.eof()){
		getline(fin, temp);
		lines.push_back(temp);
	}
}

void run_tests(vector<string> &tests, vector<string> &expected){

}
