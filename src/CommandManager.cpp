#include "Folder.h"
#include "File.h"
#include "TxtFile.h"
#include "AudioFile.h"
#include "PrivateFile.h"
#include "ZipFile.h"
#include <iostream>
#include <string>
#include "CommandManager.h"
using namespace std;


CommandManager::CommandManager(Folder* rootFolder) {
		currentFolder = rootFolder;
}
void CommandManager::searchHelper(Node* node, string name) {
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
void CommandManager::ls() {
	Node** mylist = currentFolder->getList();
	for (int i = 0; i < currentFolder->getCount(); i++)
	{
			cout << "Name: " << mylist[i]->getName() << " | Type: " << mylist[i]->getType() << " | Size: " << mylist[i]->getSize() << endl;
	}
}

void CommandManager::mkdir(string name) {
	Node** mylist = currentFolder->getList();
	for (int i = 0; i < currentFolder->getCount(); i++) {
		if (name == mylist[i]->getName()) {
			cout << "name already exists." <<endl;
			return;
		}
	}
	Folder* newFolder = new Folder(name, currentFolder);
	currentFolder->addNode(newFolder);
}
void CommandManager::cd(string name) {
	Node** mylist = currentFolder->getList();
	bool found = false;	
	
	if (name == "..") {
		Folder* temp = (Folder*)currentFolder->getPreviousNode();
		if (temp == nullptr) {
			cout << "already at the root";
			return;
		}
		currentFolder = temp;
		return;
	}

	for (int i = 0; i < currentFolder->getCount(); i++)
	{
		if (name == mylist[i]->getName()) {
			Folder* temp = dynamic_cast<Folder*>(mylist[i]);
			if (temp == nullptr)
			{
				mylist[i]->open();
				found = true;
				break;
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
void CommandManager::search(string name){
	Node** mylist = currentFolder->getList();
	for (int i = 0; i < currentFolder->getCount(); i++)
	{
		searchHelper(mylist[i], name);
	}
}
void CommandManager::rm(string name) {
	Node** mylist = currentFolder->getList();
	bool found = false;
	for (int i = 0; i < currentFolder->getCount(); i++)
	{
		if (name == mylist[i]->getName())
		{
			Node* toDelete = mylist[i];
			toDelete->remove();
			currentFolder->removeNode(toDelete);
			delete toDelete;
			found = true;
			break;
		}
	}
	if (found ==false)
	{
		cout << "not found" << endl;
	}
}
void CommandManager::rename(string name,string newname) {
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
	}
	if (found == false)
	{
		cout << "not found" <<endl;
	}
}

void CommandManager::touch(string type, string name) {
	File* newFile = nullptr;
	if (type == "txt") {
		newFile = new TxtFile(name, currentFolder);
	}
	else if (type == "mpg") {
		newFile = new AudioFile(name, currentFolder);
	}
	else if (type == "priv") {
		newFile = new pvtFile(name, currentFolder);
	}
	else if (type == "zip") {
		string nodeName;
		cout << "Enter name of node to zip: ";
		getline(cin, nodeName);
		Node** mylist = currentFolder->getList();
		for (int i = 0; i < currentFolder->getCount(); i++) {
			if (mylist[i]->getName() == nodeName) {
				File* fileNode = dynamic_cast<File*>(mylist[i]);
				if (fileNode != nullptr) {
					newFile = new ZipFile(name + "-zip", currentFolder, nodeName, fileNode->getExt());
					break;
				}
			}
		}
	}
	if (newFile != nullptr) {
		newFile->create();
		currentFolder->addNode(newFile);
	}
}
	

void CommandManager::run() {
	string option;
	while (true)
	{
		cout << "\nList of available commands:\n";
		cout << "ls" << endl;
		cout << "mkdir" << endl;
		cout << "cd" << endl;
		cout << "search" << endl;
		cout << "rm" << endl;
		cout << "rename" << endl;
		cout << "touch" << endl;
		cout << "exit\n" << endl;
		cout << currentFolder->getPath() << " > enter command: ";
		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');
		if (option == "ls")
		{
			ls();
		}
		else if(option == "mkdir")
		{
			string name;
			cout << "enter the name:";
			getline(cin, name);
			mkdir(name);
				
		}
		else if (option == "cd")
		{
			string name;
			cout << "enter the name:";
			getline(cin, name);
			cd(name);
			
		}
		else if (option == "search")
		{
			string name;
			cout << "enter the name of the node to search:";
			getline(cin, name);
			search(name);
				
		}
		else if (option == "rm")
		{
			string name;
			cout << "enter the name of the node to delete:";
			getline(cin, name);
			rm(name);
				
		}
		else if (option == "rename")
		{
			string name;
			string newname;
			cout << "enter the name to change:";
			getline(cin, name);
			cout << "enter the new name:";
			getline(cin, newname);
			rename(name, newname);
		}
		else if (option == "touch")
		{
			string name, type;
			cout << "Enter File Type (txt/mpg/priv/zip): ";
			getline(cin, type);
			if (type != "txt" && type != "mpg" && type != "priv" && type != "zip") {
				cout << "Invalid file type" << endl;
				continue;
			}
			cout << "Enter file name: ";
			getline(cin, name);
			touch(type, name);
		}
		else if (option == "exit")
		{
			cout << "exitted succefully" << endl;
			break;
		}
		else
		{
			cout << "Command does not exist." << endl;
			continue;
		}
		
	}
}
