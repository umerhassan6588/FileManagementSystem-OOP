#pragma once
#include "File.h"
using namespace std;

class TxtFile : public File {
protected:
	string* lines;
	int lineCount;
	int lineCap;
public:
	TxtFile(string nam, Node* parent);
	void open() override;
	void create() override;
	void del() override;
	void save();
	~TxtFile();
};