#include "Folder.h"
#include "CommandManager.cpp"
#include<iostream>
using namespace std;

int main() {
	Folder* root = new Folder("root", nullptr);
	CommandManager cm(root);
	cm.run();

	return 0;
}