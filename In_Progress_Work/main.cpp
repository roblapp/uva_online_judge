#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

//#define read cin

int main() {
    ifstream read("test.txt");
    string line;

    while (getline(read, line) && line != "#") {

    }

    read.close();
    return 0;
}
