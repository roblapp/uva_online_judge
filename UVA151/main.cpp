#include <iostream>
#include <cstring>

/*
Accepted: 0.000s
Algorithm: ad hoc
Description: Simply run the simulation as described in the problem description.
Things to look out for: make sure the minimal number m can be larger than n!
*/

#define MAX_REGIONS 100

using namespace std;

int nextIndex(bool used[], int index, int m, int n) {
    int cnt = 0;
    int temp = index;
    while (cnt < m) {
        temp = (temp + 1) % n;
        if (!used[temp]) cnt++;
    }
    return temp;
}

bool isOneStationLeft(bool used[], int n) {
    int cnt = 0;
    for (int i = 0; cnt < 2 && i < n; i++) if (!used[i]) cnt++;
    return (cnt == 1);
}

int getLastStationLeft(bool used[], int n) {
    for (int i = 0; i < n; i++) if (!used[i]) return (i + 1);
    return (-1);
}

int main() {
    bool used[MAX_REGIONS];
    int n;
    int index;
    int i;
    while (cin >> n && n != 0) {
        i = 2;
        if (n == 13) {
            cout << "1" << endl;
        } else {
            while (1) {
                memset(used, false, sizeof(used));
                index = 0;
                used[index] = true;
                while (!isOneStationLeft(used, n)) {
                    if (index == 12) {
                        break;
                    }
                    index = nextIndex(used, index, i, n);
                    used[index] = true;
                }
                if (index != 12 && getLastStationLeft(used, n) == 13) {
                    cout << i << endl;
                    break;
                }
                i++;
            }
        }
    }
    return 0;
}
