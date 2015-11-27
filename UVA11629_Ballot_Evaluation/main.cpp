#include <iostream>
#include <map>
#include <cmath>
#include <sstream>

/*
Accepted: 0.115s
Description: data structures - maps, parsing
*/

using namespace std;

#define read cin

bool isComparisonOperator(string &s) {
    return (s == "<" || s == ">" || s == "<=" || s == ">=" || s == "=");
}

bool isGuessCorrect(string &compareOp, int calculatedSum, int compareSum) {
    if (compareOp == "<")
        return (calculatedSum < compareSum);
    else if (compareOp == ">")
        return (calculatedSum > compareSum);
    else if (compareOp == "<=")
        return (calculatedSum <= compareSum);
    else if (compareOp == ">=")
        return (calculatedSum >= compareSum);
    return (calculatedSum == compareSum);
}

int main() {
    int nparties, nguesses, sum;
    double d;
    string line, name, token;
    map<string, int> m;

    read >> nparties >> nguesses; getline(read, line);
    for (int i = 0; i < nparties; i++) {
        getline(read, line);
        stringstream ss(line);
        ss >> name >> d;
        m[name] = (int) floor(10*d);
    }
    for (int i = 1; i <= nguesses; i++) {
        getline(read, line);
        stringstream ss(line);
        sum = 0;
        while (ss >> token && !isComparisonOperator(token))
            if (token != "+")
                sum += m[token];
        ss >> d;
        if (isGuessCorrect(token, sum, (int) 10*d))
            cout << "Guess #" << i << " was correct." << endl;
        else
            cout << "Guess #" << i << " was incorrect." << endl;
    }
    return 0;
}
