#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void save_file(string path, char * input, int length){
	ofstream fout;
	fout.open(path.c_str());
	for(int i = 0; i < length; i++){
		fout << input[i];
	}
}


char * load_file(string input, int & length){
	ifstream file (input.c_str(), ios::in|ios::binary|ios::ate);
	char * memblock;
	streampos size;  	
	if (file.is_open()){
		size = file.tellg();
		memblock = new char [size];
		file.seekg (0, ios::beg);
   		file.read (memblock, size);
		length = int(size);
   		file.close();
	}else{
		cout << "error opening file" << endl;
	}
	return memblock;
}
