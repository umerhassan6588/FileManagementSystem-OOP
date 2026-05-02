#include <iostream>
using namespace std;
class Node
{
protected:
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
	string getName() {
		return name;
	}
	Node* getPreviousNode() {
		return prev;
	}
	string getPath() {
		string path = "";
		
		if (prev != nullptr)
		{
			path = path + "/" + name;
			return prev->getPath() + path;
		}
		else
		{
			return name;
		}
	}
	string setName(string newname){
		name = newname;
	}
};
