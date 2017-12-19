#include<iostream>
#include<string>
using namespace std;


class Peluche {
private:
	string name, species;
	double price;

public:
	//Constructors
	Peluche() 
		:name("Bobo"),	species("Bear"),	price(14.95) 
		{ cout << "Teddy bear created." << endl; }
	Peluche(string n, string s, double p) 
		:name(n),		species(s),			price(p) 
		{ cout << "Teddy bear created." << endl; }
	Peluche(Peluche const& original)
		:name(original.name+"-copy"),	species(original.species), price(original.price)
		{cout << "Copy of " << original.getName() << " created, named " << name << "." << endl;}


	//Destructor
	~Peluche()
		{cout << "The teddy bear " << name << " has been eliminated." << endl;}

	//Setter
	void   newPrice(double newP) { price = newP; }

	//Getters
	string getName()    const    { return name; }
	string getSpecies() const    { return species; }
	double getPrice()   const    { return price; }
};


void etiquette(Peluche const& pel) {
	cout << "\tTeddy bear name: "	<< pel.getName()	<< endl;
	cout << "\tSpecies: "			<< pel.getSpecies() << endl;
	cout << "\tPrice: "				<< pel.getPrice()	<< endl << endl;
}


int peluche() {
	Peluche peluch, peluch1("Boris", "Dolphin", 12.25), peluch2(peluch1);

	cout << "Ticket:" << endl;
	etiquette(peluch);

	cout << "Ticket:" << endl;
	etiquette(peluch1);

	cout << "Ticket:" << endl;
	etiquette(peluch2);

	{
		Peluche peluch3(peluch2);
		cout << "Ticket:" << endl;
		etiquette(peluch3);
	}

	return 0;
}