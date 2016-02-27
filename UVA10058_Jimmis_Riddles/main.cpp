#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define NOUN "NOUN"
#define VERB "VERB"
#define ARTICLE "ARTICLE"
#define AND "AND"
#define COMMA ","

bool matchNouns(map<string,string> &m, vector<string> &v, int &i, int N) {
    if (i >= N)
        return false;

    if (m[v[i]] == ARTICLE)
        i++;

    if (m[v[i]] != NOUN)
        return false;
    i++;
    while (i < N and m[v[i]] == AND) {
        i++;
        if (i < N and m[v[i]] == ARTICLE)
            i++;
        if (i >= N or m[v[i]] != NOUN)
            return false;
        i++;
    }
    return true;
}

/* Note: verbs can have any amount of s characters appended to it. Although my
first solution did NOT take this into account I got Accepted. However, I wanted
to make my solution correct so I re-submitted it with these cases handled */
bool matchVerb(map<string,string> &m, vector<string> &v, int &i, int N) {
    if (i >= N)
        return false;
    int NS = (int) v[i].length();
    int bound = min(NS, 4);
    string temp = v[i].substr(0, bound);
    if (m[temp] != VERB) {
        return false;
    }
    /* length of temp will be > 4 since anything less would have failed above */
    /* now we must make sure there are only 's' characters for the remainder of the string */
    for (int j = 4; j < NS; j++)
        if (v[i][j] != 's')
            return false;
    i++;
    return true;
}

bool matchComma(vector<string> &v, int &i, int N) {
    if (i >= N or v[i] != COMMA)
        return false;
    i++;
    return true;
}

bool match(map<string,string> &m, vector<string> &v, int &i, int N) {
    if (!matchNouns(m, v, i, N) or i >= N)
        return false;
    if (!matchVerb(m, v, i, N) or i >= N)
        return false;
    if (!matchNouns(m, v, i, N))
        return false;
    if (i == N) /* no , ACTION --we are done */
        return true;
    if (!matchComma(v, i, N))
        return false;
    return match(m, v, i, N);
}

int stringToTokens(vector<string> &v, string &s) {
    int i = 0, N = s.length();
    int startIndex = 0, cnt = 0, ntokens = 0;

    while (i < N) {
        if (!isspace(s[i])) {
            while (i < N and !isspace(s[i])) {
                i++;
                cnt++;
            }
            v.push_back(s.substr(startIndex, cnt));
            ntokens++;
        } else {
            cnt = 0;
            i++;
            startIndex = i;
        }
    }
    return ntokens;
}

bool isValidString(map<string,string> &m, string &s) {
    vector<string> v;
    int i = 0, N = stringToTokens(v, s);
    return match(m, v, i, N);
}

void init(map<string,string> &m) {
    m["tom"] = NOUN; m["jerry"] = NOUN; m["goofy"] = NOUN; m["mickey"] = NOUN;
    m["jimmy"] = NOUN; m["dog"] = NOUN; m["cat"] = NOUN; m["mouse"] = NOUN;
    m["hate"] = VERB; m["hates"] = VERB; m["love"] = VERB; m["loves"] = VERB; m["know"] = VERB;
    m["knows"] = VERB; m["like"] = VERB; m["likes"] = VERB; m["a"] = ARTICLE; m["the"] = ARTICLE;
    m["and"] = AND;
}

int main() {
	string line;
	map<string,string> m;

	init(m);
	while (getline(cin, line))
        (isValidString(m, line)) ? cout << "YES I WILL" << endl : cout << "NO I WON'T" << endl;

    return 0;
}
