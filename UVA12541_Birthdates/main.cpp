#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

#define read cin

using namespace std;

struct Date {
    string name;
    int day, month, year;
};

typedef struct Date Date;

bool isLessThan(Date da, Date db) {
    if (da.year < db.year) return true;
    else if (da.year > db.year) return false;
    else {
        if (da.month < db.month) return true;
        else if (da.month > db.month) return false;
        else {
            return da.day < db.day;
        }
    }
}

bool isGreaterThan(Date da, Date db) {
    return !isLessThan(da, db);
}

int main() {
    int n, dd, mm, yy;
    string name;
    Date d = {}, minDate = {}, maxDate = {};
    bool first = true;
    read >> n;
    while (n--) {
        getline(read, name); /* Drain newline */
        read >> name >> dd >> mm >> yy;
        d.name = name;
        d.day = dd;
        d.month = mm;
        d.year = yy;
        if (first) {
            maxDate.name = minDate.name = name;
            maxDate.day = minDate.day = dd;
            maxDate.month = minDate.month = mm;
            maxDate.year = minDate.year = yy;
        } else {
            if (isLessThan(d, minDate)) {
                minDate.name = d.name;
                minDate.day = d.day;
                minDate.month = d.month;
                minDate.year = d.year;
            } else if (isGreaterThan(d, maxDate)) {
                maxDate.name = d.name;
                maxDate.day = d.year;
                maxDate.month = d.month;
                maxDate.year = d.year;
            }
        }
        first = false;
    }
    cout << maxDate.name << endl << minDate.name << endl;
    return 0;
}
