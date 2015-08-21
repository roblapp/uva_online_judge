#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <string.h>

/* ACCEPTED 0.496 */

using namespace std;

void clear_stack( stack<int> &st ){
    while ( !st.empty() ){
        st.pop();
    }
}

int main() {
    int ncases, ne;
    string line;
    map<string,int> indexer;
    cin >> ncases;

    for ( int i = 0; i < ncases; i++ ) {
        cin >> ne;
        cin.ignore();
        int a[ne], b[ne];
        string db[ne];
        bool used[ne + 1];
        memset( used, false, sizeof( used ) );
        for ( int j = 0; j < ne; j++ ) {
            getline( cin, line );
            indexer[line] = j;
            a[j] = j;
            db[j] = line;
        }
        for ( int j = 0; j < ne; j++ ) {
            getline( cin, line );
            b[j] = indexer[line];
        }
        stack<int> st;
        for ( int j = 0, k = 0; j < ne && k < ne; j++ ) {
            if ( !used[j] ) {
                if ( a[j] == b[k] ) {
                    k++;
                    continue;
                } else {
                    clear_stack( st );
                    for ( int x = 0; x < k; x++ ) {
                        st.push( b[x] );
                        used[ b[x] ] = true;
                    }
                    while ( b[k] != a[j] ) {
                        st.push( b[k] );
                        used[ b[k] ] = true;
                        k++;
                    }
                }
                k++;
            }
        }
        while ( !st.empty() ) {
                int x = st.top();
                cout << db[x] << endl;
                st.pop();
            }
            cout << endl;
    }
    return 0;
}

/* VERSION 2 */
/* ACCEPTED 0.502 */

/*
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

struct entry {
    int x, y;
};

bool compare( const entry &a, const entry &b ) {
    return (a.y < b.y ) ? false : true;
}

int main() {
    int ncases, ne;
    string line;
    cin >> ncases;

    for ( int i = 0; i < ncases; i++ ) {
        cin >> ne;
        cin.ignore();
        map<string,int> indexer;
        string db[ne];
        int b[ne];
        vector<entry> result;
        for ( int j = 0; j < ne; j++ ) {
            getline( cin, line );
            indexer[line] = j;
            db[j] = line;
        }
        for ( int j = 0; j < ne; j++ ) {
            getline( cin, line );
            b[ indexer[line] ] = j;
        }

        int nwp = 0;
        for ( int j = ne - 1; j >= 0; j-- ) {
            if ( b[j] - j != nwp ) {
                nwp++;
                entry e;
                e.x = j;
                e.y = b[j];
                result.push_back( e );
            }
        }

        sort( result.begin(), result.end(), compare );
        for ( vector<entry>::iterator it = result.begin(); it != result.end(); it++ ) {
            entry e = *it;
            cout << db[e.x] << endl;
        }
        cout << endl;
    }
    return 0;
}
*/


