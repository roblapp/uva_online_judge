#include <iostream>
#include <fstream>

using namespace std;

//#define read cin
//#define out cout

//NICstDst
//ICstDst
//CstDst
//stDst

bool match(string &s, int index) {

    return false;
}

char isMatchTwoToken(char c) {
    return (c == 'C' or c == 'D' or c == 'E' or c == 'I');
}

char isMatchOneToken(char c) {
    return (c == 'N');
}

int main() {
    ifstream read("test.txt");
	//ofstream out("test_out.txt");
	string line;

	while (getline(read, line)) {

	}
	//out.close();
    read.close();
    return 0;
}
