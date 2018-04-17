#include "Decoder.h"

void Decoder::startDecoding(node*top,string s){
    string decodedText = "";
    struct node* curr = top;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
           curr = curr->left;
        else
           curr = curr->right;
        // reached leaf node
        if (curr->left==NULL && curr->right==NULL)
        {
			decodedText += curr->data;
			curr = top;
        }
    }
	cout << "\n\n" << decodedText;
}