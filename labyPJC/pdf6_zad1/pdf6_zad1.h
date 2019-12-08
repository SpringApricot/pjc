#pragma once
#include <iostream>
class Point
{
	double x, y;

public:
	Point() : x(0), y(0) {}
	Point(double z) : x(z), y(z) {}
	Point(double z, double v) : x(z), y(v) {}

	double getX() const {
		return x;
	}

	double getY() const {
		return y;
	}

	Point& setX(double z) {
		x = z;
		return *this;
	}

	Point& setY(double v) {
		y = v;
		return *this;
	}

	Point& transX(double z) {
		x += z;
		return *this;
	}

	Point& transY(double v) {
		y += v;
		return *this;
	}

	Point& transXY(double z, double v) {
		x += z;
		y += v;
		return *this;
	}

	static double dist(const Point& a, const Point& b) {
		double pow1 = std::pow(b.x - a.x, 2);
		double pow2 = std::pow(b.y - a.y, 2);
		return std::sqrt(pow1 + pow2);
	}
};