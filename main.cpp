#include "Rotor.h"
#include <utility>
#include <string>
#include <iostream>
using namespace std;




int main()
{
	Rotor R1(1);
	for (int i=0; i < 26; i++)
	{

		cout << i <<": " << R1[i] <<endl;
	}

	R1.shift();
	for (int i=0; i < 26; i++)
	{

		cout << i <<": " << R1[i] <<endl;
	}
	R1.shift(5);
	R1.shift(20);
	for (int i=0; i < 26; i++)
	{

		cout << i <<": " << R1[i] <<endl;
	}
}