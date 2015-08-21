#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.029 */

#define MAXN 5001
#define TRUE 1
#define FALSE 0

int heap[MAXN];
int count;

void init()
{
    count = 0;
}

void swap( int a, int b )
{
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void insert( int x )
{
    count++;

    heap[count] = x;
    int current = count;

    while ( current / 2 >= 1 && heap[current] < heap[current / 2] )
    {
        swap( current / 2, current );
        current /= 2;
    }
}

int pop()
{
    int min, current, left, right;

    min = heap[1];

    heap[1] = heap[count];

    count--;

    current = 1;

    while ( TRUE )
    {
        left = 2*current;
        right = 2*current + 1;

        if ( left <= count && right <= count )
        {
            if ( heap[current] <= heap[left] && heap[current] <= heap[right] )
            {
                break;
            }
            else
            {
                if ( heap[left] <= heap[right] )
                {
                    swap( current, left );
                    current = 2*current;
                }
                else
                {
                    swap( current, right );
                    current = 2*current + 1;
                }
            }
        }
        else if ( left <= count && right > count )
        {
            if ( heap[current] <= heap[left] )
            {
                break;
            }
            else
            {
                swap( current, left );
                current = 2*current;
            }
        }
        else
        {
            break;
        }

    }
    return min;
}

int main()
{
    int i, n, x, y, sum;

    while ( scanf("%i", &n ) == 1 && n )
    {
        init();

        sum = 0;

        for ( i = 0; i < n; i++ )
        {
            scanf("%i", &x );

            insert( x );
        }

        for ( i = 0; i < n - 1; i++ )
        {
            x = pop();
            y = pop();
            sum = sum + x + y;
            insert( x + y );
        }

        printf("%i\n", sum );
    }

    return 0;
}
