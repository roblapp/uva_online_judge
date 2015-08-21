#include <iostream>
#include <cstdio>
#include <cmath>

/* ACCEPTED 0.016s */
/*
Algorithm:

Fibonacci Q-Matrix -> computes Nth Fibonacci number in lg(n) time

I completely copied this from the Internet...
*/

using namespace std;

unsigned long long int** get_fib_matrix(unsigned long long int a[]) {
    unsigned long long int **f = new unsigned long long int*[2];
    for (int i = 0; i < 2; i++) {
        f[i] = new unsigned long long int[2];
    }
    f[0][0] = a[0]; f[0][1] = a[1];
    f[1][0] = a[2]; f[1][1] = a[3];
    return f;
}

unsigned long long int** mult(unsigned long long int** a, unsigned long long int** b) {
    unsigned long long int temp[] = {0, 0, 0, 0};
    unsigned long long int** res = get_fib_matrix(temp);
    res[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    res[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    res[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    res[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    return res;
}

unsigned long long int** mpow(int p) {
    if (p == 0) {
        unsigned long long int temp[] = {0, 0, 0, 0};
        return get_fib_matrix(temp);
    }

    unsigned long long int temp[] = {1, 1, 1, 0};
    unsigned long long int** f = get_fib_matrix(temp);

    if (p == 1) {
        return f;
    } else if (p % 2 == 0) {
        unsigned long long int** a = mpow(p >> 1);
        return mult(a, a);
    } else {
        return mult(f, mpow(p - 1));
    }
}

int main() {

    int n, m;
    while (cin >> n >> m) {
        int mod = (1 << m);
        cout << (mpow(n)[0][1] % mod) << endl;
    }

    return 0;
}
