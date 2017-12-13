#include<iostream>

using namespace std;

class Spectateur {
public:
	void setAge();
	void askMoney();

	int writeAge() const;
	int writeMoney() const;
	
private:
	int age; int money=200;
};
void Spectateur::setAge() { cout << "How old are you? "; cin >> age; }
void Spectateur::askMoney() {
		while (money >= 100) {
		cout << "How much money do you have? "; cin >> money;
		}
}
int Spectateur::writeAge() const { cout << "Spectator: Writting age..." << endl; return age;}
int Spectateur::writeMoney() const { cout << "Spectator: Writting money..." << endl; return money; }

class Paper {
public:
	void getWrittenAge(int);
	void getWrittenMoney(int);
	int getReadenAge() const;
	int getReadenMoney() const;

private:
	int age, money;
};
void Paper::getWrittenAge(int a) { age = a;}
void Paper::getWrittenMoney(int m) { money = m; }
int Paper::getReadenAge() const { return age; }
int Paper::getReadenMoney() const { return money; }

class Assistant {
public:
	void readAge(int);
	void readMoney(int);
	int operationResult() const;

private:
	int age; int money;
};
void Assistant::readAge(int a) { age = a; cout << "Assistant: Reading age..." << endl; }
void Assistant::readMoney(int m) { money = m; cout << "Assistant: Reading money..." << endl; }
int Assistant::operationResult() const { cout << "Assistant: Calculating...\t" << ((age * 2 + 5) * 50 + money - 365) <<"!!!" << endl; return ((age * 2 + 5) * 50 + money - 365); }

class Magician {
public:
	void getAssistantInfo(int);
	void announce();

private:
	int assistantInfo;
	
	int finalResult();
};

void Magician::getAssistantInfo(int opResult) { assistantInfo = opResult; }
void Magician::announce() {
	int aux;
	aux = finalResult();

	cout << "Magician: You are " << aux / 100 << " and have " << aux % 100 << "$$ in the pocket" << endl;

}
int Magician::finalResult() { cout << "Magician: (Calculating...\t" << assistantInfo + 115 << "!)" << endl; return assistantInfo + 115; }


void magicTrick() {
	Magician mag1;
	Spectateur Spect1;
	Assistant Ass1;
	Paper paper1;

	Spect1.setAge();
	Spect1.askMoney();

	paper1.getWrittenAge(Spect1.writeAge());	
	paper1.getWrittenMoney(Spect1.writeMoney());

		
	Ass1.readAge(paper1.getReadenAge());
	Ass1.readMoney(paper1.getReadenMoney());


	mag1.getAssistantInfo(Ass1.operationResult());
	mag1.announce();

}