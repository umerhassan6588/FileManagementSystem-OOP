#pragma once
#include "File.h"
using namespace std;

class TxtFile : public File {
protected:
	string* lines;
	int lineCount;
	int lineCap;
public:
	TxtFile(string nam, Node* parent, string ext = ".txt");
	void open() override;
	void create() override;
	void remove() override;
	void save();
	~TxtFile();
};