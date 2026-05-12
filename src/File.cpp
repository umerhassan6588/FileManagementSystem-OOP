#include "File.h"
using namespace std;


File::File(string nam, Node* parent,string path ,string n) : Node(nam, parent) {
	this->fullPath = path;
	this->ext = n;
}