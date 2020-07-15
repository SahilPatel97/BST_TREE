#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>


#include "TREE.h"

using namespace std;

int main(int argx, char * argv[]) {
	if (argx != 2) {
		std::cout << "Invalid # of args .\n"
			<< "Use: ./main <filename> .\n";
		return -1;
	}


	//File Opening
	ifstream in;
	in.open(argv[1], ios::binary);

	//Double check if input file is opened
	if (!in.is_open()) {
		std::cout << "No file opened, try again .\n";
		return -1;
	}

	//Check if file is empty
	in.seekg(0, ios_base::end);
	int length = in.tellg();
	if (length == 0) {
		std::cout << "File contains no data .\n";
		return -1;
	}

	in.seekg(0, ios_base::beg);

	TREE<string> tree;
	string str;

	while (getline(in, str)) {
		//this pop_back call eliminates \r char in
		//windows text files, remove call if running
		//on unix txt files
		str.pop_back();
		tree.insert(str);
	}
	std::cout << tree.total();

}