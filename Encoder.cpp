#include "Encoder.h"
struct compare {
	bool operator()(node* l, node* r) {
		return (l->freq > r->freq);
	}
};
void Encoder::printEncoded(node*root, string str) {
	if (!root)
		return;
	if (root->data != '$'){
		encode[root->data] = str;
		cout << root->data << ": " << str << "\n";
	}
	printEncoded(root->left, str + "0");
	printEncoded(root->right, str + "1");
}
void Encoder::outputEncodedFile(){
	for(int i=0;i<originalText.size();++i)
		cout << encode[originalText[i]];
}
void Encoder::calculateFrequences(string text) {
	for (int i = 0; i < text.size(); ++i)
		this->freq[text[i]]++;
}
void Encoder::constructHuffmanTree(string text) {
	originalText = text;
	calculateFrequences(text);
	node *left, *right, *top;
	priority_queue<node*, vector<node*>, compare> huffmanTree;
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
	cout << "\n\n\n\n\n\n";
	outputEncodedFile();
}