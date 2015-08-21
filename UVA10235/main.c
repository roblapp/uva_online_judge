#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ACCEPTED 0.019s */
/*
Algorithm:

prime numbers, reversing numbers
*/

int reverse(int x) {
    int res = 0;
    while (x > 0) {
        res = 10*res + (x % 10);
        x /= 10;
    }
    return res;
}

bool is_prime(int n) {
    if (n <= 3)
        return n > 1;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    int i;
    for (i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main() {

    int x, rx;
    while (scanf("%i", &x) == 1) {
        if (is_prime(x)) {
            if (is_prime((rx = reverse(x))) && rx != x) printf("%i is emirp.\n", x);
            else printf("%i is prime.\n", x);
        } else printf("%i is not prime.\n", x);
    }

    return 0;
}
