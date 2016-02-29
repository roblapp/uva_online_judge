#include <iostream>
#include <sstream>

using namespace std;

#define MAXN 10000

int main() {
	int ncases, len;
	string line;
	int isSquare[MAXN + 1] = {0};

	for (int i = 1; i <= 100; i++)
        isSquare[i*i] = i;

    cin >> ncases; getline(cin, line); /* drain newline */
    while (ncases--) {
        getline(cin, line);
        len = line.length();
        if (!isSquare[len]) {
            cout << "INVALID" << endl;
        } else {
            int N = isSquare[len];
            stringstream ss("");
            for (int offset = 0; offset < N; offset++)
                for (int col = 0; col < len; col += N)
                    ss << line[col + offset];
            cout << ss.str() << endl;
        }
    }
    return 0;
}
