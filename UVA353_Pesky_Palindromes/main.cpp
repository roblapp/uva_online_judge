#include <iostream>
#include <set>

/*
Accepted: 0.000s
Description: ad-hoc/palindrome testing
*/

using namespace std;

bool isPalindrome(const string &s) {
    int i, len = s.length(), halfLen = s.length() >> 1;
    for (i = 0; i < halfLen; i++)
        if (s[i] != s[len-1-i]) return false;
    return true;
}

int countAnagrams(string &s) {
    int i, j, len = s.length(), cnt = 0;
    string temp;
    set<string> bank;
    set<string>::iterator it;
    for (i = 0; i < len; i++) {
        for (j = 1; i + j <= len; j++) {
            temp = s.substr(i, j);
            it = bank.find(temp);
            if (it == bank.end() and isPalindrome(temp)) {
                bank.insert(temp);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    string line;
    while (getline(cin, line)) {
        cout << "The string '" << line << "' contains " << countAnagrams(line) << " palindromes." << endl;
    }
    return 0;
}
