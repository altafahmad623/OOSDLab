#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli recur(lli n)
{
    if(n==1)
    {
        return 2017;
    }
    else if(n==2)
    {
        return 2018;
    }
    else if(n==3)
    {
        return 2019;
    }
    
    return (recur(1)+ 2*recur(2) + recur(3) - 2* recur(n-1) - recur(n-2));
}
int main()
{
    lli a1 = 2017,a2=2018,a3=2019;
    lli p=a1,q=a2,r=a3,s;
    for (int i= 3; i < 20; i++)
    {
        cout<<recur(i)<<"\n";
    }
    
    
    
}