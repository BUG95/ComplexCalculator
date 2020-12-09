#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Complex{
    T a, b;
public:
    Complex(){a = b = 0;}
    Complex(T a, T b){
        this->a = a;
        this->b = b;
    }
    Complex operator + (const Complex c){
        Complex newComplex;
        newComplex.a = a + c.a;
        newComplex.b = b + c.b;
        return newComplex;
    }
    Complex operator - (const Complex c){
        Complex newComplex;
        newComplex.a = a - c.a;
        newComplex.b = b - c.b;
        return newComplex;
    }
    Complex operator * (const Complex complex){
        T a = this->a, b = this->b, c = complex.a, d = complex.b;
        Complex newComplex;
        newComplex.a = a*c - b*d;
        newComplex.b = a*d + b*c;
        return newComplex;
    }
    Complex operator / (const Complex complex){
        T a = this->a, b = this->b, c = complex.a, d = complex.b;
        Complex newComplex;
        newComplex.a = (a*c + b*d) / (c*c + d*d);
        newComplex.b = (b*c - a*d) / (c*c + d*d);
        return newComplex;
    }
    bool operator == (int n){
        return a == n && b == n;
    }
    bool operator == (const Complex c){
        return a == c.a && b == c.b;
    }
    friend ostream & operator << (ostream &output, const Complex c){
        output << c.a << (c.b < 0 ? "" : "+") << c.b << "i";
        return output;
    }
    friend istream & operator >> (istream &input, Complex &c){
        cout << "a=";
        input >> c.a;
        cout << "b=";
        input >> c.b;
        return input;
    }
};


template <class T>
class Calculator{
public:
    T add(T a, T b){
        return a + b;
    }
    T subtract(T a, T b){
        return a - b;
    }
    T multiply(T a, T b){
        return a * b;
    }
    T divide(T a, T b){
        if(b == 0) throw "You can not divide by 0";
        return a / b;
    }
};


int main()
{
    Calculator<Complex<double>> complexCalculator;
    Complex<double> a(1, 2), b(0, 0);
    try{
        cout << complexCalculator.multiply(a, b) << endl;
        cout << complexCalculator.divide(a, b);
    } catch(const char *msg) {cout << msg;}
    cout << endl;
    Calculator<int> simpleCalculator;
    try{
        cout << simpleCalculator.multiply(2, 10) << endl;
        cout << simpleCalculator.divide(10, 0);
    } catch(const char *msg) {cout << msg;}
    return 0;
}
