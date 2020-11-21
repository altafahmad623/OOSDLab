#include <iostream>

using namespace std;
//test_cases
//{{1, 6}, {1, 3}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}} -> 4
//{{1, 2}, {2, 3}, {3, 1}, {4, 3}, {4, 1}, {4, 2}} ->4
//{{1, 6}, {1, 3}, {1, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}} -> 5
//{{1, 2}, {1, 3}, {1, 5}, {2, 5}, {3, 6}, {4, 6}} ->3
//{{2, 3}, {2, 4}, {3, 5}, {4, 5}, {4, 6}} ->2
//{1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{4,5}
//{{1,2},{1,3},{1,4},{1,5},{1,6},{2,3},{2,4},{2,5},{2,6},{3,4},{3,5},{3,6},{3,7},{3,8},{3,9},{4,5},{4,6},{5,6},{5,8},{7,8}}
//{{1, 2}, {2, 7}, {6, 7}, {2, 3}, {3, 6}, {3, 7}, {2, 4}, {2, 6}, {4, 5}, {3, 5}}
bool check_color(int* vlist, int elist[][2], int n, int m)
{
    for(int i = 0; i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
           if(elist[j][0] == i+1 && vlist[i] == vlist[elist[j][1]-1])   return false;
           if(elist[j][1] == i+1 && vlist[i] == vlist[elist[j][0]-1])   return false;
        }
    }
    return true;
}

void num_to_graph(int num, int* vlist, int n, int base)
{
    for(int i = 0;i<n;i++)
    {
        vlist[i] = num%base;
        num = num/base;
    }
}

int binpow(int n, int k)
{
    if(k==0)    return 1;
    if(k&1) return n*binpow(n, k-1);
    int x = binpow(n, k/2);
    return x*x;
}
int main()
{
    int n = 6;
    int m = 11;
    int elist[][2] = {{1, 6}, {1, 3}, {1, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};
    int* vlist = new int[n];
    for(int c = 1; c<=n;c++)
    {
        int maxval = binpow(c, n);
        for(int i =0;i<maxval;i++)
        {
            num_to_graph(i, vlist, n, c);
            if(check_color(vlist, elist, n, m))
            {
                cout << "Chromatic number of given graph is : " << c << "\nThe coloring is:\n";
                for(int i =0;i<n;i++)
                    cout << i+1 << ": " << vlist[i]+1 << "\n";
                delete []vlist;
                return 0;
            }
        }
    }
     delete[] vlist;
    return 0;
}