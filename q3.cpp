#include<iostream>
using namespace std;

void printArr(int p[], int m) 
{
   for (int i = 0; i < m; i++)
   {
      cout << p[i] ;
      if(i!=(m-1))
      {
           cout<<"+"; 
      }
   }
   cout << endl;
}
void orderedPartition(int m) 
{
   int p[m];
   int k = 0;
   p[k] = m;
   while (1) 
   {
      printArr(p, k + 1);
      int rem_val = 0;
      while (k >= 0 && p[k] == 1) {
         rem_val += p[k];
         k--;
      }
      if (k < 0)
         return;
         p[k]--;
         rem_val++;
      while (rem_val > p[k]) {
         p[k + 1] = p[k];
         rem_val = rem_val - p[k];
         k++;
      }
      p[k + 1] = rem_val;
      k++;
   }
}
int main() 
{
   int x;
   cin>>x;
   orderedPartition(x);
   return 0;
}
