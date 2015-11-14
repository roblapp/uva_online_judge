#include <iostream>
#include <cstdio>
#include <cstring>

/*
Accepted: 0.000s
Description: ad-hoc/1D array processing
Info: Since the strings are short (<100) I figure why
bother to reverse the string in place and just do the
easy thing and have another array.
*/

#define MAXLEN 100

using namespace std;

int main() {
    int n, pos, i, j, k, groupLen, len;
    char line[MAXLEN + 1];
    char rev[MAXLEN + 1];
    while (scanf("%i", &n) && n != 0) {
        scanf("%s", line);
        len = strlen(line);
        groupLen = len / n;
        pos = groupLen;
        k = 0;
        while (pos <= len) {
            j = 0;
            for (i = pos - 1; j < groupLen; i--, j++)
                rev[k++] = line[i];
            pos += groupLen;
        }
        rev[k] = 0;
        printf("%s\n", rev);
    }
    return 0;
}
