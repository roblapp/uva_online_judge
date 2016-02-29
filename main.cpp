#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	int ncases;
	char c;
	string line;

	cin >> ncases;
	for (int i = 1; i <= ncases; i++) {
        cin >> line;
        int j = 0, N = line.length();
        stringstream ss("");
        while (j < N) {
            c = line[j++];
            int x = 0;
            while (j < N and isdigit(line[j])) {
                x = 10*x + (line[j] - '0');
                j++;
            }
            ss << string(x, c);
        }
        cout << "Case " << i << ": " << ss.str() << endl;
	}
    return 0;
}
