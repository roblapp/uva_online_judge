#include <iostream>

/*
Accepted: 0.000s
Category: string processing, parsing
Algorithm: parsing, ad-hoc math
*/

using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

void parse(string &s, int &tempNum, int &tempDen) {
    int i = 0, N = s.length();
    tempNum = tempDen = 1;
    while (i < N) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = 10*num + (s[i] - '0');
                i++;
            }
            int temp = 0;
            bool readImproper = false;
            if (s[i] == '-') {
                i++;
                while (isdigit(s[i])) {
                    temp = 10*temp + (s[i] - '0');
                    i++;
                    readImproper = true;
                }
            }
            int den = 0;
            if (s[i] == '/') {
                i++;
                while (isdigit(s[i])) {
                    den = 10*den + (s[i] - '0');
                    i++;
                }
                if (readImproper) /* improper fraction was read */
                    num = den*num + temp;
            }
            if (den == 0)
                den++;
            tempNum *= num;
            tempDen *= den;
        } else {
            i++;
        }
    }
}

int main() {
	int n, num, den;
	string line;

	cin >> n; getline(cin, line); /* drain newline */
	while (n--) {
        getline(cin, line);
        parse(line, num, den);
        if (num == 0) {
            cout << num << endl;
        } else if (num < den) {
            int scale = gcd(num, den);
            cout << num/scale << "/" << den/scale << endl;
        } else {
            int tempNum = num/den, tempDen = num%den;
            if (tempDen == 0) {
                cout << tempNum << endl;
            } else {
                int scale = gcd(num, den);
                cout << tempNum << "-" << (tempDen/scale) << "/" << (den/scale) << endl;
            }
        }
	}
    return 0;
}
