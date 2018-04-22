#include "Decoder.h"

void Decoder::startDecoding(node*top){
	ifstream* infile = new ifstream("output.txt", ifstream::binary);
	infile->seekg(0, infile->end);
	long size = infile->tellg();
	infile->seekg(0);
	char* buffer = new char[size];
	infile->read(buffer, size);


	string binaryText = ""; node* curr = top; wstring decodedText;
	for (int i = 0; i < size - 1; ++i) {
		bitset<8> a(buffer[i]);
		string x = a.to_string();
		reverse(x.begin(), x.end());
		binaryText += x;
	}

	int padding = buffer[size-1] - '0';
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
	infile->close();
	if (auto f = wofstream("tmp")) {
		f.imbue(locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>));
		f << decodedText;
	}
	delete[] buffer;
	delete infile;
}