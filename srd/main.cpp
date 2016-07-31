#include<iostream>
#include<string>
#include"bit_reader.cpp"


using namespace std;

int main(){
	char * file = load_file("test.txt");
	cout << sizeof(file);
}
