#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	string type;
	double balance, tax;
public:
	Account(string typ, double initBal)
		:type(typ), balance(initBal)
	{
		cout << "Created " << typ << " account with initial balance " << initBal << endl;
		if (typ.compare("private")) { tax = 0.02; }
		else if (typ.compare("savings")) { tax = 0.01; }
		else { type = "private"; tax = 0.02; cout << "Account type was invalid and set automatically to private." << endl; }
	}

	void closeAccount() { balance = (1 + tax)*balance; }
	double getBalance() const { return balance; }
	string getType() const { return type; }
};


class Client {
private:
	string name, town, gender;
	Account privAcc, savAcc;

public:
	Client(string nom, string ville, string gen, double bal1, double bal2)
		:name(nom), town(ville), gender(gen),
		privAcc("private",bal1),
		savAcc("savings", bal2)
		{
			afficher();
		}

	void afficher() const {
		if (!gender.compare("male")) { cout << "Client "; }
		else if (!gender.compare("female")) { cout << "Cliente "; }
		else { cout << "ClientX "; }

		cout << name << " de " << town << endl;
		cout << "   Compte " << privAcc.getType() << " : " << privAcc.getBalance() << " francs" << endl;
		cout << "   Compte " << savAcc.getType() << " : " << savAcc.getBalance() << " francs" << endl;
	}

	void closeAccounts() {
		privAcc.closeAccount();
		savAcc.closeAccount();
	}
};



int bank()
{
	cout << "Données avant le bouclement des comptes :" << endl;

	Client client1("Pedro", "Geneve", "male", 1000, 2000), client2("Alexandra", "Lausanne","female", 3000, 4000), client3("SP54r", "Lion", "Cyborg", 6000, 400);


	client1.closeAccounts();
	client2.closeAccounts();
	client3.closeAccounts();
	

	cout << "Données apres le bouclement des comptes :" << endl;
	client1.afficher();
	client2.afficher();
	client3.afficher();
	return 0;
}