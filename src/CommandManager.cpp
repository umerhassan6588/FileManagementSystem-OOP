#include "Folder.cpp"
#include <iostream>
#include <string>
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
			if (name == isFolder->getName())
			{
				cout << isFolder->getPath() << endl;
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
	void rm(string name) {
		Node** mylist = currentFolder->getList();
		bool found = false;
		for (int i = 0; i < currentFolder->getCount(); i++)
		{
			if (name == mylist[i]->getName())
			{
				currentFolder->removeNode(mylist[i]);
				delete mylist[i];
				found = true;
				break;
			}
			else
			{
				bool found = false;
			}
		}
		if (found ==false)
		{
			cout << "not found"
		}
	}
	void rename(string name,string newname) {
		Node** mylist = currentFolder->getList();
		bool found = false;
		for (int i = 0; i < currentFolder->getCount(); i++)
		{
			if (name == mylist[i]->getName())
			{
				mylist[i] ->setName(newname);
				found = true;
				break;
			}
			else
			{
				found = false;
			}
		}
		if (found == false)
		{
			cout << "not found" <<endl;
		}
	}
	

	void run() {
		int option;
		while (true)
		{
			cout << "1. ls" << endl;
			cout << "2. mkdir" << endl;
			cout << "3. cd" << endl;
			cout << "4. search" << endl;
			cout << "5. rm" << endl;
			cout << "6. rename" << endl;
			cout << "7. touch" << endl;
			cout << "8. exit" << endl;
			cout << "enter the command you want to run press,1-8: " << endl;
			cin >> option;
			while (cin.fail() || (option > 8 || option < 1))
			{
				cin.ignore();
				cin.clear(1000);
				cout << "option must be between 1-8.RE-ENTER: " << endl;
				cin >> option;
			}
			switch (option)
			{
			case 1: {
				ls();
				break;
			 }
			case 2: {
				mkdir();
				break;
			 }
			case 3: {
				string name;
				cout << "enter the name:";
				getline(cin, name);
				cd(name);
				break;
			 }
			case 4: {
				string name;
				cout << "enter the name of the node to search:";
				getline(cin, name);
				search(name);
				break;
			 }
			case 5: {
				string name;
				cout << "enter the name of the node to delete:";
				getline(cin, name);
				rm(name);
				break;
			 }
			case 5:{
				string name;
				string newname;
				cout << "enter the name to change:";
				getline(cin, name);
				cin.clear(100);
				cout << "enter the new name:";
				getline(cin, newname);
				rename(name, newname);
				break;
			 }
			case 7: {
				//touch for files.
			}
			case 8:{
				cout << "program exitted";
			}

			default:
				break;
			}
		
		}
	}


};
