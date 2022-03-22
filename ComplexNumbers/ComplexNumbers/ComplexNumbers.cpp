#include<iostream>

void test(double, double, double, double);
double round(double);

class complexNumber
{
    public:
        double real;
        double imaginary;

        complexNumber()
        {
            this->real = 0.0;
            this->imaginary = 0.0;
        }

        complexNumber(double real, double imaginary)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        complexNumber conjugate(complexNumber a)
        {
            complexNumber s(a.real, -a.imaginary);
            return s;
        }

        double modulus(complexNumber a)
        {
            return sqrt((a.real * a.real) + (a.imaginary * a.imaginary));
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


double round(double var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
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

void test(double actual, double expected)
{
    if (round(actual) == round(expected))
        std::cout << "Test Passed\n";
    else
        std::cout << "Test Failed\n";
    std::cout << "Expected Values: " << expected << std::endl;
    std::cout << "Actual Values: " << actual << std::endl;
}




int main()
{
    complexNumber a(3, 4), b(8, -2);
    complexNumber c;

    std::cout << "\nPrinting the complex numbers\n";
    std::cout << a << "\t" << b << std::endl;

    std::cout << "\n\nFinding Conjugates\n";
    c = c.conjugate(a);
    std::cout << "\nConjugate of " << a << " = " << c << std::endl;
    test(c.real, c.imaginary, double(3), double(-4));
    c = c.conjugate(b);
    std::cout << "Conjugate of " << b << " = " << c << std::endl;
    test(c.real, c.imaginary, double(8), double(2));


    std::cout << "\n\nFinding Modulus\n";
    double mod1 = a.modulus(a);
    double mod2 = b.modulus(b);
    std::cout << "\nModulus of " << a << " = " << mod1 << std::endl;
    test(mod1, 5);
    std::cout << "\nModulus of " << b << " = " << mod2 << std::endl;
    test(mod2, 8.24621);

    std::cout << "\n\nAdding two complex Numbers\n";
    c = c.sum(a, b);
    std::cout << "(" << a << ") + (" << b << ") = " << c << std::endl;
    test(c.real, c.imaginary, double(11), double(2));
    

    std::cout << "\n\nMultiplying two complex numbers\n";
    c = c.product(a, b);
    std::cout << "(" << a << ") * (" << b << ") = " << c << std::endl;
    test(c.real, c.imaginary, double(32), double(26));

    std::cout << "\n\nDividing two complex numbers\n";
    c = c.divide(a, b);
    std::cout << "(" << a << ") / (" << b << ") = " << c << std::endl;
    test(c.real, c.imaginary, 0.235294, 0.558824);

    
}