#include <fstream>
#include <string>
#include "TestBed.h"


int main(int argc, char* args[]) {
	string testFile;

	//Check whether the testFile is supplied or not.
	if (argc < 2) {
		cout << "Enter a test file name:" << endl;
		cin >> testFile;
	}//If supplied pass it to the variable.
	else{
		testFile = args[1];
	}
	//Read the input file and put it to vector.
	ifstream file(testFile.c_str());
	if (file.is_open()) {
	    cin.rdbuf(file.rdbuf());
	}
	else {
		cout << "Error: cannot read the test file!" << endl;
		return -1;
	}

	TestBed *bed = new TestBed();
	bed->execute();

	delete bed;
	bed = nullptr;

	return 0;
}