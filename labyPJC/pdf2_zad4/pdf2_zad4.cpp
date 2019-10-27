#include <iostream>
#include "pdf2_zad4.h"

int main()
{
    std::cout << "GCD 12, 42: " << gcdRec(12, 42) << std::endl;
	std::cout << "GCD 12, 25: " << gcdRec(12, 25) << std::endl;
	std::cout << "Digits sum 123: : " << sumDigits(123) << std::endl;
	std::cout << "Digits sum 971: : " << sumDigits(971) << std::endl;
}

int gcdRec(int a, int b) {
	if (b == 0) return a;
	return gcdRec(b, a % b);
}

int sumDigits(int a) {
	if (a < 10) return a;
	return a % 10 + sumDigits((int)(a / 10));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu