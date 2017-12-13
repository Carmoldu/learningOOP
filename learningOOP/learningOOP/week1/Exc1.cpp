#include<iostream>

using namespace std;



class Rectangle
{
public:
	//
	void setLength(double);
	void setWidth(double);

	//
	double getLength() const;
	double getWidth() const;

	//Other methods
	double surface() const ;
	
	
private:
	double length, width;
};

double Rectangle::surface() const {
	return length*width;
}
void Rectangle::setLength(double l) {
	length = l;
}
void Rectangle::setWidth(double w) {
	width = w;
}
double Rectangle::getLength() const {
	return length;
}
double Rectangle::getWidth() const {
	return width;
}


//MAIN
void exc1() {

	Rectangle rect1;
	double in;

	cout << "Introduce length of the rectangle: "; cin >> in; rect1.setLength(in);
	cout << "Introduce width of the rectangle: "; cin >> in; rect1.setWidth(in);

	cout << "The surface of the rectangle is: " << rect1.surface() << endl;


	};