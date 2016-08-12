#ifndef SORT
#define SORT

struct loc_char{
	int val;
	long loc;
	}

list<loc_char> sort(list<char> & input){
	long location = 0;
	list<loc_char> loc_chars;
	loc_char temp;
	for (list<char>::iterator it = input.begin(); it != input.end(); ++it){
		temp.val = *it;
		temp.loc = location;
		loc_chars.push_back(temp);
		location++;
	}
//convert to loc char
	//loop until len(min.loc)+len(min.val) < len(it.dist) && it.loc > min.loc
		//shortest len(dist)+len(change)
		//swap with it+1


}
void unsort(list<char> & input){

}
#endif
