#include <iostream>
#include <sstream>

/*
Accepted: 0.003s
Description: binary search
*/

using namespace std;

#define read cin

class Fraction {
public:
    double num, den;
    Fraction(double _n, double _d) : num(_n), den(_d) {};
    double getValue() { return num / den; }
    bool equals(Fraction &f) {
        return (num == f.num && den == f.den);
    }
};

void sternBrocotBinarySearch(stringstream &result, Fraction goal, Fraction lo, Fraction hi) {
    Fraction mid(lo.num + hi.num, lo.den + hi.den);
    if (mid.equals(goal))
        return;
    if (goal.getValue() < mid.getValue()) {
        result << "L";
        sternBrocotBinarySearch(result, goal, lo, mid);
    } else {
        result << "R";
        sternBrocotBinarySearch(result, goal, mid, hi);
    }
}

string sternBrocotBinarySearch(int num, int den) {
    Fraction goal(num, den), lo(0, 1), hi(1, 0);
    stringstream ss("");
    sternBrocotBinarySearch(ss, goal, lo, hi);
    return ss.str();
}

int main() {
	int num, den;

	while (read >> num >> den && (num != 1 || den != 1))
        cout << sternBrocotBinarySearch(num, den) << endl;
    return 0;
}
