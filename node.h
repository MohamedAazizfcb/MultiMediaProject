#pragma once
typedef long long ll;
class node
{
public:
	// character to be stored
	char data;
	// Frequency of the character
	ll freq;
	// Left and right child
	node *left, *right;
	node(char data, ll freq);
	~node(){}
};

