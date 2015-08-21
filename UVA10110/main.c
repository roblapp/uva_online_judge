#include<stdio.h>
#include<math.h>

/* ACCEPTED 0.033 */

int main()
{
    long int r;
    long double root,num;

    while( scanf("%Lf",&num ) == 1 && num != 0 )
    {
        r = sqrt( num );
        root = pow( r, 2 );
        if ( root == num)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
