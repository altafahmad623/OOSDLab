#include <iostream>
using namespace std;
#define lli long long

int main()
{
    lli i,n,t=0,jk;
    cin>>n;
    lli a[n];
    for ( i = 0; i <= n; i++)
    {
        cin>>a[i];
        if(a[i]>=t)
        {
            t= a[i];
            jk = i;
        }
    }
    cout << "largest no is "<< t<<endl;
    return 0;
}