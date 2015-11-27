#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

#define read cin

char getDigit(char c) {
    c = tolower(c);
    if (c >= 'a' && c <= 'c') return '2';
    else if (c >= 'd' && c <= 'f') return '3';
    else if (c >= 'g' && c <= 'i') return '4';
    else if (c >= 'j' && c <= 'l') return '5';
    else if (c >= 'm' && c <= 'o') return '6';
    else if (c >= 'p' && c <= 's') return '7';
    else if (c >= 't' && c <= 'v') return '8';
    return '9';
}

int main() {
    string line, result;
    while (getline(read, line)) {
        result = "";
        for (int i = 0; line[i]; i++)
            result += (isalpha(line[i])) ? getDigit(line[i]) : line[i];
        cout << result << endl;
    }
    return 0;
}
