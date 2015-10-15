#include <iostream>

/*
Accepted: 0.312s
Description: ad-hoc, a trick problem
Info: Don't be fooled... follow one example on paper and you can
see that the f91 function is a joke.
*/

using namespace std;

int main(){
    int n;
    while (cin >> n and n != 0) {
        if (n >= 101) cout << "f91(" << n << ") = " << n - 10 << endl;
        else cout << "f91(" << n << ") = 91" << endl;
    }
    return 0;
}
