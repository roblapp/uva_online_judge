#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, parsing
Algorithm: straight forward parsing algorithm
*/

using namespace std;

struct Token {
    int intValue;
    char charValue;
    bool isOperator;
    Token(int _value, char _opr, bool _isOperator) : intValue(_value), charValue(_opr), isOperator(_isOperator) {}
};

struct Expression {
    vector<Token> v;
    string var;
    Expression(vector<Token> &_v) : v(_v) {}
};

bool isOperator(char c) {
    return (c == '*' or c == '+' or c == '-' or c == '/');
}

void strip(string &s, string &soln) {
    soln = "";
    for (int i = 0; s[i]; i++)
        if (!isspace(s[i]))
            soln += s[i];
}

void parse(string &eqStr, Expression &e) {
    string s;
    stack<char> st;
    strip(eqStr, s);
    int i = 0, N = s.length();
    bool foundAtLeastOneNum = false;

    while (i < N) {
        if (isdigit(s[i])) {
            int x = 0;
            while (isdigit(s[i]) and i < N) {
                x = 10*x + (s[i] - '0') % 10;
                i++;
            }
            if (st.size() == 0) {
                e.v.push_back(Token(x, 0, false));
            } else if (st.size() == 1) {
                char op = st.top(); st.pop();
                if (!foundAtLeastOneNum) {
                    if (op == '-') {
                        x *= -1;
                    }
                } else {
                    e.v.push_back(Token(0, op, true));
                }
                e.v.push_back(Token(x, 0, false));
            } else if (st.size() == 2) {
                /* <num>+-<num> or <num>-+<num> or <num>--<num> or <num>++<num> */
                char prevOp = st.top(); st.pop();
                char prevPrevOp = st.top(); st.pop();
                if (prevOp == '-') { /* <num>+-<num> or <num>--<num> */
                    x *= -1;
                }
                e.v.push_back(Token(0, prevPrevOp, true));
                e.v.push_back(Token(x, 0, false));
            } else {
                /* fatal error */
            }
            foundAtLeastOneNum = true;
        } else if (isOperator(s[i])) {
            st.push(s[i]);
            i++;
        } else if (s[i] == '=') {
            i++;
            stringstream ss("");
            while (i < N)
                ss << s[i++];
            e.var = ss.str();
        } else {
            /* fatal error */
        }
    }
}

int performSingleOperation(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a*b;
    } else if (op == '/') {
        return a/b;
    }
    return 0;
}

void showExpression(Expression &e) {
    vector<Token> v = e.v;
    for (vector<Token>::iterator it = v.begin(); it != v.end(); it++) {
        Token temp = *it;
        (temp.isOperator) ? cout << temp.charValue << " " : cout << temp.intValue << " ";
    }
    cout << "= " << e.var << endl;
}

void solve(Expression &e) {
    int i;
    vector<Token>::iterator it;
    string ops[] = {"*/", "+-"};
    showExpression(e);
    for (int j = 0; j < 2; j++) {
        char op0 = ops[j][0];
        char op1 = ops[j][1];
        i = 0;
        while (i < (int) e.v.size()) {
            if (e.v[i].isOperator and (e.v[i].charValue == op0 or e.v[i].charValue == op1)) {
                int res = performSingleOperation(e.v[i-1].intValue, e.v[i+1].intValue, e.v[i].charValue);
                e.v[i-1].intValue = res;
                it = e.v.begin();
                e.v.erase(it + i, it + i + 2); /* erase next 2 Tokens (the operator and the 2nd operand) */
                showExpression(e);
            } else {
                i++;
            }
        }
    }
}

void solveEquation(string &eqStr) {
    vector<Token> v;
    Expression e(v);
    parse(eqStr, e);
    solve(e);
}

int main() {
	string line;

	while (getline(cin, line)) {
        solveEquation(line);
        cout << endl;
	}
    return 0;
}
