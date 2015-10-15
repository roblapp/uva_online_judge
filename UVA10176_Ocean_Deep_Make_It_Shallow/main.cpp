#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc, binary numbers, bitwise operations
*/

using namespace std;

int main(){
                char c;
                int num;
                while (cin >> c) {
        num = 0;
        num += (c - '0');
        while (cin >> c) {
            if (c == '#') break;
            num = num << 1;
            num += (c - '0');
            num %= 131071;
        }
        if (num == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
                }
                return 0;
}
