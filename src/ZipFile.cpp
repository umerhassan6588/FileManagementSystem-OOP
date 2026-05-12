#include "ZipFile.h"
#include <string>
#include <iostream>
using namespace std;

ZipFile::ZipFile(string nam, Node* parent, string sourcePath, string destPath): File(nam, parent, destPath, ".zip") {
	this->orignalFullpath = sourcePath;
}
void ZipFile::create() {
	string cmd = "powershell Compress-Archive -Path " + orignalFullpath+ " -DestinationPath " + fullPath;
	system(cmd.c_str());
	cout << "The file has been zipped!\n";
}
void ZipFile::open() {
	cout << "Zipped files cannot be opened directly.\n";

	string inp;
	cout << "Type 'unzip' to extract: ";
	getline(cin, inp);

	if (inp == "unzip")
	{
		unzip();
	}
}
void ZipFile::unzip() {
	string cmd = "powershell Expand-Archive -Path " +fullPath + " -DestinationPath " + orignalFullpath + "-unzipped";
	system(cmd.c_str());
	cout << "The file has been unzipped!\n";
	return;
}
void ZipFile::remove() {
	if (::remove(fullPath.c_str()) == 0)
		isDeleted = true;
	else
		cout << "Failed to delete zip file.\n";
}

