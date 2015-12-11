#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
#include <iomanip>

/*
Accepted: 0.049s
Description: brute force closest pair problem
Info: an N^2 algorithm worked... Surely there has to be a better way
      to solve this problem. Ideas?
*/

using namespace std;

#define read cin

class Point {
public:
    int x, y, z;
    int distance(Point p) {
        int dx = x - p.x;
        int dy = y - p.y;
        int dz = z - p.z;
        return dx*dx + dy*dy + dz*dz;
    }
};

int main() {
    int x, y, z;
    vector<Point> v;
    int freq[10];
    Point p;

    memset(freq, 0, sizeof(freq));
    while (read >> x >> y >> z && (x != 0 || y != 0 || z != 0)) {
        p.x = x;
        p.y = y;
        p.z = z;
        v.push_back(p);
    }
    int tempDist, minDist;
    for (int i = 0, len = v.size(); i < len; i++) {
        minDist = INT_MAX;
        for (int j = 0; j < len; j++) {
            if (i != j) {
                tempDist = v[i].distance(v[j]);
                if (tempDist < minDist) {
                    minDist = tempDist;
                }
            }
        }
       tempDist = (int) sqrt(minDist);
        if (tempDist < 10)
            freq[tempDist]++;
    }
    for (int i = 0; i < 10; i++)
        cout << setw(4) << freq[i];
    cout << endl;
    return 0;
}
