#include <iostream>
#include <cstdio>
#include <cstring>

/*
Accepted: 0.013s
Description: ad-hoc
*/

#define MAXLEN 4
#define MAXLINE 100

using namespace std;

bool isUnEncodedLetter(char c) {
    return c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'
        or c == 'Y' or c == 'W' or c == 'H';
}

char getCode(char c) {
    if (c == 'B' or c == 'P' or c == 'F' or c == 'V') return '1';
    else if (c == 'C' or c == 'S' or c == 'K' or c == 'G' or c == 'J' or c == 'Q' or c == 'X' or c == 'Z') return '2';
    else if (c == 'D' or c == 'T') return '3';
    else if (c == 'L') return '4';
    else if (c == 'M' or c == 'N') return '5';
    else if (c == 'R') return '6';
    return c;
}

void print(char *name, char *soln) {
    int i;
    for (i = 1; i <= 9; i++) putchar(' ');
    int len = strlen(name);
    for (i = 0; i < len; i++) putchar(name[i]);
    len = 10 + len;
    for (i = len; i < 35; i++) putchar(' ');
    printf("%s\n", soln);
}

void printEnd() {
    int i;
    for (i = 1; i <= 19; i++) putchar(' ');
    printf("END OF OUTPUT\n");
}

int main() {
    int i, index, len;
    bool split, first = true;
    char c;
    char name[MAXLINE];
    char encode[MAXLEN + 1];
    while (scanf("%s", name) != EOF) {
        if (first) print("NAME", "SOUNDEX CODE");
        index = 0;
        encode[index++] = name[0];
        split = false;
        for (i = 1, len = strlen(name); i < len and index < MAXLEN; i++) {
            if (isUnEncodedLetter(name[i])) {
                split = true;
            } else {
                c = getCode(name[i]);
                if (getCode(encode[index-1]) == c and not split) ;
                else encode[index++] = c;
                split = false;
            }
        }
        for (i = index; i < MAXLEN; i++) encode[i] = '0';
        encode[MAXLEN] = 0;
        print(name, encode);
        first = false;
    }
    printEnd();
    return 0;
}
