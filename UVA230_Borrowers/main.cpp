#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/*
Accepted: 0.000s
Description: ad-hoc, 1D array processing
*/

#define read cin

using namespace std;

class Book {
public:
    string author, title;
    Book(string &a, string &t) : author(a), title(t) {};
};

bool compare(Book *ba, Book *bb) {
    int ac = ba->author.compare(bb->author);
    if (ac < 0) return true;
    else if (ac > 0) return false;
    else return (ba->title.compare(bb->title) < 0);
}

int main() {
    string line, temp, title, author;
    map<string, int> m;
    vector<Book*> v;
    int i, len;
    bool *isBorrowed;
    bool first;
    while (getline(read, line) && line != "END") {
        stringstream ss(line);
        title = "";
        first = true;
        while (ss >> temp) {
            title += (first) ? temp : " " + temp;
            first = false;
            if (temp[temp.length()-1] == '"') break;
        }
        ss >> temp; /* consume the word 'by' */
        author = "";
        first = true;
        while (ss >> temp) {
            author += (first) ? temp : " " + temp;
            first = false;
        }
        v.push_back(new Book(author, title));
    }
    sort(v.begin(), v.end(), compare);
    len = v.size();
    isBorrowed = new bool[len];
    for (i = 0; i < len; i++) {
        m[v[i]->title] = i;
        isBorrowed[i] = false;
    }

    map<string, int>::iterator it;
    string helper;
    vector<int> soln;
    while (read >> line && line != "END") {
        if (line == "SHELVE") {
            sort(soln.begin(), soln.end());
            for (i = 0, len = soln.size(); i < len; i++) {
                int j;
                for (j = soln[i] - 1; j >= 0 && isBorrowed[j]; j--) ;
                if (j < 0) cout << "Put " << v[soln[i]]->title << " first" << endl;
                else cout << "Put " << v[soln[i]]->title << " after " << v[j]->title << endl;
                isBorrowed[soln[i]] = false;
            }
            cout << "END" << endl;
            soln.clear();
        } else {
            getline(read, helper);
            stringstream ss(helper);
            title = "";
            first = true;
            while (ss >> temp) {
                title += (first) ? temp : " " + temp;
                first = false;
            }
            if (line == "BORROW") {
                it = m.find(title);
                if (it != m.end()) {
                    isBorrowed[it->second] = true;
                }
            } else if (line == "RETURN") {
                it = m.find(title);
                if (it != m.end()) {
                    soln.push_back(it->second);
                }
            }
        }
    }
    for (vector<Book*>::iterator itv = v.begin(); itv != v.end(); itv++) {
        delete *itv;
    }
    delete[] isBorrowed;
    return 0;
}
