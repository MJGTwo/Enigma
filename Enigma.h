#ifndef __ENIGMA_H__
#define __ENIGMA_H__
#include <vector>
#include "Rotor.h"
using namespace std;

class Enigma{

public:
	Enigma();

private:

	vector<Rotor> gears;
	vector<int> offset;

};





#endif