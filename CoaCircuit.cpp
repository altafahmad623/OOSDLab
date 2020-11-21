#include <bits/stdc++.h>
#define lli long long int
#include <string.h>
using namespace std;
int S1(int a, int b, int c, int d, int e, int f, int n)
{
    switch (n)
    {
    case 0:
        return a;
        break;
    case 1:
        return b;
        break;
    case 2:
        return c;
        break;
    case 3:
        return d;
        break;
    case 4:
        return e;
        break;
    case 5:
        return f;
        break;

    default:
        return 0;
        break;
    }
}
int S12(int a[],int u)
{
    return a[u];
}
string decod(int a, int n)
{
    string s;
    for (int i = 0; i < n; i++)
    {
        s.append("0");
    }
    s.append("10000000");

    return s;
}
int S(int x, int y, int z)
{
    if (z)
    {
        return y;
    }
    else
    {
        return x;
    }
}
int main()
{
    int a = 47, z = 1, p, b = 84, q, c = 29, r, d = 56, s, y = 1;
    int m = S1(a,b,c,d,1,1,z);
    int n = S1(7*c,a+d,d-a,b-c,1,1,z);
    int k = S(m,n,1);
    cout<<"Initially,\na = "<<a<<"\n";
    cout<<"b = "<<b<<"\n";
    cout<<"c = "<<c<<"\n";
    cout<<"d = "<<d<<"\n\nNow,\n";
    string str;
    str = decod(1, y);
    p = str[0] - '0';
    q = str[1] - '0';
    r = str[2] - '0';
    s = str[3] - '0';
    a=S(a,k,p)  ;
    b=S(b,k,q)  ;
    c=S(c,k,r)  ;
    d=S(d,k,s)   ;
    cout<<"a = "<<a<<"\n";
    cout<<"b = "<<b<<"\n";
    cout<<"c = "<<c<<"\n";
    cout<<"d = "<<d<<"\n";
}