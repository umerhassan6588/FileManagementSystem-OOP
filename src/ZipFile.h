#pragma once
#include "File.h"
#include <string>
using namespace std;


class ZipFile : public File {
protected:
	string orignalFullpath;
public:
	ZipFile(string nam, Node* parent, string sourcePath,string destPath);
	void create() override;
	void open() override;
	void remove() override;
	void unzip();
	string getType() override {
		return "ZipFile";
	}
	string getSourcePath() { return orignalFullpath; }
	int getSize() override {
		return 0;
	}
};