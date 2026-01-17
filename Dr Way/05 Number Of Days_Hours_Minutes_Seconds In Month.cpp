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

int NumberOfDaysInMonth(int Month, int Year)
{
	if (Month < 1 && Month > 12)
		return 0;

	if (Month == 2)
		return isLeapYear(Year) ? 29 : 28;

	short MonthsOf31Days[] = { 1, 3, 4, 7, 8, 10, 12 };

	for (int i = 1; i < 7; i++)
	{
		if (Month == MonthsOf31Days[i - 1])
			return 31;
	}

	return 30;
}

int NumberOfHoursInMonth(int Month, int Year)
{
	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(int Month, int Year)
{
	return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(int Month, int Year)
{
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

int main()
{
	int Year = ReadYear();
	int Month = ReadMonth();

	std::cout << "\nNumber Of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year) << std::endl;
	std::cout << "Number Of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Month, Year) << std::endl;
	std::cout << "Number Of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Month, Year) << std::endl;
	std::cout << "Number Of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Month, Year) << std::endl;

	system("pause>0");
}