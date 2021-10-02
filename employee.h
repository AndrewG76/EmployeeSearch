#include <stdio.h>
#include <stddef.h>

typedef struct{ //our data structure
    long number;
    char *name; 
    char *phone;
    double salary;
} Employee, *PtrToEmployee; //we are saying the variable name can be either employee or a pointer to employee
//*PtrToEmployee gets to be used in main now

typedef const Employee *PtrToConstEmployee;
/* 
Employee is the variable name, *PtrToConstEmployee is of type Employee and is a pointer of that type
We can have pointers of any type
const means that once we use initialize this value, we cannot change it
We create a pointer of type employee with that last statement
*/