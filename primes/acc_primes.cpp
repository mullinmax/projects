#include<iostream>

using namespace std;

unsigned long long find_nth_prime(unsigned long long tar);

bool is_prime(unsigned long long n);

int main(){
	unsigned long long target = 0;
	cin >> target;
	cout << "the " << target << " prime numberis: " << find_nth_prime(target) << endl;
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
