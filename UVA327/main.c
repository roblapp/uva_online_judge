#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* ACCEPTED 0.052s */

#define MAXLINE 10000
#define LEN 26
#define DIFF 97

bool eof_read = false;

int getline(char *s, char *nws, FILE *fp) {
    if (eof_read) return (-1);
    char c;
    int i = 0, k = 0;
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        s[i++] = c;
        if (!isspace(c)) {
            nws[k++] = c;
        }
    }

    if (c == EOF) eof_read = true;
    nws[k] = 0;
    s[i] = 0;
    return i;
}

void pre_post(char *s, int vals[], int start, int stop, int shift) {
    int i;
    for (i = start; i < stop; i++) {
        if (isalpha(s[i]) && s[i + shift] == s[i + 2*shift]) {
            if (s[i + shift] == '+') vals[s[i] - DIFF]++;
            else if (s[i + shift] == '-') vals[s[i] - DIFF]--;
        }
    }
}

int exp_eval(int a, int b, char op) {
    return (op == '+') ? a + b : a - b;
}

int unary_exp_eval(int a, char op) {
    return (op == '-') ? -a : a;
}

bool isoperator(char c) {
    return ((c == '+') || (c == '-'));
}

int evaluate(char *exp, bool used[], int vals[]) {
    int i = 0, res = 0, opcount = 0, varcount = 0;
    char op;
    while (exp[i]) {
        if (isalpha(exp[i])) {
            varcount++;
            if (varcount == 1) {
                res = vals[exp[i] - DIFF];
                if (opcount == 1) {
                    res = unary_exp_eval(vals[exp[i] - DIFF], op);
                }
            } else if (varcount > 1) {
                res = exp_eval(res, vals[exp[i] - DIFF], op);
            }
            opcount = 0;
            used[exp[i] - DIFF] = true;
        } else if (isoperator(exp[i])) {
            opcount++;
            if (opcount == 1 || (opcount == 3 && exp[i] != exp[i-1])) {
                op = exp[i];
            }
        }
        i++;
    }
    return res;
}

void init(int vals[], bool used[]) {
    int i;
    for (i = 0; i < LEN; i++) vals[i] = (i + 1);
    for (i = 0; i < LEN; i++) used[i] = false;
}

int main() {

    char line[MAXLINE], exp[MAXLINE];
    int vals[LEN];
    bool used[LEN];
    int i, len, res;

    FILE *fp = stdin;

    while ((len = getline(line, exp, fp)) > 0) {
        init(vals, used);
        pre_post(exp, vals, 2, len, -1);
        res = evaluate(exp, used, vals);
        pre_post(exp, vals, 0, len - 2, 1);
        printf("Expression: %s\n", line);
        printf("    value = %i\n", res);
        for (i = 0; i < LEN; i++) {
            if (used[i]) {
                printf("    %c = %i\n", (i + DIFF), vals[i]);
            }
        }
    }

    fclose(fp);

    return 0;
}
