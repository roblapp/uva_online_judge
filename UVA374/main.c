#include <stdio.h>
#include <stdlib.h>

long long int modexp( long long int base, long long int exp, long long int n) {

		if (exp == 0) return 1;
		if (exp == 1) return base % n;

		if (exp % 2 == 0)
        {
            long long int result = modexp(base,exp/2,n);
			return (result*result) % n;
		}
		return base * modexp(base,exp-1,n) % n;
	}

int main()
{
    long long int b, p, m;

    while ( scanf("%lld %lld %lld", &b, &p, &m) != EOF )
    {
        printf("%lld\n", modexp(b, p, m) );
    }

    return 0;
}
