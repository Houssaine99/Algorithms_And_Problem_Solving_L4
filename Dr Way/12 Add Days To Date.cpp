#include <iostream>
#include <string>
#include <iomanip>

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

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

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

short ReadHowManyDaysToAdd()
{
	short InputValue = 0;
	std::cout << "\nPlease enter how many days to add? ";
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

stDate DateAddDays(short Days, stDate Date)
{

	short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
	short MonthDays = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

int main()
{
	stDate Date = ReadFullDate();
	short Days = ReadHowManyDaysToAdd();


	Date = DateAddDays(Days, Date);

	std::cout << "\nDate after adding [" << Days << "] days is: ";
	std::cout << Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

	system("pause>0");
}

