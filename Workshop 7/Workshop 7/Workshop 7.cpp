#include<iostream>
#include<cmath>
#include<iostream>
#include <cmath>

void test(double, double, double, double);
double round(double var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

class complexNumber
{
public:
    double real;
    double imaginary;

    complexNumber()
    {
        this->real = 0;
        this->imaginary = 0;
    }

    complexNumber(double real, double imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    double returnReal()
    {
        return this->real;
    }

    double imaginaryReturn()
    {
        return this->imaginary;
    }

    complexNumber sum(complexNumber a, complexNumber b)
    {
        complexNumber s(a.real + b.real, a.imaginary + b.imaginary);
        return s;
    }

    complexNumber product(complexNumber a, complexNumber b)
    {
        double r, i;
        r = (a.real * b.real) - (a.imaginary * b.imaginary);
        i = (a.real * b.imaginary) + (a.imaginary * b.real);
        complexNumber pro(r, i);
        return pro;
    }

    complexNumber divide(complexNumber a, complexNumber b)
    {
        double realNumerator, realDenominator;
        double imaginaryNumerator, imaginaryDenominator;

        realNumerator = a.real * b.real + a.imaginary * b.imaginary;
        realDenominator = pow(b.real, 2) + pow(b.imaginary, 2);
        imaginaryNumerator = a.imaginary * b.real - a.real * b.imaginary;
        imaginaryDenominator = realDenominator;
        complexNumber div(realNumerator / realDenominator, imaginaryNumerator / imaginaryDenominator);
        return div;
    }
};

int main()
{
    complexNumber a(3, 4), b(8, -2);
    complexNumber c;
    c = c.divide(a, b);
    test(c.real, c.imaginary, 0.235294, 0.558824);
    c = c.sum(a, b);
    test(c.real, c.imaginary, double(11), double(2));
    c = c.product(a, b);
    test(c.real, c.imaginary, double(32), double(26));
}
void test(double actualReal, double actualImag, double expectedReal, double expectedImag)
{
    if ((round(expectedReal) == round(actualReal)) && (round(expectedImag) == round(actualImag)))
        std::cout << "Test Passed\n";
    else
        std::cout << "Test Failed\n";

    std::cout << "Expected Values: " << expectedReal << " , " << expectedImag << std::endl;
    std::cout << "Actual Values: " << actualReal << " , " << actualImag << std::endl;
    std::cout << std::endl;
}







