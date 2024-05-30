#ifndef Dragon_h
#define Dragon_h

#include "MagicalCreatures.h"

class Dragon : public MagicalCreatures
{
private:
	int size;
	bool hasSpike;

public:
  Dragon();
	Dragon(string name,string color,string type, int age, int size, bool hasSpike);
	
	int getSize();
	void changeSize(int newSize);
	bool getHasSpike();
	void setHasSpike(bool hasSpike);
  string toString();


};

#endif