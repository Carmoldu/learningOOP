#include<iostream>

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

private:
	double X, Y, Z;
};



void coord3D() {
	Point3D point1, point2, point3;

	point1.init(1.0, 2.0, -0.1);
	point2.init(2.6, 3.5, 4.1);
	point3 = point1;

	point1.show();
	point2.show();
	point3.show();

	if (point1.compare(point2)) { cout << "Point 1 and 2 have the same coordinates" << endl; }
	else{ cout << "Point 1 and 2 do not have the same coordinates" << endl; }

	if (point1.compare(point3)) { cout << "Point 1 and 3 have the same coordinates" << endl; }
	else { cout << "Point 1 and 3 do not have the same coordinates" << endl; }

	if (point3.compare(point2)) { cout << "Point 2 and 3 have the same coordinates" << endl; }
	else{ cout << "Point 2 and 3 do not have the same coordinates" << endl; }
}