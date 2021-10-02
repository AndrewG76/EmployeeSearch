#include "employee.h"
#include <string.h>

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){ //the first pointer points to the table we want to search and we want to make sure the data stays constant | then we have tableSize which helps us find the max size | then targetNumber is the id itself we're trying to match
    const PtrToConstEmployee endPtr = ptr + tableSize; //we establish end pointer by adding size to start | because there's 5 elements in EmployeeTable, tableSize in main would be 160 bytes

    for(; ptr < endPtr; ptr++){ //we increment through each row in the allocated memory (32 whole bytes later) and search until end of table
        if(ptr->number == targetNumber){ //we use the pointer to point STRAIGHT at the data structure's sect of memory and checks if it's equal
            return (PtrToEmployee) ptr; //we typecast the pointer and it returns the employee that has what we're looking for
        }
    }
    return NULL; //this will only happen if no employee number matches in the loop above
}

//Essentially the same functionality as above but comparing string to check if equal
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName){ //checks a character array (string)
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){ 
        if(strcmp(ptr->name,targetName) == 0){ //because of this function though, we're practically repeating the code and so this isn't efficient
            return (PtrToEmployee) ptr;
        }
    }
    return NULL; //this will only happen if no employee number matches in the loop above
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){ 
        if(strcmp(ptr->phone,targetPhone) == 0){
            return (PtrToEmployee) ptr;
        }
    }
    return NULL; 
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary){ 
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){
        if(ptr->salary == targetSalary){
            return (PtrToEmployee) ptr;
        }
    }
    return NULL; 
}