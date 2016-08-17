#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: Ad-hoc
*/

using namespace std;

string getWord(int index);

int main()
{
    int npeople;
    string name;
    vector<string> people;

    cin >> npeople;
    for (int i = 0; i < npeople; i++)
    {
        cin >> name;
        people.push_back(name);
    }

    int bound = 16*(npeople/16);
    if (npeople % 16 != 0)
    {
        bound += 16;
    }
    for (int i = 0, index = 0, cnt = 0; i < bound; i++, cnt = (cnt + 1) % 16, index = (index + 1) % npeople)
    {
        cout << people[index] << ": " << getWord(cnt) << endl;
    }
    return 0;
}

string getWord(int index)
{
    if (index == 0 || index % 4 == 0)
    {
        return "Happy";
    }
    else if (index % 4 == 1)
    {
        return "birthday";
    }
    else if (index % 4 == 2)
    {
        return "to";
    }
    else if (index == 11)
    {
        return "Rujia";
    }
    return "you";
}
