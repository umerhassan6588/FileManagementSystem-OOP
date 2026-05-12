#pragma once
#include "File.h"
using namespace std;


class AudioFile : public File {
public:
	AudioFile(string nam, Node* parent,string fullpath);
	void open() override;
	void create() override;
	void remove() override;
	string getType() override {
		return "AudioFile";
	}
	int getSize() override {
		return 0;
	}
};