#include "pdf3_zad3.h"
#include <iostream>

int main()
{
	int a[] = { 1,4,4,5,8 };
	int b[] = { 1,2,2,4,6,6,9 };
	constexpr size_t dima = std::size(a);
	constexpr size_t dimb = std::size(b);
	constexpr size_t dimc = dima + dimb;
	int c[dimc];
	merge(a, dima, b, dimb, c);
	printArr(a, dima, "a");
	printArr(b, dimb, "b");
	printArr(c, dimc, "c");
}

void merge(const int* a, size_t dima, const int* b, size_t dimb, int* c) {
	int ia = 0, ib = 0;

	for (int i = 0; i < dima + dimb; i++) {
		if (a[ia] < b[ib] && ia < dima) {
			c[i] = a[ia];
			ia++;
		}
		else {
			c[i] = b[ib];
			ib++;
		}
	}
}

void printArr(const int* a, size_t dima, const char* m) {
	std::cout << m << " [ ";
	for (size_t i = 0; i < dima; ++i)
		std::cout << a[i] << " ";
	std::cout << "]\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu