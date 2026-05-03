#pragma once
#include "node.h"
#include <iostream>
class Folder : public Node
{
protected:
	Node** list;
	int count;

public:
	Folder(string name, Node* prev) : Node(name, prev){}
	~Folder();

	void open();
	void create();
	void remove();
	string getType();
	int getSize();
	int getCount();
	Node** getList();
	void addNode(Node* newnode);
	void removeNode(Node* oldnode);
};