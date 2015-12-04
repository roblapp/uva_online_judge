#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

//#define read cin
#define MAXN 100000

int main() {
    ifstream read("test.txt");
    int n, m, x, k;
    map<int, int> mIndexer;
    vector<int> g[MAXN];

    while (read >> n >> m) {
        k = 0;
        for (int i = 0; i < n; i++) {
            read >> x;
            if (mIndexer.find(x) == mIndexer.end()) {
                mIndexer[x] = k++;
            } else {

            }
        }
    }



    read.close();
    return 0;
}
