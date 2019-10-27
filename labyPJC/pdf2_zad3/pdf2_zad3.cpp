#include <iostream>
#include "pdf2_zad3.h"

int main()
{
	double arr[]{ 1,7,5,4,3,2 };
	size_t size = sizeof(arr) / sizeof(*arr);
	double average = 0;
	const double* p = aver(arr, size, average);
	std::cout << *p << " " << average << std::endl;
}

const double* aver(const double* arr, size_t size, double& average) {
	average = 0;
	for (size_t i = 0; i < size; i++) {
		average += arr[i];
	}
	average = average / size;
	double dist = std::abs(arr[0]-average);
	size_t resultsIndex = 0;
	for (size_t i = 1; i < size; i++) {
		if (std::abs(arr[i] - average) < dist) {
			dist = std::abs(arr[i] - average);
			resultsIndex = i;
		}
	}
	return arr + resultsIndex;
}