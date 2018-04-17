#pragma once
#include "AllIncludes.h"
#include "node.h"
class Encoder
{
public:
	Encoder() {	}
	~Encoder() {}
	void constructHuffmanTree(string text);
	HuffmanTree getHuffmanTree();
	string getEncodedText();
private:
	string originalText;
	string encodedText;
	HuffmanTree huffmanTree;
	void calculateFrequences(string text);
	map<char, string>encode;
	map<char, ll> freq;
	vector<bool> vec;

	void printEncoded(node*root, string str);
	void outputEncodedFile();
};

