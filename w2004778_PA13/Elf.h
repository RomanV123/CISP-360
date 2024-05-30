#ifndef Elf_h
#define Elf_h
#include "MagicalCreatures.h"

//Elf Class
class Elf : public MagicalCreatures
{

public:
	Elf();
	Elf(string name, string color, string type, int age);
	string toString();
};

#endif