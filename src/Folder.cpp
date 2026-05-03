#include "node.h"
#include "Folder.h"
#include<iostream>
using namespace std;




Folder::Folder(string name, Node* prev) : Node(name, prev) {
	list = nullptr;
	count = 0;
}
Folder::~Folder() {
	for (int i = 0; i < count; i++)
	{
		delete list[i];
	}
	delete[] list;
}

Folder::void open() { cout << "Opened: " << getName() << endl; }

Folder::void create() { cout << "Created: " << getName() << endl; }

Folder::void remove() {
		cout << "Removed: " << getName() << endl;
		for (int i = 0; i < count; i++)
		{
			delete list[i];
		}
		delete[] list;
}

Folder::string getType() {
		return "Folder";
}
Folder::int getSize() {
		return count;
}
Folder::int getCount() {
		return count;
}
Folder::Node** getList() {
		return list;
}

Folder::void addNode(Node* newnode) {
		Node** temp = new Node * [count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = list[i];
		}
		temp[count] = newnode;
		delete[] list;
		list = temp;
		count++;
}
Folder::void removeNode(Node* oldnode) {
		Node** temp = new Node * [count - 1];
		int j = 0;
		for (int i = 0; i < count; i++)
		{
			if (list[i] != oldnode) {
				temp[j] = list[i];
				j++;
			}
		}
		delete[] list;
		list = temp;
		count--;
}

