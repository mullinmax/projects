#ifndef SRD_BIT_STREAM
#define SRD_BIT_STREAM
#include<fstream>
#include<vector>
using namespace std;
class bitStream{
public:
	bitStream(){
		nextEmptyOffset = 0;
	}

	void loadFile(string file){
		ifstream fin;
		fin.open(file.c_str());
		fin >> noskipws;
		char temp;
		data.clear();
		while(fin >> temp){
			data.push_back(temp);
		}	 
		fin.close();
	}

	void saveFile(string file){
		ofstream fout;
		fout.open(file.c_str());
		for(unsigned int i = 0; i < data.size(); i++){
			fout << data.at(i);
		}
	}

	bool at(int where){
		int offset = where % 8;
		int index = where / 8;
		return data.at(index) >> offset & 1;
	}

	void at(int where, bool in){
		if(where > int(8*data.size())){
			return;
		}else{
			int offset = where % 8;
			int index = where / 8;
			char temp = 1;
			temp = temp << offset;
			if(in){
				data.at(index) = data.at(index) | temp;		
			}else{
				temp = ~temp;
				data.at(index) = data.at(index) & temp;
			}

		}
	}

	char outputChar(int where){
		return data.at(where);
	}


	void append(bool in){
		if(nextEmptyOffset == 0){
			char temp = 0;			
			data.push_back(temp);
		}
		at(8 * (data.size() - 1) + nextEmptyOffset, in);
		nextEmptyOffset ++;
		nextEmptyOffset = nextEmptyOffset % 8;	
	}
	void append(char in){
		for(unsigned int i = 0; i < 8; i++){
			append((in >> i) % 2 == 1);
		}
	}

	void append(int in){
		for(unsigned int i = 0; i < 32; i++){
			append((in >> i) % 2 == 1);
		}
	}

	int length(){
		return 8*data.size();
	}

	int lengthAsChar(){
		return data.size();
	}


	vector<char> data;
	int nextEmptyOffset;
};

#endif
