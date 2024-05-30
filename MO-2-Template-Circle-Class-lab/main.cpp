// main.cpp

#include "CircleHeader.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Function to read data from a file into a vector of Circle objects
void inputData(std::vector<Circle>& circles, const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("File Open Error");
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream instream(line);
            int x, y, radius;
            if (instream >> x >> y >> radius) {
                circles.push_back(Circle(x, y, radius));
            }
        }
        file.close();
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        exit(1);
    }
}

int main() {
    std::vector<Circle> circles;

    // Call inputData function to read data from the file
    inputData(circles, "C:/Users/roman/Downloads/dataLab4.txt");

    // Display all the circles in the vector using toString method
    std::cout << "Circles in the vector:" << std::endl;
    for ( auto& circle : circles) {
        std::cout << circle.toString() << std::endl;
    }

    // Display the count of circles in the vector using getCount method
    std::cout << "Count of circles using getCount method: " << Circle::getCount() << std::endl;

    // Display the count of circles in the vector using vector size method
    std::cout << "Count of circles using vector size method: " << circles.size() << std::endl;

    // Clear the vector
    circles.clear();
    std::cout << "Clearing Vector" << std::endl;

    // Create a circle using the default constructor and push it onto the vector
    Circle c;
    circles.push_back(c);

    // Display the current count of circles using getCount method on c
    std::cout << "Current count of circles using getCount method: " << c.getCount() << std::endl;

    // Display the current count of circles using vector size method
    std::cout << "Current count of circles using vector size method: " << circles.size() << std::endl;

    return 0;
}
