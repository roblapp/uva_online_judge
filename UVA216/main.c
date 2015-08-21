#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

/* ACCEPTED 0.052s */

#define MAXV 10

typedef struct point_entry point_entry;
typedef struct stack_entry stack_entry;
typedef struct stack stack;
typedef struct point point;

stack soln;
bool visited[MAXV];
double mind;
int N = 1;


struct point {
    int px, py;
};

struct point_entry {
    int srcx, srcy, dstx, dsty;
    double dist;
};

struct stack_entry {
    point_entry *data;
    stack_entry *next;
};

struct stack {
    stack_entry *head;
    int size;
};



void init() {
    int i;
    for (i = 0; i < MAXV; i++) {
        visited[i] = false;
    }
}

void init_stack(stack *s) {
    s->head = NULL;
    s->size = 0;
}

void push(stack *s, point_entry *p) {
    stack_entry *temp = (stack_entry *) malloc(sizeof(stack_entry));
    temp->data = p;
    temp->next = s->head;
    s->head = temp;
    s->size = s->size + 1;
}

point_entry *pop(stack *s) {
    if (s->head == NULL) {
        return NULL;
    }
    stack_entry *temp = s->head;
    point_entry *result = s->head->data;
    s->head = s->head->next;
    free(temp);
    s->size = s->size - 1;

    return result;
}

bool is_empty(stack *s) {
    return (s->size == 0);
}

void clear_stack(stack *s) {
    while (!is_empty(s)) {
        pop(s);
    }
}

void copy_stack(stack *s) {
    clear_stack(&soln);
    stack_entry *temp = s->head;
    while (temp != NULL) {
        push(&soln, temp->data);
        temp = temp->next;
    }
}

void show_stack(stack *s) {
    stack_entry *temp = s->head;
    double res = 0;
    printf("**********************************************************\n");
    printf("Network #%i\n", N++);
    while (temp != NULL) {
        printf("Cable requirement to connect (%i,%i) to (%i,%i) is %0.2lf feet.\n", temp->data->srcx, temp->data->srcy,
                                    temp->data->dstx, temp->data->dsty, (16.0 + temp->data->dist));
        res += (temp->data->dist + 16.0);
        temp = temp->next;
    }
    printf("Number of feet of cable required is %0.2lf.\n", res);
}

void process_solution(stack *s) {
    copy_stack(s);
}

void backtrack(int k, int n, int prev_node, double dist_so_far, double distances[MAXV][MAXV], stack *s, point p[]) {
    int i;

    if (dist_so_far > mind) {
        return;
    }

    if (k == n && dist_so_far < mind) {
        mind = dist_so_far;
        process_solution(s);
        return;
    }

    for (i = 0; i < n; i++) { /* For each node... */
        if (!visited[i]) {
            visited[i] = true;
            if (k != 0) { /* If not the first iteration... */
                /* Push the previous node and the i_th node to the stack */
                point_entry *ptemp = (point_entry *) malloc(sizeof(point_entry));
                ptemp->srcx = p[prev_node].px;
                ptemp->srcy = p[prev_node].py;
                ptemp->dstx = p[i].px;
                ptemp->dsty = p[i].py;
                ptemp->dist = distances[prev_node][i];

                push(s, ptemp);

                backtrack(k + 1, n, i, dist_so_far + distances[prev_node][i], distances, s, p);
            } else {
                backtrack(k + 1, n, i, dist_so_far, distances, s, p);
            }

            visited[i] = false;

            pop(s);
        }
    }
}

double distance(point pa, point pb) {
    double dx = 1.0 * (pa.px - pb.px) * (pa.px - pb.px);
    double dy = 1.0 * (pa.py - pb.py) * (pa.py - pb.py);

    return sqrt((dx + dy));
}

int main() {

    int i, j, k, nedges;
    point p[MAXV];
    double distances[MAXV][MAXV];
    stack s;

    while (scanf("%i", &nedges) == 1 && nedges > 0) {
        init();
        init_stack(&s);
        mind = INT_MAX;
        for (i = 0; i < MAXV; i++) {
            for (j = 0; j < MAXV; j++) {
                distances[i][j] = 0;
            }
        }

        for (i = 0; i < nedges; i++) {
            scanf("%i %i", &p[i].px, &p[i].py);
        }

        for (j = 0; j < nedges - 1; j++) {
            for (k = j + 1; k < nedges; k++) {
                distances[j][k] = distances[k][j] = distance(p[j], p[k]);
            }
        }

        backtrack(0, nedges, 0, 0, distances, &s, p);

        show_stack(&soln);
    }

    return 0;
}
