#include <iostream>

/*
Accepted: 0.000s
Category: recursion
Algorithm: recursive algorithm
Info: There has to be a shorter way of doing this problem... I am not happy
with the code here, but it works and runs quickly. I would like to come
back and re-factor this.
*/

using namespace std;

int countTreeAndOrAdvanceIndex(string &s, int &index, int pixelCount) {
    if (s[index] == 'e') {
        index++;
        return 0;
    }  else if (s[index] == 'f') {
        index++;
        return pixelCount*pixelCount;
    }
    index++;
    int sum = 0;
    for (int i = 0; i < 4; i++) { /* process 4 children */
        sum += countTreeAndOrAdvanceIndex(s, index, pixelCount/2);
    }
    return sum;
}

int func(string &s, string &t, int &sindex, int &tindex, int pixelCount) {
    if (s[sindex] == 'f') {
        if (t[tindex] == 'f') {
            sindex++; tindex++;
            return pixelCount*pixelCount;
        } else if (t[tindex] == 'p') {
            sindex++;
            countTreeAndOrAdvanceIndex(t, tindex, pixelCount);
            return pixelCount*pixelCount;
        } else { /* t[tindex] == 'e' */
            tindex++; sindex++;
            return pixelCount*pixelCount;
        }
    } else if (s[sindex] == 'p') {
        if (t[tindex] == 'f') {
            tindex++;
            countTreeAndOrAdvanceIndex(s, sindex, pixelCount);
            return pixelCount*pixelCount;
        } else if (t[tindex] == 'p') { /* both nodes are parent nodes... must recurse */
            sindex++; tindex++;
            int sum = 0;
            for (int i = 0; i < 4; i++) { /* process 4 children */
                sum += func(s, t, sindex, tindex, pixelCount/2);
            }
            return sum;
        } else { /* t[tindex] == 'e' */
            tindex++;
            return countTreeAndOrAdvanceIndex(s, sindex, pixelCount);
        }
    } else { /* s[sindex] == 'e' */
        if (t[tindex] == 'f') {
            tindex++;
            countTreeAndOrAdvanceIndex(s, sindex, pixelCount);
            return pixelCount*pixelCount;
        } else if (t[tindex] == 'p') {
            sindex++;
            return countTreeAndOrAdvanceIndex(t, tindex, pixelCount);
        } else { /* t[tindex] == 'e' */
            sindex++; tindex++;
            return 0;
        }
    }
}

int main() {
	int ncases;

	cin >> ncases;
	while (ncases--) {
        string treea, treeb;
        int indexa = 0, indexb = 0;
        cin >> treea >> treeb;
        cout << "There are " << func(treea, treeb, indexa, indexb, 32) << " black pixels." << endl;
	}
    return 0;
}
