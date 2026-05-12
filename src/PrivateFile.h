#pragma once
#include "TxtFile.h"
#include <string>
using namespace std;



class pvtFile : public TxtFile {
protected:
	string pass;
public:
	pvtFile(string name, Node* parent);
	pvtFile(string name, Node* parent, string password);
	void open() override;
	void create() override;
	void remove() override;
	string getPass();
	string getType() override {
		return "PrivateFile";
	}
};