#ifndef LOC_CHAR
#define LOC_CHAR
using namespace std;

struct loc_char{
	long get_loc(){
		return loc;
	}
	unsigned char val;
	unsigned long loc;
};

long len(long next, long prev){
	if(next < prev){
		return len(prev, 0b11111111) + len(0b00000000, next);
	}
	int i = 0;
	while(1 << i < next-prev){
		i++;
	}
	return i-1;
}

#endif
