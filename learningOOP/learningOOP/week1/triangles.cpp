#include<iostream>
#include<math.h>

using namespace std;

class Point3D
{
public:
	void init(double x, double y, double z) { X = x; Y = y; Z = z; }
	void show() const { cout << "Point coordinates (x,y,z): (" << X << "," << Y << "," << Z << ")" << endl; }
	bool compare(Point3D point) {
		if (X == point.X && Y == point.Y && Z == point.Z) { return true; }
		else { return false; }
	}

	double distance(Point3D point) const {
		return sqrt(pow((X - point.X), 2) + pow((Y - point.Y), 2) + pow((Z - point.Z), 2));
	}
private:
	double X, Y, Z;
};


class Triangle {
public:
	void init(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
		point1.init(x1, y1, z1); point2.init(x2, y2, z2); point3.init(x3, y3, z3);
	}

	double perimeter() const {
		return point1.distance(point2)+ point2.distance(point3)+ point3.distance(point1);
	}

	bool isIsoceles() const {
		if (point1.distance(point2) == point2.distance(point3) || point1.distance(point2) == point3.distance(point1) || point2.distance(point3) == point3.distance(point1)) {
			return true;
		} else { return false; }
	}

private:
	Point3D point1, point2, point3;

};

void triangles() {

	Triangle triangle;

	triangle.init(0, 0, 0, 1, 1, 0, 2, 0, 0);

	cout << "Triangle perimeter: " << triangle.perimeter() << endl;

	if (triangle.isIsoceles()) { cout << "The triangle is isoceles." << endl; }
	else { cout << "The triangle is not isoceles." << endl; }

}