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

bool isLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool isLastMonthInYear(short Month)
{
	return (Month == 12);
}

void PrintFormatedDate(stDate Date)
{
	std::cout << Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;
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

	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if(Date.Day > NumberOfDaysInCurrentMonth)
		Date.Day = NumberOfDaysInCurrentMonth;


	return Date;
}

stDate IncreaseDateByXDays(stDate Date, short NumberOfDays)
{
	for (int i = 1; i <= NumberOfDays; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	return IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeks)
{
	for (int i = 1; i <= NumberOfWeeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
		Date.Month++;

	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short NumberOfMonths)
{
	for (int i = 1; i <= NumberOfMonths; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(stDate Date, short NumberOfYears)
{
	for (int i = 1; i <= NumberOfYears; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYears)
{
	Date.Year += NumberOfYears;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	return IncreaseDateByXYears(Date, 10);
}

stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecades)
{
	for (int i = 1; i <= NumberOfDecades; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades)
{
	Date.Year += NumberOfDecades * 10;

	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	return IncreaseDateByXDecadesFaster(Date, 10);
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	return IncreaseDateByXDecadesFaster(Date, 100);
}

int main()
{
	
	stDate Date = ReadFullDate();

	std::cout << "Date After:\n\n";

	Date = IncreaseDateByOneDay(Date);
	std::cout << "01-Adding one day is               : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByXDays(Date, 10);
	std::cout << "02-Adding 10 days is               : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByOneWeek(Date);
	std::cout << "03-Adding one week is              : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByXWeeks(Date, 10);
	std::cout << "04-Adding 10 weeks is              : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByOneMonth(Date);
	std::cout << "05-Adding one month is             : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByXMonths(Date, 5);
	std::cout << "06-Adding 5 months is              : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByOneYear(Date);
	std::cout << "07-Adding 1 year is                : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByXYears(Date, 10);
	std::cout << "08-Adding 10 years is              : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByXYearsFaster(Date, 10);
	std::cout << "09-Adding 10 years (faster) is     : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByOneDecade(Date);
	std::cout << "10-Adding one decade is            : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByXDecades(Date, 10);
	std::cout << "11-Adding 10 decades is            : "; 
	PrintFormatedDate(Date);

	Date = IncreaseDateByXDecadesFaster(Date, 10);
	std::cout << "12-Adding 10 decades is (faster) is: ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByOneCentury(Date);
	std::cout << "13-Adding one century is           : ";
	PrintFormatedDate(Date);

	Date = IncreaseDateByOneMillennium(Date);
	std::cout << "14-Adding one millennium is        : ";
	PrintFormatedDate(Date);

	
	system("pause>0");
}
	
	
	

