#pragma once
#include "AllIncludes.h"
class node
{
public:
	// character to be stored
	char data;
	// Frequency of the character
	long long freq;
	// Left and right child
	node *left, *right;
	node(char data, ll freq);
	~node(){}
};

