#ifndef MagicalCreatures_h
#define MagicalCreatures_h

#include <string> 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//MagicalCreatures Class
class MagicalCreatures
{
private:
	string name, color, type;
    int age;

public:
  MagicalCreatures();
	MagicalCreatures(string name, string color, string type, int age);
  virtual string  talk(); 
  virtual string liveIn(); 
	virtual string getName();
	virtual void setName(string name);
	virtual string getColor();
	virtual void setColor(string color);
	virtual int getAge();
	virtual void setAge(int age);
	virtual string getType();
	virtual void setType(string type);
  virtual string toString();

  bool operator > (MagicalCreatures other);
  

  bool operator ==(MagicalCreatures other);

};

#endif