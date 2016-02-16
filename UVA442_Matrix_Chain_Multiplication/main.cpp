#include <iostream>
#include <stack>
#include <cstring>

/*
Accepted: 0.000s
Category: string processing, parsing
Algorithm: parsing using a stack
*/

using namespace std;

#define NALPHA 26
#define ASCII_DIFF 'A'

struct Entry {
    int rows, cols;
    bool isParen;
    Entry(int _rows, int _cols, bool _isParen) : rows(_rows), cols(_cols), isParen(_isParen) {}
};

bool isValidMult(int colsA, int rowsB) {
    return (colsA == rowsB);
}

int solve(int rows[], int cols[], string &expr) {
    int res = 0;
    stack<Entry> st;
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') {
            st.push(Entry(0, 0, true));
        } else if (expr[i] == ')') {
            Entry temp = st.top(); st.pop();
            st.pop(); /* pop a paren */
            if (!st.empty()) {
                if (!temp.isParen) { /* we have a matrix at the top */
                    Entry prev = st.top();
                    if (!prev.isParen) {
                        st.pop();
                        /* if valid dimensions */
                        if (isValidMult(prev.cols, temp.rows)) {
                            st.push(Entry(prev.rows, temp.cols, false));
                            res += prev.rows*prev.cols*temp.cols;
                        } else {
                            return -1;
                        }
                    } else {
                        st.push(temp);
                    }
                } else {
                    /* fatal error */
                }
            } else {
                return res;
            }
        } else {
            int rowDim = rows[expr[i]-ASCII_DIFF];
            int colDim = cols[expr[i]-ASCII_DIFF];
            if (!st.empty()) {
                Entry temp = st.top();
                if (!temp.isParen) {
                    st.pop();
                    if (isValidMult(temp.cols, rowDim)) {
                        st.push(Entry(temp.rows, colDim, false));
                        res += temp.rows*temp.cols*colDim;
                    } else {
                        return -1;
                    }
                } else {
                    st.push(Entry(rowDim, colDim, false));
                }
            } else {
                st.push(Entry(rowDim, colDim, false));
            }
        }
    }
    return res;
}

int main() {
	int nmatrices, a, b, temp;
	string line;
	int rows[NALPHA];
	int cols[NALPHA];
	memset(rows, sizeof(rows), 0);
	memset(cols, sizeof(cols), 0);

	cin >> nmatrices;
	while (nmatrices--) {
        cin >> line >> a >> b;
        rows[line[0]-ASCII_DIFF] = a;
        cols[line[0]-ASCII_DIFF] = b;
	}

	while (cin >> line) {
        if ((temp = solve(rows, cols, line)) >= 0)
            cout << temp << endl;
        else
            cout << "error" << endl;
	}
    return 0;
}
