#include "Encoder.h"
void Encoder::encodeTree(node * root)
{
	if (!root) return;
	if (!root->left && !root->right) {
		// this node is a chid
		encodedTree.push_back("1");
		encodedTree.push_back(encode[root->data]);
		return;
	}
	encodedTree.push_back("0");
	encodeTree(root->left);
	encodeTree(root->right);
}
void Encoder::printEncoded(node*root, string str) {
	if (!root)
		return;
	if (root->data != '$'){
		vec.clear();
		vec.resize(str.size());
		encode[root->data] = str;
		cout << root->data << ": " << str << "\n";
	}
	printEncoded(root->left, str + "0");
	printEncoded(root->right, str + "1");
}
void Encoder::outputEncodedFile(const wstring & text){
	encodedText = "";  int padding = 0; int lastStatus = -1;
	ofstream out("output.txt", ios::out); 

	cout << "############ Encoding Stage ###########\n";
	for (int i = 0; i < text.size(); ++i) {
		int copyingStatus = int(double((i + 1)) / (text.size()) * 100);
		if (copyingStatus != lastStatus) {
			cout << "Encoding Status " << copyingStatus << "%" << endl;
			lastStatus = copyingStatus;
		}
		encodedText += encode[text[i]];
	}
	cout << "############ Encoding Done ###########\n\n";

	lastStatus = -1;
	/*
	for (int i = 0; i < encodedText.size(); i += 8) {
		unsigned char character = 0; string s = "";
		int compressionStatus = int(double((i + 1)) / (encodedText.size()) * 100);
		if (compressionStatus != lastStatus) {
			cout << "Compression Status " << compressionStatus << "%" << endl;
			lastStatus = compressionStatus;
		}
		if (i + 8 < encodedText.length()) {
			s = encodedText.substr(i, i + 8);
		} else {
			s = encodedText.substr(i);
			padding = 8 - s.size();
			for (int i = 0; i < padding; ++i)
				s += "0";
		}
		for (int i = 0; i < 8; ++i)
			if (s[i] == '1')
				character |= 1 << (7 - i);
		out.put(character);
		
	}
	*/
	const size_t n = encodedText.size();
	const int num8 = n / 8;
	vector<char> byteArray(num8);
	for (size_t i = 0; i < num8; ++i) {
		byteArray[i] = 0;
		for (size_t j = 0; j < 8; ++j)
			if (encodedText[i * 8 + j] == '1')
				byteArray[i] |= 1 << j;
	}
	
	for (int i = 0; i < num8; ++i)
		out.put(byteArray[i]);

	padding = n % 8;
	if (padding == 0) 
		out.put('0');
	else {
		string s = encodedText.substr(n - padding);
		for (int i = 0; i < 8 - padding; ++i)
			s += "0";
		char byte = 0;
		for (size_t j = 0; j < 8; ++j)
			if (s[j] == '1')
				byte |= 1 << j;
		out << byte << 8 - padding;
	}
	
	cout << "\nThe input file size is " << GetSizeOfFile(L"DataSet_3.tsv") << " Bytes\tand the output file size is " << uint64_t(ceil(encodedText.size() / 8)) << " Bytes\n";
	//cout << encodedText << endl;
	
	out.close();
	out.flush();
}
void Encoder::constructHuffmanTree(const wstring & text)
{
	calculateFrequences(text);
	node *left, *right, *top;
	for (map<int, ll>::iterator it = freq.begin(); it != freq.end(); ++it)
		huffmanTree.push(new node(it->first, it->second));
	while (huffmanTree.size() != 1) {
		left = huffmanTree.top();
		huffmanTree.pop();
		right = huffmanTree.top();
		huffmanTree.pop();
		top = new node('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		huffmanTree.push(top);
	}
	cout << "The Frequency Tree is \n";
	
	printEncoded(huffmanTree.top(), "");
	//encodeTree(huffmanTree.top());
	outputEncodedFile(text);
}

HuffmanTree Encoder::getHuffmanTree()
{
	return huffmanTree;
}

string Encoder::getFileText()
{
	return FileText;
}

string Encoder::getEncodedText()
{
	return encodedText;
}

void Encoder::calculateFrequences(const wstring & text)
{
	cout << "############ Calculating Frequences ###########\n";
	int lastStatus = -1;
	for (int i = 0; i < text.size(); ++i) {
		int calculatingFrequencies = int(double((i + 1)) / (text.size()) * 100);
		if (calculatingFrequencies != lastStatus) {
			cout << "Calculating Frequences Status " << calculatingFrequencies << "%" << endl;
			lastStatus = calculatingFrequencies;
		}
		freq[text[i]]++;
	}
}
