#include <iostream>
#include <string>

int ReadYear()
{
	int InputValue = 0;
	std::cout << "Enter a year? ";
	std::cin >> InputValue;

	return InputValue;
}

int ReadMonth()
{
	int InputValue = 0;
	std::cout << "\nEnter a month to check? ";
	std::cin >> InputValue;

	return InputValue;
}

bool isLeapYear(int Year)
{
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

int NumberOfDays(int Month, int Year)
{
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
		return 31;

	else if (Month == 2)
		return (isLeapYear(Year)) ? 29 : 28;

	else
		return 30;	
}

int NumberOfHours(int Month, int Year)
{
	return NumberOfDays(Month, Year) * 24;
}

int NumberOfMinutes(int Month, int Year)
{
	return NumberOfHours(Month, Year) * 60;
}

int NumberOfSeconds(int Month, int Year)
{
	return NumberOfMinutes(Month, Year) * 60;
}

int main()
{
	int Year = ReadYear();
	int Month = ReadMonth();

	std::cout << "\nNumber Of Days    in Month [" << Month << "] is " << NumberOfDays(Month, Year) << std::endl;
	std::cout << "Number Of Hours   in Month [" << Month << "] is " << NumberOfHours(Month, Year) << std::endl;
	std::cout << "Number Of Minutes in Month [" << Month << "] is " << NumberOfMinutes(Month, Year) << std::endl;
	std::cout << "Number Of Seconds in Month [" << Month << "] is " << NumberOfSeconds(Month, Year) << std::endl;

	system("pause>0");
}