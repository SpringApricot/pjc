#include <iostream>
#include "pdf2_zad2.h"

int main()
{
	int a[]{ 5,2,3,4,2,7,4,7,2 };
	size_t size = sizeof(a) / sizeof(*a);
	int min, max;
	size_t minCnt, maxCnt;

	minMaxRep(a, size, min, minCnt, max, maxCnt);

	for (size_t i = 0; i < size; i++) {
		std::cout << a[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Min: " << min << ", times " << minCnt << std::endl << "Max: " << max << ", times " << maxCnt << std::endl;
}

void minMaxRep(int a[], size_t size, int& min, size_t& minCnt, int& max, size_t& maxCnt) {
	min = *a;
	max = *a;
	maxCnt = 0;
	minCnt = 0;

	for (size_t i = 0; i < size; i++) {
		if (*(a + i) < min) {
			min = *(a + i);
			minCnt = 1;
		}
		else if (*(a + i) == min) minCnt++;
		if (*(a + i) > max) {
			max = *(a + i);
			maxCnt = 1;
		}
		else if (*(a + i) == max) maxCnt++;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu