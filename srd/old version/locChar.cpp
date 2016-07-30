#ifndef SRD_LOCCHAR
#define SRD_LOCCHAR
class locChar{
public:
	locChar(){
		loc = 0;
		data = 0;
	}
	locChar(int l, char d){
		loc = l;
		data = d;
	}
	
	int loc;
	char data;
};
#endif
