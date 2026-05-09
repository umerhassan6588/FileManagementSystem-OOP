#include "AudioFile.h"
#include <iostream>
#include <cstdio>
using namespace std;


AudioFile::AudioFile(string nam, Node* parent) : File(nam, parent, ".mpg") { }
void AudioFile::open() {
	string cmd = "start root/" + name + ".mpg";			// opens the audio file with windows default audio player
	system(cmd.c_str());
}
void AudioFile::create() {
	cout << "Recording for 5 seconds...\n";
	string cmd = "ffmpeg -f dshow -i audio=\"Microphone\" -t 5 root/" + name + ".mpg";
	system(cmd.c_str());
	cout << "Recording Completed!\n";
}
void AudioFile::remove() {
	string path = "root/" + name + ".mpg";
	::remove(path.c_str());
	isDeleted = true;
}