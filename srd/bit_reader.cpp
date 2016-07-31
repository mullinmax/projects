#include<iostream>
#include<fstream>
#include<string>
using namespace std;


char * load_file(string input){
	ifstream file ("example.bin", ios::in|ios::binary|ios::ate);
	char * memblock;  	
	if (file.is_open()){
		int size = file.tellg();
		memblock = new char [size];
		file.seekg (0, ios::beg);
   		file.read (memblock, size);
   		file.close();
	}
	return memblock;
}
