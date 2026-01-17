#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
//#include "MyLib.h"


struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

short ReadDay()
{
	short InputValue = 0;
	std::cout << "Please enter a day? ";
	std::cin >> InputValue;

	return InputValue;
}

short ReadYear()
{
	short InputValue = 0;
	std::cout << "Please enter a year? ";
	std::cin >> InputValue;

	return InputValue;
}

short ReadMonth()
{
	short InputValue = 0;
	std::cout << "Please enter a month? ";
	std::cin >> InputValue;

	return InputValue;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	std::cout << std::endl;

	return Date;
}

bool isLeapYear(short Year)
{
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month == 0)
		return 0;
	short MonthsDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1];
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)) : false);
}

short NumberOfDaysFromTheBeginningOfTheYear(stDate Date)
{
	short TotalDays = 0;

	for (int i = 1; i <= Date.Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Date.Year);
	}
	
	TotalDays += Date.Day;

	return TotalDays;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Date.Month) / 12;
	y = Date.Year - a;
	m = Date.Month + 12 * a - 2;

	return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

std::string DayShortName(short DayOfWeekOrder)
{
	std::string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool isEndOfWeek(short DayOfWeekOrder)
{
	if (DayOfWeekOrder == 6)
		return true;
	else
		return false;
}

bool isWeekEnd(short DayOfWeekOrder)
{
	if (DayOfWeekOrder > 4)
		return true;
	else
		return false;
}

bool isBusinessDay(short DayOfWeekOrder)
{
	if (DayOfWeekOrder < 5)
		return true;
	else
		return false;
}

short DaysUntilEndOfWeek(short DayOfWeekOrder)
{
	short Days = 0;
	for (int i = DayOfWeekOrder + 1; i < 7; i++)
		Days++;

	return Days;
}

short DaysUntilEndOfMonth(stDate Date)
{
	short Days = 0;

	for (int i = Date.Day; i <= NumberOfDaysInMonth(Date.Month, Date.Year); i++)
		Days++;
	
	return Days;

}

bool isLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool isLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (isLastDayInMonth(Date))
	{
		if (isLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
		Date.Day++;

	return Date;
}

short DaysUntilEndOfYear(stDate Date)
{
	short Days = 0;
	short CurrentYear = Date.Year;

	while (true)
	{
		if (Date.Year == CurrentYear)
		{
			Date = IncreaseDateByOneDay(Date);
			Days++;
		}
		else
			break;

	}

	return Days;
}

int main()
{
	
	stDate Date = ReadFullDate();

	short DayOrder = DayOfWeekOrder(Date);

	std::cout << "Today is " << DayShortName(DayOrder) << ", "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	std::cout << "\nIt is End of Week?\n";
	if (isEndOfWeek(DayOrder))
		std::cout << "Yes it is end of week.\n";
	else
		std::cout << "No it is NOT end of week.\n";

	std::cout << "\nIs it Weekend?\n";
	if (isWeekEnd(DayOrder))
		std::cout << "Yes it is a weekend\n";
	else
		std::cout << "No it is NOT a weekend\n";

	std::cout << "\nIs it Business Day?\n";
	if (isBusinessDay(DayOrder))
		std::cout << "Yes it is a business day\n";
	else
		std::cout << "No it is NOT a business day\n";

	std::cout << "\nDays until end of week: " << DaysUntilEndOfWeek(DayOrder) << " Day(s)";
	std::cout << "\nDays until end of month: " << DaysUntilEndOfMonth(Date) << " Day(s)";
	std::cout << "\nDays until end of year: " << DaysUntilEndOfYear(Date) << " Day(s)\n";
	
	
	
	system("pause>0");
}
	
	
	

