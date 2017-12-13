#include <iostream>
using namespace std;

/*****************************************************
* Compléter le code à partir d'ici
*****************************************************/
class Patient {
public:
	void init(double w, double h) {
		if (w >= 0 && h >= 0) { masse = w; hauteur = h; }
		else { hauteur = 0; masse = 0; }
	}
	void afficher() const { cout << "Patient : " << masse << " kg pour " << hauteur << " m" << endl; }
	double poids() const { return masse; }
	double taille() const { return hauteur; }

	double imc() const {
		if (hauteur > 0) { return masse / (hauteur*hauteur); }
		else { return 0; }
	}

private:
	double masse = 0, hauteur = 0;
};

/*******************************************
* Ne rien modifier après cette ligne.
*******************************************/

int imc()
{
	Patient quidam;
	double poids, taille;
	do {
		cout << "Entrez un poids (kg) et une taille (m) : ";
		cin >> poids >> taille;
		quidam.init(poids, taille);
		quidam.afficher();
		cout << "IMC : " << quidam.imc() << endl;
	} while (poids * taille != 0.0);
	return 0;
}