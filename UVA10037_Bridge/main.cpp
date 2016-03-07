#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

/*
Accepted: 0.016s
Category: Sorting
Algorithm: Sorting, greedy
Info: at each step we must determine what the cheapest way to get the 2 slowest people
across will be. Suppose we have the following people (sorted in ascending order based on time):
A, B, C, D
At each step we must ask is it cheaper to have A, B shuttle, A returns, C, D shuttle, B returns,
so the cost, C = B + A + D + B = 2*B + A + D
OR
A, D shuttle, A returns, A, C shuttle, A returns, so the cost, C = D + A + C + A = 2*A + C + D
At each step we choose the cheapest process.
Note: There are special cases that happen when the number of remaining people = 1, 2 and 3.
We can use the above equality but must make sure to not sum the cost of 4 people when less exist.
In the code below if the number of people = 3 we DO use the inequality to determine the cheapest cost,
which may be wrong (since there aren't 4 people which is what the inequality calls for)  but we check
to make sure that there is at least 1 person (SIZE > 0 in the code) before sending the final person back
to shuttle more people.
*/

using namespace std;

struct Data {
    int x, y;
    Data(int _x, int _y) : x(_x), y(_y) {}
};

int main() {
	int ncases, nelements, x, sum, lastIndex, SIZE, N = 0;

	cin >> ncases;
	while (ncases--) {
        cin >> nelements;
        deque<int> dq;
        for (int i = 0; i < nelements; i++) {
            cin >> x;
            dq.push_back(x);
        }
        sort(dq.begin(), dq.end());
        sum = 0;
        vector<Data> soln;
        while (!dq.empty()) {
            SIZE = (int) dq.size();
            lastIndex = SIZE - 1;
            if (SIZE == 1) {
                sum += dq[0];
                soln.push_back(Data(dq[0], -1));
                dq.pop_back();
            } else if (SIZE == 2) {
                sum += dq[1];
                soln.push_back(Data(dq[0], dq[1]));
                dq.pop_back(); dq.pop_back();
            } else {
                if (2*dq[0] + dq[lastIndex] + dq[lastIndex-1] < 2*dq[1] + dq[0] + dq[lastIndex]) {
                    soln.push_back(Data(dq[0], dq[lastIndex-1]));
                    soln.push_back(Data(dq[0], -1));
                    soln.push_back(Data(dq[0], dq[lastIndex]));
                    sum += dq[0] + dq[lastIndex] + dq[lastIndex-1];
                    dq.pop_back(); dq.pop_back();
                    if (dq.size() == 1) {
                        dq.pop_back();
                    } else {
                        soln.push_back(Data(dq[0], -1));
                        sum += dq[0];
                    }
                } else {
                    soln.push_back(Data(dq[0], dq[1]));
                    soln.push_back(Data(dq[0], -1));
                    soln.push_back(Data(dq[lastIndex-1], dq[lastIndex]));
                    sum += dq[1] + dq[0] + dq[lastIndex];
                    dq.pop_back(); dq.pop_back();
                    if (dq.size() == 1) {
                        dq.pop_back();
                    } else {
                        soln.push_back(Data(dq[1], -1));
                        sum += dq[1];
                    }
                }
            }
        }
        if (N++)
            cout << endl;
        cout << sum << endl;
        for (int i = 0; i < (int) soln.size(); i++) {
            if (soln[i].y == -1)
                cout << soln[i].x << endl;
            else
                cout << soln[i].x << " " << soln[i].y << endl;
        }
	}
    return 0;
}
