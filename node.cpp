#include "node.h"

node::node(char data, ll freq) {
	left = right = nullptr;
	this->data = data;
	this->freq = freq;
}

