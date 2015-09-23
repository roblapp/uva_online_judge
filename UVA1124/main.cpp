#include <iostream>
#include <string>

/*
Accepted: 0.000s
Description: A very stupid problem. I did not even understand what the question
was looking for until I looked up this problem online. Just read each line and
print it. Definitely a problem where the directions try and throw you off and
make you think harder than you should!
*/

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        cout << line << endl;
    }
    return 0;
}
