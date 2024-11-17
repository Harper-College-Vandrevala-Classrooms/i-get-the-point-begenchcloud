#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    

    Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        double mid_x = (x + other.x) / 2;
        double mid_y = (y + other.y) / 2;
        return Point(mid_x, mid_y);
    }

    void prettyPrint() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {

    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    cout << "Distance between points: " << p1 - p2 << endl;

    cout << "Are points equal? " << (p1 == p2) << endl;

    cout << "Are points not equal? " << (p1 != p2) << endl;

    Point midpoint = p1 / p2;
    cout << "Midpoint between points: ";
    midpoint.prettyPrint();
    cout << endl;

    return 0;
}
