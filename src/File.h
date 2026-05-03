#pragma once
#include "Node.h"
#include <string>
using namespace std;

class File : public Node {
protected:
	string ext;
public:
	File(string nam, Node* parent, string n);
	virtual void open() = 0;
	virtual void create() = 0;
	virtual void remove() = 0;
};