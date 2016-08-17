#include <iostream>
#include <vector>
#include <map>

/*
Accepted: 0.070s
Category: ad-hoc, data structures
*/

using namespace std;

int main()
{
	int ncourses;
	int ncategories;
	string course;

	while (cin >> ncourses && ncourses != 0)
    {
        cin >> ncategories;
        vector<string> coursesToTake;
        for (int i = 0; i < ncourses; i++)
        {
            cin >> course;
            coursesToTake.push_back(course);
        }
        map<string,vector<int> > ccMap; /* Course - Category map */
        vector<int> mcv; /* min course vector */
        for (int i = 0; i < ncategories; i++)
        {
            int ncoursesInCategory;
            int nMinCourses;

            cin >> ncoursesInCategory >> nMinCourses;
            mcv.push_back(nMinCourses);
            for (int j = 0; j < ncoursesInCategory; j++)
            {
                cin >> course;
                ccMap[course].push_back(i);
            }
        }

        for (vector<string>::iterator it = coursesToTake.begin(); it != coursesToTake.end(); it++)
        {
            map<string, vector<int> >::iterator mapIterator = ccMap.find(*it);
            if (mapIterator != ccMap.end()) /* If the course was found */
            {
                vector<int> v = mapIterator->second;
                /* check each category and count the course from the min course count */
                for (vector<int>::iterator vit = v.begin(); vit != v.end(); vit++)
                {
                    int category = *vit;
                    mcv[category]--;
                }
            }
        }

        bool isOk = true;
        for (vector<int>::iterator mcvIterator = mcv.begin(); isOk && mcvIterator != mcv.end(); mcvIterator++)
        {
            if (*mcvIterator > 0)
            {
                isOk = false;
            }
        }
        isOk ? cout << "yes" << endl : cout << "no" << endl;
    }

    return 0;
}
