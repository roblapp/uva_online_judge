#include <iostream>
#include <vector>

/*
Accepted: 0.499s
Description: 1D array processing, linked lists
*/

#define read cin

using namespace std;

class Node {
public:
    Node *next;
    Node *prev;
    int data;
};

int main() {
    int i, j, x, y, l, r;
    while (read >> x >> y && (x != 0 || y != 0)) {
            vector<Node*> v(x + 2);
            v[0] = v[x+1] = NULL;
            for (j = 1; j <= x; j++) {
                v[j] = new Node;
            }
            for (j = 1; j <= x; j++) {
                v[j]->prev = v[j-1];
                v[j]->next = v[j+1];
                v[j]->data = j;
            }
            for (i = 0; i < y; i++) {
                read >> l >> r;
                if (v[l]->prev != NULL) {
                    cout << v[l]->prev->data;
                    v[l]->prev->next = v[r]->next;
                } else {
                    cout << "*";
                }
                if (v[r]->next != NULL) {
                    cout << " " << v[r]->next->data << endl;
                    v[r]->next->prev = v[l]->prev;
                } else {
                    cout << " *" << endl;
                }
            }
            for (j = 0; j <= x + 1; j++) {
                delete v[j];
            }
            v.clear();
            cout << "-" << endl;
    }
    return 0;
}
