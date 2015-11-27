#include <iostream>
#include <set>
#include <cstring>
#include <cstdio>
 
/*
Accepted: 0.019s
Description: ad-hoc
*/
 
#define read cin
#define MAX_FRIENDS 50
#define MAXN 10000 + 1
#define FOR(start,end,increment) for (int i = start; i < end; i += increment)
 
using namespace std;
 
typedef struct {
    int owner, numOwners;
} Entry;
 
 
int main() {
    int ncases, nfriends, nstamps, x;
    Entry f[MAXN];
    set<int> collection[MAX_FRIENDS];
 
    read >> ncases;
    for (int i = 1; i <= ncases; i++) {
        read >> nfriends;
        memset(f, 0, sizeof(f));
        for (int j = 0; j < MAXN; j++) {
            f[j].owner = -1;
            f[j].numOwners = 0;
        }
        for (int j = 0; j < nfriends; j++) {
            read >> nstamps;
            collection[j].clear();
            for (int k = 0; k < nstamps; k++) {
                read >> x;
               collection[j].insert(x);
                if (f[x].owner == -1) {
                    f[x].owner = j;
                    f[x].numOwners = 1;
                }
                if (f[x].owner != j)
                    f[x].numOwners++;
            }
        }
        int sum = 0, howMany;
        for (int j = 0; j < MAXN; j++)
            if (f[j].numOwners == 1)
                sum++;
        printf("Case %i:", i);
        if (sum == 0)
            sum = 1;
        for (int j = 0; j < nfriends; j++) {
            howMany = 0;
            for (set<int>::iterator it = collection[j].begin(); it != collection[j].end(); it++)
                if (f[*it].numOwners == 1)
                    howMany++;
            printf(" %.6lf%%", 100*(1.0*howMany/sum));
        }
        putchar('\n');
    }
    return 0;
}
