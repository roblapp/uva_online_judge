#include <cstdio>
#include <cstring>
#include <vector>

/*
Accepted: 0.000s
Category: string processing, encryption/decryption
Algorithm: ad-hoc
*/

using namespace std;

#define MAXN 210

int next(FILE *fp, char *s) {
    char c;
    int k = 0;
    fgetc(fp); /* read and discard the single empty char */
    while ((c = fgetc(fp)) != EOF and c != '\n')
        s[k++] = c;
    s[k] = 0;
    return k;
}

int main() {
	int n, k, x, cycle;
	char line[MAXN];

	while (scanf("%d", &n) == 1 and n != 0) {
        vector<int> v(n), cycleLen(n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            v[i]--;
        }
        /* now compute the cycle's */
        for (int i = 0; i < n; i++) {
            x = v[i], cycle = 1;
            while (x != i) {
                x = v[x];
                cycle++;
            }
            cycleLen[i] = cycle;
        }
        while (scanf("%d", &k) == 1 and k != 0) {
            int lastChar = next(stdin, line);
            for (int i = lastChar; i < n; i++) {
                line[i] = ' ';
            }
            line[n] = 0;

            int bound, index;
            char temp[MAXN];
            for (int i = 0; i < n; i++) {
                bound = k % cycleLen[i];
                index = i;
                for (int j = 0; j < bound; j++) {
                    index = v[index];
                }
                temp[index] = line[i];
            }
            temp[n] = 0;
            strcpy(line, temp);
            printf("%s\n", line);
        }
        printf("\n");
	}
    return 0;
}
