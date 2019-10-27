// pdf3_zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "pdf3_zad2.h"

int main()
{
	double a, b, c, * ptrMin, * ptrMax;

	a = 2; b = 1; c = 3;
	ord3(a, b, c);
	printOrd(&a, &b, &c);

	a = 3; b = 2; c = 1;
	ord3(&a, &b, &c);
	printOrd(&a, &b, &c);

	a = -1; b = -1; c = 1;
	ord3(&a, &b, &c);
	printOrd(&a, &b, &c);

	a = 2; b = 3; c = 1;
	getMinMax(a, b, c, ptrMin, ptrMax);
	printMinMax(ptrMin, ptrMax);

	a = 3; b = 1; c = 2;
	getMinMax(&a, &b, &c, &ptrMin, &ptrMax);
	printMinMax(ptrMin, ptrMax);

	a = 3; b = 3; c = -1;
	getMinMax(&a, &b, &c, &ptrMin, &ptrMax);
	printMinMax(ptrMin, ptrMax);
}

void ord3(double& a, double& b, double& c) {
	double tmp;
	if (a > b){
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b > c){
		tmp = b;
		b = c;
		c = tmp;
	}
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
}

void ord3(double* a, double* b, double* c) {
	ord3(*a, *b, *c);
}

void getMinMax(double& a, double& b, double& c, double*& ptrMin, double*& ptrMax) {
	ptrMin = &a;
	if (*ptrMin > b) ptrMin = &b;
	if (*ptrMin > c) ptrMin = &c;
	ptrMax = &a;
	if (*ptrMax < b) ptrMax = &b;
	if (*ptrMax < c) ptrMax = &c;
}

void getMinMax(double* a, double* b, double* c, double** ptrMin, double** ptrMax) {
	getMinMax(*a, *b, *c, *ptrMin, *ptrMax);
}

void printOrd(const double* a, const double* b, const double* c) {
	using std::cout; using std::endl;
	cout << *a << " " << *b << " " << *c << endl;
}

void printMinMax(const double* pmn, const double* pmx) {
	using std::cout; using std::endl;
	std::cout << "Min = " << *pmn << "; "
		<< "Max = " << *pmx << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
