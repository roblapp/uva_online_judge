#include <iostream>
#include <deque>
#include <vector>

/*
Accepted: 0.000s
Description: data structures - queue
*/

#define read cin

using namespace std;

int main() {
    int n;
    deque<int> q;
    vector<int> v;
    while (read >> n && n != 0) {
        q.clear(); v.clear();
        for (int i = 1; i <= n; i++) q.push_back(i);
        while (q.size() != 1) {
            v.push_back(q.front());
            q.pop_front();
            q.push_back(q.front());
            q.pop_front();
        }
        cout << "Discarded cards:";
        for (int i = 0; i < n - 1; i++)
            (i == 0) ? cout << " " << v[i] : cout << ", " << v[i];
        cout << endl << "Remaining card: " << q.front() << endl;
    }
    return 0;
}
