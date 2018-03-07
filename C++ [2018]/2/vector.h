#pragma once
#include <iostream>

class Vector {
public:
	const double dx = 0;
	const double dy = 0;

	//konstruktory
	Vector() = default;
	Vector(const Vector&);
	Vector(const double dx, const double dy);

	//off operator przypisania
	Vector operator=(const Vector&) = delete;
};
//funkcja globalna zlozenia wektorow

Vector assembly(const Vector &a, const Vector &b);
std::ostream& operator<<(std::ostream& str, const Vector& A);