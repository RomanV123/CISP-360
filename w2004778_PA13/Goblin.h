#ifndef Goblin_h
#define Goblin_h

#include "MagicalCreatures.h"

//Goblin Class
class Goblin : public MagicalCreatures
{
public:
	Goblin();
	Goblin(string name, string color, string type, int age);
  string talk();
  //void toString();
	
};

#endif