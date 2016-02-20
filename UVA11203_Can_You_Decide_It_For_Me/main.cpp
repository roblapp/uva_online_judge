#include <iostream>

/*
Accepted: 0.000s
Category: string processing, frequency counting
Algorithm: string processing, frequency counting, ad-hoc
*/

using namespace std;

bool scanAndCountFreq(string &line, int &i, int N, char delimiter, int &freq) {
    freq = 0;
    while (i < N and line[i] != delimiter) {
        if (line[i] == '?')
            freq++;
        else
            return false;
        i++;
    }
    return true;
}

bool parse(string &line) {
    int i = 0, N = line.length(), fa = 0, fb = 0, fc = 0;
    if (!scanAndCountFreq(line, i, N, 'M', fa) or i >= N or fa == 0)
        return false;
    i++;
    if (!scanAndCountFreq(line, i, N, 'E', fb) or i >= N or fb == 0)
        return false;
    i++;
    if (!scanAndCountFreq(line, i, N, 0, fc) or fc == 0)
        return false;
    if (i != N)
        return false;
    fc -= fa;
    if (fc <= 0)
        return false;
    return (fb == fc);
}

int main() {
	int ncases;
	string line;

	cin >> ncases;
	while (ncases--) {
        cin >> line;
        parse(line) ? cout << "theorem" << endl : cout << "no-theorem" << endl;
	}
    return 0;
}
