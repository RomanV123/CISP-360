#include "VectorHeader.h"

void initializeVector(std::vector<int>& numbers)
{

    srand(time(0)); //sets the seed for random number generation

    for (int i = 0; i < VECTOR_SIZE; i++) {

        int randomNumber = rand() % MAX_VALUE + 1; //Max value here is 100, this is a const value that was made in VectorHeader.h
        numbers.push_back(randomNumber) ;
    
    }

}

void sortVector(std::vector<int>& numbers) {

    std::sort(numbers.begin(), numbers.end());              //Sorts the vector with the "sort" algorithm

}
void reverseVector(std::vector<int>& numbers)
{
    std::reverse(numbers.begin(), numbers.end());           //Reverses the vector with the "reverse" algorithm

}
void displayVector(std::vector<int>numbers)
{
    
    for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
        std::cout << *iter << "  ";

   }                                                        //Uses an iterator to display the vector going through the
                                                            //beggining of the vector to the end
    
    std::cout << std::endl;
   
}
void removeLowest(std::vector<int>& numbers)
{
    
    numbers.pop_back();                                     //Uses "pop_back" to remove the last element of the vector

}
void displayResults(double value)
{
    std::cout << "The average is: " << value << std::endl;


}
double calculateAverage(std::vector<int>numbers)
{
    double sum = 0;
    std:: cout << std::fixed << std::setprecision(2);

    for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
        
        sum += *iter;
         
    }                                                      //Uses iterator again to read through the vector and add up the
                                                           //individual values and place them into a sum

    return sum / VECTOR_SIZE;           //returns sum


}
