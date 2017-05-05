#include<iostream>
#include "openacc.h"
using namespace std;

int main(){
	int out = 0;
	int n = 10000;
	//#pragma acc data copy( out )
	#pragma acc parallel reduction(+:out)
	for(int i = 0; i < n; i++){
		out += i;
		for(int j = 0; j < n; j++){
			out += j;	
		}	
	}
	cout << out;
	return 0;
}
