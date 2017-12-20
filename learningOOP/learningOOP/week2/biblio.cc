#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères �  utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

class Auteur {
private:
	string nom; bool awarded;

public:
	Auteur(string n, bool aw=false)
		:nom(n), awarded(aw)
	{}

	string getNom() const { return nom; }
	bool getPrix() const { return awarded; }
};

class Oeuvre {
private:
	string titre; Auteur const &auteur; string langue;

public:
	Oeuvre(string titl, Auteur const &aut, string lan)
		:titre(titl),auteur(aut),langue(lan)
	{}

	Oeuvre(const Oeuvre&) = delete;

	~Oeuvre()
	{
		cout << "L'oeuvre \"" << titre << ", " << auteur.getNom() << ", en " << langue << "\" n'est plus disponible" << endl;
	}

	string getTitre() const { return titre; }
	Auteur const getAuteur() { return auteur; }
	string getLangue() const { return langue; }
	void affiche() const 
		{cout << titre << ", " << auteur.getNom() << ", en " << langue;}
};

class Exemplaire {
private:
	Oeuvre const &oeuvre;

public:
	Exemplaire(Oeuvre const &oeu)
		:oeuvre(oeu)
	{
		cout << "Nouvel exemplaire de : "; oeuvre.affiche(); cout << endl;
	}

	Exemplaire(Exemplaire const& original)
		:oeuvre(original.oeuvre)
	{
		cout << "Copie d�un exemplaire de : "; oeuvre.affiche(); cout << endl;
	}

	~Exemplaire()
	{
		cout << "Un exemplaire de \""; oeuvre.affiche(); cout << "\" a �t� jet� !" << endl;
	}

	Oeuvre const& getOeuvre() { return oeuvre; }

	void affiche() const { cout << "Exemplaire de : "; oeuvre.affiche(); }
};

class Bibliotheque {
private:
	vector<Exemplaire *> exemplaires; string nom;

public:
	Bibliotheque(string n)
		:nom(n)
	{
		exemplaires.reserve(15);
		cout << "La biblioth�que " << nom << " est ouverte !" << endl;
	}

	string getNom() const { return nom; }
	void stocker(Oeuvre const& oeu, int n=1)
	{
		Exemplaire exemp(oeu);

		for (int i = 0; i < n; i++) 
		{
			exemplaires.push_back(&exemp);
		}
	}

	void lister_exemplaires(string langue) const
	{
		for (int i = 0; i < exemplaires.size(); i++)
		{
			Oeuvre &oeuv = *exemplaires[i].getOeuvre();
			if(oeuv.getLangue()==langue)
			{ }
		}
	}

};
/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int biblio()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs �  succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}