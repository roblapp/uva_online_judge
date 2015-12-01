#include <iostream>
#include <queue>

/*
Accepted: 0.082s
Description: data structures - priority queues
*/

using namespace std;

#define read cin
#define out cout

void clearQueue(priority_queue<int> &q) {
    while (!q.empty())
        q.pop();
}

int main() {
    int ncases, b, sa, sb, x, bound;
    priority_queue<int> qa, qb;

    read >> ncases;
    while (ncases--) {
        read >> b >> sa >> sb;
        clearQueue(qa); clearQueue(qb);
        for (int i = 0; i < sa; i++) {
            read >> x;
            qa.push(x);
        }
        for (int i = 0; i < sb; i++) {
            read >> x;
            qb.push(x);
        }
        vector<int> v;
        int len;
        while (!qa.empty() && !qb.empty()) {
            v.clear();
            len = 0;
            bound = min((int) qa.size(), min((int) qb.size(), b));
            for (int i = 0; i < bound; i++) {
                v.push_back(qa.top()); qa.pop();
                v.push_back(qb.top()); qb.pop();
                len += 2;
            }
            for (int i = 0; i < len - 1; i += 2) {
                if (v[i] > v[i+1]) {
                    qa.push(v[i] - v[i+1]);
                } else if (v[i] < v[i+1]) {
                    qb.push(v[i+1] - v[i]);
                } /* else they're equal, do not push a 0 to the queue */
            }
        }
        if (qa.empty()) {
            if (qb.empty()) {
                out << "green and blue died" << endl;
            } else {
                out << "blue wins" << endl;
                while (!qb.empty()) {
                    out << qb.top() << endl;
                    qb.pop();
                }
            }
        } else {
            out << "green wins" << endl;
            while (!qa.empty()) {
                out << qa.top() << endl;
                qa.pop();
            }
        }
        if (ncases)
            out << endl;
    }
    return 0;
}
