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


stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}
	}
	else
		Date.Day--;

	return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (int i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
		Date.Month--;

	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
		Date.Day = NumberOfDaysInCurrentMonth;

	return Date;
}

stDate DecreaseDateByXMonths(short Months, stDate Date)
{
	for (int i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYears(short Years, stDate Date)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(short Decades, stDate Date)
{
	for (int i = 1; i <= Decades * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	
	return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decades, stDate Date)
{
	Date.Year -= Decades * 10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}

int main()
{
	
	stDate Date = ReadFullDate();

	std::cout << "Date After:\n\n";

	Date = DecreaseDateByOneDay(Date);
	std::cout << "01-Subtracting one day is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByXDays(10, Date);
	std::cout << "02-Subtracting 10 days is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByOneWeek(Date);
	std::cout << "03-Subtracting one week is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByXWeeks(10, Date);
	std::cout << "04-Subtracting 10 weeks is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByOneMonth(Date);
	std::cout << "05-Subtracting one month is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByXMonths(5, Date);
	std::cout << "06-Subtracting 5 months is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByOneYear(Date);
	std::cout << "07-Subtracting one year is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByXYears(10, Date);
	std::cout << "08-Subtracting 10 years is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByXYearsFaster(10, Date);
	std::cout << "09-Subtracting 10 years (faster) is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByOneDecade(Date);
	std::cout << "10-Subtracting one decade is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByXDecades(10, Date);
	std::cout << "11-Subtracting 10 decades is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByXDecadesFaster(10, Date);
	std::cout << "12-Subtracting 10 decades (faster) is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByOneCentury(Date);
	std::cout << "13-Subtracting one century is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	Date = DecreaseDateByOneMillennium(Date);
	std::cout << "14-Subtracting one millennium is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	
	
	
	system("pause>0");
}
	
	
	

