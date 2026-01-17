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

bool isDate1LessThanDate2(stDate Date1, stDate Date2)
{
	short Date1DayOrderInYear = NumberOfDaysFromTheBeginningOfTheYear(Date1.Day, Date1.Month, Date1.Year);
	short Date2DayOrderInYear = NumberOfDaysFromTheBeginningOfTheYear(Date2.Day, Date2.Month, Date2.Year);

	if (Date2DayOrderInYear > Date1DayOrderInYear && Date2.Year >= Date1.Year)
		return true;
	else
		return false;
}


int main()
{
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();


	if (isDate1LessThanDate2(Date1, Date2))
		std::cout << "\nYes, Date1 is less than date2.\n";
	else
		std::cout << "\nNo, Date1 is not less than date2.\n";
	
	system("pause>0");
}

