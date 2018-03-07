#include "point.h"
#include "vector.h"
#include <iostream>


Point::Point(const Point &p) : x(p.x), y(p.y)
{
}

Point::Point(const double x1, const double y1) : x(x1), y(y1)
{
}

Point::Point(const Point &p, const Vector &w) : x(p.x + w.dx), y(p.y + w.dy)
{
}
std::ostream& operator<<(std::ostream& str, const Point& A)
{
	return str << "(" << A.x << ", " << A.y << ")";
}
