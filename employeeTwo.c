#include <string.h>
#include "employee.h"

//Note: 5 functions have been defined below

//What does setting a function to static do??
//functionPtr is the address of the function just use the name
//()(The second set of parentheses is the arguments of the function call)
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee)){
    //the static in function declaration means that searchEmployeeTable can ONLY be used in this file and nowhere else, keeps things private
    //ptr - points to table to be searched
    //tableSize - size of the table
    //const void * is a generic version allows it to point at any type of data and gets type casted later
    //targetPtr - points to value that will be searched for in table
    //functionPtr - points to a comparison function and will perform the associated check

    PtrToConstEmployee endPtr = ptr + tableSize; //this acts the same way as before

    for(; ptr < endPtr; ptr++){ //we iterate through but do the comparison differently
        if((*functionPtr)(targetPtr, ptr) == 0){ //"Call that function that was passed, and pass the arguments set for it"
        //targetPtr here comes from the function parameters above and provides the data value we are specifically trying to check against but it's the address so &1045
        //as we increment through, we keep on passing the exact row we should be looking at 
            return (PtrToEmployee) ptr; //if true, we get the location returned
        }
    }
    return NULL; //if not, we return our null
}

//The functionPtr will point to one of these comparison functions to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (long *) targetPtr != tableValuePtr->number; //const void *targetPtr points to the data type
    //1045 is supposed to be a long pointer which is why we type cast the void pointer back to a long pointer, dereference it, and then check if it's equal to the number
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return strcmp((char *) targetPtr, tableValuePtr->name); //const void *targetPtr ==> typecast the void pointer back to character pointer
    //the if statement in the for loop above run a string compare with the char that gets dereferenced 
}

//These are called wrappers. These functions are what you will use in main! | here, these methods will be able to be used in main
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number){
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber); //we pass pointer and size directly but the address of number instead since we have a void pointer to it and then it passes compareEmployeeNumber
    //the method at the top gets called and that's what makes this a wrapper
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name){ //name is already an address so you can use the input directly within the statement inside
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}