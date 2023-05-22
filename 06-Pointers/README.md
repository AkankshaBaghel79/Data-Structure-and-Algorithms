
# Pointers

- Pointers are variables that store the memory addresses of other variables.

- Like regular variables, Pointers have a data type. For example, a pointer of type integer can hold the address of a variable of type integer. A pointer of character type can hold the address of a variable of character type.

- With pointers, programs can simulate call-by-reference. 




## Addresses in C++

- When you create a variable in your C++ program, it is assigned some space the computer memory. The value of this variable is stored in the assigned location.

- To know the location in the computer memory where the data is stored, C++ provides the & (reference) operator also known as address of operator(&).

- address of operator(&) returns the address that a variable occupies. 
> For example, if x is a variable, &x returns the address of the variable.

> **Symbol table is an important data structure used in a compiler. Symbol table is used to store the information about the occurrence of various entities such as objects, classes, variable name, interface, function name etc. it is used by both the analysis and synthesis phases**.

The symbol table is used to store essential information about every symbol contained within the program. 

## Reference operator (&) and Deference operator (*)

- The reference operator (&) returns the variable’s address.
- The dereference operator (*) helps us get the value that has been stored in a memory address.
### Example 1

```C++
#include <iostream>
using namespace std;
int main() {
	int  x = 27;  
	int  *ip;        
	ip = &x;       
	cout << "Value of x is : ";
	cout << x << endl;
	cout << "Value of ip is : ";
	cout << ip<< endl;
	cout << "Value of *ip is : ";
	cout << *ip << endl;
	return 0;
}

output:
Value of x is: 27
value of ip is: 0039FA2C
value of *ip is: 27
```

### Note:

> The Size of Pointer is always of **8** bytes because it stores only the addresss of varialble




## Types of Pointers

- Null Pointers 
- Void Pointers
- Double Pointers
- Wild Pointers
- Dangling Pointers

### 1. Null Pointers
A Null Pointer is a pointer which is pointing to nothing, if we don't have the address to be assigned to a pointer we can use NULL.

**Advantages of NULL pointer**

- To initialize a pointer variable when that pointer variable isn't assigned any valid memory address yet.
-  To pass a null pointer to a function argument when we don't want to pass any valid memory address.
- To check for null pointer before accessing any pointer variable.

### Example 

```C++
int *p;         //Contains garbage value
int *q = NULL; // NULL is constant with value 0
int *r = 0;   //NULL value is assigned
```

In the above example p pointer contains garbage value. To dereference the pointer we have to initialized it to **NULL** to avoid the unexpected behavior

### Note:

> An uninitialized Pointer variable contains garbage, this will lead to unexpected results or segmentation faults. Hence we should never leave a pointer to uninitialized.

### Example 

```C++
#include <iostream>
using namespace std;
int main() {
	//NULL Pointer
  int *p = NULL;
  cout<<"The value of p is "<<p;
	return 0;
}

output:
The value of p is 0

```

### 2. Double Pointers
We can create a pointer to a pointer that in turn may point to data or another pointer.The first pointer is used to store the address of the variable. And the second pointer is used to store the address of the first pointer.
That is why they are also known as double pointers.

### Example 

```C++
int a = 10;         
int *p = &a;
int **q = &p;   
```
Here q is a pointer to a pointer i.e., a double pointer, as indicated by **.

### Example 

```C++
#include <iostream>
using namespace std;
int main() {
    int a = 10;
    int *p = &a; //Pointer
    int **q = &p; //double pointer
    cout<<"Address of a : "<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<*q<<endl;
    cout<<"Address of p :"<<endl;
    cout<<&p<<endl;
    cout<<q<<endl;
    cout<<"Value of a :"<<endl;
    cout<<a<<endl;
    cout<<*p<<endl;
    cout<<**q<<endl;

	return 0;
}

output:
Address of a :
0x7ffcab7af9ac
0x7ffcab7af9ac
0x7ffcab7af9ac
Address of p :
0x7ffcab7af9b0
0x7ffcab7af9b0
Value of a :
10
10
```

### 3. Void Pointers

A void pointer is a generic pointer, it has no associated type with it. A void pointer can hold an address of any type and can be typecasted to any type. Thus we can use the void pointer to store the address of any variable.

Void pointer is declared by:
```C++
void *ptr;  
```

**Note**
- Void pointer cannot be dereferenced . It can, however, be done using typecasting the void pointer.
- Pointer arithmetic is not possible on pointer of void due to lack of concrete value and size.


```C++
#include <iostream>
using namespace std;
int main() {
    void *ptr;
    int i = 10;
    //assign int address to void
    ptr = &i;
    cout<<"Addrress of variable i : "<<&i<<endl;
    cout<<"Adress where the void pointer is pointing : "<<ptr<<endl;
    return 0;
}

output:
Addrress of variable i : 0x7ffc848c25f4
Adress where the void pointer is pointing : 0x7ffc848c25f4
```
### 4. Wild Pointers

A pointer behaves like a wild pointer when declared but not initialized . So, they point to any random memory location.

```C++
int *ptr; //Wild pointer
*ptr = 5
```
**Note**
> If a pointer p points to a known variable, it's not a wild pointer.

### Example
```
int *p; //wild pointer
int a = 10;
p = &a; //p is not a wild pointer now
*p = 12; // This is fine. Value of a is changed
```

### 5. Dangling Pointers

A Dangling pointer is a pointer pointing to a memory location that has beed freed(or deleted) .There are three different ways where Pointer acts as a Dangling pointer.

a) function Call
The pointer pointing to the local variable becomes dangling when the local variable is not static .

### Example
```C++
#include <iostream>
using namespace std;
int *func(){
    int x = 10;
    return &x;
}
int main() {
    int *p = func();
    //p points to something which is not valid anymore
    cout<<*p;
    return 0;
}
```

b) Deallocation of memory
Deallocating a memory pointed by a pointer causes a dangling pointer.

### Example
```C++
#include <iostream>
using namespace std;
int main() {
    //dynamic memory allocation
    int *p = (int *)malloc(sizeof(int));
    //after calling free() p becomes a dangling pointer
    free(p);
    //now p no more a dangling pointer.
    p = NULL;
    return 0;
}
```

c) Variable goes out of scope

When a pointer goes out of scope where it is valid , then it becomes a dangling pointer.

### Example
```C++
#include <iostream>
using namespace std;
int main() {
    int *ptr;
    ......//any code statements
    {int ch;
    ptr = &ch;
    }
    ...
    //Here ptr is dangling pointer
    return 0;
}
```



