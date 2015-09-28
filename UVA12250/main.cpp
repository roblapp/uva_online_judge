#include <iostream>

/*
Accepted: 0.000s
*/
using namespace std;

int main() {
    int i = 1;
    string line, result;
    while (getline(cin, line) && line != "#") {
        if (line == "HOLA") result = "SPANISH";
        else if (line == "HELLO") result = "ENGLISH";
        else if (line == "HALLO") result = "GERMAN";
        else if (line == "BONJOUR") result = "FRENCH";
        else if (line == "CIAO") result = "ITALIAN";
        else if (line == "ZDRAVSTVUJTE") result = "RUSSIAN";
        else result = "UNKNOWN";
        cout << "Case " << i++ << ": " << result << endl;
    }
    return 0;
}
