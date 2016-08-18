#include <iostream>
#include <iomanip>
#include <vector>

/*
Accepted: 0.270s
Category: simulation
*/

using namespace std;

void printBytes(vector<int> &v, int caseNum);

int incrementPointer(int index, int nbytes);

int decrementPointer(int index, int nbytes);

int incrementByte(int value, int maxBytes);

int decrementByte(int value, int maxBytes);


int main()
{
	int ncases;
	int nBytes = 100;
	int maxBytes = 256;
	string line;

	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
    {
        cin >> line;
        vector<int> v(nBytes, 0);
        int index = 0;

        for (int j = 0; line[j]; j++)
        {
            char c = line[j];
            if (c == '>')
            {
                index = incrementPointer(index, nBytes);
            }
            else if (c == '<')
            {
                index = decrementPointer(index, nBytes);
            }
            else if (c == '+')
            {
                v[index] = incrementByte(v[index], maxBytes);
            }
            else if (c == '-')
            {
                v[index] = decrementByte(v[index], maxBytes);
            }
        }
        cout << "Case " << dec << i << ":";
        for (int j = 0; j < nBytes; j++)
        {
            cout << " " << hex << uppercase << setw(2) << setfill('0') << v[j];
        }
        cout << endl;
    }

    return 0;
}

int incrementPointer(int index, int nbytes)
{
    return (index + 1) % nbytes;
}

int decrementPointer(int index, int nbytes)
{
    return index <= 0 ? nbytes - 1 : index - 1;
}

int incrementByte(int value, int maxBytes)
{
    return (value + 1) % maxBytes;
}

int decrementByte(int value, int maxBytes)
{
    return value <= 0 ? maxBytes - 1 : value - 1;
}
