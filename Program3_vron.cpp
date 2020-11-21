/*
Name - Varun Gupta
Roll Number - 18MA20050
Logic - The main logic used is that we input from a text file and continuosly check if any characters are present and hence remove them and hence output only the numbers ,commas and spaces
*/

#include <iostream>     // Including the I/O library
#include <fstream>     // Library to take input from files and file funstion

using namespace std;  // Using the required namespace for the functions
                      // We can also use std::cout if we don't particularly use the namespace

int main()                                              // defining the main function where the program starts
{
    const int MAX = 100000;         // size of buffer
    char buffer;           // character buffer
    ifstream infile("input.txt");   // create file for input
    int minimum;
    while(!infile.eof())            // until end of file
    {
        infile.getline(buffer);    // read a line of text
        ofstream outfile("output.txt");     // giving an output file
        int min=0;                          // finding the length of the buffer if lesse than the input MAX then only would loop till that point
        while(buffer[min]!='\n')            // checking the buffer characters for end of line character
            min++;
        if(min<MAX)
            minimum = min;                  // minimum of both
        else
            minimum = MAX;
        for(int i=0;i<100000;i++)                                                  // the loop through the input buffer

        {
            if((buffer[i]>= 'a' && buffer[i] <='z') || (buffer[i]>= 'A' && buffer[i] <='Z'))        // condition when there is a character present then we skip the character
                continue;                                                                           // if alphabet is present then move to next character
            else if((buffer[i]>= '0' && buffer[i] <='9') || (buffer[i] == '.'))                     // if number or decimal present then we give it out to the output file
                        outfile << buffer[i];                                           // writing to the output file
            else if(buffer[i] == ',')                                                               // if comma is there then we assume a number ends and another would start after that and hence would give a comma and a space to give a proper format for output file
                        outfile << ", ";            // writing to the output file
        }
        outfile.close();                    // closing the output file
    }
    infile.close();                 // closing the file
    // cout << minimum << "\n";
    return 0;                       // end of main program
}
