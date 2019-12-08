#include "pdf6_zad1.h"

int main()
{
	Point p;
	Point q(1);
	Point r(1, 2);
	p.transXY(5, 6);
	q.transX(-1).transY(-1).transXY(2, 2);
	r.setX(10).transY(-8);
	std::cout << Point::dist(p, q) << std::endl;
	std::cout << Point::dist(p, r) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
