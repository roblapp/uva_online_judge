#include <iostream>
#include <iomanip>
#include <sstream>

/*
Accepted: 0.000s
Category: ad-hoc
*/

using namespace std;

int getCost(char bracket, int time, int &c1, int &c2, int &c3) {
    int res = 0;
    if (time >= 801 and time <= 1800) {
        if (toupper(bracket) == 'A')
            res = 10;
        else if (toupper(bracket) == 'B')
            res = 25;
        else if (toupper(bracket) == 'C')
            res = 53;
        else if (toupper(bracket) == 'D')
            res = 87;
        else
            res = 144;
        c1++;
    } else if (time >= 1801 and time <= 2200) {
        if (toupper(bracket) == 'A')
            res = 6;
        else if (toupper(bracket) == 'B')
            res = 15;
        else if (toupper(bracket) == 'C')
            res = 33;
        else if (toupper(bracket) == 'D')
            res = 47;
        else
            res = 80;
        c2++;
    } else {
        if (toupper(bracket) == 'A')
            res = 2;
        else if (toupper(bracket) == 'B')
            res = 5;
        else if (toupper(bracket) == 'C')
            res = 13;
        else if (toupper(bracket) == 'D')
            res = 17;
        else
            res = 30;
        c3++;
    }
    return res;
}

int nextMinute(int time) {
    if (time % 100 == 59) {
        return (time + 41) % 2400;
    }
    return time + 1;
}

int compute(char bracket, int startTime, int endTime, int &c1, int &c2, int &c3) {
    int sum = 0;
    c1 = c2 = c3 = 0;
    if (startTime == endTime) {
        c1 = 600;
        c2 = 240;
        c3 = 600;
        sum = 8640;
    } else if (startTime < endTime) {
        for (int i = nextMinute(startTime); i <= endTime and i != 0; i = nextMinute(i)) {
            sum += getCost(bracket, i, c1, c2, c3);
        }
    } else {
        for (int i = nextMinute(startTime); i != 0; i = nextMinute(i)) {
            sum += getCost(bracket, i, c1, c2, c3);
        }
        for (int i = 0; i <= endTime; i = nextMinute(i)) {
            sum += getCost(bracket, i, c1, c2, c3);
        }
    }
    return sum;
}

int main() {
	string line, number;
	char bracket;
	int startHour, startMin, endHour, endMin;

	while (1) {
        getline(cin, line);
        if (line[0] == '#')
            break;
        stringstream ss(line);
        ss >> bracket >> number >> startHour >> startMin >> endHour >> endMin;
        int c1, c2, c3;
        int res = compute(bracket, startHour*100 + startMin, endHour*100 + endMin, c1, c2, c3);
        cout << setw(10) << number;
        cout << setw(6) << c1;
        cout << setw(6) << c2;
        cout << setw(6) << c3;
        cout << setw(3) << bracket;
        cout << setw(5) << res / 100 << ".";
        cout << setw(2) << setfill('0') << res % 100 << endl;
        cout << setfill(' ');
	}
    return 0;
}
