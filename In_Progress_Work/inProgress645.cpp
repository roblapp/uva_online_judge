#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//#define read cin
//#define out cout
#define ROOT "ROOT"

struct Entry {
    string s;
    int pos;
    Entry(string _s, int _pos) : s(_s), pos(_pos) { /* cout << "$" << endl; */ }
};

bool compare(Entry ea, Entry eb) {
    if (ea.s == ROOT) return true;
    else if (eb.s == ROOT) return false;
    if (ea.s[0] == 'd') {
        if (eb.s[0] == 'd')
            return ea.pos < eb.pos;
        else
            return true;
    }
   //     return  ? ea.pos < eb.pos : true;
    return (eb.s[0] == 'd') ? false : ea.s < eb.s;
}

void printDir(vector<vector<Entry> > &v, vector<bool> &used, int k, int NCOLS, ofstream &out) {
    if (k >= NCOLS or used[k]) { /* done */
        return;
    }

    vector<Entry> temp = v[k];
    string prefix = "";

    if (k > 0) {
        for (int i = 0; i < k; i++)
            prefix += "|     ";
    }

    for (int i = 0; i < (int) temp.size(); i++) {
        out << prefix << temp[i].s << endl;
        if (temp[i].s[0] == 'd' or temp[i].s == "ROOT") {
            printDir(v, used, k + 1, NCOLS, out);
        }
    }
    used[k] = true;
}

void __debugPrint(vector<vector<Entry> > &v)
{
    for (int i = 0; i < (int) v.size(); i++)
    {
        cout << "depth " << i << ": ";
        for (int j = 0; j < (int) v[i].size(); j++)
        {
            if (j > 0)
                cout << ", ";
            cout << v[i][j].s;
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main() {
    ifstream read("test.txt");
	ofstream out("test_out.txt");
	int N = 0;
	string line;
	bool first = false;

	while (1) {
        int depth = 0, k = 0;
	    vector<vector<Entry> > v(1, vector<Entry>(1, Entry(string(ROOT), k++)));
        while (1) {
            if (!first)
                getline(read, line);
            if (line == "*") {
                //process
                /*
                cout << "PRE" << endl;
                __debugPrint(v);
                for (int i = 0; i < (int) v.size(); i++) {
                    sort(v[i].begin(), v[i].end(), compare);
                }
                cout << "POST" << endl;
                __debugPrint(v);
                */
                break;
            } else if (line == "]") {
                depth--;
            } else {
                if (line[0] == 'd') {
                    cout << "DIR " << line << endl;
                    depth++;
                }

                if (depth == (int) v.size()) {
                    v.push_back(vector<Entry>());
                }
                v[depth].push_back(Entry(line, k));
                cout << line << " " << k << endl;
                k++;
            }
            first = false;
        }
        int NCOLS = (int) v.size();
        for (int i = 0; i < NCOLS; i++)
            sort(v[i].begin(), v[i].end(), compare);
        if (N++)
            out << endl;
        out << "DATA SET " << N << ":" << endl;
        vector<bool> used(NCOLS, false);
        printDir(v, used, 0, NCOLS, out);

        getline(read, line);
        if (line == "#") {
            cout << "ALL DONE" << endl;
            break;
        }
        first = true;
	}
	out.close();
    read.close();
    return 0;
}
