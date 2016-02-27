#include <iostream>
#include <vector>
#include <map>

/*
Accepted: 0.000s
Category: string processing, output formatting
Algorithm: ad-hoc
*/

using namespace std;

void printGraph(string &s) {
    char c, prevChar = 0;
    int nspaces;
    int maxHeight = 0, minHeight = 0, height = 0;
    map<int,string> lineMap;
    map<int,int> lastIndexMap;
    map<int,int>::iterator indexIt;

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'R')
            c = '/';
        else if (s[i] == 'F')
            c = '\\';
        else
            c = '_';

        if (c == '/' and prevChar == '/' and prevChar != 0) {
            height--;
        } else if (c == '\\' and (prevChar == '_' or prevChar == '\\') and prevChar != 0) {
            height++;
        } else if (c == '_' and prevChar == '/') {
            height--;
        }

        maxHeight = max(maxHeight, height);
        minHeight = min(minHeight, height);
        indexIt = lastIndexMap.find(height);

        string temp;
        if (indexIt == lastIndexMap.end()) { /* this is the first char for this row */
            nspaces = i + 1; /* add 1 since graph is offset by 1 from y-axis */
            temp = string(nspaces, ' ') + c;
            lastIndexMap[height] = i;
        } else {
            nspaces = i - indexIt->second - 1;
            temp = lineMap[height] + string(nspaces, ' ') + c;
            indexIt->second = i;
        }
        prevChar = c;
        lineMap[height] = temp;
    }

    for (int i = minHeight; i <= maxHeight; i++)
        cout << "|" << lineMap[i] << endl;
    cout << "+" << string(s.length() + 2, '-') << endl;
}

int main() {
	int ncases, N = 1;
	string line;

	cin >> ncases;
	while (ncases--) {
        cin >> line;
        cout << "Case #" << N++ << ":" << endl;
        printGraph(line);
        cout << endl;
	}
    return 0;
}
