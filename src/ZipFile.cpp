#include "ZipFile.h"
#include <string>
#include <iostream>
using namespace std;

ZipFile::ZipFile(string nam, Node* parent, string originalName, string originalExt) : File(nam, parent, ".zip") {
	this->originalName = originalName;
	this->originalExt = originalExt;
}
void ZipFile::create() {
	string cmd = "powershell Compress-Archive -Path root/" + originalName + originalExt + " -DestinationPath root/" + name + ".zip";
	system(cmd.c_str());
	cout << "The file has been zipped!\n";
}
void ZipFile::open() {
	cout << "Zipped files cannot be opened, unzip first." << endl;
}
void ZipFile::unzip() {
	string cmd = "powershell Expand-Archive -Path root/" + name + ".zip -DestinationPath root/" + originalName + "-unzipped";
	system(cmd.c_str());
	cout << "The file has been unzipped!\n";
}
void ZipFile::remove() {
	string path = "root/" + name + ".zip";
	::remove(path.c_str());
	isDeleted = true;
}
