#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Compl√©ter le code √  partir d'ici
  *******************************************************/
private:
	double poids; string couleur; int age, esperance_vie; bool clonee;
  
public:
	Souris(double w, string c, int a=0, int e_v=36)
		:poids(w),couleur(c),age(a),esperance_vie(e_v),clonee(false)
		{cout << "Une nouvelle souris !" << endl;}

	Souris(Souris const& original)
		:poids(original.poids), couleur(original.couleur), age(original.age),esperance_vie(original.esperance_vie*4/5), clonee(true)
		{cout << "Clonage d'une souris !" << endl;	}

	~Souris() { cout << "Fin d'une souris..." << endl; }

	void afficher() const 
	{
		if (clonee) {cout << "Une souris " << couleur << ", clonee,  de " << age << " mois et pesant " << poids << " grammes" << endl;}
		else { cout << "Une souris " << couleur << " de " << age << " mois et pesant " << poids << " grammes" << endl; }
	}

	void vieillir() 
	{ 
		age++; 
		if (clonee) 
		{
			if (age > (esperance_vie / 2)) { couleur = "verte"; }
		}
	}

	void evolue() {while (age != esperance_vie) { vieillir(); }	}


	/*******************************************
   * Ne rien modifier apr√®s cette ligne.
   *******************************************/
}; // fin de la classe Souris

int labo()
{
	Souris s1(50.0, "blanche", 2);
	Souris s2(45.0, "grise");
	Souris s3(s2);
	// ... un tableau peut-Ítre...
	s1.afficher();
	s2.afficher();
	s3.afficher();
	s1.evolue();
	s2.evolue();
	s3.evolue();
	s1.afficher();
	s2.afficher();
	s3.afficher();
	return 0;
}