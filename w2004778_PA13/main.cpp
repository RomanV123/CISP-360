#include<memory>
#include "Dragon.h"
#include "Elf.h"
#include "Genie.h"
#include "Goblin.h"
#include "MagicalCreatures.h"

void printCreature(shared_ptr<MagicalCreatures> m)
{
	cout << endl;
	cout << "I am a : " << (m)->getType() << endl;
	cout << "My name is : " << (m)->getName() << endl;
	cout << "My color is : " << (m)->getColor() << endl;
	cout << "My speech :" << (m)->talk() << endl;
	cout << "My habitat: " << (m)->liveIn() << endl;
	cout << "I am " << (m)->getAge() << " years of age." << endl << endl;
	cout << "Displaying the " << (m)->getType() << " Object" << endl;
	cout << m->toString() << endl;

}

void displayCreatures(vector<shared_ptr<MagicalCreatures>> m){
   for ( auto iter = m.begin(); iter < m.end(); iter++)
	
  printCreature(*iter);
;
}

void swap(vector<shared_ptr<MagicalCreatures>> &m,int source, int destination){
  // use to swap creatures in partition method
	shared_ptr<MagicalCreatures> temp = m[source];
	m[source] = m[destination];
	m[destination] = temp;
}
int partition(vector<shared_ptr<MagicalCreatures>> &m, int start, int end){
  // implement partition search space
	shared_ptr<MagicalCreatures> pivotValue;
		int pivotIndex, mid;

	mid = (start + end) / 2;
	swap(m, start, mid);
	pivotIndex = start; 
	pivotValue = m[start];
	for (int scan = start + 1; scan <= end; scan++)
	{
		if (*pivotValue > *m[scan])
		{
			pivotIndex++;
			swap(m, pivotIndex, scan);
		}
	}
	swap(m, start, pivotIndex);
	return pivotIndex;
}
  
void recursiveQuickSort(vector<shared_ptr<MagicalCreatures>> &m, int start, int end)
{
	int pivotPoint;

	if (start < end)
	{
		pivotPoint = partition(m, start, end);
		recursiveQuickSort(m, start, pivotPoint - 1);
		recursiveQuickSort(m, pivotPoint + 1, end);
	}

  //implement recursive Quick sort by calling partition method
}

int recursiveBinarySearch(vector<shared_ptr<MagicalCreatures>> m, int first, int last, string name){
 //implement binary search method
	int middle;
	if (first > last)
		return -1;
	middle = (first + last) / 2;
	if (m[middle]->getName() == name)
		return middle;
	if (m[middle]->getName() < name)
		return recursiveBinarySearch(m, middle + 1, last, name);
	else
		return recursiveBinarySearch(m, first, middle - 1, name);
}

void searchCreature(vector<shared_ptr<MagicalCreatures>> m){
  string name;
  cout<<"Please enter the name of the Creature"<<endl;
  cin>>name;
  int index= recursiveBinarySearch(m,0,m.size()-1,name);
  if (index <0)
    cout<<"Creature Not Found "<<endl;
  else {
    cout<<"Creature found at index "<<index <<endl;
    cout<<"Here it is "<<m[index]->toString()<<endl;
  } 
}

int main()
{
	//create a vector of pointer to MagicalCreatures
	vector<shared_ptr<MagicalCreatures>> creatures;

	//create the individual creatures of type pointer of MagicalCreatures
	shared_ptr<Dragon> dragon = make_shared< Dragon>("Jack","black","Dragon", 200, 500, true);
	shared_ptr<Elf> elf = make_shared<Elf>("Doug", "green", "Elf", 80);
	shared_ptr<Genie> genie = make_shared< Genie>("Cosmo", "blue", "Genie", 1000, 40, true);
	shared_ptr<Goblin> goblin = make_shared<Goblin>("Harry", "red", "Goblin", 150);

	//push back each specific creature to the vector of MagicalCreatures
 
	creatures.push_back(dragon);
	creatures.push_back(elf);
	creatures.push_back(genie);
	creatures.push_back(goblin);
  displayCreatures(creatures);
  std::cout<<"*****AFTER SORTING *******"<<std::endl;
  recursiveQuickSort(creatures,0,creatures.size()-1);
  displayCreatures(creatures);
  searchCreature(creatures);
}