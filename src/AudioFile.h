#pragma once
#include "File.h"
using namespace std;


class AudioFile : public File {
public:
	AudioFile(string nam, Node* parent);
	void open() override;
	void create() override;
	void remove() override;
};