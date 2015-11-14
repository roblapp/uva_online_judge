#include <iostream>
#include <string>

/*
Accepted: 0.000s
Description: ad-hoc
Info: Not the cleanest solution, but since N is of negligable
size it works just fine.
*/

#define read cin
#define N 10

using namespace std;

int main() {
    int n;
    int s[N + 1];
    for (int i = 0; i <= N; i++) s[i] = 0;
    bool isHonest = true;
    string line;
    while (read >> n && n != 0) {
        getline(read, line); getline(read, line);
        if (line == "right on") {
            (s[n] == 0) ? cout << "Stan may be honest" << endl : cout << "Stan is dishonest" << endl;
            for (int i = 0; i <= N; i++) s[i] = 0;
            isHonest = true;
        } else if (line == "too low" && isHonest) {
            for (int i = 1; i <= n; i++)
                    if (s[i] == 1)
                        isHonest = false;
            if (isHonest)
                for (int i = 1; i <= n; i++) s[i] = -1;
        } else if (isHonest) {
            for (int i = N; i >= n; i--)
                    if (s[i] == -1)
                        isHonest = false;
                if (isHonest)
                    for (int i = N; i >= n; i--) s[i] = 1;
        }
    }
    return 0;
}
