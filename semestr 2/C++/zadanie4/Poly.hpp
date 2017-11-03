#pragma once

#include <iostream>
#include <initializer_list>

class Poly
{
    int n;
    double *Tab;
public:
// ##### Constructors #####
    Poly(int st=0, double wsp=1.0);
    Poly(int st, const double wsp[]);
    Poly(std::initializer_list<double> wsp);
    Poly(const Poly &w);
    Poly(Poly &&w);

// ##### Assignment operators #####
    Poly& operator=(const Poly &w);
    Poly& operator=(Poly &&w);

// ##### Input/Output operators #####
    friend std::istream& operator >> (std::istream &In, Poly &Obj);
    friend std::ostream& operator << (std::ostream &Out, const Poly &Obj);

// ##### Arithmetic operators #####
    friend Poly operator + (const Poly &u, const Poly &v);
    friend Poly operator - (const Poly &u, const Poly &v);
    friend Poly operator * (const Poly &u, const Poly &v);
    Poly operator * (double c);
    Poly& operator += (const Poly &v);
    Poly& operator -= (const Poly &v);
    Poly& operator *= (const Poly &v);
    Poly& operator *= (double c);
    double operator () (double x) const;
    double operator [] (int i) const;

// ##### Destructor #####
    ~Poly ();
};