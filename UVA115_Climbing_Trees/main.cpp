
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED 0.013s */

#define MAXNAMES 350

using namespace std;

int parent[MAXNAMES];
bool visited[MAXNAMES];
int dist[MAXNAMES];

void no_relation() { cout << "no relation" << endl; }

void parent_child_relation( int m, int type ) {

    if ( m > 1 ) {
        for ( int i = 0; i < m - 1; i++ ) {
            cout << "great ";
        }
    }
    if ( m > 0 ) {
        cout << "grand ";
    }
    string label[] = {"parent", "child"};
    cout << label[type] << endl;
}

void cousin_relation( int k, int j ) {
    if ( k == 0 && j == 0 ) {
        cout << "sibling" << endl;
    } else if ( j == 0 ) {
        cout << k << " cousin" << endl;
    } else {
        cout << k << " cousin removed " << j << endl;
    }
}
/* checks if p is a cousin of q */
bool is_cousin( int p, int q, int *k, int *j ) {
    memset( visited, false, sizeof( visited ) );
    memset( dist, -1, sizeof( dist ) );
    int m = -1, n = 0;
    while ( parent[p] != -1 ) {
        visited[parent[p]] = true;
        m++;
        dist[parent[p]] = m;
        p = parent[p];
    }
    if ( m == -1 ) return false;
    while ( parent[q] != -1 && !visited[parent[q]] ) {
        q = parent[q];
        n++;
    }
    if ( parent[q] == -1 ) return false;
    int d = dist[parent[q]]; /* obtain the distance to least common ancestor */
    *j = *k = 0;
    *k = min( n, d );
    *j = abs( n - d );
    return true;
}

/* checks if p is a child of q */
bool is_childof( int p, int q, int *m ) {
    if ( parent[p] == q ) {
        return true;
    }
    if ( parent[p] == -1 ) {
        return false;
    }
    *m = *m + 1;
    if ( is_childof( parent[p], q, m ) ) {
        return true;
    }
    return false;
}

bool is_parentof( int p, int q, int *m ) {
    return is_childof( q, p, m );
}

void find_relation(int p, int q) {
    int m = 0;
    if ( is_parentof( p, q, &m ) ) {
        parent_child_relation( m, 0 );
        return;
    }
    m = 0;
    if ( is_childof( p, q, &m ) ) {
        parent_child_relation( m, 1 );
        return;
    }
    int j = 0, k = 0;
    if ( is_cousin( p, q, &k, &j ) ) {
        cousin_relation( k, j );
    } else {
        no_relation();
    }
 }

int main() {
    string p, q;
    map indexer;
    int i = 0, pi, qi;
    pair::iterator,bool> ret;
    indexer["no.child"] = -1, indexer["no.parent"] = -1;
    memset( parent, -1, sizeof( parent ) );
    while ( cin >> p >> q ) {
        ret = indexer.insert( pair( p, i ) );
        if ( ret.second == true ) {
            i++;
        }
        ret = indexer.insert( pair( q, i ) );
        if ( ret.second == true ) {
            i++;
        }
        pi = indexer[p];
        qi = indexer[q];
        if ( pi == -1 && qi == -1 ) break;
        parent[pi] = qi;
    }
    while ( cin >> p >> q ) {
        if ( indexer.count( p ) == 0 || indexer.count( q ) == 0 || indexer[p] == indexer[q] ) {
            no_relation();
        } else {
            find_relation(indexer[p],indexer[q]);
        }
    }
    return 0;
}