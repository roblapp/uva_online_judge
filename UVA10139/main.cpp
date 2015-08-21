#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

int factor(int x, vector<int>& factors) {
    int len = 0;
    while (x % 2 == 0) {
        factors.push_back(2);
        x /= 2;
        len++;
    }

    for (int i = 3; i <= sqrt(x); i += 2) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
            len++;
        }
    }

    if (x > 2) {
        factors.push_back(x);
        len++;
    }
    return len;
}

int main() {

    int a, b;
    vector <int> f;
    bool soln;

    while (cin >> a >> b) {

        int last_index = factor(b, f) - 1;



        if (soln) cout << b << " divides " << a << "!" << endl;
        else cout << b << " does not divide " << a << "!" << endl;

        f.clear();

    }
    return 0;
}
