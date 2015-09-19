#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

/*
Accepted 0.053s
Algorithm: 2d geometry, dynamic programming(ish)
The idea: try every arrangement of the circles and take the smallest width over
each arrangement. This works since there is at most 8 circles per test case and
at most 50 test cases. You cannot simply compute the distance between the circles.
You must compute how far along the x-axis each circle is by keeping track of the
center of each circle.
Tips: watch out for circles that are very small that can fit underneath larger circles!
*/

using namespace std;

double computeDist(double r0, double r1) {
    double hyp = r0 + r1, opp = max(r0, r1) - min(r0, r1);
    return (sqrt(hyp*hyp - opp*opp));
}

double solve(vector<double> radii) {
    int i, j, len = radii.size();
    double maxCenter, dist;
    vector<double> centers(len);
    centers[0] = radii[0];
    for (i = 1; i < len; i++) {
        maxCenter = 0;
        for (j = 0; j < i; j++) {
            dist = centers[j] + computeDist(radii[j], radii[i]);
            if (dist > maxCenter) {
                maxCenter = dist;
            }
        }
        centers[i] = max(radii[i], maxCenter);
    }
    maxCenter = 0;
    for (i = 0; i < len; i++) {
        if (centers[i] + radii[i] > maxCenter) {
            maxCenter = centers[i] + radii[i];
        }
    }
    return maxCenter;
}

int main() {
    int i, ncases, nradii;
    double x, minSum;
    vector<double> radii;
    cin >> ncases;
    while (ncases--) {
        cin >> nradii;
        radii.clear();
        minSum = 0;
        for (i = 0; i < nradii; i++) {
            cin >> x;
            minSum += 2*x;
            radii.push_back(x);
        }
        sort(radii.begin(), radii.end());
        do {
            x = solve(radii);
            if (x < minSum) {
                minSum = x;
            }
        } while (next_permutation(radii.begin(), radii.end()));
        printf("%.3f\n", minSum);
    }
    return 0;
}
