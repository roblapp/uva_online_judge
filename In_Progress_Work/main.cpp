#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream read("test.txt");
	//ofstream out("test_out.txt");

	//out.close();
    read.close();
    return 0;
}
