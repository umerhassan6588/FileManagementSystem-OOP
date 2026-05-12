#pragma once
#include <string>
#include <iostream>
using namespace std;
class Node
{
protected:
	string name;
	Node* prev;
	
public:
	bool isDeleted = false;
	Node(string fname, Node* p) {
		name = fname;
		prev = p;
	}
	virtual void open() = 0;
	virtual void create() = 0;
	virtual void remove() = 0;
	virtual ~Node() {}
	string getName() {
		return name;
	}
	Node* getPreviousNode() {
		return prev;
	}
	string getPath() {//recursive function to get path of node.
		{
			if (prev == nullptr) {
				return name;
			}

			return prev->getPath() + "/" + name;
		}
	}
	
	void setName(string newname){
		name = newname;
	}
	virtual string getType() = 0;
	virtual int getSize() = 0;


};
