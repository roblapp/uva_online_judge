#include <iostream>

/*
Accepted: 0.000s
Category: ad-hoc, counting
*/

using namespace std;

#define NALPHA 5
#define MAXN 100

struct Data {
    int i, v, x, l, c;
    Data() : i(0), v(0), x(0), l(0), c(0) {}
};

int getArrayIndex(char c) {
    if (c == 'i') return 0;
    else if (c == 'v') return 1;
    else if (c == 'x') return 2;
    else if (c == 'l') return 3;
    return 4;
}

void countRomanNumerals(int f[], int x) {
    if (x == 0) return;
    if (x == 100) {
        f[getArrayIndex('c')]++;
        return;
    }
    if (x <= 10) {
        if (x == 4) {
            f[getArrayIndex('i')]++;
            f[getArrayIndex('v')]++;
        } else if (x == 9) {
            f[getArrayIndex('i')]++;
            f[getArrayIndex('x')]++;
        } else if (x < 5) {
            f[getArrayIndex('i')] += x;
        } else if (x == 10) {
            f[getArrayIndex('x')]++;
        } else {
            f[getArrayIndex('i')] += (x-5);
            f[getArrayIndex('v')]++;
        }
    } else {
        int temp = x/10*10;
        if (temp == 40) {
            f[getArrayIndex('x')]++;
            f[getArrayIndex('l')]++;
        } else if (temp == 90) {
            f[getArrayIndex('x')]++;
            f[getArrayIndex('c')]++;
        } else if (x < 50) {
            f[getArrayIndex('x')] += (x/10);
        } else {
            f[getArrayIndex('l')]++;
            f[getArrayIndex('x')] += (x/10 - 5);
        }
        countRomanNumerals(f, x%10);
    }
}

int main() {
	int x;
	int f[NALPHA] = {0};
	Data d[MAXN + 1];

	for (int i = 1; i <= MAXN; i++) {
        countRomanNumerals(f, i);
        d[i].i = f[getArrayIndex('i')];
        d[i].v = f[getArrayIndex('v')];
        d[i].x = f[getArrayIndex('x')];
        d[i].l = f[getArrayIndex('l')];
        d[i].c = f[getArrayIndex('c')];
	}
    while (cin >> x and x != 0)
        cout << x << ": " << d[x].i << " i, " << d[x].v << " v, " << d[x].x << " x, " << d[x].l << " l, " << d[x].c << " c" << endl;

    return 0;
}
