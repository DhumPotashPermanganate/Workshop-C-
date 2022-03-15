/*
 * Input: String, character
 * Output: Integer
 * This function returns the index of the character if a character is found in the given string.
 * If the character is not found, it returns -1.
*/

#include<iostream>
int position(std::string, char);
void test(int, int);


void Task3()
{
    test(position("Hello World", 'o'), 4);
    test(position("Hello World", 'p'), -1);

}

int position(std::string s, char c)
{
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]==c)
            return i;
    }
    return -1;
}


void test(int expected, int actual)
{
   
    if(actual == expected)
        std::cout << "Test Passed\n";
    else
        std::cout<<"Test Failed\n";
    std::cout << "Expected Values: " << expected << " , " << expected<<std::endl;

}
