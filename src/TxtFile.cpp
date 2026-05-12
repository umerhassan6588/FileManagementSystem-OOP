#include "TxtFile.h"
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

TxtFile::TxtFile(string nam, Node* parent, string fullpath) : File(nam, parent, fullpath,".txt"), lineCount(0), lineCap(10) {
	lines = new string[lineCap];
	ifstream file(fullpath);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			lineCount++;
		}
		file.close();
	}
	
	
}
TxtFile::~TxtFile() {
	delete[] lines;
}

void TxtFile::save() {
	ofstream file(fullPath);
	for (int i = 0; i < lineCount; i++) {
		file << lines[i] << endl;
	}
	file.close();
}

void TxtFile::open() {
	ifstream file(fullPath);
	string line;
	while (getline(file, line)) {		// file means it keeps copying till it hits "\n" and then goes to the next line
		if (lineCount == lineCap) {
			lineCap += 10;
			string* templines = new string[lineCap];
			for (int i = 0; i < lineCount; i++) {
				templines[i] = lines[i];
			}
			delete[] lines;
			lines = new string[lineCap];
			for (int i = 0; i < lineCount; i++) {
				lines[i] = templines[i];
			}
			delete[] templines;
		}
		lines[lineCount++] = line;
	}
	file.close();
	for (int i = 0; i < lineCount; i++) {
		cout << lines[i] << endl;
	}

	do {
		string inp;
		cout << "\nType in:\n";
		cout << "1.\"add\" to add text\n";
		cout << "2.\"edit\" to edit text\n";
		cout << "3.\"quit\" to exit\n";
		getline(cin, inp);

		if (inp == "add") {
			if (lineCount == lineCap) {
				lineCap += 10;
				string* templines = new string[lineCap];
				for (int i = 0; i < lineCount; i++) {
					templines[i] = lines[i];
				}
				delete[] lines;
				lines = new string[lineCap];
				for (int i = 0; i < lineCount; i++) {
					lines[i] = templines[i];
				}
				delete[] templines;
			}
			cout << "Enter new text: ";
			getline(cin,lines[lineCount++]);
			continue;
		}
		else if(inp == "edit") {
			int x;
			cout << "Line number: ";
			cin >> x;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "New Text: ";
			getline(cin, lines[x - 1]);
			continue;
		}
		else if (inp == "quit") {
			cout << "Saving changes....\n";
			save();
			break;
		}
		else {
			cout << "Invalid Command. Try Again.\n";
			continue;
		}
	} while (true);

}

void TxtFile::remove() {
	string dir = (fullPath);
	::remove(fullPath.c_str());// bcs remove only takes in char arr not strings
	isDeleted = true;
}									// :: bcs there is another remove() in Folder.cpp

void TxtFile::create() {
	ofstream file(fullPath);		// name from node class. TxtFile -> File -> Node
	file.close();
}