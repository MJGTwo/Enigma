#ifndef __ENIGMA_H__
#define __ENIGMA_H__
#include <vector>
#include "Rotor.h"
using namespace std;

class Enigma{

public:
	Enigma();
	~Enigma();
	void ShowRotorValues(int n);
	void encrypt(string text);
	void decrypt(string text){encrypt(text);}

private:
	void Deconhelper(Rotor*R);
	void makeBankE();

	Rotor* front;
	Rotor* back;
	vector<int> offset;
	int size;

	Reflector* RF;

};





#endif