#include "Poly.hpp"

#include <iostream>
#include <initializer_list>

Poly::Poly(int st, double wsp)
{
    n=st;
    Tab = new double[st+1]{};
    Tab[0] = wsp;
}
Poly::Poly(int st, const double wsp[]) // st:3 {1,5,3,0}
{
    n=st;
    Tab = new double[st+1];
    for(int i=0; i<st+1; ++i) Tab[i]=wsp[i];
    Tab[st] = n;
}
Poly::Poly(std::initializer_list<double> wsp)
{
    n=wsp.size()-1;
    Tab = new double[n+1];
    double *ItrBase=Tab;
    for(std::initializer_list<double>::iterator Itr=wsp.begin(); Itr!=wsp.end(); ++Itr, ++ItrBase) *ItrBase=*Itr;
}
Poly::Poly(const Poly &Obj)
{
    n = Obj.n;
    if(Tab) delete[] Tab;
    Tab = new double[n+1];
    for(int i=0; i<n+1; ++i) Tab[i]=Obj.Tab[i];
}
Poly::Poly(Poly &&Obj)
{
    n=Obj.n;
    Tab=Obj.Tab;
    Obj.n=0;
    Obj.Tab=nullptr;
}
Poly::~Poly()
{
    if(Tab)
    {
        delete[] Tab;
        Tab=nullptr;
    }
}

// ##### Assignment operator overloading #####
Poly& Poly::operator=(const Poly &Obj)
{
    n = Obj.n;
    if(Tab) delete[] Tab;
    Tab = new double[n+1];
    for(int i=0; i<n+1; ++i) Tab[i]=Obj.Tab[i];
    return *this;
}
Poly& Poly::operator=(Poly &&Obj)
{
    n=Obj.n;
    Tab=Obj.Tab;
    Obj.n=0;
    Obj.Tab=nullptr;
    return *this;
}

// ##### Input/Output operators #####
std::istream& operator>>(std::istream &In, Poly &Obj)
{
    std::cout<<"Degree: ";
    In>>Obj.n;
    std::cout<<"Coeff ["<<Obj.n+1<<"]: ";
    if(Obj.Tab) delete[] Obj.Tab;
    Obj.Tab = new double[Obj.n+1];
    for(int i=0; i<Obj.n+1; ++i) In>>Obj.Tab[i];
}
std::ostream& operator<<(std::ostream &Out, const Poly &Obj)
{
    Out<<"f(x)=";
    if(!Obj.Tab)
    {
        Out<<'0';
        return Out;
    }
    bool First = true;
    for(int i=0; i<Obj.n+1; ++i)
    {
        if(Obj.Tab[i])
        {
            if(!First)
                if(Obj.Tab[i]>=0) Out<<'+';
            Out<<Obj.Tab[i];
            if(i<Obj.n) std::cout<<'x';
            if(Obj.n-i>1) Out<<'^'<<Obj.n-i;
            First = false;
        }
    }
    return Out;
}

// ##### Arithmetic operators #####
Poly operator+(const Poly &Arg1, const Poly &Arg2)
{
    int MaxIndex = (Arg1.n>Arg2.n?Arg1.n:Arg2.n);
    Poly NewObj(MaxIndex, 0.0);
    NewObj.n=MaxIndex;
    for(int i=0; i<Arg1.n+1; ++i) NewObj.Tab[MaxIndex-i]=Arg1.Tab[Arg1.n-i];
    for(int i=0; i<Arg2.n+1; ++i) NewObj.Tab[MaxIndex-i]+=Arg2.Tab[Arg2.n-i];
    return NewObj;
}
Poly operator-(const Poly &Arg1, const Poly &Arg2)
{
    int MaxIndex = (Arg1.n>Arg2.n?Arg1.n:Arg2.n);
    Poly NewObj(MaxIndex, 0.0);
    NewObj.n=MaxIndex;
    for(int i=0; i<Arg1.n+1; ++i) NewObj.Tab[MaxIndex-i]=Arg1.Tab[Arg1.n-i];
    for(int i=0; i<Arg2.n+1; ++i) NewObj.Tab[MaxIndex-i]-=Arg2.Tab[Arg2.n-i];
    return NewObj;
}
Poly operator*(const Poly &Arg1, const Poly &Arg2)
{
    int MaxIndex = Arg1.n+Arg2.n;
    Poly NewObj(MaxIndex, 0.0);
    NewObj.n=MaxIndex;
    for(int i=0; i<Arg1.n+1; ++i)
        for(int j=0; j<Arg2.n+1; ++j)
            NewObj.Tab[MaxIndex-i-j]+=Arg1.Tab[Arg1.n-i]*Arg2.Tab[Arg2.n-j];
    return NewObj;
}
Poly Poly::operator*(double Value)
{
    Poly NewObj(*this);
    for(int i=0; i<n+1; ++i) NewObj.Tab[i]*=Value;
    return NewObj;
}
Poly& Poly::operator+=(const Poly &Arg)
{
    int MaxIndex = (n>Arg.n?n:Arg.n);
    double *NewTab = new double[MaxIndex+1]{};
    for(int i=0; i<n+1; ++i) NewTab[MaxIndex-i]=Tab[n-i];
    for(int i=0; i<Arg.n+1; ++i) NewTab[MaxIndex-i]+=Arg.Tab[Arg.n-i];
    n=MaxIndex;
    if(Tab) delete[] Tab;
    Tab = NewTab;
    return *this;
}
Poly& Poly::operator-=(const Poly &Arg)
{
    int MaxIndex = (n>Arg.n?n:Arg.n);
    double *NewTab = new double[MaxIndex+1]{};
    for(int i=0; i<n+1; ++i) NewTab[MaxIndex-i]=Tab[n-i];
    for(int i=0; i<Arg.n+1; ++i) NewTab[MaxIndex-i]-=Arg.Tab[Arg.n-i];
    n=MaxIndex;
    if(Tab) delete[] Tab;
    Tab = NewTab;
    return *this;
}
Poly& Poly::operator*=(const Poly &Arg)
{
    int MaxIndex = Arg.n+n;
    double *NewTab = new double[MaxIndex+1]{};
    for(int i=0; i<n+1; ++i)
        for(int j=0; j<Arg.n+1; ++j) NewTab[i+j]+=Tab[i]*Arg.Tab[j];
    n=MaxIndex;
    if(Tab) delete[] Tab;
    Tab = NewTab;
    return *this;
}
Poly& Poly::operator*=(double Value)
{
    for(int i=0; i<n+1; ++i) Tab[i]*=Value;
    return *this;
}
double Poly::operator()(double x) const
{
    int Ret = Tab[0];

    for(int i=1; i<n+1; i++)
        Ret = Ret*x + Tab[i];

    return Ret;
}
double Poly::operator[](int i) const
{
    return Tab[n-i];
}
