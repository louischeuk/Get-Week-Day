getWeekDay: dayCalculator.o DayClass.o
	g++ -std=c++14 -g -Wall dayCalculator.o DayClass.o -o getWeekDay

dayCalculator.o: dayCalculator.cpp DayClass.h
	g++ -std=c++14 -g -Wall -c dayCalculator.cpp

DayClass.o: DayClass.cpp DayClass.h
	g++ -std=c++14 -g -Wall -c DayClass.cpp

clean:
	rm -f *.o getWeekDay
