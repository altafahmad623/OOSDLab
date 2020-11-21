#include <iostream>
#include <string.h>
using namespace std;
class Number
{
public:
    string num;
    void get_numb() // takes input as string from the user
    {
        string s;
        cout << "Please Enter your number:\n";
        cin >> s;
        num = s;
    }
    void show_number() //displays the numbers
    {
        cout << num << endl;
    }
    void multiply_number(string s1, string s2) //does the multiplication of the numbers
    {
        int n = s1.size(),m = s2.size();
        string multipl(n + m, '0'); // initally puts zeroes in all the final multiplication
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int digit = (s1[i] - '0') * (s2[j] - '0') + (multipl[i + j + 1] - '0'); // calculates the product one by one as well as the carry product- the carry is
                //stored in the multipl[i+j+1] 
                multipl[i + j + 1] = digit % 10 + '0'; //stores it's value in the place
                multipl[i + j] += digit / 10; //
            }
        }
        num = multipl;
    }
};
int main()
{
    Number no1, no2, mul;
    no1.get_numb();
    no2.get_numb();
    mul.multiply_number(no1.num,no2.num);
    cout<<"The Multiplication is :\n";
    mul.show_number();
    return 0;
}