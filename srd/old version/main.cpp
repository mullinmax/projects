#include<iostream>
#include<string>
#include"bitStream.cpp"
#include"compressor.cpp"
using namespace std;
int main(int argc,char *arg[]){
	if(argc != 4){
		cout << "Please try again with the correct number of arguments\n";
		return 0;
	}
	compress(arg[1], arg[2]);
	decompress(arg[2], arg[3]);
}
