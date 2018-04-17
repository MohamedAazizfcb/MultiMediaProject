#pragma once
#include "AllIncludes.h"
class BitChar
{
public:
	unsigned char* c;
	int shift_count;
	std::string BITS;


	BitChar();
	void setBITS(string _X);
	int insertBits(ofstream& outf);
	string getBits(unsigned char _X);
	void writeBits(std::ofstream& outf);
	~BitChar();
};

