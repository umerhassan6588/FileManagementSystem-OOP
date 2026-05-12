#pragma once
#include "TxtFile.h"
#include <string>
using namespace std;



class pvtFile : public TxtFile {
protected:
	string pass;
public:
	pvtFile(string name, Node* parent,string fullpath);
	pvtFile(string name, Node* parent, string password,string fullpath);
	void open() override;
	void create() override;
	void remove() override;
	string getPass();
	string getType() override {
		return "PrivateFile";
	}
};