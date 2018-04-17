#include "Encoder.h"
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
void Encoder::outputEncodedFile(){
	encodedText = "";
	for (int i = 0; i < originalText.size(); ++i) {
		cout << encode[originalText[i]];
		encodedText += encode[originalText[i]];
	}
}
void Encoder::calculateFrequences(string text) {
	for (int i = 0; i < text.size(); ++i)
		this->freq[text[i]]++;
}
void Encoder::constructHuffmanTree(string text) {
	originalText = text;
	calculateFrequences(text);
	node *left, *right, *top;
	for(map<char,ll>::iterator it = freq.begin();it != freq.end();++it)
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
	printEncoded(huffmanTree.top(), "");
	cout << "\n";
	outputEncodedFile();
}

HuffmanTree Encoder::getHuffmanTree()
{
	return huffmanTree;
}

string Encoder::getEncodedText()
{
	return encodedText;
}
