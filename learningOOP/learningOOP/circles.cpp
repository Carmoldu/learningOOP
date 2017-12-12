#include<iostream>
#include<math.h>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle
{
public:
	void setRadius(double);
	void setCentre(double, double);

	double getRadius() const;
	void getCentre(double&, double&) const;

	//Other methods
	double surface() const;
	bool isInside(double, double) const;

private:
	double radius; double centre[2];

	void setXcoord(double);
	void setYcoord(double);
};

void Circle::setRadius(double r) { radius = r; }
void Circle::setXcoord(double x) { centre[0] = x; }
void Circle::setYcoord(double y) { centre[1] = y; }
void Circle::setCentre(double x, double y) { setXcoord(x); setYcoord(y); }
double Circle::getRadius() const { return radius; }
void Circle::getCentre(double& x, double& y) const { x = centre[0]; y = centre[1]; }
double Circle::surface() const { return M_PI*radius*radius; }
bool Circle::isInside(double x, double y) const {
	double distance2centre;

	distance2centre = sqrt(pow(x - centre[0], 2) + pow(y - centre[1], 2));

	if (distance2centre <= radius) { return true; }
	else { return false; }
}

void circles() {
	Circle circ1, circ2;
	double in1, in2;

	cout << "Introduce first circle radius: "; cin >> in1; circ1.setRadius(in1);
	cout << "Introduce first circle centre: "; cin >> in1 >> in2; circ1.setCentre(in1, in2);

	cout << "Introduce second circle radius: "; cin >> in1; circ2.setRadius(in1);
	cout << "Introduce second circle centre: "; cin >> in1 >> in2; circ2.setCentre(in1, in2);

	circ1.getCentre(in1, in2);
	cout << endl << "First circle info:" << endl << "Centre: (" << in1 << "," << in2 << ")\tRadius: " << circ1.getRadius() << "\tSurface: " << circ1.surface() << endl << endl;

	circ2.getCentre(in1, in2);
	cout << endl << "Second circle info:" << endl << "Centre: (" << in1 << "," << in2 << ")\tRadius: " << circ2.getRadius() << "\tSurface: " << circ2.surface() << endl << endl;




	cout << "Introduce a point: "; cin >> in1 >> in2;

	if (circ1.isInside(in1, in2)) {
		cout << "The point is inside circle 1." << endl;
	}else{ cout << "The point is not inside circle 1." << endl; }

	if (circ2.isInside(in1, in2)) {
		cout << "The point is inside circle 2." << endl;
	}
	else { cout << "The point is not inside circle 2." << endl; }
}