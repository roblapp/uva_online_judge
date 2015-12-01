#include <iostream>
#include <queue>
#include <sstream>

/*
Accepted: 0.009s
Description: data structures - priority queues
*/

#define read cin

using namespace std;

typedef struct Record Record;

struct Record {
    int qnum, freq, originalFreq;
    bool operator<(const Record &rhs) const {
        if (freq > rhs.freq) return true;
        else if (freq < rhs.freq) return false;
        return qnum > rhs.qnum;
    };
};

int main() {
    string line, token;
    int qnum, freq, x;
    priority_queue<Record> q;
    Record r;

    while (getline(read, line) && line != "#") {
        stringstream ss(line);
        ss >> token >> qnum >> freq;
        r.qnum = qnum;
        r.freq = freq;
        r.originalFreq = freq;
        q.push(r);
    }
    read >> x;
    while (x--) {
        r = q.top(); q.pop();
        cout << r.qnum << endl;
        r.freq += r.originalFreq;
        q.push(r);
    }
    return 0;
}
