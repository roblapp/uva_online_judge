#include <iostream>
#include <stack>

using namespace std;

int compare(char op0, char op1) {
    if (op0 == '/' or op0 == '*') {
        return (op1 == '/' or op1 == '*') ? 0 : 1;
    } else {
        return (op1 == '+' or op1 == '-') ? 0 : -1;
    }
}

bool isoperator(char c) {
    return c == '+' or c == '-' or c == '/' or c == '*' or c == '(' or c == ')';
}

void print(char c) {
    if (c != '(' and c != ')') {
        cout << c;
    }
}

int main() {
	int ncases;
	char c;
	string line;
	bool first = true;

	cin >> ncases; getline(cin, line); getline(cin, line);
	while (ncases--) {
        stack<char> s;
        if (!first)
            print('\n');
        while (getline(cin, line) and !line.empty()) {
            c = line[0];
            if (isoperator(c)) {
                if (s.empty() or s.top() == '(' or c == '(') {
                    s.push(c);
                } else if (c == ')') {
                    while (s.top() != '(') {
                        print(s.top()); s.pop();
                    }
                    s.pop();
                } else {
                    while (1) {
                        if (s.empty() or s.top() == '(' or c == '(') {
                            s.push(c);
                            break;
                        } else if (compare(c, s.top()) > 0) {
                            s.push(c);
                            break;
                        } else if (compare(c, s.top()) == 0) {
                            print(s.top()); s.pop();
                            s.push(c);
                            break;
                        } else { /* stack is not empty and top operator has lower precedence */
                            print(s.top()); s.pop();
                        }
                    }
                }
            } else {
                print(c);
            }
        }
        while (!s.empty()) {
            print(s.top()); s.pop();
        }
        print('\n');
        first = false;
	}
    return 0;
}
