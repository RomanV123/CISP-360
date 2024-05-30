
#include "VectorHeader.h"

int main() {
std::vector<int> numbers; // declare a vector of integers
initializeVector(numbers); // populate the vector with VECTOR_SIZE number of random integers of value between 1 and 100
sortVector(numbers);      // use the vector and algorithm library to sort this vector database
displayVector(numbers);     // display the vector contents by iterating through the vector
reverseVector(numbers);     // use the vector and algorithm library to reverse this vector database
displayVector(numbers);      // display the vector contents by iterating through the vector
removeLowest(numbers);        // remove the number with the least value
displayVector(numbers);      // display the reduced vector contents by iterating through the vector
displayResults(calculateAverage(numbers)); // calculate the average of the contents of the vector. 
}                              