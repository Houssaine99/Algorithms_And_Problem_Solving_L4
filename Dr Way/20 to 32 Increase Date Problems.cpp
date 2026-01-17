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

stDate IncreaseDateByXDays(stDate Date, short Days)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, short Weeks)
{
	for (int i = 1; i <= Weeks; i++)
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

	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
		Date.Day = NumberOfDaysInCurrentMonth;

	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short Months)
{
	for (int i = 1; i <= Months; i++)
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

stDate IncreaseDateByXYears(stDate Date, short Years)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short Years)
{
	Date.Year += Years;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short Decades)
{
	for (int i = 1; i <= Decades * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short Decades)
{
	Date.Year += 10 * Decades;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}

int main()
{
	
	stDate Date = ReadFullDate();

	std::cout << "Date After:\n\n";

	Date = IncreaseDateByOneDay(Date);
	std::cout << "01-Adding one day is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByXDays(Date, 10);
	std::cout << "02-Adding 10 days is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByOneWeek(Date);
	std::cout << "03-Adding one week is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByXWeeks(Date, 10);
	std::cout << "04-Adding 10 weeks is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByOneMonth(Date);
	std::cout << "05-Adding one month is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByXMonths(Date, 5);
	std::cout << "06-Adding 5 months is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByOneYear(Date);
	std::cout << "07-Adding one year is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByXYears(Date, 10);
	std::cout << "08-Adding 10 years is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByXYearsFaster(Date, 10);
	std::cout << "09-Adding 10 years (faster) is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByOneDecade(Date);
	std::cout << "10-Adding one decade is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByXDecades(Date, 10);
	std::cout << "11-Adding 10 decades is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByXDecadesFaster(Date, 10);
	std::cout << "12-Adding 10 decades (faster) is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByOneCentury(Date);
	std::cout << "13-Adding one century is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = IncreaseDateByOneMillennium(Date);
	std::cout << "14-Adding one millennium is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	
	
	
	system("pause>0");
}
	
	
	

