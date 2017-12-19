#include<iostream>
#include<string>

using namespace std;

class Flower {
private:
	string type, color;

public:
	Flower(string typ, string col)
		:type(typ), color(col)
		{cout << type << " fraichement cueillie" << endl;}
	Flower(Flower const& flow)
		:type(flow.type), color(flow.color)
		{cout << "Fragile corolle taillée" << endl;	}
	~Flower() { cout << "qu'un simple soufle..." << endl; }

	void eclore() { cout << "veine de " << color << endl; }

};



int poem() {
	Flower f1("Violette", "bleu");
	Flower f2(f1);
	cout << "dans un cristal ";
	f2.eclore();
	cout << "Donne un poème un peu fleur bleue" << endl
		<< "ne laissant plus ";
	return 0;
}