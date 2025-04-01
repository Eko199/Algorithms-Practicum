#include<bits/stdc++.h>
using namespace std;

double getArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs((x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1)) / 2;
}

int main() {
    int l, xb, yb, x, y;

    cin >> l >> xb >> yb;
    cin >>  x >> y;
    int xa = 0, ya = 0, xc = 0, yc = l;

    if (getArea(xc, yc, xb, yb, x, y) == 0) {
        swap(xa, xc);
        swap(ya, yc);
    } else if (getArea(xc, yc, xa, ya, x, y) == 0) {
        swap(xb, xc);
        swap(yb, yc);
    }

    double abc = getArea(xa, ya, xb, yb, xc, yc);
    double acm = getArea(xa, ya, x, y, xc, yc);

    if (acm * 2 < abc) {
        swap(xa, xb);
        swap(ya, yb);
    }

    double left = 0, right = 1, mid, xn, yn;

    for (unsigned i = 0; i < 128; ++i) {
        mid = (left + right) / 2.0;
        xn = xa + (xc - xa) * mid;
        yn = ya + (yc - ya) * mid;

        double amn = getArea(x, y, xn, yn, xa, ya);

        if (2 * amn > abc) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    cout << std::fixed << std::setprecision(6) << xn << " " << yn;
    return 0;
}