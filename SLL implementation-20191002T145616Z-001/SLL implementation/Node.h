#pragma once;

struct Node {
	int data;
	Node *next;
	
	Node(int a = 0, Node *b = 0)
		: data(a)
		, next(b)
	{}
};
