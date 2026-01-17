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

std::string MonthShortName(short MonthOfYear)
{
	std::string arrMonths[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return arrMonths[MonthOfYear - 1];
}

void PrintMonthCalendar(short Month, short Year)
{
	short NumberOfDays = NumberOfDaysInMonth(Month, Year);
	short Current = DayOfWeekOrder(1, Month, Year);

	printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	int i;
	for (i = 0; i < Current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n  _________________________________\n");
}

void PrintYearCalendar(short Year)
{
	printf("\n\n  ________________________________\n");
	printf("\n           Calendar - %d\n", Year);
	printf("  ________________________________\n\n");

	for (int i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(i, Year);
		std::cout << std::endl;
	}
}

int main()
{

	PrintYearCalendar(ReadYear());
	
	system("pause>0");
}

