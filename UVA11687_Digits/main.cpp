#include <iostream>
#include <sstream>

/*
Accepted: 0.020s
Description: ad-hoc, simulation
*/

using namespace std;

int solve(string &s);

int getDigitsInt(int x);

int getDigitsStr(string &s);

int main()
{
	string s;

	while (cin >> s && s != "END")
    {
        int soln = solve(s);
        cout << soln << endl;
    }
    return 0;
}

int solve(string &s)
{
    if (s == "1")
        return 1;
    int prev = getDigitsStr(s);
    int temp;
    int cnt = 1;

    while (1)
    {
        cnt++;
        temp = getDigitsInt(prev);
        if (temp == prev)
            break;
        prev = temp;
    }
    return cnt;
}

int getDigitsInt(int x)
{
    stringstream ss;
    ss << x;
    return ss.str().length();
}

int getDigitsStr(string &s)
{
    return s.length();
}
