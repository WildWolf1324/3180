// Review - Classes
// Adapted from A Tour of C++ by Bjarne Stroustrup
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class complex {
    double re, im;
public:
    complex(double r, double i) : re{r}, im{i} {} //construct complex from two scalars
    complex(double r): re{r}, im{0} {}            //construct complex from one scalar
    complex() : re{0}, im{0} {}
    
    double real() const {return re;}
    void real(double d) {re = d;}
    double imag() const {return im;}
    void imag(double d) {im = d;}
    
    complex& operator +=(complex z) {re+=z.re, im+=z.im; return *this;}
    complex& operator -=(complex z) {re-=z.re, im-=z.im; return *this;}


};

    complex operator+(complex a, complex b) {return a+= b;}
    complex operator-(complex a, complex b) {return a-= b;}
    complex operator-(complex a){return {-a.real(), -a.imag()};} //unary minus
    ostream& operator<<(ostream& os, const complex& a) { return os << a.real() << " + " << "j" << a.imag(); }

int main()
{
    complex a{2.3}, b{1,2}, c;
    c = a + -b;
    cout << c << endl;
    
    return 0;
    
}
