#include <iostream>

/*
Accepted: 0.026s
Category: math- number theory
Algorithm: see https://www.math.hmc.edu/funfacts/ffiles/10013.5.shtml
*/

using namespace std;

int getNextDiff(string &num, int index, int N)
{
    int a = 0, b = 0;
    if (index < N)
    {
        a = num[index] - '0';
    }
    if (index + 1 < N)
    {
        b = num[index+1] - '0';
    }
    return a - b;
}

bool isDivisibleBy11(string &num)
{
    int N = (int) num.length();
    int sum = 0;
    for (int i = 0; i < N; i += 2)
    {
        sum += getNextDiff(num, i, N);
    }
    return sum % 11 == 0;
}

int main()
{
	string num;

	while (cin >> num and num != "0")
    {
        isDivisibleBy11(num) ? cout << num << " is a multiple of 11." << endl
            : cout << num << " is not a multiple of 11." << endl;
	}
    return 0;
}
