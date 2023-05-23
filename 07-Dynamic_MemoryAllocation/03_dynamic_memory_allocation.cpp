#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void displayValue(void* ptr, char type) 
{
    if (type == 'i') {
        // int* intPtr = (int*)(ptr); //--> C-style cast
        int* intPtr = static_cast<int*>(ptr); //--> Static cast

        cout << "Value: " << *intPtr << endl;
    } else if (type == 'd') {
        // double* doublePtr = static_cast<double*>(ptr);
        double * doublePtr = (double*)(ptr);
        cout << "Value: " << *doublePtr << endl;
    } else {
        cout << "Invalid type." << endl;
    }
}


int main() {
    int intValue = 42;
    double doubleValue = 3.14;

    void* voidPtr = nullptr;

    voidPtr = &intValue;
    displayValue(voidPtr, 'i');  // Output: Value: 42

    voidPtr = &doubleValue;
    displayValue(voidPtr, 'd');  // Output: Value: 3.14

    return 0;
}


/*
In C++, a void pointer (or void*) is a special type of pointer that can hold the address 
of an object of any type. It is a generic pointer type that does not have a specific associated
data type. The void* pointer can be used to store addresses of objects of different types but 
cannot be directly dereferenced. Instead, it needs to be casted to a specific pointer type before dereferencing.
*/