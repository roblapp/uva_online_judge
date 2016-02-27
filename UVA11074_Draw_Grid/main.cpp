#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, output formatting
Algorithm: ad-hoc
*/

using namespace std;

int main() {
	int s, t, n, N = 1;

	while (cin >> s >> t >> n and (s != 0 or t != 0 or n != 0)) {
	    string verticle, inner;
        stringstream ssi(""), ss("");
        string wall(t, '*'), grid(s, '.');
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ssi << wall;
            ssi << grid << wall;
        }
        inner = ssi.str();
        verticle = string(n*s + (n+1)*t, '*');
        cout << "Case " << N++ << ":" << endl;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                for (int j = 0; j < t; j++)
                    ss << verticle << endl;
            for (int j = 0; j < s; j++)
                ss << inner << endl;
            for (int j = 0; j < t; j++)
                ss << verticle << endl;
        }
        cout << ss.str() << endl;
	}
    return 0;
}
