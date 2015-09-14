#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <sstream>

/* ACCEPTED 0.000s */
/*
Algorithm: Ad hoc
The idea: read each line and convert each term read into
a term object. Each pair of lines gets parsed into 2 vectors of term objects.
Then, go through and perform standard multiplication between the 2 vectors
eliminating terms that begin with 0 wherever possible.
*/
using namespace std;

class term {
public:
    int coeff, xpow, ypow;
    term() : coeff(0), xpow(0), ypow(0) {};
    term(int _coeff, int _xpow, int _ypow) : coeff(_coeff), xpow(_xpow), ypow(_ypow) {};
};

void processTerm(vector<term*> &v, int res, int pos, int offset) {
    if (offset == 0) v[pos]->coeff = res;
    else if (offset == 1) v[pos]->xpow = res;
    else  v[pos]->ypow = res;
}

void parseLine(string &line, vector<term*> &v) {
    v.push_back(new term);
    if (line[0] == '0') return;
    char pc;
    int i = 0, j = 0, len = line.length(), res = 0;
    if (line[i] == '-') pc = line[i];
    else pc = '+';
    if (line[i] == '-' || line[i] == '+') i++;
    while (i <= len) {
        if ((i == len) || (line[i] == 'x' || line[i] == 'y' || line[i] == '-' || line[i] == '+')) {
            if (pc == '-') {
                if (res == 0) res = 1;
                processTerm(v, -1*res, j, 0);
            }
            else if (pc == '+') {
                if (res == 0) res = 1;
                processTerm(v, res, j, 0);
            }
            else if (pc == 'x') {
                if (res == 0) res = 1;
                processTerm(v, res, j, 1);
            }
            else if (pc == 'y') {
                if (res == 0) res = 1;
                processTerm(v, res, j, 2);
            }
            if (line[i] == '+' || line[i] == '-') {
                v.push_back(new term);
                j++;
            }
            if (i != len) {
                pc = line[i];
            }
            res = 0;
        } else if (isdigit(line[i])) {
            res = 10*res + (line[i] - '0');
        }
        i++;
    }
}

bool compare(term *ta, term *tb) {
    if (ta->xpow > tb->xpow) {
        return true;
    } else if (ta->xpow < tb->xpow) {
        return false;
    } else if (ta->ypow < tb->ypow) {
        return true;
    }
    return false;
}

int numLen(int n) {
    stringstream ss;
    ss << n;
    return ss.str().length();
}

string whiteSpace(int n) {
    stringstream ss;
    for (int i = 0; i < n; i++) ss << " ";
    return ss.str();
}

void preProcess(stringstream &top, stringstream &bot, int c, int x, int y, bool first) {
    if (first && c < 0) {
        bot << "-";
        top << " ";
    } else if (c < 0) {
        bot << " - ";
        top << "   ";
    } else if (!first) {
        bot << " + ";
        top << "   ";
    }
    if ((x == 0 and y == 0) or (abs(c) != 1)) { /* Force to print coefficient */
        bot << abs(c);
        top << whiteSpace(numLen(abs(c)));
    }
}

void process(stringstream &top, stringstream &bot, char tc, int pow, bool first) {
    top << " ";
    bot << tc;
    if (pow > 1) {
        top << pow;
        bot << whiteSpace(numLen(pow));
    }
}

void formatSolution(vector<term*> &soln) {
    int coeff, xpow, ypow;
    term *t;
    stringstream top, bot;
    bool first = true;
    for (vector<term*>::iterator it = soln.begin(); it != soln.end(); it++) {
        t = *it;
        coeff = t->coeff;
        xpow = t->xpow;
        ypow = t->ypow;
        preProcess(top, bot, coeff, xpow, ypow, first);
        if (xpow != 0) process(top, bot, 'x', xpow, first);
        if (ypow != 0) process(top, bot, 'y', ypow, first);
        first = false;
     }
     cout << top.str() << endl;
     cout << bot.str() << endl;
}

int main() {
    string line;
    vector<term*> poly0, poly1, soln;
    int cnt = 0, coeff, xpow, ypow;
    bool combined;
    term *t0, *t1, *t2;
    while (1) {
        getline(cin, line);
        if (line == "#") {
            break;
        }
        if (cnt == 0) {
            parseLine(line, poly0);
        } else {
            parseLine(line, poly1);
        }

        if (cnt == 1) {
            for (vector<term*>::iterator it0 = poly0.begin(); it0 != poly0.end(); it0++) {
                t0 = *it0;
                for (vector<term*>::iterator it1 = poly1.begin(); it1 != poly1.end(); it1++) {
                    t1 = *it1;
                    coeff = t0->coeff * t1->coeff;
                    xpow = t0->xpow + t1->xpow;
                    ypow = t0->ypow + t1->ypow;
                    combined = false;
                    for (vector<term*>::iterator solnit = soln.begin(); coeff != 0 && !combined && solnit != soln.end(); solnit++) {
                        t2 = *solnit;
                        if (t2->xpow == xpow && t2->ypow == ypow) {
                            t2->coeff = t2->coeff + coeff;
                            combined = true;
                            if (t2->coeff == 0) {
                                soln.erase(solnit);
                            }
                        }
                    }
                    if (!combined && coeff != 0) {
                        soln.push_back(new term(coeff, xpow, ypow));
                    }
                }
            }
            if (soln.size() == 0) {
                cout << " " << endl;
                cout << "0" << endl;
            } else {
                sort(soln.begin(), soln.end(), compare);
                formatSolution(soln);
            }
            for (vector<term*>::iterator it = poly0.begin(); it != poly0.end(); it++) delete *it;
            for (vector<term*>::iterator it = poly1.begin(); it != poly1.end(); it++) delete *it;
            for (vector<term*>::iterator it = soln.begin(); it != soln.end(); it++) delete *it;
            poly0.clear(); poly1.clear(); soln.clear();
            cnt = 0;
        } else {
            cnt++;
        }
    }
    return 0;
}
