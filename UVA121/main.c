#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* ACCEPTED 0.013s */

int compute(double width, double height) {
    if (height < 1.0) return 0;
    int layers = floor((height - 1.0) / sqrt(0.75) + 1.0);
    int pipes_per_odd_full_row = floor(width);
    int pipes_per_even_full_row = pipes_per_odd_full_row - 1;

    if ((width - pipes_per_odd_full_row) >= 0.5)
       pipes_per_even_full_row = pipes_per_odd_full_row;

    int nSkew = ceil(layers / 2.0) * pipes_per_odd_full_row +
        floor(layers / 2.0) * pipes_per_even_full_row;

   return nSkew;
}

int main() {
    double a, b;
    char max_result[5];
    int max_pipes = 0;
    int temp;

    while (scanf("%lf %lf", &a, &b) == 2) {
        max_pipes = ((int) a) * ((int) b);
        strcpy(max_result, "grid");
        if ((temp = compute(a, b)) > max_pipes) {
            max_pipes = temp;
            strcpy(max_result, "skew");
        }
        if ((temp = compute(b, a)) > max_pipes) {
            max_pipes = temp;
            strcpy(max_result, "skew");
        }
        printf("%i %s\n", max_pipes, max_result);

    }

    return 0;
}
