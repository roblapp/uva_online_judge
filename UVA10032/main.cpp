#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

/* ACCEPTED 0.275s */
/*
Algorithm used:
variation of subset sum problem solved by dynamic programming.
*/

#define MAXN 100
#define MAXWEIGHT 45000

using namespace std;

void partition_set(int weights[], int n, int total) {

    int w = (total >> 1);
    bool v[MAXWEIGHT];
    int min_people[MAXWEIGHT];
    int max_people[MAXWEIGHT];
    for (int i = 0; i < MAXWEIGHT; i++) {
        min_people[i] = INT_MAX;
        max_people[i] = v[i] = 0;
    }
    /* creating a sum of 0 is trivial... use none of the elements from weights[] */
    v[0] = true;
    min_people[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = w; j >= 0; j--) {
            if (v[j]) { /* if we know we can obtain this sum... */
                v[j + weights[i]] = true; /* we can certainly obtain the sum with the added element from weights[] */
                if (min_people[j] + 1 < min_people[j + weights[i]]) { /* did obtaining this sum use less people? */
                    min_people[j + weights[i]] = min_people[j] + 1;
                }
                if (max_people[j] + 1 > max_people[j + weights[i]]) { /* did obtaining this sum use more people? */
                    max_people[j + weights[i]] = max_people[j] + 1;
                }
            }
        }
    }

    for (int i = w; i >= 0; i--) {
        /* First case is when there is a perfect number of people in each team */
        /* Second case is when the teams differ by one person */
        if (v[i] && ((min_people[i] <= n/2 && max_people[i] >= n/2) || (min_people[i] <= n/2 + n%2 && max_people[i] >= n/2 + n%2)) ) {
            cout << i << " " << (total - i) << endl;
            break;
        }
    }
}

int main() {

    int ncases, nmembers, total, N = 0;
    int weights[MAXN];

    scanf("%i", &ncases);

    for (int i = 0; i < ncases; i++) {

        total = 0;
        scanf("%i", &nmembers);

        for (int j = 0; j < nmembers; j++) {
            scanf("%i", &weights[j]);
            total += weights[j];
        }
        if (N++) cout << endl;
        partition_set(weights, nmembers, total);
    }

    return 0;
}
