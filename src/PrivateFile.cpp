#include "PrivateFile.h"
#include <iostream>
#include <string>
using namespace std;

pvtFile::pvtFile(string nam, Node* parent) : TxtFile(nam, parent, ".priv") {

}
void pvtFile::open() {
	string inp;
	cout << "Enter Passkey:";
	getline(cin, inp);
	if (inp == pass) {
		TxtFile::open();
	}
	else {
		cout << "Wrong Password!\n";
	}
}
void pvtFile::create() {
	TxtFile::create();
	cout << "Enter Passkey for this file: ";
	getline(cin, pass);
}
void pvtFile::remove() {
	string inp;
	cout << "Enter Passkey:";
	getline(cin, inp);
	if (inp == pass) {
		char inp1;
		while (true) {
			cout << "Are you sure you want to delete? press y to confirm and n to exit: ";
			cin >> inp1;
			if (inp1 == 'y' || inp1 == 'Y') {
				TxtFile::remove();
				isDeleted = true;
				break;
			}
			else if (inp1 == 'n' || inp1 == 'N') {
				break;
			}
			else {
				cout << "invalid input.Try Again.\n";
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	}
	else {
		cout << "Wrong Password!\n";
	}
}