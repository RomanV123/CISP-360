#include "VectorHeader.h"

void initializeVector(std::vector<int> &numbers){ 
	
	srand(time(0)); // sets seed the random number
	
	for (int i=0;i<10;i++) {
		
	int randomNumber = rand() % MAX_VALUE + 1;// Max Value of 100 and was created in VectorHeader.h
	numbers.push_back(randomNumber);

}
}
void sortVector(std::vector<int> &numbers){    // Sorts the vector using the sort command
	
	std::sort(numbers.begin(), numbers.end());
}
void reverseVector(std::vector<int> &numbers){   //  Reverses the elements in the vector 
	
	std::reverse(numbers.begin(), numbers.end());
}
void displayVector(std::vector<int>numbers) {     

	for (auto iter = numbers.begin();iter < numbers.end();iter++) {

		std::cout << *iter << " ";  //An iterator that shows us that the vector is moving from the beginning to the end. 
	}

	std::cout << std::endl;
}

void removeLowest(std::vector<int> &numbers){ 
	
	numbers.pop_back();					//Uses "pop_back to remove the last digit/element of the vector

}

void displayResults(double value){       // display the calculated average of the values

	std::cout << "The Average is " << value << std::endl;

}
double calculateAverage(std::vector<int>numbers){ // calculate the average of the vector contents

	double sum = 0;
	std::cout << std::fixed << std::setprecision(2);

	for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {

		sum += *iter; // uses iterator to read the vector to add values and add them into a sum. 

	}

	return sum / VECTOR_SIZE; // returns the average

}
