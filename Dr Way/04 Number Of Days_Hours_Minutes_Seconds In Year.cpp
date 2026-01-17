#include <iostream>
#include <string>

int ReadYear()
{
	int InputValue = 0;
	std::cout << "Enter a year? ";
	std::cin >> InputValue;

	return InputValue;
}

bool isLeapYear(int Year)
{
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

int NumberOfDays(int Year)
{
	return (isLeapYear(Year)) ? 366 : 365;
}

int NumberOfHours(int Year)
{
	return NumberOfDays(Year) * 24;
}

int NumberOfMinutes(int Year)
{
	return NumberOfHours(Year) * 60;
}

int NumberOfSeconds(int Year)
{
	return NumberOfMinutes(Year) * 60;
}

int main()
{
	int Year = ReadYear();

	std::cout << "Number Of Days    in Year [" << Year << "] is " << NumberOfDays(Year) << std::endl;
	std::cout << "Number Of Hours   in Year [" << Year << "] is " << NumberOfHours(Year) << std::endl;
	std::cout << "Number Of Minutes in Year [" << Year << "] is " << NumberOfMinutes(Year) << std::endl;
	std::cout << "Number Of Seconds in Year [" << Year << "] is " << NumberOfSeconds(Year) << std::endl;

	system("pause>0");
}