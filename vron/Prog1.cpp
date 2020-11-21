/*
Name - Varun Gupta
Roll Number - 18MA20050
Logic -

*/
#include <iostream>  // Including the I/O library
#include <string.h> // Including the string library
#include <algorithm>

using namespace std;  // Using the required namespace for the functions
                      // We can also use std::cout if we don't particularly use the namespace

class Number                // Defining the required class
{
    public:                 // defining variables in the public domain
        string num;
        void get_num(void)              // member function for getting the large number
        {
            cout << "Enter the number:\n";
            cin >> num;
        }

        void show_num(void)           // member function for showing the respective value of the number
        {
            cout << num << "\n";
        }

        string add(Number one,Number two)       // member function to add the two large numbers
        {
            string num1 = one.num;
            string num2 = two.num;              // storing the numbers as strings from the class
            string tempstring;
            if(num1.length() > num2.length())   // replacing for shorter string for the longer one
            {
                tempstring = num1;
                num1 = num2;
                num2 = tempstring;
            }
            string answer = "";                 //
            long long int n1 = num1.length();
            long long int n2 = num2.length();
            reverse(num1.begin(),num1.end());
            reverse(num2.begin(),num2.end());

            long long int carried = 0;
            for(long long int i=0;i<n1;i++)
            {
                long long int adding = ((num1[i] - '0') + (num2[i] - '0') + carried);
                answer.push_back(adding%10 + '0');

                carried = adding/10;
            }

            for(long long int j = n1;j<n2;j++)
            {
                long long int adding = ((num2[j] - '0') + carried);
                answer.push_back(adding%10 + '0');
                carried = adding/10;
            }
            if(carried)
                answer.push_back(carried + '0');

            reverse(answer.begin(),answer.end());
            return answer;
        }

};

int main()                              // The main function which contains all the required variables and algorithm
{
    Number num1,num2,num3;              // defining the required variables
    num1.get_num();                     // inputting the values
    num2.get_num();
    num3.num = num3.add(num1,num2);     // adding the first two numbers and storing in num3

    num1.show_num();                    // using member function to print the number
    num2.show_num();
    num3.show_num();

    return 0;                                   //returning an int as we defined main as an int function
}

