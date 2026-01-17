#include <iostream>
#include <string>
#include <iomanip>

short ReadDay()
{
	short InputValue = 0;
	std::cout << "\nPlease enter a day? ";
	std::cin >> InputValue;

	return InputValue;
}

short ReadYear()
{
	short InputValue = 0;
	std::cout << "\nPlease enter a year? ";
	std::cin >> InputValue;

	return InputValue;
}

short ReadMonth()
{
	short InputValue = 0;
	std::cout << "\nPlease enter a month? ";
	std::cin >> InputValue;

	return InputValue;
}

bool isLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month == 0)
		return 0;

	short NumberOfDaysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDaysInMonths[Month - 1];
	
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}

	 TotalDays += Day;

	 return TotalDays;
}

std::string GetDateFromTotalDays(short TotalDays, short Month, short Year)
{
	for (int i = 1; i <= 12; i++)
	{
		if (i != Month)
			TotalDays -= NumberOfDaysInMonth(i, Year);
		else
			return std::to_string(TotalDays) + "/" + std::to_string(i) + "/" + std::to_string(Year);
	}
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	short NumberOfDays = NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year);

	std::cout << "\nNumber of days from the beginning of the year is ";
	std::cout << NumberOfDays << std::endl;

	std::cout << "\nDate for [" << NumberOfDays << "] is: " << GetDateFromTotalDays(NumberOfDays, Month, Year) << std::endl;

	system("pause>0");
}

