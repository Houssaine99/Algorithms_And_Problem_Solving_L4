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

bool isDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false) : false;
}

int main()
{
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();


	if (isDate1EqualDate2(Date1, Date2))
		std::cout << "\nYes, Date1 is equal to date2.\n";
	else
		std::cout << "\nNo, Date1 is not equal to date2.\n";
	
	system("pause>0");
}

