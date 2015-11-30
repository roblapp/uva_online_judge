#include <iostream>
#include <set>
#include <fstream>

using namespace std;

//#define read cin

int main() {
    ifstream read("test.txt");
    int n, x, y, sum;
    multiset<int> s;
    multiset<int>::iterator it;
    multiset<int>::reverse_iterator rit;

    while (read >> n && n != 0) {
        sum = 0;
        s.clear();
        for (int i = 0; i < n; i++) {
            read >> x;
            for (int j = 0; j < x; j++) {
                read >> y;
                cout << "added " << y << endl;
                s.insert(y);
            }
            for (multiset<int>::iterator t = s.begin(); t != s.end(); t++) {
                cout << '\t' << *t << endl;
            }

            it = s.begin();
            cout << "FRONT " << *it << endl;
            rit = s.rbegin();
            cout << "BACK ELEMENT " << *rit << endl;
            sum += *it - *rit;
            s.erase(it);
            s.erase(*rit);
            cout << endl;
            for (multiset<int>::iterator t = s.begin(); t != s.end(); t++) {
                cout << '\t' << *t << endl;
            }
        }
        cout << sum << endl;
    }
    read.close();
    return 0;
}
