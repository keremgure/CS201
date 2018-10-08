#include <fstream>
#include <string>
#include "TestBed.h"


int main(int argc, char* args[]) {
	string testFile;
	vector<int> *arr = new vector<int>;

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
		string temp;
		string::size_type sz;
		while (getline(file, temp)) {
			(*arr).push_back(stoi(temp, &sz));
		}
	}
	else {
		cout << "Error: cannot read the test file!" << endl;
		return -1;
	}

	TestBed *bed = new TestBed(*arr);
	bed->execute();
	
	delete bed;
	bed = 0;

	return 0;
}