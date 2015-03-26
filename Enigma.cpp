#include "Enigma.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;




Enigma::Enigma()
{
	string choice;
	cout << "Loading Bank Enigma"<<endl;

	Rotor R1(1);
	Rotor R2(2);
	Rotor R3(3);

	cout << "What order do you want the rotors? (Enter 123 in any order) "<<endl;
	cin>>choice;

	
}