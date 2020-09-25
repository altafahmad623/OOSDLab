/*
We want to implement precision mathematics. For this, write a class Number, 
which takes as input an arbitrarily large integer as a string of numbers via a 
member function get_num, and may display it via a member function show_num.
It also has a member function add for adding such two numbers.
*/
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
    void reverseStr(string &str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    void show_number() //displays the numbers
    {
        cout << num << endl;
    }
    void add_number(string s1, string s2) //does the addition of the numbers
    {
        string sum = ""; // final string that will store the addition
        int i, j, k, t1, carry;
        int l1 = s1.length(), l2 = s2.length();
        if (l1 > l2)
        {
            carry = 0;
            for (i = (l1 - 1), j = (l2 - 1); j >= 0; i--, j--)
            {
                t1 = carry + (s1[i] - '0') + (s2[j] - '0'); // this stores the result after addition of each digit
                sum.push_back(t1 % 10 + '0');               // this saves it in the sum
                carry = t1 / 10;                            // this gets forwarded to the next digit for carry
            }
            for (i; i >= 0; i--) //if the smaller digit gets over, then this stores the left out values
            {
                t1 = carry + (s1[i] - '0'); // carry is added similarly to each digit
                sum.push_back(t1 % 10 + '0');
                carry = t1 / 10;
            }
            if (carry)
            {
                sum.push_back(carry + '0'); //finally if some carry is left
            }
            reverseStr(sum);
            num = sum;
        }
        else //similar case for the other way round, that is the other number is larger
        {
            carry = 0;
            for (i = (l1 - 1), j = (l2 - 1); i >= 0; i--, j--)
            {
                t1 = carry + (s1[i] - '0') + (s2[j] - '0');
                sum.push_back(t1 % 10 + '0');
                carry = t1 / 10;
            }
            for (j; j >= 0; j--)
            {
                t1 = carry + (s2[j] - '0');
                sum.push_back(t1 % 10 + '0');
                carry = t1 / 10;
            }
            if (carry)
            {
                sum.push_back(carry + '0');
            }
            reverseStr(sum);
            num = sum;
        }
    }
};
int main()
{
    Number no1, no2, sum;
    no1.get_numb();
    no2.get_numb();
    sum.add_number(no1.num, no2.num);
    cout << "The sum is: \n";
    sum.show_number();

    return 0;
}