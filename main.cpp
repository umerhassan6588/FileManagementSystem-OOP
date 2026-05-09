#include "src/Folder.h"
#include <iostream>
#include "src/CommandManager.h"
using namespace std;

int main() {
	system("rmdir /s /q root");
	system("mkdir root");
	Folder* root = new Folder("root", nullptr);
	CommandManager cm(root);
	cm.run();

	return 0;
}