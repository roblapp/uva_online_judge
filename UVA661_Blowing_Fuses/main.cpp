#include <iostream>
#include <cstring>
#include <climits>

/*
Accepted: 0.000s
Description: ad-hoc, simulation
*/

#define MAXN 100

using namespace std;

int main()
{
	int m, n, c;
	bool turnedOn[MAXN + 1];
	int amps[MAXN + 1];
	int seq = 1;

	while (cin >> n >> m >> c)
    {
        if (n == m && m == c && m == 0) break;

        memset(turnedOn, false, sizeof(turnedOn));
        memset(amps, 0, sizeof(amps));

        int x;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            amps[i] = x;
        }

        int sum = 0;
        int maxSum = INT_MIN;
        bool hasBlown = false;

        for (int i = 0; i < m; i++)
        {
            cin >> x;
            turnedOn[x] = !turnedOn[x];
            if (turnedOn[x])
            {
                sum += amps[x];
                maxSum = max(maxSum, sum);
            }
            else
            {
                sum -= amps[x];
            }
            if (sum > c)
            {
                hasBlown = true;
            }
        }
        if (hasBlown)
        {
            cout << "Sequence " << seq << endl << "Fuse was blown." << endl << endl;
        }
        else
        {
            cout << "Sequence " << seq << endl << "Fuse was not blown." << endl << "Maximal power consumption was " << maxSum << " amperes." << endl << endl;
        }
        seq++;
    }

    return 0;
}
