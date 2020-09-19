#include <iostream>
using namespace std;

int minimum(int arr[],int i, int n)
{
    int mini=arr[i], index=i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<mini)
        {
            mini=arr[j];
            index=j;
        }
    }
    return index;
}

 

int main() 
{
    int n=10;
    //cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++)
    {
        int index = minimum(arr, i, n);
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}