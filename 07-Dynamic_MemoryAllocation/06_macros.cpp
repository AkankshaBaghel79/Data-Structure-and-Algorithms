#include <iostream>
using namespace std;
 
// Macro definition
#define AREA(l, b) (l * b)
 

int main()
{
    int l1 = 10, l2 = 5, area;
 
    // Find the area using macros
    area = AREA(l1, l2);
 
    // Print the area
    cout << "Area of rectangle"<< " is: "<< area;
 
    return 0;
}