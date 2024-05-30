#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include "CircleHeader.h"
#include <vector>


// Default constructor
Circle::Circle() {
    x = 0;
    y = 0;
    radius = 1;
    count++;
    

    // Creates a unit circle with the center at the origin
}


// Regular constructor
Circle::Circle(int xcoord, int ycoord, int r) : x(xcoord), y(ycoord), radius(r) {
    x = xcoord;
    y = ycoord;
    radius = r;
    count++;
}

int Circle::getX() {
    return x;
}

int Circle::getY() {
    return y;
}

int Circle::getRadius() {
    return radius;
}

double Circle::getArea() {
    return M_PI * radius * radius;
}

double Circle::getCircumference() {
    return 2 * M_PI * radius;
}

double Circle::getDistance( Circle other) {
    int xDiff = x - other.x;
    int yDiff = y - other.y;
    
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

int Circle::intersects(Circle other) {
    
    return(radius + other.getRadius()) > getDistance(other);
}

 int Circle::getCount(){
   
       return count; // Return the count of circles
}


Circle Circle::resize(double scale) {
    int newRadius = static_cast<int>(radius * scale);
    return Circle(x, y, newRadius);
}

void Circle::move(int new_x, int new_y) {
    x = new_x;
    y = new_y;
}

 std::string Circle::toString() {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ") : " + std::to_string(radius);
}


 Circle::~Circle() {

 }
 int Circle::count = 0; // initialize global variable count
