#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

int getValue(string &s);
int digitSum(int x);
int charSum(string &s);

int main()
{
	string sa;
	string sb;

	while (getline(cin, sa) && getline(cin, sb))
    {
        int x = getValue(sa);
        int y = getValue(sb);
        int den = max(x, y);
        int num = min(x, y);
        if (den != 0)
        {
            double result = 100.0*num/den;
            cout << fixed << setprecision(2) << result << " %";
        }
        cout << endl;
    }
    return 0;
}

int getValue(string &s)
{
    int sum = charSum(s);

    while ((sum = digitSum(sum)) >= 10)
    {
    }

    return sum;
}

int digitSum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int charSum(string &s)
{
    int sum = 0;
    for (int i = 0; s[i]; i++)
    {
        if (isalpha(s[i]))
        {
            sum += tolower(s[i]) - 'a' + 1;
        }
    }
    return sum;
}
