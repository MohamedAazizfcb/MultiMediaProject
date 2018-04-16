#pragma once
#include "AllIncludes.h"
#include "node.h"
class Encoder
{
public:
	Encoder() {	}
	~Encoder() {}
	void constructHuffmanTree(string text);
private:
	string originalText;
	string encodedText;
	void calculateFrequences(string text);
	map<char,string>encode;
	map<char, ll> freq;
	void printEncoded(node*root, string str);
	void outputEncodedFile();
};

