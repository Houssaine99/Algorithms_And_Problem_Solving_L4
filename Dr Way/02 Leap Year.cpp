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
	if (Year % 400 == 0)
		return true;

	else if (Year % 100 == 0)
		return false;

	else if (Year % 4 == 0)
		return true;

	else
		return false;
}

int main()
{
	int Year = ReadYear();

	if (isLeapYear(Year))
		std::cout << "\nYes, " << Year << " is a leap year.\n";
	else
		std::cout << "\nNo, " << Year << " is not a leap year.\n";

	system("pause>0");
}