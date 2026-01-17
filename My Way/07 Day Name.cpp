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

short GetDayOrder(short Year, short Month, short Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12 * a - 2;

	return (Day + y + (y / 4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7;
}

std::string GetDayName(short Day)
{
	std::string Days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return Days[Day];
}

bool isLeapYear(int Year)
{
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	short DayOrder = GetDayOrder(Year, Month, Day);

	std::cout << "\nDate     : " << Day << "/" << Month << "/" << Year;
	std::cout << "\nDay Order: " << DayOrder;
	std::cout << "\nDay Name : " << GetDayName(DayOrder) << std::endl;

	system("pause>0");
}

