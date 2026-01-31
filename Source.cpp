#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	int x, y;
	Point(int X = 0, int Y = 0) : x(X), y(Y) {}
};

template <class T>
class Line {
protected:
	T p1, p2;
public:
	Line(T t1, T t2) : p1(t1), p2(t2) {}
	double distance() {
		return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	}
};

template <>
class Line<int> {
protected:
	int p1, p2;
public:
	Line(int t1, int t2) : p1(t1), p2(t2) {}
	double distance() {
		return abs(p1 - p2);
	}
};

template <class T>
class Circle : public Line<T> {
private:
	double radius;
public:
	Circle(T t1, T t2) : Line<T>(t1, t2) {
		radius = this->distance() / 2.0;
	}
	double getArea() {
		return 3.14159 * radius * radius;
	}
};

int main() {
	Point p1(3, 0), p2(0, 4);
	Line<Point> l1(p1, p2);
	cout << l1.distance() << endl;
	Circle<Point> c2(p1, p2);
	cout << c2.getArea() << endl;

	return 0;
}