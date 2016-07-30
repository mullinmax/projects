#ifndef SRD_COMPRESSOR
#define SRD_COMPRESSOR
#include "bitStream.cpp"
#include "locChar.cpp"
using namespace std;
//
// PROTOTYPES
//
void addHeader(bitStream compressed, bitStream original);
int removeHeader(bitStream &in);

vector<locChar> sort(bitStream &inBits, int dataChunkSize, int locationChunkSize);
void unsort(bitStream &in, int lengthInBytes);

void deflate(vector<locChar> &locChars);
void enflate(bitStream &in, int langthInBytes);

bitStream squeeze(vector<locChar> &locChars);
void stretch(bitStream &in, int lengthInBytes);

void compress(string inFile, string outFile);
void decompress(string inFile, string outFile);
	

//
// DEFINITIONS
//

void compress(string inFile, string outFile){
	bitStream inBits;
	bitStream outBits;
	vector<locChar> locChars;
	
	inBits.loadFile(inFile);
	
	int dataChunkSize = 8;
	int locationChunkSize = 32;
	
	locChars = sort(inBits, dataChunkSize, locationChunkSize);		// sort for compression
	deflate(locChars);	// remove consecutive duplicates 
	outBits = squeeze(locChars);	// final step of compression
	addHeader(inBits, outBits);	// add header to the output


	outBits.saveFile(outFile);		// saves compressed file	

			
}	

void decompress(string inFile, string outFile){
	bitStream inBits;
	inBits.loadFile(inFile);
	
	int lengthInBytes;	

	lengthInBytes = removeHeader(inBits);
	unsort(inBits, lengthInBytes);	
	stretch(inBits, lengthInBytes);
	enflate(inBits, lengthInBytes);

	inBits.saveFile(outFile);
}


void addHeader(bitStream compressed, bitStream original){
	//layered compression
	//total size of file
}

int removeHeader(bitStream &in){
	//layered output
	//total size of file
	return 0;
}

void enflate(bitStream &in, int lengthInBytes){		// inserts consecutive duplicates where nessisary

}

void deflate(vector<locChar> &locChars){		// removes consecutive duplicates 

}

vector<locChar> sort(bitStream &inBits, int dataChunkSize, int locationChunkSize){
	vector<locChar> locChars;	
	bitStream outBits;
	for(int i = 0; i < inBits.lengthAsChar(); i++){	
		locChars.push_back(locChar(i,inBits.outputChar(i)));
	}
	return locChars;
}

void unsort(bitStream &in, int lengthInBytes){
	vector<locChar> locChars;
	for(int i = 0; i < inBits.length(); i++){
		//!!!!!
	}	
}
		
bitStream squeeze(vector<locChar> &locChars){		// makes small numbers smaller via Maxwell encoding
	bitStream out;
	for(unsigned int i = 0; i < locChars.size(); i++){
		out.append(locChars.at(i).data);
		out.append(locChars.at(i).loc);
	}
	return out;
}

void stretch(bitStream &in, int lengthInBytes){		//oposite of squeeze

}

int numDigits(int num){		//unfinished????
	int i = 0;
	while(num != 0){
		num = num >> 1;
	}
	return i;
}

#endif
