#ifndef LOAD_SAVE_FILE
#define LOAD_SAVE_FILE
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include "loc_char.cpp"


using namespace std;

void save_file(string path, list<unsigned char> input, long length){
	ofstream fout;
	fout.open(path.c_str());	//open a new stream
	for (list<unsigned char>::iterator it = input.begin(); it != input.end(); ++it){
    	fout << *it;
	}
	fout.close();
}


list<loc_char> load_file(string input){
	ifstream fin (input.c_str(), ios::in|ios::binary|ios::ate);	//open file in binary mode and move to the end
	char * memblock;	
	streampos size;  	
	if (fin.is_open()){
		size = fin.tellg();	//find the size based on the location of the end of the file
		memblock = new char [size];	//make a new char array large enough for the file
		fin.seekg (0, ios::beg);	//move to the beggining of the file
   		fin.read (memblock, size);	//read in the file
   		fin.close();
	}else{
		cout << "error opening file" << endl;
	}
	list<loc_char> file;
	loc_char temp;
	for(int i = 0; i < size; i++){
		temp.loc = i;
		temp.val = memblock[i];
		file.push_back(temp);
	}
	return file;
}
#endif
