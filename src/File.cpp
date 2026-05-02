#include "File.h"
using namespace std;


File::File(string nam, Node* parent, string n) :Node(nam, parent) {
	ext = n;
}