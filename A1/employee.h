// SPECIFICATION FILE  (employee.h)
// Author: Yunan Liao
// Class Employee declaration

// Edit History:
// 2/13 initial version

#include <iostream>
#include <stdlib.h>
#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee {
	public:
		Employee(string f, string l, double income);	// Constructor for employee
		void set(double salary);						// set salary
		template <typename T>
		int change_info(int field, T info);				// use info to replace given field(`firstname`, `lastname`)
		void info() const;	    						// output information
		void raise(double percentage);					// give raise to the employee
		string get(int field);						// directly return information
		
	private:
		string firstname;   			//First name
		string lastname;				//Last name
		double monthlyincome;			//Monthly salary
};

// define change_info
template <typename T>
int Employee::change_info(int field, T info) 
{

	switch (field) {
		case 0:
			firstname = info;
		break;
		case 1:
			lastname = info;
			break;
		/* // This does not work. Incorrect variable type.
		case 2:
			monthlyincome = info;
			break;
		*/
		default:
			cout << "\nUnknown parameter: " << field << endl;
	}
	return 0;
}

#endif