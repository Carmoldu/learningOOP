#include<iostream>

using namespace std;

class Aperit {
private:

public:
	//Constructors
	Aperit()
		{cout << "It is apperitive time!" << endl;}

	//Destructor
	~Aperit() { cout << "Lunch is ready!" << endl; }

	//Other methods
	void bis() { cout << "Do you want another one?" << endl; }

};


int aperitive() {
	Aperit bic;
	cout << "Super !" << endl;
	bic.bis();
	cout << "No thanks." << endl;
	return 0;
}