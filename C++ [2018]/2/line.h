#pragma once
#include "point.h"
#include "vector.h"
#include <iostream>
class Line
{
	
	//wspolczynniki rownania prostej w postaci normalnej
	double a, b, c;
	//funkcja normujaca
	void normalize(double& a, double& b, double& c);


public:
	
	//konstruktory
	Line() = default;
	Line(const Point& p1, const Point& p2);
	Line(const Vector&);
	Line(const double a, const double b, const double c);
	Line(const Line& pr, const Vector& w);
	
	//off kopiowanie
	Line(const Line&) = delete;
	Line& operator=(const Line&) = delete;
	
	//Gettery
	double getA() const { return a; };
	double getB() const { return b; };
	double getC() const { return c; };
	
	//Inne funkcje
	bool onLine(const Point&);
	bool isParallel(const Vector&);
	bool isNormal(const Vector&);





};

bool areNormal(const Line& a, const Line& b);
bool areParallel(const Line& a, const Line& b);
Point crossingPoint(const Line& a, const Line& b);
std::ostream& operator<<(std::ostream& str, const Line& A);
