//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c | you must compile the correct relevant files
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    //defined in employeeOne.c or employeeTwo.c as well so main can be reused for both implementations, it always calls it but it depends on which file is being compiled
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[]; //extern is telling us that we don't have to declare any variables
    extern const int EmployeeTableEntries; //

    PtrToEmployee matchPtr; //Decalaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); //says which structure to look at, tells the size of the structure, and then says what we need to look for

    //Example not found
    if(matchPtr != NULL){
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    }
    else{
        printf("Employee ID 1045 is NOT found in the record\n");
    }

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL){
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
        //printf("Employee Tony Bobcat is in record %d %d %d\n", matchPtr, EmployeeTable, matchPtr - EmployeeTable); 
        //the literals print out FAT numbers on purpose and substracting them gives you 96 which when divided by 32 means it's in the index 3 record
    }
    else{
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }

    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if(matchPtr != NULL){
        printf("Employee Phone Number 310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
    }
    else{
        printf("Employee Phone Number 310-555-1215 is NOT found in the record\n");
    }
 
    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 10.65);
    if(matchPtr != NULL){
        printf("Employee Salary 10.65 is in record %d\n", matchPtr - EmployeeTable);
    }
    else{
        printf("Employee Salary 10.65 is NOT found in the record\n");
    }
 
    return EXIT_SUCCESS; //this is part of the standard library we included up top
}