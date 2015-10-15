#include <iostream>
#include <algorithm>

/*
Accepted: 0.003s
Description: ad-hoc/palindrome problem
*/

using namespace std;

int main() {
    int i, len;
    string line, lettersOnly, reversedLettersOnly;
    while (getline(cin, line) and line != "DONE") {
        lettersOnly = "";
        for (i = 0, len = line.length(); i < len; i++)
            if (isalnum(line[i])) lettersOnly += tolower(line[i]);
        reversedLettersOnly = lettersOnly;
        reverse(reversedLettersOnly.begin(), reversedLettersOnly.end());
        if (reversedLettersOnly == lettersOnly) cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;
    }
    return 0;
}
