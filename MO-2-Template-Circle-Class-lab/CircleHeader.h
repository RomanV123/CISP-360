#include <math.h>
#include <string>


class Circle{  
private:
static int count;
   int x,y;
   int radius;
   
   

   // all the method headers for the class
public:
   Circle();
  // Circle(int xcoord,int ycoord, int r):x(xcoord),y(ycoord),radius(r){};
  // The commented constructor above  is another way of doing inline assignments
  // You do not need to use it.Its just for your information
   
   Circle(int xcoord,int ycoord, int r);
   int getX();
   std::string toString();
   
   
   int getY();
   
   int getRadius();
   double getArea();
   double getCircumference();
   static int getCount(); // Static method to get the count of circles

   double getDistance(Circle other);
   int intersects( Circle other);
   Circle resize(double scale);
   void move(int new_x, int new_y);
   ~Circle();
  
};