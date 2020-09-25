/*
Name - Varun Gupta
Roll Number - 18MA20050
Logic - Implemented the required Class and hence the required function to show the working and used in the main function
*/

#include <iostream>  // Including the I/O library
#include <string.h> // Including the string library
#include <algorithm> // using for reversing the strings

using namespace std;  // Using the required namespace for the functions

void reversing(string& str)         // function to reverse the string
{
    long long int n = str.length();
    char temp;
    for (long long int i = 0; i < n / 2; i++)
    {
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

class Number            // defining the required class
{
    public:             // defining the public domain which contains all the methods and attributes
        string num;     // the num attribute to store the value
        void get_num(string number)     // member function to store the number
        {
            num = number;
        }

        void show_num(void)             // member function to print the number
        {
            cout << num << "\n";
        }

        Number operator + (Number const &obj)       //member function to add the two numbers
        {
            Number output;                      // outputs the class answer
            string num1 = one.num;              // taking the values of the classes as numbers
            string num2 = two.num;
            string tempstring;                  // storing the temporary string
            if(num1.length() > num2.length())   // swaping the string for the longer and shorted one
            {
                tempstring = num1;
                num1 = num2;
                num2 = tempstring;
            }
            string answer = "";                 // to store the answer
            long long int n1 = num1.length();   // gets the length of the respective shorter string
            long long int n2 = num2.length();
            reversing(num1);   // reversing the string as we are using a simple logic of addition from last digit
            reversing(num2);

            long long int carried = 0;          // always storing the carry part from previous additions
            for(long long int i=0;i<n1;i++)     // adding from the last digit respectively
            {
                long long int adding = ((num1[i] - '0') + (num2[i] - '0') + carried);
                answer.push_back(adding%10 + '0');      // storing the sum of last digits and we are '0' as that is the base

                carried = adding/10;    //storing the carry
            }

            for(long long int j = n1;j<n2;j++)      // adding the rest numbers of the longer numeral
            {
                long long int adding = ((num2[j] - '0') + carried);
                answer.push_back(adding%10 + '0');
                carried = adding/10;
            }
            if(carried)                                 // if carried is left then adding that resepctively
                answer.push_back(carried + '0');

            reversing(answer);       // reversing the number as we were adding from behind
            output.num = answer;
            return output;                              // returning the resepctive answer
        }
};

int main()                              // The main function which contains all the required variables and algorithm
{
    Number num1,num2,num3;              // defining the required variables
    string number1 = "100";
    string number2 = "145";
    num1.get_num(number1);                     // inputting the values
    num2.get_num(number2);
    num3 = num1 + num2;     // adding the first two numbers and storing in num3

    num1.show_num();                    // using member function to print the number
    num2.show_num();
    num3.show_num();

    return 0;                                   //returning an int as we defined main as an int function
}
