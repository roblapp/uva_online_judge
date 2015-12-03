#include <iostream>
#include <fstream>

using namespace std;

//#define read cin
#define MAXN 1000

int main() {
    ifstream read("test.txt");
    int n, x;
    int a[MAXN];

    while (read >> n && n != 0) {
        while (1) {
            read >> x;
            if (x == 0)
                break;
            int i = 0;
            a[i++] = x;
            while (i < n) {
                read >> x;
                a[i++] = x;
            }
            if (n <= 2) {
                cout << "Yes" << endl;
            } else {
                bool isYes = true;
                for (int j = 0; isYes && j < n - 2; j++)
                    if (a[j] > a[j+1] && a[j] > a[j+2] && a[j+1] < a[j+2])
                        isYes = false;
                if (isYes)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
        cout << endl;
    }
    read.close();
    return 0;
}
