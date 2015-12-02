#include <iostream>
#include <vector>
#include <queue>

/*
Accepted: 0.385s
Description: graph, bfs traversal
*/

using namespace std;

#define read cin
#define MAXN 26
#define ASCII_DIFF 'A'

void bfsHelper(vector<int> v[], bool disc[], int vertex) {
    queue<int> q;
    int temp;
    q.push(vertex);
    disc[vertex] = true;
    while (!q.empty()) {
        vertex = q.front(); q.pop();
        vector<int> neighbors = v[vertex];
        for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
            temp = *it;
            if (!disc[temp]) {
                q.push(temp);
                disc[temp] = true;
            }
        }
    }
}

void bfs(vector<int> v[], bool isNode[], int &ntrees, int &nacorns) {
    bool disc[MAXN];
    ntrees = nacorns = 0;
    for (int i = 0; i < MAXN; i++) disc[i] = false;
    for (int i = 0; i < MAXN; i++) {
        if (isNode[i] && !disc[i]) {
            if (v[i].size() == 0) {
                nacorns++;
                disc[i] = true;
            } else {
                ntrees++;
                bfsHelper(v, disc, i);
            }
        }
    }
}

int main() {
    int ncases;
    string line;
    int src, dst, ntrees, nacorns;
    vector<int> v[MAXN];
    bool isNode[MAXN];

    read >> ncases; getline(read, line);
    for (int i = 0; i < ncases; i++) {
        for (int j = 0; j < MAXN; j++) {
            v[j].clear();
            isNode[j] = false;
        }
        while (getline(read, line) && line[0] != '*') {
            int j = 0;
            while (!isalpha(line[j]))
                j++;
            src = line[j++] - ASCII_DIFF;
            while (!isalpha(line[j]))
                j++;
            dst = line[j] - ASCII_DIFF;
            v[src].push_back(dst);
            v[dst].push_back(src);
            isNode[src] = isNode[dst] = true;
        }
        getline(read, line);
        for (int j = 0; line[j]; j++)
            if (isalpha(line[j]))
                isNode[line[j] - ASCII_DIFF] = true;
        bfs(v, isNode, ntrees, nacorns);
        cout << "There are " << ntrees << " tree(s) and " << nacorns << " acorn(s)." << endl;
    }
    return 0;
}
