#include <iostream>
#include <vector>

using namespace std;

int wavioSequence(vector<int> &v, int N) {
    int SI[N];
    int SD[N];
    int temp;

    for (int i = 0; i < N; i++) /* Do you need this? */
        SI[i] = SD[i] = 0;

    SI[0] = 1;
    for (int i = 1; i < N; i++) {
        temp = 0;
        for (int j = 0; j < i; j++)
            if (v[j] < v[i] && SI[j] > temp)
                temp = SI[j];
        SI[i] = temp + 1;
    }

    SD[N-1] = 1;
    for (int i = N - 2; i >= 0; i--) {
        temp = 0;
        for (int j = N - 1; j > i; j--)
            if (v[j] < v[i] && SD[j] > temp)
                temp = SD[j];
        SD[i] = temp + 1;
    }

    int result = 0;
    for (int i = 0; i < N; i++)
        if ((temp = min(SI[i], SD[i])) > result)
            result = temp;
    return 2*result - 1;
}

int main() {
    int n, x;

    while (cin >> n) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        cout << wavioSequence(v, (int) v.size()) << endl;
    }
    return 0;
}
