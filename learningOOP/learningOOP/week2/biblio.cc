#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caract√®res √  utiliser pour les affichages:
/*

√©t√© jet√©

d'un

n'est

L'oeuvre

biblioth√®que

d√©truit

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
	const Auteur getAuteur() const { return auteur; }
	string getLangue() const { return langue; }
	void affiche() const 
		{cout << titre << ", " << auteur.getNom() << ", en " << langue;}
};

class Exemplaire {
private:
	Oeuvre &oeuvre;

public:
	Exemplaire(Oeuvre &oeu)
		:oeuvre(oeu)
	{
		cout << "Nouvel exemplaire de : "; oeuvre.affiche(); cout << endl;
	}

	Exemplaire(Exemplaire const& original)
		:oeuvre(original.oeuvre)
	{
		cout << "Copie díun exemplaire de : "; oeuvre.affiche(); cout << endl;
	}

	~Exemplaire()
	{
		cout << "Un exemplaire de \""; oeuvre.affiche(); cout << "\" a ÈtÈ jetÈ !" << endl;
	}

	Oeuvre const& getOeuvre() const { return oeuvre; }

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
		cout << "La bibliothËque " << nom << " est ouverte !" << endl;
	}

	~Bibliotheque() {
		cout << "La bibliothËque " << nom << " ferme ses portes, et dÈtruit ses exemplaires :" << endl;
		for (unsigned int i = 0; i < exemplaires.size(); i++) {
			exemplaires[i]->~Exemplaire();
		}
	}

	string getNom() const { return nom; }
	
	void stocker(Oeuvre &oeu, int n=1) {
		for (int i = 0; i < n; i++) {
			exemplaires.push_back(new Exemplaire(oeu));
		}
	}

	void lister_exemplaires(string langue = "") const{
		if (langue.empty()) {
			for (unsigned int i = 0; i < exemplaires.size(); i++) {
				exemplaires[i]->affiche(); cout << endl;
				}
		}
		else {
			for (unsigned int i = 0; i < exemplaires.size(); i++) {
				const Oeuvre& oeuv = exemplaires[i]->getOeuvre();
				if (oeuv.getLangue() == langue) { exemplaires[i]->affiche(); cout << endl; }
			}
		}			
	}



	int compter_exemplaires(const Oeuvre& oeuv)	{
		int cont = 0;
		for (unsigned int i = 0; i < exemplaires.size(); i++) {
			const Oeuvre& itiOeuv = exemplaires[i]->getOeuvre();
			if ( itiOeuv.getTitre() == oeuv.getTitre()) { cont++;}
		}
		return cont;
	}

	void afficher_auteurs(bool hasAward=false) const {
		for (unsigned int i = 0; i < exemplaires.size(); i++) {
			
			const Oeuvre& oeuv = exemplaires[i]->getOeuvre();
			const Auteur& aut = oeuv.getAuteur();

			if (!hasAward){ cout << aut.getNom() << endl; }
			else { 
				if(aut.getPrix()) { cout << aut.getNom() << endl;} 
			}
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

	Oeuvre o1("Les Mis√©rables", a1, "fran√ßais"),
		o2("L'Homme qui rit", a1, "fran√ßais"),
		o3("Le Comte de Monte-Cristo", a2, "fran√ßais"),
		o4("Zazie dans le m√©tro", a3, "fran√ßais"),
		o5("The Count of Monte-Cristo", a2, "anglais");

	Bibliotheque biblio("municipale");
	biblio.stocker(o1, 2);
	biblio.stocker(o2);
	biblio.stocker(o3, 3);
	biblio.stocker(o4);
	biblio.stocker(o5);

	cout << "La biblioth√®que " << biblio.getNom()
		<< " offre les exemplaires suivants :" << endl;
	biblio.lister_exemplaires();

	const string langue("anglais");
	cout << " Les exemplaires en " << langue << " sont :" << endl;
	biblio.lister_exemplaires(langue);

	cout << " Les auteurs √  succ√®s sont :" << endl;
	biblio.afficher_auteurs(true);

	cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
		<< o3.getTitre() << endl;

	return 0;
}