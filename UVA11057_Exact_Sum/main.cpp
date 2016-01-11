#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

/*
Accepted: 0.013s
Description: sorting/binary search
Info: I kept getting TLE which surprised me because I looked online and saw
people had N^2 solutions that passed in the given time. I kept trying different
stuff and wondering my NLOGN solution was getting TLE...
until I finally realized my binary search function had an error...

    int binarySearch(vector<int> v, int low, int high, int val)

when it should have been

    int binarySearch(vector<int> &v, int low, int high, int val)

Notice the correct version v is passed by reference! What a stupid mistake to make! Lesson learned!
*/

using namespace std;

int binarySearch(vector<int> &v, int low, int high, int val) {
    if (low > high)
        return -1;
    int mid = (low + high) >> 1;
    if (v[mid] > val)
        return binarySearch(v, low, mid - 1, val);
    else if (v[mid] < val)
        return binarySearch(v, mid + 1, high, val);
    else
        return mid;
}

int main() {
	int n, x, targetSum;

	while (scanf("%d", &n) == 1) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        scanf("%d", &targetSum);
        int ci = -1, cj = -1, minDist = INT_MAX, temp;
        for (int i = 0; i < n; i++) {
            temp = binarySearch(v, i + 1, n, targetSum - v[i]);
            if (temp != -1 && temp - i < minDist) {
                ci = i;
                cj = temp;
                minDist = temp - i;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", v[ci], v[cj]);
	}
    return 0;
}
