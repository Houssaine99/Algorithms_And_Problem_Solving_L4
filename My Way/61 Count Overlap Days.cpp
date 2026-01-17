#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
//#include "MyLib.h"

enum enDatesCompare
{
	eBefore = -1,
	eEqual = 0,
	eAfter = 1
};

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
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

stPeriod ReadPeriod()
{
	stPeriod Period;

	std::cout << "\nEnter Start Date:\n\n";
	Period.StartDate = ReadFullDate();

	std::cout << "Enter End Date:\n\n";
	Period.EndDate = ReadFullDate();

	return Period;

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

bool isDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
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
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

stDate GetSystemTime()
{
	stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Day = now->tm_mday;
	Date.Month = now->tm_mon + 1;
	Date.Year = now->tm_year + 1900;

	return Date;
}

std::string DayShortName(short DayOfWeekOrder)
{
	std::string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool EncludeEndDay = false)
{
	int Days = 0;
	while (isDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return EncludeEndDay ? ++Days : Days;

}

bool isDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!isDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
}

enDatesCompare CompareDates(stDate Date1, stDate Date2)
{
	if (isDate1BeforeDate2(Date1, Date2))
		return enDatesCompare::eBefore;
	if (isDate1EqualDate2(Date1, Date2))
		return enDatesCompare::eEqual;

	return enDatesCompare::eAfter;
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsDateWithinPeriod(stPeriod Period, stDate DateToCheck)
{
	return !((CompareDates(DateToCheck, Period.StartDate) == enDatesCompare::eBefore)
		       ||
		     (CompareDates(DateToCheck, Period.EndDate) == enDatesCompare::eAfter));
}

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
	stDate Current = Period2.StartDate;
	short Days = 0;
	
	while (CompareDates(Current, Period2.EndDate) != enDatesCompare::eAfter)
	{
		Current = IncreaseDateByOneDay(Current);

		if (IsDateWithinPeriod(Period1, Current))
			Days++;
	}

	return Days;
}

int main()
{ 
	stPeriod Period1, Period2;
	
	std::cout << "Enter Period 1:\n";
	Period1 = ReadPeriod();

	std::cout << "Enter Period 2:\n";
	Period2 = ReadPeriod();

	std::cout << "Overlap Days Count: " << CountOverlapDays(Period1, Period2) << std::endl;

	


	
	

	system("pause>0");

}
	
	
	

