/*
 * dayclass.h
 *
 *  Created on: 26 Sep 2020
 *      Author: louischeuk
 */

#ifndef DAYCLASS_H_
#define DAYCLASS_H_

#include <iostream>
using namespace std;

class DayClass {
public:
	DayClass();
	bool isLeapValidiation(int year);
	bool dayValidation(int day, int month, int year, bool isLeap);
	void reEnterInput(int &d, int m, int y, bool isLeap);
	int dayCalculate(int pointer, int month, int year, bool dayValid);
	string monthToString(int month);
	string getWeekDay(int remainder);
	virtual ~DayClass();
	void whatDayIsIt(int pointer, int month, int year, int remainder, string monthToString, string whichDay);
};

#endif /* DAY_H_ */
