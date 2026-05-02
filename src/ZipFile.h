#pragma once
#include "File.h"
#include <string>
using namespace std;


class ZipFile : public File {
protected:
	string originalName;
	string originalExt;
public:
	ZipFile(string nam, Node* parent, string originalName, string originalExt);
	void create() override;
	void open() override;
	void del() override;
	void unzip();
};