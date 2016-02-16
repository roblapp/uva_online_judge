#include <iostream>
#include <stack>

/*
Accepted: 0.022s
Category: string processing
Algorithm: parsing, stacks
*/

using namespace std;

bool isValidSingleSentence(char c) {
    return (c >= 'p' and c <= 'z');
}

bool requiresOneMatch(char c) {
    return (c == 'N');
}

bool requiresTwoMatches(char c) {
    return (c == 'C' or c == 'D' or c == 'E' or c == 'I');
}

bool isValidSentence(string &s) {
    int N = s.length(), x;
    stack<int> st;

    for (int i = 0; i < N; i++) {
        if (isValidSingleSentence(s[i])) {
            if (st.empty()) {
                if (N == 1) { /* special case of a single valid sentence */
                    return true;
                }
                return false;
            }
            x = st.top(); st.pop();
            x--;
            if (x == 0) {
                while (!st.empty() and st.top() == 1) {
                    st.pop();
                }
                if (!st.empty()) { /* there are other items to match */
                    x = st.top(); st.pop();
                    x--;
                    st.push(x);
                } else {
                    /* if we're at the last char we've matched everything */
                    /* else if not at the last char then this is an invalid sentence */
                    return (i == N - 1);
                }
            } else {
                st.push(x);
            }
        } else if (requiresOneMatch(s[i])) {
            st.push(1);
        } else if (requiresTwoMatches(s[i])) {
            st.push(2);
        } else {
            return false;
        }
    }
    return (st.empty());
}

int main() {
	string line;

    while (getline(cin, line)) {
        if (isValidSentence(line))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
