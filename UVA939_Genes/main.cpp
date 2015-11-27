#include <iostream>
#include <map>
#include <vector>

/*
Accepted: 0.009s
Description: data structures - maps, recursion
*/

#define read cin
#define DOMINANT "dominant"
#define RECESSIVE "recessive"
#define NON_EXISTENT "non-existent"

using namespace std;

class Entry {
public:
    vector<string> parents;
    string status;
    Entry() {
        status = "";
    }
};

bool hasGene(string status) {
    if (status.empty())
        return false;
    if (status == RECESSIVE || status == DOMINANT)
        return true;
    return false;
}

string getStatus(map<string, Entry*> &m, Entry *e) {
    if (e->status.empty()) {
        vector<string> parents = e->parents;
        if (parents.size() == 0) { /* Not sure if this can ever happen */
            e->status = NON_EXISTENT;
            return NON_EXISTENT;
        }
        string pa, pb;
        Entry *ea = m.find(parents[0])->second;
        pa = (ea->status.empty()) ? getStatus(m, ea) : ea->status;

        Entry *eb = m.find(parents[1])->second;
        pb = (eb->status.empty()) ? getStatus(m, eb) : eb->status;

        bool hasA = hasGene(pa);
        bool hasB = hasGene(pb);
        /* the child has the gene if, and only if, both parents have it or it is dominant in one of the parents */
        if ((hasA && hasB) || (pa == DOMINANT) || (pb == DOMINANT)) {
            /*  the child’s gene is dominant if, and only if, the gene is dominant in both parents
                or dominant in one and recessive in the other parent */
            if ((pa == DOMINANT && pb == DOMINANT) ||
                (pa == DOMINANT && pb == RECESSIVE) ||
                (pa == RECESSIVE && pb == DOMINANT)) {
                e->status = DOMINANT;
                return DOMINANT;
            }
            e->status = RECESSIVE;
            return RECESSIVE;
        }
        e->status = NON_EXISTENT;
        return NON_EXISTENT;
    } else { /* Status is empty */
        return e->status;
    }
}

int main() {
    int n;
    string a, b;
    map<string, Entry*> m;
    vector<string> parents;
    read >> n; getline(read, a);
    while (n--) {
        read >> a >> b;
        if (m.find(a) == m.end())
            m[a] = new Entry;
        if (b == "non-existent" || b == "recessive" || b == "dominant")
            m[a]->status = b;
        else {
            if (m.find(b) == m.end())
                m[b] = new Entry;
            m[b]->parents.push_back(a);
        }
    }
    for (map<string, Entry*>::iterator it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << getStatus(m, it->second) << endl;
    return 0;
}
