#include <iostream>
#include <fstream>

using namespace std;

//#define read cin

int index;

int countBlackPixels(string &s, int pixelCount) {
   // cout << "called function with index = " << index << endl;
   // cout << "pixelCount = " << pixelCount << endl;
    if (index >= s.length()) {
        return 0;
    }
    if (s[index] == 'f') {
  //      cout << "index now " << index + 1 << endl;
    //    cout << "\treturning pixelCount^2" << endl;
        index++;
        return pixelCount*pixelCount;
    } else if (s[index] == 'e') {
    //    cout << "index now " << index + 1 << endl;
        index++;
        return 0;
    }
    index++;
    int sum = 0;
    for (int i = 0; i < 4; i++) { /* s[index] == 'p' -> Process the 4 children */
        if (s[index] == 'p')
            sum += countBlackPixels(s, pixelCount/2);
        else
            sum += countBlackPixels(s, pixelCount/2);
    }
    return sum;
}

int main() {
    ifstream read("test.txt");
    int ncases, sum;
    string line;

    read >> ncases; getline(read, line);
    for (int i = 0; i < ncases; i++) {
        sum = 0;
        index = 0;
        getline(read, line);
        sum += countBlackPixels(line, 32);
        /*
        getline(read, line);
        cout << line << endl;
        index = 0;
        sum += countBlackPixels(line, 32);
        */
        cout << "There are " << sum << " black pixels." << endl;
    }
    read.close();
    return 0;
}
