#include <iostream>

/*
Accepted: 0.000s
Category: math- fibonacci(ish)
*/

using namespace std;

long long compute(int n)
{
    if (n == 1 or n == 2)
    {
        return n + 1;
    }
    long long prev = 3, prevPrev = 2, f;
    for (int i = 2; i < n; i++)
    {
        f = prevPrev + prev;
        prevPrev = prev;
        prev = f;
    }
    return f;
}

int main()
{
	int ncases, x;

	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
    {
        cin >> x;
        cout << "Scenario #" << i << ":" << endl << compute(x) << endl << endl;
    }
    return 0;
}
