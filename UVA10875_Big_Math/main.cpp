#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>

/*
Accepted: 0.000s
Category: string processing, bignum, output formatting
Algorithm: ad-hoc
*/

using namespace std;

#define ASCII_DIFF '0'
#define ZERO "0000.00.00.0000"
#define ONE ".0..0..0..0..0."
#define TWO "000..00000..000"
#define THREE "000..0000..0000"
#define FOUR "0.00.0000..0..0"
#define FIVE "0000..000..0000"
#define SIX "0..0..0000.0000"
#define SEVEN "000..0..0..0..0"
#define EIGHT "0000.00000.0000"
#define NINE "0000.0000..0..0"
#define ADD ".0..0.000.0..0."
#define SUB "......000......"
#define MULT "0.00.0.0.0.00.0"
#define DIV ".0....000....0."

void init(map<string,char> &m, vector<string> &v) {
    m[ZERO] = '0'; m[ONE] = '1'; m[TWO] = '2'; m[THREE] = '3'; m[FOUR] = '4'; m[FIVE] = '5';
    m[SIX] = '6'; m[SEVEN] = '7'; m[EIGHT] = '8'; m[NINE] = '9'; m[ADD] = '+'; m[SUB] = '-';
    m[MULT] = '*'; m[DIV] = '/';
    v.push_back(ZERO); v.push_back(ONE); v.push_back(TWO); v.push_back(THREE); v.push_back(FOUR);
    v.push_back(FIVE); v.push_back(SIX); v.push_back(SEVEN); v.push_back(EIGHT); v.push_back(NINE);
}

void performOps(vector<int> &operands, vector<char> &operators, char op0, char op1) {
    int k = 0;
    while (k < (int) operators.size()) {
        if (operators[k] == op0 or operators[k] == op1) {
            while (k < (int) operators.size() and (operators[k] == op0 or operators[k] == op1)) {
                if (operators[k] == op0 and op0 == '*')
                    operands[k] = operands[k] * operands[k+1];
                else if (operators[k] == op0 and op0 == '+')
                    operands[k] = operands[k] + operands[k+1];
                else if (operators[k] == op1 and op1 == '/')
                    operands[k] = operands[k] / operands[k+1];
                else
                    operands[k] = operands[k] - operands[k+1];
                operands.erase(operands.begin() + k + 1);
                operators.erase(operators.begin() + k);
            }
        }
        k++;
    }
}

void printBigNum(vector<string> &dic, int n) {
    bool isNegative = n < 0;
    vector<string> soln;

    n = abs(n);
    if (n != 0) {
        stack<int> s;
        if (isNegative)
            soln.push_back("......000......");
        while (n > 0) {
            s.push(n%10);
            n /= 10;
        }
        while (!s.empty()) {
            soln.push_back(dic[s.top()]);
            s.pop();
        }
    } else
        soln.push_back(ZERO);

    int ntokens = (int) soln.size();

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < ntokens; j++) {
            if (j > 0) cout << " ";
            for (int x = 0; x < 3; x++)
                cout << soln[j][3*i + x];
        }
        cout << endl;
    }
    cout << endl;
}

void solve(map<string,char> &m, vector<string> &dic, vector<string> &v) {
    int k = 0, ntokens = (int) v.size();
    char c;
    vector<int> operands; vector<char> operators;
    while (k < ntokens) {
        c = m[v[k]];
        if (isdigit(c)) {
            int x = 0;
            while (isdigit(c)) {
                x = 10*x + (c - ASCII_DIFF);
                k++;
                if (k == ntokens)
                    break;
                c = m[v[k]];
            }
            operands.push_back(x);
        } else {
            operators.push_back(c);
            k++;
        }
    }
    performOps(operands, operators, '*', '/');
    performOps(operands, operators, '+', '-');

    printBigNum(dic, operands[0]);
}

int main() {
	map<string,char> m;
	vector<string> dic;
	init(m, dic);

	while (1) {
	    string line;
        int ntokens = 0, N = 0;
        vector<string> v;
        for (int i = 0; i < 5; i++) {
            getline(cin, line);
            if (i == 0) {
                N = line.length();
                int nspaces = 0;
                for (int j = 0; j < N; j++)
                    if (isspace(line[j]))
                        nspaces++;
                ntokens = nspaces + 1;
                v.assign(ntokens, "");
            }
            for (int j = 0; j < ntokens; j++)
                for (int k = 0; k < 3; k++)
                    v[j] += line[4*j + k];
        }
        if (ntokens == 1 and m[v[0]] == '0')
            break;
        solve(m, dic, v);
        getline(cin, line); /* drain empty line */
	}
    return 0;
}
