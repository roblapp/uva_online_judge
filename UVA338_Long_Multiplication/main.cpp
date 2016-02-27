#include <iostream>
#include <iomanip>
#include <vector>

/*
Accepted: 0.175s
Category: string processing, output formatting, bignum
Algorithm: grade school multiplication and addition
*/

using namespace std;

#define ASCII_DIFF '0'

void printMultSoln(string &x, string &y, vector<string> &v, vector<int> &skipv, string &soln) {
    int maxLen = max(x.length(), y.length());
    int maxoffset = max((int) soln.length(), maxLen);
    cout << setw(maxoffset) << x << endl << setw(maxoffset) << y << endl << setw(maxoffset) << string(maxLen, '-') << endl;
    if (v.size() >= 2) {
        for (int i = 0; i < (int) v.size(); i++)
            cout << setw(maxoffset-skipv[i]) << v[i] << endl;
        cout << string(soln.length(), '-') << endl << soln << endl << endl;
    } else
        cout << setw(maxoffset) << soln << endl << endl;
}

string addStr(string &x, string &y, int skips) {
    string soln = "", yshifted(y);
    while (skips-- > 0)
        yshifted += "0";
    int xii = x.length() - 1, yii = yshifted.length() - 1, len = max(x.length(), yshifted.length()), sum, dig0, dig1, remainder = 0;
    for (int i = 0; i < len; i++) {
        dig0 = (xii >= 0) ? x[xii--]-ASCII_DIFF : 0;
        dig1 = (yii >= 0) ? yshifted[yii--]-ASCII_DIFF : 0;
        sum = dig0 + dig1 + remainder;
        soln.insert(0, 1, (sum%10 + ASCII_DIFF));
        remainder = sum/10;
    }
    if (remainder > 0)
        soln.insert(0, 1, (remainder%10 + ASCII_DIFF));
    if (soln.empty())
        soln = "0";
    return soln;
}

void multStr(string &strx, string &stry) {
    int lenX = strx.length(), lenY = stry.length(), remainder = 0, prod, skipCount = 0;
    vector<string> v;
    vector<int> skipv;
    string soln = "0";

    if (strx[0] == '0' or stry[0] == '0') {
        soln = "0";
        printMultSoln(strx, stry, v, skipv, soln);
        return;
    }

    for (int yii = lenY - 1; yii >= 0; yii--) {
        if (stry[yii] != '0') {
            string temp = "";
            remainder = 0;
            for (int xii = lenX - 1; xii >= 0; xii--) {
                prod = (stry[yii]-ASCII_DIFF)*(strx[xii]-ASCII_DIFF) + remainder;
                temp.insert(0, 1, prod%10 + ASCII_DIFF);
                remainder = prod/10;
            }
            if (remainder > 0)
                temp.insert(0, 1, remainder%10 + ASCII_DIFF);
            v.push_back(temp);
            skipv.push_back(skipCount);
            soln = addStr(soln, temp, skipCount);
        }
        skipCount++;
    }
    printMultSoln(strx, stry, v, skipv, soln);
}

int main() {
	string strx, stry;

	while (cin >> strx >> stry)
        multStr(strx, stry);

    return 0;
}
