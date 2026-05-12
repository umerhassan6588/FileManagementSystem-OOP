#pragma once
#include "Node.h"
#include <string>
using namespace std;

class File : public Node {
protected:
	string ext;
	string fullPath;
public:
	File(string nam, Node* parent, string path, string ext);
	virtual void open() = 0;
	virtual void create() = 0;
	virtual void remove() = 0;
	virtual string getType() {
		return "File";
	}
	virtual int getSize() {
		return 0;
	}
	virtual string getExt() {
		return ext;
	}
};