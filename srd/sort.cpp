#ifndef SORT
#define SORT
#include "loc_char.cpp"
using namespace std;
void sort(list<loc_char> & input){
	loc_char prev;
	prev.loc = 0;
	prev.val = 0;
	list<loc_char>::iterator best = loc_chars.begin();
	for (list<loc_char>::iterator it = loc_chars.begin(); it != loc_chars.end(); ++it){
		
	}
	prev.loc = best.loc;
	prev.val = best.val;
	loc_chars.;
//convert to loc char
	//loop until len(min.loc)+len(min.val) < len(it.dist) && it.loc > min.loc && != end of file
		//shortest len(dist)+len(change)
		//swap with it+1

	return loc_chars;
}
void unsort(list<unsigned char> & input){

}

#endif
