#include <iostream>
#include <cmath>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

int main()
{
	int ncases;
	int ncalls;
	int milesRate = 10;
	int milesTime = 30;
	int juiceRate = 15;
	int juiceTime = 60;

	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
    {
        cin >> ncalls;
        int miles = 0;
        int juice = 0;
        int callLength;
        int temp;

        for (int j = 0; j < ncalls; j++)
        {
            cin >> callLength;
            temp = milesRate*ceil(1.0*callLength/milesTime);
            if (callLength % milesTime == 0)
            {
                temp += milesRate;
            }
            miles += temp;

            temp = juiceRate*ceil(1.0*callLength/juiceTime);
            if (callLength % juiceTime == 0)
            {
                temp += juiceRate;
            }
            juice += temp;
        }
        if (miles == juice)
        {
            cout << "Case " << i << ": " << "Mile Juice " << miles << endl;
        }
        else if (miles < juice)
        {
            cout << "Case " << i << ": " << "Mile " << miles << endl;
        }
        else
        {
            cout << "Case " << i << ": " << "Juice " << juice << endl;
        }
    }
    return 0;
}
