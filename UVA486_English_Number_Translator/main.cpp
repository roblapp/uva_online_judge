#include <iostream>
#include <map>
#include <sstream>

/*
Accepted: 0.012s
Category: string processing, parsing
Algorithm: parsing
*/

using namespace std;

void initMap(map<string, int> &m) {
    int N = 32;
    string keys[] = {"negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                    "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand",
                    "million"};
    int values[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80,
                    90, 100, 1000, 1000000};
    for (int i = 0; i < N; i++) {
        m[keys[i]] = values[i];
    }
}

int main() {
	string line, token;
	map<string, int> m;

	initMap(m);
    while (getline(cin, line)) {
        stringstream ss(line);
        int res = 0, temp = 0, value;
        bool isNegative = false;
        while (ss >> token) {
            value = m[token];
            if (value == -1) {
                isNegative = true;
            } else if (value == 1000 or value == 1000000) { /* take temp and multiply it */
                temp *= value;
                res += temp;
                temp = 0;
            } else if (value == 100) {
                temp *= 100;
            } else if (value == 0) {

            } else {
                temp += value;
            }
        }
        res += temp;
        if (isNegative) {
            res *= -1;
        }
        cout << res << endl;
	}
    return 0;
}
