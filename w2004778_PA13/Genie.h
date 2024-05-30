#ifndef Genie_h
#define Genie_h
#include "MagicalCreatures.h"
//Genie Class
class Genie : public MagicalCreatures
{
private:
	int size;
	bool hasWand;

public:
	Genie();
	Genie(string name, string color, string type, int age, int size, bool hasWand);

	int getSize();
	void changeSize(int newSize);
	bool getHasWand();
	void setHasWand(bool hasWand);
  string liveIn();
  //void toString();
};

#endif