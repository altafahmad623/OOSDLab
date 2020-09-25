#include <iostream>
using namespace std;
int main()
{
    int i,n,t=0,j,sum=0;    //i is the counter which checks all the numbers between 2 and n, sum counts these prime numbers
    n=100000000;
    for ( i = 2; i <= n; i++) // the loop to traverse through 2 to n
    {
        for ( j = 2; j*j <= i ; j++)    // This loop checks if there is a factor of the number between 2 and the square root of the number
        {
            if(i%j==0)  // if there is any one divisible then
            {
                t=1;    // it marks variable "t" for counting outside this loop
                break;  // and breaks from this inner loop
            }
        }
        if(t==0)    // So, now if there are no factors of that number t would be zero and the number would be recorded as a prime
        {
            //cout<<i<<" is Prime\n";   //We can also print these numbers
            sum++;  //takes a count of the prime numbers
        }
        t=0;    // this gets updated after checking each number so that it can check properly
    }
    cout<<"The Number of Primes is "<<sum<<endl;    //finally, it outputs the number of primes between 2 and n
    return 0;
}