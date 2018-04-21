#pragma once
#include "AllIncludes.h"
#include "node.h"

class Decoder
{
private:
	string encodedText;
	string binaryEncodedText;
public:
	Decoder(){}
	void startDecoding(node* top);
	~Decoder(){}
};

