#include<iostream>
using namespace std;
#define lli long long
void printOrder(long long ar[], int n, int kj)
{
    int i;
    if(n==0)
    {
        for(i=0;i<kj;i++)
        {
            cout<<ar[i]<<"+";
        }
        cout<<endl;
        return;
    }

    for(i=1;i<=n;i++)
    {
        ar[kj]=i;
        printOrder(ar, n-i, kj+1);
    }
}

int main()
{
    lli n;
    cin>>n;
    lli ar[n+1];
    printOrder(ar, n, 0);
}
