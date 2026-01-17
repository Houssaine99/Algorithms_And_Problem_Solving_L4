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

int main()
{
	int Year = ReadYear();

	if (isLeapYear(Year))
		std::cout << "\nYes, [" << Year << "] is a leap year.\n";
	else
		std::cout << "\nNo, [" << Year << "] is not a leap year.\n";

	system("pause>0");
}