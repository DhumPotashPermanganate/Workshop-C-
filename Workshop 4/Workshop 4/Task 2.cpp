#include<iostream>
int cal(char, int , int);
int cal(int, int , char );
void test(double, double);

void Task2()
{
    test(cal('+', 8, 9), 17);
    test(cal('-', 32, -9), 41);
    test(cal(8, 9, '*'), 72.0);
    test(cal(120, 10, '/'), 12.0);

}

int cal(int a, int b, char c)
{
    if(c=='*')
        return a*b;
    return a/b;
}

int cal(char c, int a, int b)
{
    if(c=='+')
        return a+b;
    return a-b;
}


void test(double expected, double actual)
{
    if(actual == expected)
        std::cout << "Test Passed\n";
    else
        std::cout<<"Test Failed\n";
    std::cout << "Expected Values: " << expected << " , " << expected<<std::endl;
}




