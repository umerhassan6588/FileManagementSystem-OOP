#pragma once
#include "Folder.h"
#include "File.h"
#include "TxtFile.h"
#include "AudioFile.h"
#include "PrivateFile.h"
#include "ZipFile.h"
#include <iostream>
#include <string>
using namespace std;

class CommandManager
{
	Folder* currentFolder;
	Folder* rootFolder;
public:
	string basePath = "C:/Users/Hamiz/Desktop/projetest/projetest/";
	CommandManager(Folder* rootFolder);
	void searchHelper(Node* node, string name);
	void ls();
	void mkdir(string name);
	void cd(string name);
	void search(string name);
	void rm(string name);
	void Rename(string name, string newname);
	void touch(string type, string name);
	void saveHelper(Node* node, ofstream& file);
	void save();
	void load();
	Folder* findFolder(Node* node, string path);
	void run();
	void deleteRecursively(Node* node);
	
};