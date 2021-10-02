#include <string.h>
#include <stdlib.h>
#include "employee.h"

Employee EmployeeTable[] = { //we're just initializing everything here and the compiler can already figure out the size
    {1001l, "Daphne Borromeo", "909-555-2134", 8.78}, //the l at the end represents it as a long
    {1011l, "Tammy Franklin", "213-555-1212", 4.50},
    {1140l, "Dorris Perl", "310-555-1215", 7.80},
    {4011l, "Tony Bobcat", "909-555-1235", 6.34},
    {5045l, "Brian Height", "714-555-2749", 8.32}   
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]); //160/32 why ?? | we made this const because once it's in our file, we never let the file change | the [0] part is to represent the row aspect | we make everything 32 bytes for consistency sake and making stuff quicker to work with

/*
void main(){
    printf("%d\n", sizeof(EmployeeTable));
    printf("%d\n", sizeof(EmployeeTable[0]));
    printf("%d\n", sizeof(long)); //number 4 bytes
    printf("%d\n", sizeof(char*)); //*name 4 bytes | this could by 4 bytes or 8 bytes depending on what CPU you have but we always have 8 bytes on a 64 bit processor
    printf("%d\n", sizeof(char*)); //*phone 4 bytes
    printf("%d\n", sizeof(double)); //*salary 8 bytes
}
*/