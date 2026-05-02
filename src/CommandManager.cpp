#include "Folder.cpp"
#include <iostream>
using namespace std;

class CommandManager
{
	Folder* currentFolder;
public:
	CommandManager(Folder* rootFolder) {
		currentFolder = rootFolder;
	}
	void searchHelper(Node* node, string name) {
		Folder* isFolder = dynamic_cast<Folder*>(node);
		if (isFolder == nullptr)
		{
			if (name == node->getName())
			{
				cout << node->getPath() << endl;
			}
		}
		else
		{
			if (name == isFolder->getName)
			{
				isFolder->getPath();
			}
			Node** mylist = isFolder->getList();
			for (int i = 0; i < isFolder->getCount(); i++)
			{
				searchHelper(mylist[i], name);
			}
		}
	}




	void ls() {
		Node** mylist = currentFolder->getList();
		for (int i = 0; i < currentFolder->getCount(); i++)
		{
			cout << "Name: " << mylist[i]->getName() << " | Type: " << mylist[i]->getType() << " | Size: " << mylist[i]->getSize() << endl;
		}
	}
	void mkdir() {
		Folder* newFolder = new Folder(name, currentFolder);
		currentFolder->addNode(newFolder);
	}
	void cd(string name) {
		Node** mylist = currentFolder->getList();
		bool found = false;	
		
		if (name == "..") {
			currentFolder = (Folder*)currentFolder->getPreviousNode();
			return;
		}

		for (int i = 0; i < currentFolder->getCount(); i++)
		{
			if (name == mylist[i]->getName()) {
				Folder* temp = dynamic_cast<Folder*>mylist[i];
				if (temp == nullptr)
				{
					cout << "Not a folder" << endl; break;
				}
				else
				{
					currentFolder = temp;
					found = true;
					
				}
				break;
			}
		}
		if (found == false)
		{
			cout << "not found" << endl;
		}
	}
	search(string name){ 
		Node** mylist = currentFolder->getList();
		for (int i = 0; i < currentFolder->getCount(); i++)
		{
			searchHelper(mylist[i], name);
		}
	}


};
