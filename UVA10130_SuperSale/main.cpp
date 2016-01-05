#include <iostream>
#include <vector>

/*
Accepted: 0.019s
Description: dynamic programming - 0/1 knapsack
Info: I had a little help... See
    https://tausiq.wordpress.com/2010/08/08/uva-10130-supersale/
I would have done this with a 2D array. After examining the above solution I
realized that only a 1D array is needed.
*/

using namespace std;

#define read cin
#define MAX_WEIGHT 30

int main() {
	int ncases, n, price, weight, nq, x;

	read >> ncases;
	while (ncases--) {
        read >> n;
        vector<int> pricev, weightv;
        int DP[MAX_WEIGHT + 1];
        for (int i = 0; i < n; i++) {
            read >> price >> weight;
            pricev.push_back(price);
            weightv.push_back(weight);
        }
        for (int i = 0; i <= MAX_WEIGHT; i++)
            DP[i] = 0;
        /* Still not sure how we can omit a 2D array? See link above. */
        for (int i = 0; i < n; i++)
            for (int j = MAX_WEIGHT; j >= 0; j--)
                if (weightv[i] <= j && DP[j] < DP[j-weightv[i]] + pricev[i])
                    DP[j] = DP[j-weightv[i]] + pricev[i];
        read >> nq;
        int sum = 0;
        for (int i = 0; i < nq; i++) {
            read >> x;
            sum += DP[x];
        }
        cout << sum << endl;
	}
    return 0;
}
