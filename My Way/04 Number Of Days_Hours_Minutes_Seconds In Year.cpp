#include <iostream>
#include <string>

int ReadYear()
{
	int InputValue = 0;
	std::cout << "Enter a year? ";
	std::cin >> InputValue;

	return InputValue;
}

bool isLeapYear(int Year)
{
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

int NumberOfDays(int Year)
{
	return (isLeapYear(Year)) ? 366 : 365;
}

int NumberOfHours(int NumberOfDays)
{
	return NumberOfDays * 24;
}

int NumberOfMinutes(int NumberOfHours)
{
	return NumberOfHours * 60;
}

int NumberOfSeconds(int NumberOfMinutes)
{
	return NumberOfMinutes * 60;
}

int main()
{
	int Year = ReadYear();

	int NumberOfDaysInYear = NumberOfDays(Year);
	int NumberOfHoursInYear = NumberOfHours(NumberOfDaysInYear);
	int NumberOfMinutesInYear = NumberOfMinutes(NumberOfHoursInYear);
	int NumberOfSecondsInYear = NumberOfSeconds(NumberOfMinutesInYear);


	std::cout << "Number Of Days    in Year [" << Year << "] is " << NumberOfDaysInYear << std::endl;
	std::cout << "Number Of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear << std::endl;
	std::cout << "Number Of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear << std::endl;
	std::cout << "Number Of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear << std::endl;

	system("pause>0");
}