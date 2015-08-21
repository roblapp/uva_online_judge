#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#define MAXN 25000

using namespace std;

int iabs(int x) { return (x < 0) ? -x : x; }

/* A function that compares two strings and determines if string
    a is one edit step from b */
bool compare(string& a, string& b) {
    int l0 = a.length();
    int l1 = b.length();

    if (l0 == l1) { /* if lengths are the same then check if one char is different */
        int ndiff = 0;
        for (int i = 0; i < l0 && ndiff < 2; i++) {
            if (a[i] != b[i]) ndiff++;
        }
        return (ndiff <= 1);
    } else if (iabs(l0 - l1) == 1) { /* lengths only differ by one char */
        int ndiff = 0, k = 0;
        if (l0 > l1) {
            for (int i = 0; i < l0 && k < l1 && ndiff < 2; i++) {
                if (a[i] == b[k]) k++;
                else ndiff++;
            }
            return (ndiff < 2 && k == l1);
        } else {
            for (int i = 0; i < l1 && k < l0 && ndiff < 2; i++) {
                if (b[i] == a[k]) k++;
                else ndiff++;
            }
            return (ndiff < 2 && k == l0);
        }
    }
    return false;
}

int main() {

    string line;
    vector<string> v;

    while (cin >> line) {
        v.push_back(line);
    }

    int dp[MAXN + 1];
    int N = v.size();
    int temp, soln = 1;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        temp = 1;
        for (int j = 0; j < i; j++) {
            if (compare(v[j], v[i]) && dp[j] + 1 > temp) {
                temp = dp[j] + 1;
            }
        }
        dp[i] = temp;
        if (temp > soln) soln = temp;
    }

    cout << soln << endl;

    return 0;
}
