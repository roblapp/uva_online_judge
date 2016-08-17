#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc, simulation
*/

using namespace std;

int main()
{
	double wallHeight, distanceCanClimbToday, slideDistance, fatiguePercentage;

	while (cin >> wallHeight >> distanceCanClimbToday >> slideDistance >> fatiguePercentage && wallHeight != 0)
    {
        double fatigueFactor = fatiguePercentage/100*distanceCanClimbToday;
        double currentHeight = 0;
        int day = 1;

        while (true)
        {
            if (distanceCanClimbToday >= 0)
            {
                currentHeight += distanceCanClimbToday;
            }
            if (currentHeight > wallHeight)
            {
                break;
            }
            currentHeight -= slideDistance;
            if (currentHeight < 0)
            {
                break;
            }
            distanceCanClimbToday = distanceCanClimbToday - fatigueFactor;
            day++;
        }
        if (currentHeight < 0)
        {
            cout << "failure on day " << day << endl;
        }
        else
        {
            cout << "success on day " << day << endl;
        }
    }
    return 0;
}
