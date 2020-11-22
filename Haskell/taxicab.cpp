#include<bits/stdc++.h>
using namespace std;

void printTaxicab2(int N)
{
    // Starting from 1, check every number if
    // it is Taxicab until count reaches N.
    int i = 1, count = 0;
    while (count < N) 
    {
    int int_count = 0;

    // Try all possible pairs (j, k) whose cube 
    // sums can be i.
    for (int j = 1; j <= pow(i, 1.0/3); j++) 
        for (int k = j + 1; k <= pow(i, 1.0/3); k++) 
            if (j*j*j + k*k*k == i)
                int_count++;

    // Taxicab(2) found
    if (int_count == 2) 
    {
        count++;
        cout << count << " " << i << endl; 
    }

    i++;
    }
}

// Driver code
int main() 
{
    int N = 10;
    printTaxicab2(N);

    return 0;
}