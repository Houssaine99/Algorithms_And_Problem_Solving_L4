#include <iostream>
#include <string>

enum enLeapYearOrNot { LeapYear = 1, NotLeapYear = 2};

int ReadYear()
{
	int InputValue = 0;
	std::cout << "Enter a year? ";
	std::cin >> InputValue;

	return InputValue;
}

enLeapYearOrNot isLeapYear(int Year)
{
	if (Year % 400 == 0)
		return enLeapYearOrNot::LeapYear;
	else if (Year % 4 == 0)
	{
		if (Year % 100 != 0)
			return enLeapYearOrNot::LeapYear;
		else
			return enLeapYearOrNot::NotLeapYear;
	}
	else
		return enLeapYearOrNot::NotLeapYear;
}

int main()
{
	int Year = ReadYear();

	if (isLeapYear(Year) == enLeapYearOrNot::LeapYear)
		std::cout << "\nYes, " << Year << " is a leap year.\n";
	else
		std::cout << "\nNo, " << Year << " is not a leap year.\n";

	system("pause>0");
}