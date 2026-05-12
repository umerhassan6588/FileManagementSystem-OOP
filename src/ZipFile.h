#pragma once
#include "File.h"
#include <string>
using namespace std;


class ZipFile : public File {
protected:
	string orignalFullpath;
public:
	ZipFile(string nam, Node* parent, string orignalFullpath);
	void create() override;
	void open() override;
	void remove() override;
	void unzip();
	string getType() override {
		return "ZipFile";
	}
	int getSize() override {
		return 0;
	}
};