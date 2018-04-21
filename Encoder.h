#pragma once
#include "AllIncludes.h"
#include "node.h"
class Encoder
{
public:
	Encoder() {	}
	~Encoder() {}
	void constructHuffmanTree(const wstring & text);
	HuffmanTree getHuffmanTree();
	string getFileText();
	string getEncodedText();
private:
	wstring originalText;
	string encodedText;
	string FileText;
	HuffmanTree huffmanTree;
	map<int, string>encode;
	map<int, ll> freq;
	vector<string>encodedTree;
	vector<bool>vec;
	void encodeTree(node*root);
	void printEncoded(node*root, string str);
	void outputEncodedFile(const wstring & text);
	void calculateFrequences(const wstring & text);
};

