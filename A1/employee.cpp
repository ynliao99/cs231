// IMPLEMETION FILE  (employee.cpp)
// Author: Yunan Liao
// Define Employee's functions

// Edit History:
	// 2/13 initial version
	
#include "employee.h"
#include <iomanip>

// create an `Employee`
Employee::Employee(string f, string l, double income){
	firstname  = f;
	lastname = l;
	monthlyincome = income;
	
}

// change salary to a fixed amount
void Employee::set(double salary){
	if (salary >= 0){
	monthlyincome = salary;
	}else{
	cout << "Invalid input!" << endl;
	}
}

// output employee information
void Employee::info() const{
	double yearlyincome = monthlyincome * 12.00;
	// format number output
	cout << setiosflags(ios::fixed) << setprecision(2) << firstname <<" "<< lastname <<"'s monthly income: "<< monthlyincome <<", yearly income: "<< yearlyincome << endl;
}

// give raise to employee
void Employee::raise(double percentage){
	// percentage can also <0, which means a pay cut However it can NOT < -100, which will cause the salary <0
	
	if (percentage >=-100){
	monthlyincome *= (1+percentage*0.01); // monthlyincome = monthlyincome * (1+percentage/100)
	}else{
	cout << "Invalid input!" << endl;
	}
}

string Employee::get(int field){
	switch (field) {
		case 0:
			return firstname;
			break;
		case 1:
			return lastname;
			break;
		case 2:
			return to_string(monthlyincome);
			break;
		default:
			cout << "\nUnknown parameter: " << field << endl;
			return "null";
	}
}
