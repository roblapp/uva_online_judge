#include <iostream>
#include <map>
#include <string>

/* ACCEPTED 0.009 */

using namespace std;

struct data {
    int original, cv;
};

int main() {
    int i, j, nc, cv, npg, N = 0;
    string s, t;
    map<string,data> m;
    while ( cin >> nc ) {
        string db[nc];
        for ( i = 0; i < nc; i++ ) {
            cin >> s;
            data d;
            d.original = d.cv = 0;
            m[s] = d;
            db[i] = s;
        }
        for ( i = 0; i < nc; i++ ) {
            cin >> s >> cv >> npg;
            m[s].original = cv;
            if ( npg > 0 ) m[s].cv += (cv % npg);
            else m[s].cv += cv;
            for ( j = 0; j < npg; j++ ) {
                cin >> t;
                m[t].cv += (cv / npg);
            }
        }
        if ( N++ ) cout << endl;
        for ( i = 0; i < nc; i++ ) {
            cout << db[i] << " " << m[db[i]].cv - m[db[i]].original << endl;
        }
        m.clear();
    }
    return 0;
}
