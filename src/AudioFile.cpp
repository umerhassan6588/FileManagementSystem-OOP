#include "AudioFile.h"
#include <iostream>
#include <cstdio>
using namespace std;

AudioFile::AudioFile(string nam, Node* parent, string fullPath): File(nam, parent, fullPath, ".mpg"){}
void AudioFile::open() {
	string cmd = "start " + fullPath;			// opens the audio file with windows default audio player
	system(cmd.c_str());								// had to download and install ffmpeg
}
void AudioFile::create() {
	cout << "Recording for 5 seconds...\n";
	string cmd = "ffmpeg -f dshow -i audio=\"Microphone (Realtek(R) Audio)\" -t 5 " + fullPath;
	system(cmd.c_str());
	cout << "Recording Completed!\n";
}
void AudioFile::remove() {
	if (::remove(fullPath.c_str()) == 0)
	{
		isDeleted = true;
	}
	else
	{
		cout << "Failed to delete audio file.\n";
	}
}