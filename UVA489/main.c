#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.079 */

#define MAXC 26
#define MAXL 2000
#define OFFSET 97

#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct cell cell;

struct cell {

    int count;
    bool guessed;
};

cell a[MAXC];

void init()
{
    int i;

    for ( i = 0; i < MAXC; i++ )
    {
        a[i].count = 0;
        a[i].guessed = FALSE;
    }
}

int main()
{
    int i, casen, uc, bg;
    char p[MAXL];
    char s[MAXL];

    while ( scanf("%i", &casen ) == 1 && casen != -1 )
    {
        scanf("%s %s", p, s );
        init();
        i = uc = 0;
        while ( p[i] )
        {
            if ( a[ p[i] - OFFSET ].count == 0 )
                uc++;
            a[ p[i] - OFFSET ].count = a[ p[i] - OFFSET ].count + 1;
            i++;
        }

        i = 0;
        bg = 7;

        while ( s[i] && uc > 0 && bg > 0 )
        {
            if ( a[ s[i] - OFFSET ].count > 0 )
            {
                if ( !a[ s[i] - OFFSET ].guessed ) /* if not guessed */
                {
                    uc--;
                }
            }
            else /* count = 0 */
            {
                if ( !a[ s[i] - OFFSET ].guessed )
                {
                    bg--;
                }
            }

            a[ s[i] - OFFSET ].guessed = TRUE;

            i++;
        }

        printf("Round %i\n", casen );

        if ( uc == 0 )
            printf("You win.\n");
        else if ( bg == 0 )
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }

    return 0;
}
