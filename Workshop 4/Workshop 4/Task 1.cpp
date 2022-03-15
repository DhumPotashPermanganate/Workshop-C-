#include<iostream>
void swap(int*, int*);


void Task1()
{
    int a = 8, b = 9;
    std::cout << "Values Before Swapping:\na= " << a << ", b= " << b << std::endl;
    swap(&a, &b);
    std::cout << "Values After Swapping:\na= " << a << ", b= " << b << std::endl;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}