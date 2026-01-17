#include <iostream>
#include <string>

int ReadNumber()
{
	int InputValue = 0;
	std::cout << "Enter a number? ";
	std::cin >> InputValue;
	return InputValue;
}

std::string NumberToText(int Number)
{
	int Ten = 10;
	int Hundred = 100;
	int Thousand = 1000;
	int Million = 1000000;
	int Billion = 1000000000;
	
	if (Number == 0)
		return "";

	else if (Number >= 1 && Number <= 19)
	{
		std::string Arr[] = { "", "One", "Two", "Three", "four", "Five", "Sex", "Seven", "Eight", "Nine",
		"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };

		return Arr[Number] + " ";
	}

	else if (Number >= 20 && Number <= 99)
	{
		std::string Arr[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty" };

		return Arr[Number / Ten] + " " + NumberToText(Number % Ten);
	}

	else if (Number >= Hundred && Number <= 199)
		return "One Hundred " + NumberToText(Number % Hundred);

	else if (Number >= 200 && Number <= 999)
		return NumberToText(Number / Hundred) + "Hundreds " + NumberToText(Number % Hundred);

	else if (Number >= Thousand && Number <= 1999)
		return "One Thousand " + NumberToText(Number % Thousand);

	else if (Number >= 2000 && Number <= 999999)
		return NumberToText(Number / Thousand) + "Thousands " + NumberToText(Number % Thousand);

	else if (Number >= Million && Number <= 1999999)
		return "One Million " + NumberToText(Number % Million);

	else if (Number >= 2000000 && Number <= 999999999)
		return NumberToText(Number / Million) + "Millions " + NumberToText(Number % Million);

	else if (Number >= Billion && Number <= 1999999999)
		return "One Billion " + NumberToText(Number % Billion);

	else if (Number >= 2000000000 && Number <= 999999999999)
		return NumberToText(Number / Billion) + "Billions " + NumberToText(Number % Billion);
}

int main()
{
	int Number = ReadNumber();

	std::cout << NumberToText(Number) << std::endl << std::endl;

	system("pause>0");
}