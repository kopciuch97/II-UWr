#include "Poly.hpp"

int main()
{
    Poly Obj1({2,3,1});
    Poly Obj2({5,1});
    Poly Obj3(0,0.0);

    std::cout<<"a(x): "<<Obj1<<'\n';
    std::cout<<"b(x): "<<Obj2<<'\n';
    std::cout<<"a(x)+b(x):\n";
        std::cout<<"   "<<Obj1+Obj2<<'\n';
        Obj3=Obj1; Obj3+=Obj2;
        std::cout<<"   "<<Obj3<<'\n';
    std::cout<<"a(x)-b(x):\n";
        std::cout<<"   "<<Obj1-Obj2<<'\n';
        Obj3=Obj1; Obj3-=Obj2;
        std::cout<<"   "<<Obj3<<'\n';
    std::cout<<"a(x)*b(x):\n";
        std::cout<<"   "<<Obj1*Obj2<<'\n';
        Obj3=Obj1; Obj3*=Obj2;
        std::cout<<"   "<<Obj3<<'\n';

    std::cout<<"a(2): "<<Obj1(2)<<'\n';
    std::cout<<"b(6): "<<Obj2(5)<<'\n';

    std::cout<<"a[2]: "<<Obj1[2]<<'\n';
    std::cout<<"a[1]: "<<Obj1[1]<<'\n';
    std::cout<<"a[0]: "<<Obj1[0]<<'\n';
    std::cout<<"b[1]: "<<Obj2[1]<<'\n';
    std::cout<<"b[0]: "<<Obj2[0]<<'\n';

    std::cout<<"c(x)=a(x)"<<'\n';
    Obj3=Obj1;
    std::cout<<"   c(x): "<<Obj3<<'\n';
    std::cout<<"c(x)=std::move(b(x))"<<'\n';
    Obj3=std::move(Obj2);
    std::cout<<"   c(x): "<<Obj3<<'\n';
    std::cout<<"   b(x): "<<Obj2<<'\n';
}
