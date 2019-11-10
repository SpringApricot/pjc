#include "pdf4_zad1.h"

int main()
{
	int testArr1[] = { 3, 1, 5, 7, -2 };
	std::cout << "3, 1, 5, 7, -2. Greatest's index is " << findGreatest(testArr1, 5) << std::endl;

	double testArr2[] = { 3.5, 1.7, 5.3, 7.2, 7.8, -2.1 };
	std::cout << "3.5, 1.7, 5.3, 7.2, 7.8, -2.1. Greatest's index is " << findGreatest(testArr2, 6) << std::endl;

	std::string testArr3[] = { "asd", "A", "aaa", "zzzzzzzzzzzzzzz", "asdzxc", "z", "ZZZZZZ" };
	std::cout << "asd, A, aaa, zzzzzzzzzzzzzzz, asdzxc, z, ZZZZZZ. Greatest's index is " << findGreatest(testArr3, 7) << std::endl;
}

template <typename T>
int findGreatest(T arr[], size_t arrSize) {
	int index = 0;
	for (size_t i = 1; i < arrSize; i++) {
		if (arr[index] < arr[i]) index = i;
	}
	return index;
}
