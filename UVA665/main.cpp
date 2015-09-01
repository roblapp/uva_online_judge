#include <iostream>
#include <cstring>

#define MAXN 100

/*
ACCEPTED 0.003s
*/

using namespace std;

int main() {
    int ncases, ncoins, nweightings, coinsPerSide, element, cnt, soln, N = 0;
    char result;
    bool candidates[MAXN + 1], scale[MAXN + 1];

    cin >> ncases;
    while (ncases--) {
        cin >> ncoins >> nweightings;
        memset(candidates, 1, sizeof(candidates));
        soln = 0;
        while (nweightings--) {
            cin >> coinsPerSide;
            coinsPerSide *= 2;
            memset(scale, 0, sizeof(scale));
            for (int i = 0; i < coinsPerSide; i++) {
                cin >> element;
                scale[element] = true;
            }
            cin.get(result); cin.get(result);
            if (soln == 0) { /* don't process if we found a solution */
                if (result == '=') {
                    for (int i = 1; i <= ncoins; i++) {
                        if (scale[i]) {
                            candidates[i] = false;
                        }
                    }
                } else {
                    for (int i = 1; i <= ncoins; i++) { /* for each coin not on the scale (the i_th coin)*/
                        if (!scale[i]) { /* any item not on the scale cannot be false since the false coin must be on the scale */
                            candidates[i] = false;
                        }
                    }
                    /* get the number of unknowns */
                    cnt = 0;
                    for (int i = 1; i <= ncoins; i++) {
                        if (scale[i] && candidates[i]) { /* */
                            cnt++;
                            element = i;
                        }
                    }
                    if (cnt == 1) { /* if there is only 1 unknown on the scale */
                        soln = element;
                    }
                }
                cnt = 0;
                for (int i = 1; i <= ncoins && cnt < 2 && soln == 0; i++) {
                    if (candidates[i]) {
                        cnt++;
                        element = i;
                    }
                }
                if (cnt ==  1) {
                    soln = element;
                }
            }
        } /* end for each weighting... */
        if (N++) {
            cout << endl;
        }
        cout << soln << endl;
    } /* end for each case... */

    return 0;
}
