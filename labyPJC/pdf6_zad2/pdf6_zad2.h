#pragma once
#include <iostream>
#include <cmath>

class Frac
{
	int n, d;

public:
	Frac(int x = 0, int y = 1) : n(x), d(y) {
		if (x != 0) {
			while (gcd(x, y) > 1) {
				x = x / gcd(x, y);
				y = y / gcd(x, y);
			}
		}
		
	}

private:
	int gcd(int a, int b) {
		if (a < 0) a = -a;
		if (b < 0) b = -b;

		while (a != b) {
			if (a > b) a = a - b;
			else b = b - a;
		}

		return a;
	}
};