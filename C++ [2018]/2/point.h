#pragma once
#include "vector.h"
#include <iostream>

class Point {
public:
	//wspó³rzêdne
	const double x = 0;
	const double y = 0;

	//kostruktory
	Point() = default;
	Point(const Point&);
	Point(double x, double y);
	Point(const Point &p, const Vector &v);
	Point operator=(const Point &) = delete;
};
std::ostream& operator<<(std::ostream& str, const Point& A);