#include <iostream>
using namespace std;
//The static_cast operator 
//  It performs compile-time type conversion and is mainly used for explicit conversions that are considered safe by the compiler. 
//  The static_cast can be used to convert between related types, such as numeric types or pointers in the same inheritance hierarchy.

//The dynamic_cast operator
//  is mainly used to perform downcasting(converting a pointer / reference of a base class to a derived class).
//  It ensures type safety by performing a runtime check to verify the validity of the conversion.

//The const_cast operator
//  is used to modify the const or volatile qualifier of a variable.
//  It allows programmers to temporarily remove the constancy of an object and make modifications.
//  Caution must be exercised when using const_cast, as modifying a const object can lead to undefined behavior.

//The reinterpret_cast operator
//  is used to convert the pointer to any other type of pointer.
//  It does not perform any check whether the pointer converted is of the same type or not.
int main()
{
    int num = 10;

    // converting int to double
    double numDouble = static_cast<double>(num);

    // printing data type
    cout << typeid(num).name() << endl;

    // typecasting
    cout << typeid(static_cast<double>(num)).name() << endl;

    // printing double type t
    cout << typeid(numDouble).name() << endl;


    int number = 10;
    // Store the address of number in numberPointer
    int* numberPointer = &number;

    // Reinterpreting the pointer as a char pointer
    char* charPointer
        = reinterpret_cast<char*>(numberPointer);

    // Printing the memory addresses and values
    cout << "Integer Address: " << numberPointer << endl;
    cout << "Char Address: "
        << reinterpret_cast<void*>(charPointer) << endl;
    return 0;
}