// Program File (prog.cpp)
// Author: Yunan Liao
// Program code

// Edit History:
	// 2/15 Initial version

// Create two employees

#include <conio.h>
#include "employee.h"

int main()
{
	Employee e1("John", "Doe", 1234.56);
	Employee e2("Jane", "Jones", 7890.12);
	
	e1.info(); // print information
	e2.info(); // print information
	//pause
	printf("Press any key to give each employee a raise...\n");
    getch();
        
    e1.raise(10); //give raise
	e2.raise(10); //give raise
	
    e1.info(); // print updated information
	e2.info(); // same as above
	//pause
	cout << "Press any key to change "<< e2.get(1) <<"'s last name...\n";
	//printf("Press any key to change Jane's last name...\n");
    getch();
    
	string value = "Doe"; 
	cout << e2.get(1) <<"'s last name changed to " << value << "...\n";
	
	e2.change_info(1, value); //change Jane's last name
	e2.info(); //print updated information
	//pause
	printf("Press any key to continue to test other functions...\n");
    getch();
    printf("e2.set(0);\n");
    e2.set(0);
    e2.info();
    printf("e2.set(-100);\n");
    e2.set(-100);
    e2.info();
    printf("e2.set(100);\n");
    e2.set(100);
    e2.info();
    printf("e2.raise(100);\n");
    e2.raise(100);
    e2.info();
    printf("e2.raise(-101);\n");
    e2.raise(-101);
    e2.info();
    printf("e2.raise(-100);\n");
    e2.raise(-100);
    e2.info();
	return 0;
}