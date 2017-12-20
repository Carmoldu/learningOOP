#include <iostream>
#include<string>
#include <vector>

using namespace std;


class Article {
private:
	string nom; double prixUnitaire; bool enAction;

public:
	Article(string n, double prix, bool enAct)
		:nom(n),prixUnitaire(prix),enAction(enAct){}
	Article(string n, double prix)
		:nom(n), prixUnitaire(prix), enAction(false) {}
	
	//getters
	string	getName()	const { return nom; }
	double	getPrice()	const { return prixUnitaire; }
	bool	getSale()	const { return enAction; }
};

class Achat {
private:
	Article article; int quantite; double total;

public:
	Achat(Article art, int quant)
		:article(art),quantite(quant)
	{	
		if (art.getSale()) { total = quant*art.getPrice()/2; }
		else { total = quant*art.getPrice(); }
	}

	void afficher() const 
	{
		cout << article.getName() << " : " << article.getPrice() << " x " << quantite << " = " << total << " Frs";
		if (article.getSale()) { cout << " (en action)" << endl; }
		else { cout << endl; }
	}

	double getTotal() const { return total; }
};

class Caddie {
private:
	vector<Achat> achats;

public:
	Caddie(){ achats.reserve(7); }

	void remplir (Article art, unsigned int quant=1)
		{  
		achats.push_back(Achat(art, quant));
		}

	int caddieSize() const { return achats.size(); }

	double caddieContent() const{
		double total(0.0);
		for (int i = 0; i < caddieSize(); i++) {
			achats[i].afficher();
			total += achats[i].getTotal();
			}
		return total;
	}
};

class Caisse {
private:
	double total;

public:
	Caisse():total(0.0){}

	void scanner(Caddie const& cad) {
		total += cad.caddieContent();

		cout << "-----" << endl << "Total à payer : " << total << " F" << endl;
	}

	void afficher() const { cout << total << " F"; }
};

// ======================================================================
int supermarche()
{
  // Les articles vendus dans le supermarché
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }

  return 0;
}
