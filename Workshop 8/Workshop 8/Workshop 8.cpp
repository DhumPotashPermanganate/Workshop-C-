#include<iostream>
#include <cmath>

void test(double, double, double, double);
void test(bool, bool);
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

    bool isEquals(complexNumber x)
    {
        if (real == x.real && imaginary == x.imaginary)
            return true;
        return false;
    }

    complexNumber operator + (const complexNumber& x)
    {
        complexNumber y;
        y.real = real + x.real;
        y.imaginary = imaginary + x.imaginary;
        return y;
    }

    complexNumber operator - (const complexNumber& x)
    {
        complexNumber y;
        y.real = real - x.real;
        y.imaginary = imaginary - x.imaginary;
        return y;
    }

    complexNumber operator / (const complexNumber& x)
    {
        double realNumerator, realDenominator;
        double imaginaryNumerator, imaginaryDenominator;

        realNumerator = real * x.real + imaginary * x.imaginary;
        realDenominator = pow(x.real, 2) + pow(x.imaginary, 2);
        imaginaryNumerator = imaginary * x.real - real * x.imaginary;
        imaginaryDenominator = realDenominator;
        complexNumber div(realNumerator / realDenominator, imaginaryNumerator / imaginaryDenominator);
        return div;
    }

    complexNumber operator * (const complexNumber& x)
    {
        complexNumber y;
        y.real = (real * x.real) - (imaginary * x.imaginary);
        y.imaginary = (real * x.imaginary) + (imaginary * x.real);
        return y;
    }

    bool operator == (const complexNumber& x)
    {
        if (real == x.real && imaginary == x.imaginary)
            return true;
        return false;
    }

    friend std::ostream& operator<< (std::ostream& out, const complexNumber& x);


};


std::ostream& operator<< (std::ostream& out, const complexNumber& x)
{
    char sign = '+';
    if (x.imaginary < 0)
        sign = ' ';

    out << x.real << sign << x.imaginary << "i";
    return out;
}

int main()
{
    complexNumber a(3, 4), b(-2, 6);
    complexNumber c;
    c = a + b;
    test(c.real, c.imaginary, 1, 10);
    c = a - b;
    test(c.real, c.imaginary, 5, -2);
    c = c.divide(a, b);
    test(c.real, c.imaginary, 0.45, -0.65);
    c = a / b;
    test(c.real, c.imaginary, 0.45, -0.65);
    c = a * b;
    test(c.real, c.imaginary, -30, 10);
    c = c.product(a, b);
    test(c.real, c.imaginary, -30, 10);
    test(a.isEquals(b), false);
    test(a.isEquals(a), true);
    test(a == b, false);
    test(a == a, true);
    std::cout << a;
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

void test(bool actual, bool expected)
{
    if (actual == expected)
        std::cout << "Test Passed\n";
    else
        std::cout << "Test Failed\n";
    std::cout << "Expected Values: " << expected << " , " << expected << std::endl;
}
