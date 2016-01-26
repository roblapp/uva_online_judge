#include <iostream>
#include <vector>
#include <map>
#include <queue>

/*
Accepted: 0.003s
Description: topological sorting
Info: first used A.D.M. implementation of topological sorting, but this
problem called for a specific sort where ties were broken by which node
appeared first in the input. The ADM implementation was not able to handle
this requirement, so I had to look around and get some help on an implementation
that worked.
*/

using namespace std;

int main() {
	int ndrinks, npairs, src, dst, N = 1;
	string line, srcStr, dstStr;

	while (cin >> ndrinks) {
        map<string, int> m;
        vector<string> reverseMap;
        vector<vector<int> > graph(ndrinks);
        vector<int> indegree(ndrinks, 0);

        for (int i = 0; i < ndrinks; i++) {
            cin >> line;
            m[line] = i;
            reverseMap.push_back(line);
        }
        cin >> npairs;
        for (int i = 0; i < npairs; i++) {
            cin >> srcStr >> dstStr;
            src = m[srcStr];
            dst = m[dstStr];
            graph[src].push_back(dst);
            indegree[dst]++;
        }
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < ndrinks; i++)
            if (indegree[i] == 0)
                pq.push(i);

        vector<int> soln;
        while (!pq.empty()) {
            int vertex = pq.top(); pq.pop();
            soln.push_back(vertex);
            for (vector<int>::iterator it = graph[vertex].begin(); it != graph[vertex].end(); it++)
                if (--indegree[*it] == 0)
                    pq.push(*it);
        }

        cout << "Case #" << N++ << ": Dilbert should drink beverages in this order:";
        for (vector<int>::iterator it = soln.begin(); it != soln.end(); it++)
            cout << " " << reverseMap[*it];
        cout << "." << endl << endl;
	}
    return 0;
}
