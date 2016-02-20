#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Category: string processing, frequency counting
Algorithm: frequency counting
*/

using namespace std;

#define ASCII_DIFF 'a'
#define NALPHA 26

int main() {
	string line;
	vector<string> dic;

	while (getline(cin, line) and line != "#") {
        dic.push_back(line);
	}

	while (getline(cin, line) and line != "#") {
	    vector<int> freq(NALPHA, 0);
        for (int i = 0; line[i]; i++)
            if (isalpha(line[i]))
                freq[line[i]-ASCII_DIFF]++;
        int k, res = 0;
        bool isCandidate;
        for (vector<string>::iterator it = dic.begin(); it != dic.end(); it++) {
            string temp = *it;
            isCandidate = true;
            k = 0;
            for (int i = 0; isCandidate and temp[i]; i++) {
                if (freq[temp[i]-ASCII_DIFF] == 0) {
                    isCandidate = false;
                } else {
                    freq[temp[i]-ASCII_DIFF]--;
                    k++;
                }
            }
            for (int i = 0; i < k; i++) /* reset frequencies */
                freq[temp[i]-ASCII_DIFF]++;

            if (isCandidate)
                res++;
        }
        cout << res << endl;
	}
    return 0;
}
