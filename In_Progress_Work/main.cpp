#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//#define read cin
//#define out cout

int main() {
    ifstream read("test.txt");
	ofstream out("test_out.txt");
	int nrows, ncols, x;

	while (read >> nrows >> ncols && (nrows != 0 || ncols != 0)) {
        int m[nrows][ncols];
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                read >> x;
                m[i][j] = x;
            }
        }
        int dp[nrows][ncols];
        for (int j = 0; j < ncols; j++)
            dp[0][j] = (m[0][j] == 0) ? 1 : 0;
        for (int i = 1; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                dp[i][j] = (m[i][j] == 0) ? dp[i-1][j] + 1 : 0;
        for (int i = 0; i < nrows; i++) {

        }
	}
	out.close();
    read.close();
    return 0;
}
