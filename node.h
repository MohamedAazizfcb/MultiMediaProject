#pragma once
typedef long long ll;
class node
{
public:
	// character to be stored
	int data;
	// Frequency of the character
	ll freq;
	// Left and right child
	node *left, *right;
	node(int data, ll freq);
	~node() {}
};

