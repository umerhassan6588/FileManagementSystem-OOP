#include "Folder.h"
#include "File.h"
#include "TxtFile.h"
#include "AudioFile.h"
#include "PrivateFile.h"
#include "ZipFile.h"
#include <iostream>
#include <string>
#include "CommandManager.h"
#include <fstream>
using namespace std;


CommandManager::CommandManager(Folder* rootFolder) {
		currentFolder = rootFolder;
		this ->rootFolder = rootFolder;
		load();
}
void CommandManager::searchHelper(Node* node, string name) {  // a recursive function used in search. To search for the specified nodes path.
	Folder* isFolder = dynamic_cast<Folder*>(node);
	if (isFolder == nullptr)
	{
	    if (name == node->getName())
			{
				cout << node->getPath() << endl;
				cout << "Searched Successfully." << endl;
				return;
			}
	}
	else
	{
		if (name == isFolder->getName())
		{
			cout << isFolder->getPath() << endl;
			cout << "Searched Successfully." << endl;
		}
		Node** mylist = isFolder->getList();
		for (int i = 0; i < isFolder->getCount(); i++)
		{
				searchHelper(mylist[i], name);
		}
	}
}
void CommandManager::ls() {  // list all the nods in the current folder/path.
	Node** mylist = currentFolder->getList();
	for (int i = 0; i < currentFolder->getCount(); i++)
	{
			cout << "Name: " << mylist[i]->getName() << " | Type: " << mylist[i]->getType() << " | Size: " << mylist[i]->getSize() << endl;
	}
}

void CommandManager::mkdir(string name) {// creates a folder.
	if (name == "" || name[0] == ' ') {
		cout << "Invalid name." << endl;
		return;
	}
	Node** mylist = currentFolder->getList();
	for (int i = 0; i < currentFolder->getCount(); i++) {
		if (name == mylist[i]->getName()) {
			cout << "name already exists." <<endl;
			return;
		}
	}
	Folder* newFolder = new Folder(name, currentFolder);
	currentFolder->addNode(newFolder);
	cout << "Folder created Successfully." << endl;
}
void CommandManager::cd(string name) { //opens the nodes in the current folder
	if (name == "" || name[0] == ' ') {
		cout << "Invalid name." << endl;
		return;
	}
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
void CommandManager::search(string name){// used to search for required node and print its path.
	if (name == "" || name[0] == ' ') {
		cout << "Invalid name." << endl;
		return;
	}
	Node** mylist = currentFolder->getList();
	for (int i = 0; i < currentFolder->getCount(); i++)
	{
		searchHelper(mylist[i], name);
	}
}

void CommandManager::rm(string name) {// used to delete a node.
	if (name == "" || name[0] == ' ') {
		cout << "Invalid name." << endl;
		return;
	}
	Node** mylist = currentFolder->getList();
	bool found = false;
	for (int i = 0; i < currentFolder->getCount(); i++)
	{
		if (name == mylist[i]->getName())
		{
			Node* toDelete = mylist[i];
			toDelete->remove();
			if (toDelete->isDeleted == true)
			{
				currentFolder->removeNode(toDelete);
				delete toDelete;
				cout << "removed Successfully" << endl;
			}
			found = true;
			
			break;
		}
	}
	if (found ==false)
	{
		cout << "not found" << endl;
	}

}
void CommandManager::rename(string name,string newname) {//used to rename the opened node.
	if (name == "" || name[0] == ' ') {
		cout << "Invalid name." << endl;
		return;
	}
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

void CommandManager::touch(string type, string name) {//create file of any type
	if (name == "" || name[0] == ' ') {
		cout << "Invalid name." << endl;
		return;
	}
	Node** mylist = currentFolder->getList();
	for (int i = 0; i < currentFolder->getCount(); i++)
	{
		
		File* existingFile = dynamic_cast<File*>(mylist[i]);
		if (existingFile != nullptr) {
			string checkname = name;
			if (type == "zip")
			{
				checkname = checkname + "-zip";
			}
			if (mylist[i]->getName() == checkname && existingFile->getExt() == ("." + type)) {
				cout << "Name already exists." << endl;
				return;
			}
		}
	}

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
				else
				{
					cout << "Cannot Zip a folder." << endl;
					return;
				}
			}
		}
		if (newFile == nullptr) {
			cout << "Node not found." << endl;
			return;
		}
	}
	if (newFile != nullptr) {
		newFile->create();
		currentFolder->addNode(newFile);
	}
}
void CommandManager::saveHelper(Node* node, ofstream& file) {// a recursive function to save the paths of the nodes in a file.
	
	pvtFile* Private = dynamic_cast<pvtFile*>(node);
		if (Private != nullptr)
		{
			file << Private->getType() << "," << Private->getName() << "," << Private->getPath() << Private->getPass() << endl;
		}
		else
		{
			file << node->getType() << "," << node->getName() << "," << node->getPath() << endl;
		}
	Folder* isFolder = dynamic_cast<Folder*>(node);
	if (isFolder != nullptr)
	{
		for (int i = 0; i < isFolder->getCount(); i++) {
			saveHelper(isFolder->getList()[i], file);
		}
	}
}
void CommandManager::save() {//used to save the paths in the file with the help of saveHelper
	ofstream file("save.txt");
	if (file.is_open())
	{
		Node** mylist = rootFolder->getList();
		for (int i = 0; i < rootFolder->getCount(); i++)
		{
			saveHelper(mylist[i], file);
		}
		file.close();
	}
	else
	{
		cout << "Error file did not open" << endl;
	}
}
Folder* CommandManager::findFolder(Node* node, string path) {//recursive function used to find the folder or file to create
	Folder* isFolder = dynamic_cast<Folder*>(node);
	if (isFolder == nullptr) {
		return nullptr;
	}
	else if (isFolder->getPath() == path)
	{
		return isFolder;
	}
	else
	{
		for (int i = 0; i < isFolder->getCount(); i++) {
			Folder* found = findFolder(isFolder->getList()[i], path);
			if (found != nullptr) { 
				return found;
			}

		}
	}
	return nullptr;
}

void CommandManager::load() {//used to load and create the nodes using the paths saved in the file.
	ifstream file("save.txt");
	if (file.is_open())
	{
		string line;
		while (getline(file, line)) {
			int firstComma = line.find(',');
			int secondComma = line.find(',', firstComma+1);
			string type = line.substr(0,firstComma);
			string name = line.substr(firstComma+1,secondComma-firstComma-1);
			string path = line.substr(secondComma+1);
			int lastSlash= path.find_last_of('/');
			string parentPath = path.substr(0, lastSlash);
			Folder* parent = findFolder(rootFolder, parentPath);
			if (parent == nullptr) {
				continue;
			}
			Node* newNode = nullptr;
			if (type == "Folder")
			{
				newNode = new Folder(name, parent);
			}
			else if (type == "TxtFile")
			{
				newNode = new TxtFile(name, parent);
			}
			else if (type == "AudioFile")
			{
				newNode = new AudioFile(name, parent);
			}
			else if (type == "PrivateFile")
			{
				int thirdComma = line.find(',', secondComma + 1);
				string cleanPath = line.substr(secondComma + 1, thirdComma - secondComma - 1);
				string password = line.substr(thirdComma + 1);
				int ls = cleanPath.find_last_of('/');
				string ppath = cleanPath.substr(0, ls);
				parent = findFolder(rootFolder, ppath);
				if (parent == nullptr) {
					continue; 
				}
				newNode = new pvtFile(name, parent,password);
			}
			else if (type == "ZipFile")
			{
				newNode = new ZipFile(name, parent, name, ".zip");
			}
			if (newNode != nullptr)
			{
				parent->addNode(newNode);
			}
		}
	}
	file.close();
}

void CommandManager::run() {//main run function to use all commands.
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
			save();
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
