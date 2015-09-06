#include <iostream>
#include <iomanip>

using namespace std;

int modifiedBinarySearch(long long int n, long long int lo, long long int hi) {
    if (hi < lo) {
        return 0;
    }
    long long int mid = (lo + hi) >> 1;
    long long int res = 2*mid*mid;
    if (res < n) {
        return modifiedBinarySearch(n, mid + 1, hi);
    } else if (res > n) {
        return modifiedBinarySearch(n, lo, mid - 1);
    } else {
        return mid;
    }
}

int main() {
    int a[] = {6, 8, 35, 49, 204, 288, 1189, 1681, 6930, 9800, 40391, 57121, 235416, 332928,
                1372105, 1940449, 7997214, 11309768, 46611179, 65918161};
     for (int i = 0; i < 20; i += 2) {
        cout << setw(10) << a[i] << setw(10) << a[i+1] << endl;
     }
    /*
    Here is the algorithm I used to determine the results...

    long long int i = 2, nsolutions = 0, res;
    while (nsolutions != 10) {
        res = modifiedBinarySearch(i*i + i, 1, i);
        if (res != 0) {
            cout << min(i, res) << " " << max(i, res) << endl;
            nsolutions++;
        }
        i++;
    }
    */
    return 0;
}
