#include <iostream>
#include <string>
#include <math.h>

/* ACCEPTED 0.015s */

#define DIFF 48

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void reverse(string& x) {
    int len = x.length();
    int bound = len >> 1;
    for (int i = 0; i < bound; i++) {
        char temp = x[i];
        x[i] = x[len - i - 1];
        x[len - i - 1] = temp;
    }
}

string add(string& x, string& y) {
    int len0 = x.length();
    int len1 = y.length();

    int n = max(len0, len1);
    int rem = 0;
    int digit0, digit1, last_non_zero;

    char res[n + 2];

    len0--;
    len1--;

    for (int i = 0; i <= n; i++) {
        if (len0 >= 0) {
            digit0 = x[len0--] - DIFF;
        } else {
            digit0 = 0;
        }

        if (len1 >= 0) {
            digit1 = y[len1--] - DIFF;
        } else {
            digit1 = 0;
        }

        int sum = digit0 + digit1 + rem;

        res[i] = (sum % 10) + DIFF;

        if (sum % 10 != 0) last_non_zero = i;

        rem = sum / 10;
    }

    string r(res, last_non_zero + 1);

    return r;

}

void show(string s) {
    int len = s.length();
    int i;
    for (i = 0; i < len && s[i] == '0'; i++);
    for ( ; i < len; i++) cout << s[i];
    cout << endl;
}

int main() {
    int ncases;
    string a, b;

    cin >> ncases;

    for (int i = 0; i < ncases; i++) {
        cin >> a >> b;

        reverse(a);
        reverse(b);

        string r = add(a, b);

        show(r);
    }


    return 0;
}
