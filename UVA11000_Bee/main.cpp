#include <iostream>

/*
Accepted: 0.000s
Category: math
*/

using namespace std;

void compute(int nyears, long long &sumMales, long long &sum)
{
    long long f = 1, m = 0, temp;
    sum = 1, sumMales = 0;
    for (int i = 0; i < nyears; i++)
    {
        temp = m;
        m += f;
        sumMales += m;
        f = temp;
        sum += m + f;
    }
}

int main()
{
	int nyears;
	long long sumMales, sum;

	while (cin >> nyears and nyears >= 0)
	{
	    compute(nyears, sumMales, sum);
	    cout << sumMales << " " << sum << endl;
	}

    return 0;
}
