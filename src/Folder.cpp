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

void Folder::open() { cout << "Opened: " << getName() << endl; }

void Folder::create() { cout << "Created: " << getName() << endl; }

void Folder::remove() {
		cout << "Removed: " << getName() << endl;
		for (int i = 0; i < count; i++)
		{
			delete list[i];
		}
		delete[] list;
		list = nullptr;
		count = 0;
		isDeleted = true;
}

string Folder::getType() {
		return "Folder";
}
int Folder::getSize() {
		return count;
}
int Folder::getCount() {
		return count;
}
Node** Folder::getList() {
		return list;
}

void Folder::addNode(Node* newnode) {
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
void Folder::removeNode(Node* oldnode) {
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

