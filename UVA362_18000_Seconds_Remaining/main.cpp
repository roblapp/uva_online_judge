#include <iostream>
#include <cstdio>
#include <cmath>

#define read cin

using namespace std;

int main() {
    int nbytes, bytesread, bytesthisfive, N = 1, cnt;
    while (read >> nbytes and nbytes != 0) {
        cnt = bytesthisfive = 0;
        printf("Output for data set %i, %i bytes:\n", N++, nbytes);
        while (nbytes > 0) {
            read >> bytesread;
            nbytes -= bytesread;
            bytesthisfive += bytesread;
            cnt++;
            if (cnt % 5 == 0) {
                if (bytesthisfive == 0) {
                    printf("   Time remaining: stalled\n");
                } else {
                    printf("   Time remaining: %.0f seconds\n", ceil(nbytes/(bytesthisfive*0.2)));
                    bytesthisfive = 0;
                }
            }
        }
        printf(   "Total time: %i seconds\n\n", cnt);
    }
    return 0;
}
