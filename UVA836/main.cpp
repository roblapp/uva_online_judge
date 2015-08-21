#include <iostream>
#include <fstream>

/* ACCEPTED 0.032s */
/* hahahahaha with an O(N^6) solution */
/* I am going to try a dynamic programming solution later on. */

#define MAXN 25
#define in cin

using namespace std;

int main() {
        int n, len, N = 0;
        int nrows, ncols;
        string line;
        bool a[MAXN][MAXN];

        in >> n;
        getline(in, line); /* chew up remaining line */
        getline(in, line); /* chew up blank */

        while (n--) {
            if (N++) cout << endl;
            nrows = ncols = 0;
            while (1) {
                if (!getline(in, line) || (len = line.length()) == 0) break;
                ncols = len;
                for (int i = 0; line[i]; i++) {
                    if (line[i] == '0') {
                        a[nrows][i] = false;
                    } else {
                        a[nrows][i] = true;
                    }
                }
                nrows++;
            }

            int maxn = 0, temp;
            for (int i = 0; i < nrows; i++) {
                for (int j = 0; j < ncols; j++) {
                    for (int endr = i; endr < nrows; endr++) {
                        for (int endc = j; endc < ncols; endc++) {
                        temp = 0;
                        for (int k = i; k <= endr; k++) {
                                for (int l = j; l <= endc; l++) {
                                    if (a[k][l]) {
                                        temp++;
                                    } else {
                                        temp = 0;
                                        goto LOOP;
                                    }
                                }
                                if (temp > maxn) maxn = temp;
                            }
                            LOOP :;
                        }
                    }
                }
            }

            cout << maxn << endl;
        }

    return 0;
}
