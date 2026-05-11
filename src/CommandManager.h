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
	CommandManager(Folder* rootFolder);
	void searchHelper(Node* node, string name);
	void ls();
	void mkdir(string name);
	void cd(string name);
	void search(string name);
	void rm(string name);
	void rename(string name, string newname);
	void touch(string type, string name);
	void saveHelper(Node* node, ofstream& file);
	void save();
	void run();
	
};