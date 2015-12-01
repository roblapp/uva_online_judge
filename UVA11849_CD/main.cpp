#include <iostream>
#include <vector>

/*
Accepted: 0.793s
Description: ad-hoc? First wrote a solution using a set and had a time of
1.319s. How else can this be improved? I then tried to use binary_search
and obtained a run time of 0.845s. So for now this is the fastest solution
I can think of. How did a user get 0.000s!?
*/

#define read cin

using namespace std;

int main() {
    int N, M, x, sum, k, len;
    while (read >> N >> M && (N != 0 || M != 0)) {
        vector<int> v;
        sum = len = 0;
        for (int i = 0; i < N; i++) {
            read >> x;
            v.push_back(x);
            len++;
        }
        k = 0;
        for (int i = 0; i < M; i++) {
            read >> x;
            while (k < len && v[k] < x)
                k++;
            if (k < len && v[k] == x)
                sum++;
        }
        cout << sum << endl;
    }
    return 0;
}

