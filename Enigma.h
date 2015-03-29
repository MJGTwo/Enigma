#ifndef __ENIGMA_H__
#define __ENIGMA_H__
#include <vector>
#include "Rotor.h"
#include <string>
using namespace std;

class Counter{

public:
	Counter(int i);
	vector<int> move();
private:

	vector <int> counts;


};



class Enigma{

public:
	Enigma();
	~Enigma();
	string encrypt();
	string decrypt(string text);
	const bool getMade() const {return made;}

private:
	void Deconhelper(Rotor*R);
	void makeBankE();
	void makeArmyE();
	void makeNavalE();
	void makeANavalE();

	void basic(int i);

	Rotor* front;
	Rotor* back;
	Counter* c;
	int size;

	bool made;
	Reflector* RF;

};





#endif