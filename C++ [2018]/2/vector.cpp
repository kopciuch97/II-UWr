#include "vector.h"

Vector::Vector(const Vector& v) : dx(v.dx), dy(v.dy)
{
}

Vector::Vector(const double dx1, const double dy1) : dx(dx1), dy(dy1)
{
}
std::ostream& operator<<(std::ostream& str, const Vector& A)
{
	return str << "[" << A.dx << ", " << A.dy << "]";
}

Vector assembly(const Vector &a, const Vector &b) {
	return Vector(a.dx + b.dx, a.dy + b.dy);
}