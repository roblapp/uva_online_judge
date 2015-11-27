#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>

/*
Accepted: 0.000s
Description: data structures - map
*/

#define read cin
#define MAXLEN 100

using namespace std;

double computeEntropy(map<string, int> &m, int lambda) {
    double sum = 0.0, logLambda = log10(lambda);
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        sum += (it->second)*(logLambda - log10(it->second));
    }
    return (1.0/(lambda)*sum);
}

void insertWord(map<string, int> &m, char word[]) {
    map<string, int>::iterator it = m.find(word);
    if (it != m.end()) it->second = it->second + 1;
    else m[word] = 1;
}

bool isValidChar(char c) {
    return !(isspace(c) || c == ',' || c == '.' || c == ':' || c == ';'
            || c == '!' || c == '?' || c == '"' || c == '(' || c == ')');
}

int main() {
    string line;
    int i, len, wordIndex = 0, lambda = 0;
    double entropy, maxEntropy;
    char word[MAXLEN + 1];
    map<string, int> m;
    map<string, int>::iterator it;
    while (getline(read, line) && line != "****END_OF_INPUT****") {
        if (line == "****END_OF_TEXT****") {
            entropy = computeEntropy(m, lambda);
            maxEntropy = log10(lambda);
            printf("%i %.1lf %.0lf\n", lambda, entropy, 100*entropy/maxEntropy);
            lambda = 0;
            m.clear();
        } else {
            for (i = 0, len = line.length(); i <= len; i++) {
                if (i < len && isValidChar(line[i])) word[wordIndex++] = tolower(line[i]);
                else if (wordIndex > 0) {
                    word[wordIndex] = 0;
                    insertWord(m, word);
                    wordIndex = 0;
                    lambda++;
                }
            }
        }
    }
    return 0;
}
