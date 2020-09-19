#include <iostream>
using namespace std;

int arr_mx(int a[], int n)
{
    int i,t=-999999,jk;
    for(i=0;i<n;i++)
    {
        if(a[i]>=t)
        {
            t= a[i];
            jk = i;
        }
    }
    return jk;
}
int main()
{
    int i,j,k,n,temp,maxind;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    /*
    for(i=n-1;i>0;i--)
    {
        maxind = arr_mx(a,i);
        //cout<<a[maxind]<<endl;
        temp = a[i];
        a[i]= a[maxind];
        a[maxind] = temp;
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    */
   cout<<a[arr_mx(a,n)];
}