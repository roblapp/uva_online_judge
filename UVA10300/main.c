#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.012 */

int main()
{
    int i, j, ncases, nfarmers, r, size, nanimals, neco;

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        scanf("%i", &nfarmers );
        r = 0;

        for ( j = 0; j < nfarmers; j++ )
        {
            scanf("%i %i %i", &size, &nanimals, &neco );
            r += size * neco;
        }
        printf("%i\n", r );
    }

    return 0;
}
