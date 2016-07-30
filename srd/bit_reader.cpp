#include<iostream>


bool read(string in_file){

	istream fin;
	fin.open(in_file);
	
	string temp;
	while(fin >> temp){
		cout << temp;
	}
	return true
}
