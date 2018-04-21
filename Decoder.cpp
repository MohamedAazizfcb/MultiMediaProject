#include "Decoder.h"

void Decoder::startDecoding(node*top){
	ifstream input("output.txt", ios::in);
	string text = "", x, binaryText = ""; node* curr = top; wstring decodedText;
	while (getline(input,x))
		text += x;
	for (int i = 0; i < text.size() - 1; ++i) {
		bitset<8> a(text[i]);
		string x = a.to_string();
		reverse(x.begin(), x.end());
		binaryText += x;
	}

	int padding = text.back() - '0';
	for (int i = 0; i < padding; ++i)
		binaryText.pop_back();

	//cout << endl << binaryText << endl;

	for (int i=0;i<binaryText.size();i++){
        if (binaryText[i] == '0')
			curr = curr->left;
        else
			curr = curr->right;
        // reached leaf node
        if (curr->left==NULL && curr->right==NULL) {
			decodedText += curr->data;
			curr = top;
        }
    }
	input.close();
	if (auto f = wofstream("tmp")) {
		f.imbue(locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>));
		f << decodedText;
	}
}