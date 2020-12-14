//============================================================================
// Name        : dayCalculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DayClass.h"
using namespace std;

/*
 * --Zeller's Rule--
 * https://beginnersbook.com/2013/04/calculating-day-given-date/
 */

int main() {

	// --- input in script ----
	int day = 28;
	int month = 9;
	int year = 2020;

	DayClass dayClass;
	bool isLeap = dayClass.isLeapValidiation(year);
	bool dayValid = dayClass.dayValidation(day, month, year, isLeap);
	int remainder = dayClass.dayCalculate(day, month, year, dayValid);
	string whichDay = dayClass.getWeekDay(remainder);
	string monthToString = dayClass.monthToString(month);
	dayClass.whatDayIsIt(day, month, year, remainder, monthToString, whichDay);


	printf("\n"); // separate line


	// --- Manual input ---
	int d, m, y;
	bool dayValid2 = true;

	// input with conditions
	do {
		printf("Day in number: ");
		scanf("%d", &d);
	} while (d < 0 || d > 31);

	do {
		printf("Month in number: ");
		scanf("%d", &m);
	} while (m < 0 || m > 12);

	do {
		printf("Year in number: ");
		scanf("%d", &y);
	} while (y < 1900 || y  > 2200);

	DayClass dayClassManual;
	bool isLeap2 = dayClassManual.isLeapValidiation(y);
	dayClassManual.reEnterInput(d, m, y, isLeap2);
	int remainder2 = dayClassManual.dayCalculate(d, m, y, dayValid2);
	string whichDay2 = dayClassManual.getWeekDay(remainder2);
	string monthToString2 = dayClassManual.monthToString(m);
	dayClassManual.whatDayIsIt(d, m, y, remainder2, monthToString2, whichDay2);

	return 0;
}
