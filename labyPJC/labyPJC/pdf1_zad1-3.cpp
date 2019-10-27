#include <iostream>
#include "zjazd1.h"

int main()
{
	std::cout << "Sanity" << std::endl;
	double *result;

 	result = kwadr(1, 4, 3);
	if (result == nullptr)
		std::cout << "Bledne dane!" << std::endl;
	else {
		for (int i = 0; i < 2; i++)
			std::cout << "wynik" /*<< i + 1*/ << ": " << *(result + i) << std::endl;
	}

	result = kwadr(0, 0, 0);
	if (result == nullptr)
		std::cout << "Bledne dane!" << std::endl;
	else {
		for (int i = 0; i < 2; i++)
			std::cout << "wynik" << i + 1 << ": " << *(result + i) << std::endl;
	}

	result = kwadr(-2, 1, -3);
	if (result == nullptr)
		std::cout << "Bledne dane!" << std::endl;
	else {
		for (int i = 0; i < 2; i++)
		{
			std::cout << "wynik" << i + 1 << ": " << *(result + i) << std::endl;
		}
	}

	double masa, wzrost;
	std::cout << "Podaj mase w kilogramach: ";
	std::cin >> masa;
	std::cout << "Podaj wzrost w metrach: ";
	std::cin >> wzrost;
	std::cout << "Bmi: " << bmi(masa, wzrost) << std::endl;
	std::cout << std::endl;

	std::cout << "Give 3 non-negative numbers: ";
	int a, b, c;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	histogram(a, b, c);
}

double bmi(double masa, double wzrost) {
	return masa / (wzrost * wzrost);
}

void histogram(int a, int b, int c) {
	int top;
	if (a > b)
		top = a;
	else
		top = b;
	if (c > top)
		top = c;
	for (int i = top; i > 0; i--)
	{
		if (a >= i)
			std::cout << "*";
		else
			std::cout << " ";
		if (b >= i)
			std::cout << "*";
		else
			std::cout << " ";
		if (c >= i)
			std::cout << "*";
		else
			std::cout << " ";
		std::cout << std::endl;
	}
}

double* kwadr(int a, int b, int c) {
	static double result[2];

	if (a == 0 && b == 0 && c == 0) return nullptr;

	double delta = ((double)b * (double)b) - (4 * (double)a * (double)c);
	if (delta < 0) return nullptr;

	double x1 = ((0 - (double)b) + std::sqrt(delta)) / (2 * (double)a);
	double x2 = ((0 - (double)b) - std::sqrt(delta)) / (2 * (double)a);

	*(result) = x1;
	*(result + 1) = x2;

	return result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
