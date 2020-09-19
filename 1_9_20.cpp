#include <iostream>
using namespace std;
#define lli long long
bool isNoPrime(lli n)
{
    lli t=0,i;
    for ( i = 2; i*i <= n ; i++)
    {
        if(n%i==0)
        {
            t++;
            break;
        }
    }
    if(t)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    lli i,n,t=0;
    cin>>n;
    for ( i = 2; i <= n; i++)
    {
        if (isNoPrime(i))
        {
            cout<<i<<" is Prime\n";
        }
        
    }
    
    return 0;
}