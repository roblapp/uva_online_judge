#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Description: simple counting problem
Info: Originally I thought this was a backtracking problem
and was wondering how to prune... Thankfully I came to the
realization that in order for there to be a loop there has
to be the same number of Male connectors as Females.
*/

#define read cin

using namespace std;

int main() {
    int i, len, ncases, m, f, ntracks;
    string line, temp;
    read >> ncases; getline(read, line);
    while (ncases--) {
        getline(read, line);
        m = f = ntracks = 0;
        stringstream ss(line);
        while (ss >> temp) {
            for (i = 0, len = temp.length(); i < len; i++) {
                if (temp[i] == 'M') m++;
                else if (temp[i] == 'F') f++;
            }
            ntracks++;
        }
        if (m == f && ntracks > 1) cout << "LOOP" << endl;
        else cout << "NO LOOP" << endl;
    }
    return 0;
}
