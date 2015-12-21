#include <iostream>
#include <fstream>

using namespace std;

//#define read cin

int main() {
    ifstream read("test.txt");
    int numNodes, n;


    do {
        read >> numNodes >> n;

        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {

            }
        }
    } while (read >> x && x < 0);

    read.close();
    return 0;
}
