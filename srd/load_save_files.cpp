#ifndef LOAD_SAVE_FILE
#define LOAD_SAVE_FILE
#include<iostream>
#include<fstream>
#include<string>

//CONVERT TO USING STL LINKED LIST
#include<list>


using namespace std;

void save_file(string path, char * input, int length){
	ofstream fout;
	fout.open(path.c_str());	//open a new stream
	for(int i = 0; i < length; i++){	//print each character in array 
		fout << input[i];
	}
	fout.close();
}


list<char> load_file(string input, int & length){
	ifstream fin (input.c_str(), ios::in|ios::binary|ios::ate);	//open file in binary mode and move to the end
	char * memblock;	
	streampos size;  	
	if (fin.is_open()){
		size = fin.tellg();	//find the size based on the location of the end of the file
		memblock = new char [size];	//make a new char array large enough for the file
		fin.seekg (0, ios::beg);	//move to the beggining of the file
   		fin.read (memblock, size);	//read in the file
		length = int(size);	//set length equal to the new size
   		fin.close();
	}else{
		cout << "error opening file" << endl;
	}
	list<char> file;
	for(int i = 0; i < length; i++){
		file.push_back(memblock[i]);
	}
	return file;
}
#endif
