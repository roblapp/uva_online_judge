#include <iostream>

/*
Accepted: 0.000s
Category: string processing, output formatting
Algorithm: ad-hoc
Info: this problem was irritating!
*/

using namespace std;

bool findIntersection(string &hs, string &vs, int &hi, int &vi) {
    for (int i = 0; hs[i]; i++) {
        for (int j = 0; j < vs[j]; j++) {
            if (hs[i] == vs[j]) {
                hi = i;
                vi = j;
                return true;
            }
        }
    }
    hi = vi = -1;
    return false;
}

void fancyPrint(string &hsa, string &vsa, string &hsb, string &vsb) {
    int hia, via, hib, vib;

    if (!findIntersection(hsa, vsa, hia, via) or !findIntersection(hsb, vsb, hib, vib)) {
        cout << "Unable to make two crosses" << endl;
        return;
    }

    int rowToStartPrintingA = 0, rowToStartPrintingB = 0;
    int indexToPrintHorizontalString;
    int vsaii = 0, vsbii = 0;
    int hsaLen = hsa.length(), vsaLen = vsa.length(), vsbLen = vsb.length();
    int nrows = max(via, vib)  + max(vsa.length() - via, vsb.length() - vib);
    int offset;
    string temp;

    if (via < vib) {
        rowToStartPrintingA = vib - via;
    } else if (via > vib) {
        rowToStartPrintingB = via - vib;
    }

    indexToPrintHorizontalString = rowToStartPrintingA + via;

    for (int row = 0; row < nrows; row++) {
        temp = "";
        if (row == indexToPrintHorizontalString) {
            temp = hsa + "   " + hsb;
            vsaii++;
            vsbii++;
        } else {
            if (row >= rowToStartPrintingA) {
                if (vsaii < vsaLen) {
                    temp += string(hia, ' ') + vsa[vsaii++];
                    offset = hsaLen - hia - 1 + 3 + hib;
                } else {
                    offset = hsaLen + 3 + hib;
                }
                if (row >= rowToStartPrintingB and vsbii < vsbLen) {
                    temp += string(offset, ' ') + vsb[vsbii++];
                }
            } else if (row >= rowToStartPrintingB and vsbii < vsbLen) {
                temp += string(hsaLen + 3 + hib, ' ') + vsb[vsbii++];
            }
        }
        cout << temp << endl;
    }
}

int main() {
	bool isFirstCase = true;
	string ha, va, hb, vb;

	while (true) {
        cin >> ha;
        if (ha == "#")
            break;
        cin >> va >> hb >> vb;
        if (!isFirstCase)
            cout << endl;
        fancyPrint(ha, va, hb, vb);
        isFirstCase = false;
	}
    return 0;
}
