#pragma once
#include "TxtFile.h"
#include <string>
using namespace std;



class pvtFile : public TxtFile {
protected:
	string pass;
public:
	pvtFile(string name, Node* parent);
	void open() override;
	void create() override;
	void del() override;
};