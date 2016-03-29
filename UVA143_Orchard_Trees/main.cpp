#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

/*
Accepted: 0.126s
Category: geometry/ad-hoc
Info: I kept getting WA. So I basically copied this solution:
    https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/I/143%20-%20Orchard%20Trees.cpp
*/

using namespace std;

struct Point{
    double x,y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

double signedArea(Point &p1, Point &p2, Point &p3){
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2;
}

bool ccw(Point &p1, Point &p2, Point &p3){
    return signedArea(p1, p2, p3) > -1e-9;
}

bool inConvexPolygon(Point p, vector<Point> &poly){
    for (int i = 1; i < (int) poly.size(); i++)
        if (!ccw(poly[i-1], poly[i], p))
            return false;

    if (!ccw(poly[2], poly[0], p))
        return false;

    return true;
}

int main() {
	int left, top, right, bottom, sum;
	double xa, xb, xc, ya, yb, yc;
	vector<Point> poly(3);

	while (1) {
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        if (xa == 0 and ya == 0 and xb == 0 and yb == 0 and xc == 0 and yc == 0) {
            break;
        }

        poly[0] = Point(xa, ya);
        poly[1] = Point(xb, yb);
        poly[2] = Point(xc, yc);
        if (!ccw(poly[0], poly[1], poly[2]))
            swap(poly[0], poly[2]);

        left = min(ceil(xa), min(ceil(xb), ceil(xc)));
        left = max(left, 1);
        right = max(floor(xa), max(floor(xb), floor(xc)));
        right = min(right, 99);
        bottom = min(ceil(ya), min(ceil(yb), ceil(yc)));
        bottom = max(bottom, 1);
        top = max(floor(ya), max(floor(yb), floor(yc)));
        top = min(top, 99);
        sum = 0;

        for (int y = bottom; y <= top; y++)
            for (int x = left; x <= right; x++)
                if (inConvexPolygon(Point(x, y), poly))
                    sum++;
        cout << setw(4) << sum << endl;
	}
    return 0;
}
