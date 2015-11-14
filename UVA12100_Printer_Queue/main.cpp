#include <iostream>
#include <deque>

/*
Accepted: 0.000s
Description: data structures - a double ended queue
*/

#define read cin
#define MAXN 10

using namespace std;

struct PrintJob {
    int priority;
    bool isMyJob;
};

int main() {
    int ncases, njobs, mypos, x, cnt;
    bool solnFound;
    deque<PrintJob> q;
    PrintJob p;
    int a[MAXN];
    read >> ncases;
    while (ncases--) {
        q.clear();
        for (int i = 0; i < MAXN; i++) a[i] = 0;
        read >> njobs >> mypos;
        for (int i = 0; i < njobs; i++) {
            read >> x;
            p.priority = x;
            p.isMyJob = (i == mypos);
            q.push_back(p);
            a[x]++;
        }
        cnt = 0;
        solnFound = false;
        LOOP : for (int i = MAXN - 1; i >= 1 && !solnFound; i--) {
            while (a[i] > 0) {
                p = q.front();
                if (p.priority == i) {
                    q.pop_front();
                    a[i]--;
                    cnt++;
                    if (p.isMyJob) {
                        solnFound = true;
                        goto LOOP;
                    }
                } else {
                    q.push_back(q.front());
                    q.pop_front();
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
