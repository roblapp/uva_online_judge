#include <iostream>
#include <climits>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

int main()
{
	int npeople;
	int budget;
	int nhotels;
	int nweeks;

	while (cin >> npeople >> budget >> nhotels >> nweeks)
    {
        int hotelCost;
        int cost = INT_MAX;
        for (int i = 0; i < nhotels; i++)
        {
            cin >> hotelCost;
            int nrooms;
            int temp;

            for (int j = 0; j < nweeks; j++)
            {
                cin >> nrooms;

                if (nrooms >= npeople and (temp = npeople*hotelCost) <= budget)
                {
                    cost = min(cost, temp);
                }
            }
        }
        cost == INT_MAX ? cout << "stay home" << endl : cout << cost << endl;
    }
    return 0;
}
