#include <iostream>
#include <string>

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

short ReadDay()
{
	short InputValue = 0;
	std::cout << "\nPlease enter a day? ";
	std::cin >> InputValue;
	return InputValue;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
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
	short Day = ReadDay();

	std::cout << "\nDate     : " << Day << "/" << Month << "/" << Year;
	std::cout << "\nDay Order: " << DayOfWeekOrder(Day, Month, Year);
	std::cout << "\nDay Name : " << DayShortName(DayOfWeekOrder(Day, Month, Year)) << std::endl;

	system("pause>0");
}

