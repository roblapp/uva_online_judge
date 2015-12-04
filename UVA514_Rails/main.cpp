#include <iostream>
#include <stack>

/*
Accepted: 0.106s
Description: data structures - stacks
Info: I need to think of a faster way of doing this problem. It is not
possible to arrange the coaches if you have the following situation:
X, ... Y, ... Z
where X > Y and X > Z, but Y < Z
*/

using namespace std;

#define read cin
#define MAXN 1000

int main() {
    int n, x;
    int a[MAXN];

    while (read >> n && n != 0) {
        while (1) {
            read >> x;
            if (x == 0)
                break;
            int i = 0;
            a[i++] = x;
            while (i < n) {
                read >> x;
                a[i++] = x;
            }
            bool isYes = true;
                int k = 1;
                stack<int> s;
                for (int j = 0; isYes && j < n; j++) {
                    if (!s.empty() && s.top() == a[j]) {
                        s.pop();
                    } else {
                        while (k <= n && a[j] != k) {
                            s.push(k);
                            k++;
                        }
                        if (k > n)
                            isYes = false;
                        else
                            k++;
                    }
                }
                if (isYes)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}
