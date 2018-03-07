#include "line.h"
#include "point.h"
#include <stdexcept>
#include <cmath>
#include <iostream>
//ctors
Line::Line(const Point &p1, const Point &p2)
{
	if (p1.x == p2.x)
		throw std::invalid_argument("Nie mozna utworzyc prostej z punktow o rownych x\n");
	if (p1.x == p2.x && p1.y == p2.y)
		throw std::invalid_argument("Nie mozna jednoznacznie utworzyc prostej na bazie tego samego punktu!\n");
	a = p1.y - p2.y;
	b = p2.x - p1.x;
	c = -(p2.x * p1.y) + (p1.x * p2.y);
	normalize(a, b, c);
}

Line::Line(const Vector &w)
{
	if (w.dx == 0 && w.dy == 0)
		throw std::invalid_argument("Nie mozna utworzyc prostej na zerowym wektorze\n");
	a = -w.dy;
	b = w.dx;
	c = -(a * w.dx + b * w.dy);
	normalize(a, b, c);
}

Line::Line(const double a1, const double b1, const double c1)
{
	if (a1 == b1 && a1 == 0)
		throw std::invalid_argument("A i B nie moga byc rowne 0\n");
	a = a1;
	b = b1;
	c = c1;
	normalize(a, b, c);
}

Line::Line(const Line &l, const Vector &w)
{
	a = l.getA();
	b = l.getB();
	c = l.getC() + a * -w.dx + w.dy;
	normalize(a, b, c);
}


bool Line::isNormal(const Vector &w)
{
	return (a * (w.dy / b) == w.dx && b * (w.dy / b) == w.dy);
}

bool Line::isParallel(const Vector &w)
{
	return (a * (w.dx / b) == -w.dy && b * (w.dx / b) == w.dx);
}

bool Line::onLine(const Point &p)
{
	return (p.x * a + p.y * b + c == 0);
}

void Line::normalize(double &a, double &b, double &c)
{
	double norma;
	if (c > 0) {
		norma = 1 / std::sqrt(a * a + b * b);
	}
	else {
		norma = -1 / std::sqrt(a * a + b * b);
	}

	a *= norma;
	b *= norma;
	c *= norma;
}

//wlasnosci dwoch prostych
bool areNormal(const Line &a, const Line &b)
{
	return (a.getA() * b.getB() == -1);
}

bool areParallel(const Line &a, const Line &b)
{
	return (a.getA()* b.getB() - b.getA() * a.getB() == 0);
}

Point crossingPoint(const Line & a, const Line& b)
{
	double coefficient = a.getA()* b.getB() - b.getA() * a.getB();
	if (coefficient == 0) throw std::invalid_argument("Nie mozna obliczyc punktu przeciecia prostych rownoleglych!\n");
	double x = (-a.getC() * b.getB() - (-b.getC())*a.getB()) / coefficient;
	double y = (a.getA()*(-b.getC()) - b.getA()*(-a.getC())) / coefficient;
	return Point(x, y);
}

std::ostream& operator<<(std::ostream& str, const Line& A)
{
	return str << A.getA() << "x + " << A.getB() << "y + " << A.getC() << " = 0";
}