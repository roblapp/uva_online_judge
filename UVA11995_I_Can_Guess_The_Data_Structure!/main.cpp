#include <iostream>
#include <stack>
#include <queue>

/*
Accepted: 0.029s
Description: data structures - stack, queue, priority queue, ad-hoc
*/

using namespace std;

#define read cin

void clearPQ(priority_queue<int> &pq) {
    while (!pq.empty())
        pq.pop();
}

void clearStack(stack<int> &s) {
    while (!s.empty())
        s.pop();
}
void clearQ(queue<int> &q) {
    while (!q.empty())
        q.pop();
}

int main() {
    priority_queue<int> pq;
    queue<int> q;
    stack<int> s;
    bool ispq, isq, iss;
    int n, x, y, pqe, qe, se;

    while (read >> n) {
        clearPQ(pq); clearStack(s); clearQ(q);
        ispq = isq = iss = true;
        for (int i = 0; i < n; i++) {
            read >> x >> y;
            if (x == 1) {
                pq.push(y);
                s.push(y);
                q.push(y);
            } else {
                if (pq.empty()) {
                    ispq = false;
                } else if (ispq) {
                    pqe = pq.top(); pq.pop();
                    if (y != pqe)
                        ispq = false;
                }
                if (q.empty()) {
                    isq = false;
                } else if (isq) {
                    qe = q.front(); q.pop();
                    if (y != qe)
                        isq = false;
                }
                if (s.empty()) {
                    iss = false;
                } else if (iss) {
                    se = s.top(); s.pop();
                    if (y != se)
                        iss = false;
                }
            }
        }
        if (ispq) {
            if (isq || iss)
                cout << "not sure" << endl;
            else
                cout << "priority queue" << endl;
        } else if (isq) {
            if (iss)
                cout << "not sure" << endl;
            else
                cout << "queue" << endl;
        } else if (iss) {
            cout << "stack" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}
