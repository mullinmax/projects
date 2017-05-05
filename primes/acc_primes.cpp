#include<iostream>
#include "openacc.h"
using namespace std;

unsigned long long find_nth_prime(unsigned long long tar);

bool is_prime(unsigned long long n);

unsigned long long num_primes_in(unsigned long long start, unsigned long long stop);

int main(){
	unsigned long long target = 0;
	cin >> target;
	cout << "The number of Prime numbrs between 0 and " << target << " is: " << num_primes_in(0, target) << endl;
	//cout << "the " << target << " prime numberis: " << find_nth_prime(target) << endl;
	return 0;
}

unsigned long long find_nth_prime(unsigned long long tar){
	unsigned long long num_found = 0;
	unsigned long long last_checked = 0;
	while(num_found < tar){
		if(is_prime(++last_checked)){
			num_found++;
		}
	}
	return last_checked;
}

bool is_prime(unsigned long long n){
	if(n == 2){
		return true;
	}
	if(n % 2 == 0 || n == 1){
		return false;
	}
	for(unsigned long long i = 3; i*i <= n; i += 2){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

unsigned long long num_primes_in(unsigned long long start, unsigned long long stop){
	unsigned long long out = 0;
	#pragma acc data copy(out, start, stop)
	{
		if(start % 2 == 0){
			if(start == 2){
				out++;
			}
			start++;
		}
		bool is_prime = true;
		#pragma acc parallel
		for(unsigned long long n = start; n <= stop; n += 2){
			for(unsigned long long i = 3; i*i <= n; i += 2){
				if(n % i == 0){
					is_prime = false;
					break;
				}
			}
			if(is_prime){
				out++;
			}else{
				is_prime = true;
			}
		}
	}
	return out;
}



