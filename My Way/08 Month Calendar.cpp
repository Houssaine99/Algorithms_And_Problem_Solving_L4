#include <iostream>
#include <string>
#include <iomanip>

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

void PrintMonthCalendar(short Month, short Year)
{
	std::string arrWeekDays[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	std::string arrMonths[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	
	short NumberOfDays = NumberOfDaysInMonth(Month, Year);
	short FirstDayOfTheMonth = DayOfWeekOrder(1, Month, Year);
	short CurrentDay = 1;

	std::cout << "\n\n_______________" << arrMonths[Month - 1] << "_______________\n";

	for (int i = 0; i < 7; i++)
	{
		std::cout << std::setw(3) << arrWeekDays[i] << "  ";
	}
	std::cout << "\n";

	for (int i = 0; CurrentDay <= NumberOfDays; i++)
	{
		if (i < FirstDayOfTheMonth)
		{
			std::cout << "     ";
			continue;
		}

		std::cout << std::setw(3) << CurrentDay << "  ";

		if (DayOfWeekOrder(CurrentDay, Month, Year) == 6)
			std::cout << std::endl;
		
		CurrentDay++;
	}
	std::cout << "\n_________________________________\n";
}

std::string DayShortName(short DayOfWeekOrder)
{
	std::string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintMonthCalendar(Month, Year);
	
	system("pause>0");
}

