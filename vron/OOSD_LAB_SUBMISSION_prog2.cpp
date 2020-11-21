/*
Name - Varun Gupta
Roll Number - 18MA20050
Logic - Implemented the required Class and hence the required function to show the working and used in the main function
*/

#include <iostream>  // Including the I/O library
#include <string.h> // Including the string library

using namespace std;  // Using the required namespace for the functions

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

        string multiply(Number one,Number two)       //member function to multiplt the two numbers
        {
            string num1 = one.num;              // taking the values of the classes as numbers
            string num2 = two.num;
            long long int n1 = num1.length();   // gets the length of the respective shorter string
            long long int n2 = num2.length();
            string answer(n1+n2,'0');                 // to store the answer that would have length sum of the previous both lengths
            long long int i;                        //variable for parsing through the length
            long long int j;
            long long int i1 = 0;                       // finding the respective positions
            long long int j1 = 0;
            for(i=n1-1;i>=0;i--)
            {
                long long int carried = 0;
                long long int number1 = num1[i] - '0';

                j1 = 0;
                for(j=n2-1;j>=0;j--)
                {
                    long long int number2 = num2[j] - '0';
                    long long int a = number1*number2 + (answer[i1+j1] - '0') + carried;      //getting individual characters from both and hence multiplying
                    carried = a/10;
                    answer[i+j] = a%10 + '0';         // storing the number
                    j1++;
                }
            }
            return answer;          // returning the answer
        }
};

int main()                              // The main function which contains all the required variables and algorithm
{
    Number num1,num2,num3;              // defining the required variables
    string number1 = "100";
    string number2 = "145";
    num1.get_num(number1);                     // inputting the values
    num2.get_num(number2);
    num3.num = num3.multiply(num1,num2);     // adding the first two numbers and storing in num3

    num1.show_num();                    // using member function to print the number
    num2.show_num();
    num3.show_num();

    return 0;                                   //returning an int as we defined main as an int function
}
