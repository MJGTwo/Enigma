#include "Rotor.h"
#include <utility>
#include <string>
#include <iostream>
using namespace std;




int main()
{

	Rotor R1(1);
	Rotor R2(2);
	Rotor R3(3);
	string test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i=0; i < test.size(); i++)
	{

		cout << test[i] <<": " << R1[test[i]] << ", " << R2[test[i]]<<endl;
	}

}