#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.039s
Description: ad-hoc
*/

#define read cin
#define DELIM ','

using namespace std;

class Entry {
public:
    string title, firstName, lastName, department, street, homePhone, workPhone, campusBox;
    void show() {
        cout    << "----------------------------------------" << endl
                << title << " " << firstName << " " << lastName << endl
                << street << endl
                << "Department: " << department << endl
                << "Home Phone: " << homePhone << endl
                << "Work Phone: " << workPhone << endl
                << "Campus Box: " << campusBox << endl;
    }

    bool operator<(const Entry &e) const {
        if (this->lastName < e.lastName) return true;
        return false;
    }
};

int main() {
    int n;
    string line;
    Entry e;
    vector<Entry> v;
    read >> n; getline(read, line); /* Eat newline */
    while (n--) {
        getline(read, e.department); /* Read department */
        while (getline(read, line) && !line.empty()) {
            stringstream ss(line);
            getline(ss, e.title, DELIM);
            getline(ss, e.firstName, DELIM);
            getline(ss, e.lastName, DELIM);
            getline(ss, e.street, DELIM);
            getline(ss, e.homePhone, DELIM);
            getline(ss, e.workPhone, DELIM);
            getline(ss, e.campusBox, DELIM);
            v.push_back(e);
        }
    }
    sort(v.begin(), v.end());
    for (vector<Entry>::iterator it = v.begin(); it != v.end(); it++) {
        it->show();
    }
    return 0;
}
