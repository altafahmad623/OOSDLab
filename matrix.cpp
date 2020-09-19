#include <iostream>
using namespace std;
int main()
{
    int i,j,a[3][3],b[3][3],sum[3][3],prod[3][3],k,s=0;
    for ( i = 0; i <3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"\n";
    for ( i = 0; i <3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            cin>>b[i][j];
            sum[i][j]= a[i][j] + b[i][j];
        }
        
    }
    for ( i = 0; i <3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            //find out prod[i][j] 
            s=0;
            for(k=0;k<3;k++)
            {
                s=s+a[i][k]*b[k][j];
            }
            prod[i][j] =s ;
        }
        
    }
    cout<<"\nSum is\n";
    for ( i = 0; i <3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            cout<<sum[i][j]<<" ";

        }
        cout<<"\n";
    }
    cout<<"\nProduct is\n";
    for ( i = 0; i <3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            cout<<prod[i][j]<<" ";

        }
        cout<<"\n";
    }
    
}