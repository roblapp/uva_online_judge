#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/*
Accepted: 0.015s
Category: string processing, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

struct Entry {
    string name;
    int m, s, ms;
    Entry(string _name, int _m, int _s, int _ms) : name(_name), m(_m), s(_s), ms(_ms) {}
};

bool compare(Entry ea, Entry eb) {
    if (ea.m < eb.m) {
        return true;
    } else if (ea.m > eb.m) {
        return false;
    } else {
        if (ea.s < eb.s) {
            return true;
        } else if (ea.s > eb.s) {
            return false;
        } else {
            if (ea.ms < eb.ms) {
                return true;
            } else if (ea.ms > eb.ms) {
                return false;
            } else {
                return strcasecmp(ea.name.c_str(), eb.name.c_str()) < 0;
            }
        }
    }
}

int main() {
	int n, m, s, ms, N, row;
	char c;
	string name, mstr, sstr, msstr;

	while (cin >> n) {
        vector<Entry> v;
        while (n--) {
            cin >> name >> c >> m >> mstr >> s >> sstr >> ms >> msstr;
            v.push_back(Entry(name, m, s, ms));
        }
        sort(v.begin(), v.end(), compare);
        N = (int) v.size();
        row = 1;
        for (int i = 0; i < N; i += 2) {
            cout << "Row " << row++ << endl << v[i].name << endl;
            if (i + 1 < N)
                cout << v[i+1].name << endl;
        }
        cout << endl;
	}
    return 0;
}
