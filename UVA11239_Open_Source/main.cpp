#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

/*
Accepted: 0.006s
Description: data structures - maps, sorting
*/

using namespace std;

#define read cin

typedef struct {
    string projectName;
    int nstudents;
} Entry;

bool isproject(string &s) {
    if (!s.empty() && isupper(s[0])) return true;
    return false;
}

bool compare(Entry ea, Entry eb) {
    if (ea.nstudents > eb.nstudents) return true;
    else if (ea.nstudents < eb.nstudents) return false;
    return (ea.projectName < eb.projectName);
}

int main() {
    string line, project;
    map<string, set<string> > m; /* projects, students */
    map<string, set<string> > m2; /* students, projects -> make sure only to count students who are in 1 project */
    vector<Entry> v;
    set<string> dummyset;
    Entry e;
    int index;

    bool skip = true;
    do {
        v.clear(); m.clear(); m2.clear();
        index = -1;
        while (!skip || (getline(read, line) && line != "1")) {
            if (isproject(line)) {
                project = line;
                m.insert(pair<string, set<string> >(project, dummyset));
            } else {
                m[project].insert(line);
                m2[line].insert(project);
            }
            skip = true;
        }
        for (map<string, set<string> >::iterator it = m.begin(); it != m.end(); it++) {
            /* for each student in that project, make sure student only belongs to this project */
            e.nstudents = 0;
            e.projectName = it->first;
            v.push_back(e);
            index++;
            for (set<string>::iterator sit = it->second.begin(); sit != it->second.end(); sit++) {
                /* Every student will be in m2 by design */
                if (m2.find(*sit)->second.size() == 1) { /* the student counts */
                    v[index].nstudents = v[index].nstudents + 1;
                }
            }
        }
        sort(v.begin(), v.end(), compare);
        for (vector<Entry>::iterator vit = v.begin(); vit != v.end(); vit++) {
            cout << (*vit).projectName << " " << (*vit).nstudents << endl;
        }
        getline(read, line);
        skip = false;
    } while (line != "0");
    return 0;
}
