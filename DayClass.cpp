/*
 * day.cpp
 *
 *  Created on: 26 Sep 2020
 *      Author: louischeuk
 */

#include "DayClass.h"
using namespace std;


DayClass::DayClass() {}

//leap year is 366 days; non-leap year is 365 days (1 is true; 0 is false)
bool DayClass::isLeapValidiation(int year) {
	bool isLeap = false;

	if (year%4 == 0 and year%100 != 0) {
		isLeap = true;
	} else if ( year%400 == 0 ) {
		isLeap = true;
	}

	if (isLeap == false) {
		printf("%d is not a leap year and it has 365 days.\n", year);
	} else {
		printf("Hey! %d is a leap year and it has 366 days!\n", year);
	}
	printf("%d\n", isLeap);

	return isLeap;
}

// For input in script: check if the date is valid
bool DayClass::dayValidation(int day, int month, int year, bool isLeap) {

	bool dayValid = true;

	if ( (day < 1 || day > 31) || (month < 1 || month > 12) || (year < 1900 || year > 2200) ) { return false; }

	if (isLeap == true) {
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			dayValid = (day > 30) ? false : true ;
		} else if (month == 2 ) {
			dayValid = (day > 29) ? false : true ;
		} else {
			dayValid = true ;
		}
	} else {
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			dayValid = (day > 30) ? false : true ;
		} else if (month == 2 ) {
			dayValid = (day > 28) ? false : true ;
		} else {
			dayValid = true ;
		}
	}

	if (dayValid == false) {
		printf("Invalid date\n");
	} else {
		printf("Hey valid date!\n");
	}
	printf("%d\n",dayValid);

	return dayValid;
}

// For manual input: amend the date until it is valid
void DayClass::reEnterInput(int &d, int m, int y, bool isLeap) {

	if (isLeap == true) {
		if (m == 4 || m == 6 || m == 9 || m == 11) {
			while (d > 30) {
				printf("Invalid Day. Enter a day below 31: ");
				scanf("%d", &d);
			}
		} else if ( m == 2 ) {
			while (d > 29) {
				printf("Invalid Day. Enter a date below 30: ");
				scanf("%d", &d);
			}
		}
	} else {
		if (m == 4 || m == 6 || m == 9 || m == 11) {
			while (d > 30) {
				printf("Invalid Day. Enter a date below 31: ");
				scanf("%d", &d);
			}
		} else if ( m == 2 ) {
			while (d > 28) {
				printf("Invalid Day. Enter a date below 29: ");
				scanf("%d", &d);
			}
		}
	}
}

int DayClass::dayCalculate(int day, int month, int year, bool dayValid) {
	int remainder = -1;

	if (dayValid == true) {

		year = (month == 1 || month == 2) ? year-1 : year ;

		int C = year / 100;
		int D = year - C*100;

		if (month == 1) {
			month = 11;
		} else if ( month == 2) {
			month = 12;
		} else {
			month = month - 2;
		}

		// Zeller's Rule
		int F = day + ((13*month-1) / 5) + D + (D/4) + (C/4) - 2*C;

		// F % 7
		if ( F < 0 ) {
			while ( F < 0) {
				F = F + 7;
			}
			remainder = F;
		} else {
			remainder = F%7;
		}
		return remainder;
	} else {
		printf("Invalid date. No calculation is be done.\n");
		return remainder;
	}
}

string DayClass::monthToString(int month) {
	switch(month) {
	case 1: return "JAN";
	case 2: return "FEB";
	case 3: return "MAR";
	case 4: return "APR";
	case 5: return "MAY";
	case 6: return "JUN";
	case 7: return "JULY";
	case 8: return "AUG";
	case 9: return "SEPT";
	case 10: return "OCT";
	case 11: return "NOV";
	case 12: return "DEC";
	default: return "Error";
	}
}

string DayClass::getWeekDay(int remainder) {
	const char *Names[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return Names[remainder];
}

void DayClass::whatDayIsIt(int day, int month, int year, int remainder, string monthToString, string whichDay) {
	if (remainder != -1) {
		printf("%d-%s-%d is %s.\n", day, monthToString.c_str(), year, whichDay.c_str());
	} else {
		return;
	}
}

DayClass::~DayClass() {}

