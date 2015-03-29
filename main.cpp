#include "Rotor.h"
#include "Enigma.h"
#include <utility>
#include <string>
#include <vector>
#include <iostream>
using namespace std;




int main()
{
	bool flag = true;
	string tester;
	do
	{
		Enigma machine0;
		flag= machine0.getMade();
		if (flag) tester = machine0.encrypt();
	}while (flag);

	

}