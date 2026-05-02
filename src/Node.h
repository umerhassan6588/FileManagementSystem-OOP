#include <iostream>
using namespace std;
class Node
{
	string name;
	Node* prev;
public:
	Node(string fname, Node* p) {
		name = fname;
		prev = p;
	}
	virtual void open() = 0;
	virtual void create() = 0;
	virtual void remove() = 0;
	virtual ~Node() {}
	virtual int getSize() = 0;
	virtual string getType() = 0;
	string getName() {
		return name;
	}
	Node* getPreviousNode() {
		return prev;
	}

};
