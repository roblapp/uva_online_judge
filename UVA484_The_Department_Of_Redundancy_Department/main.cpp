#include <iostream>
#include <map>
#include <vector>

/*
Accepted: 0.012s
Description: ad-hoc
*/

using namespace std;

int main() {
    int x;
    map<int, int> m;
    map<int, int>::iterator it;
    vector<int> v;
    while (cin >> x) {
        it = m.find(x);
        if (it == m.end()) {
            m[x] = 1;
            v.push_back(x);
        }
        else it->second = it->second + 1;
    }
    for (vector<int>::iterator vit = v.begin(); vit != v.end(); vit++) {
        cout << *vit << " " << m[*vit] << endl;
    }
    return 0;
}
