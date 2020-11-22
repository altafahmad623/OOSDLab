/*
Name : Altaf Ahmad
Roll no: 18MA20005
*/
#include <iostream>
using namespace std;
int store[100];
int adjacency[100][100];
int list[100];
int maxx = 0;
bool check_if_clique(int b) // Function to check if the given set of vertices in store array is a clique or not
{
    for (int i = 1; i < b; i++) // Run a loop for all set of edges
    {
        for (int j = i + 1; j < b; j++)
        {
            if (adjacency[store[i]][store[j]] == 0) // If any edge is missing
                return false;
        }
    }
    if (b > maxx)
    {
        maxx = b;
        for (int i = 1; i < b; i++)
        {
            list[i] = store[i];
        }
    }
    for (int i = 1; i < b; i++)
    {
        cout << store[i] << " ";
    }
    cout << "\n";
    return true;
}
int outPutMaximumClique(int i, int l, int n) // Function to find all the sizes of maximal cliques
{
    int maximumUpToNow = 0;
    for (int j = i + 1; j <= n; j++) // Check if any vertices from i+1 can be inserted
    {
        store[l] = j;               // Add the vertex to store
        if (check_if_clique(l + 1)) // If the graph is not a clique of size k then it cannot be a clique by adding another edge
        {
            maximumUpToNow = max(maximumUpToNow, l);

            maximumUpToNow = max(maximumUpToNow, outPutMaximumClique(j, l + 1, n)); // Check if another edge can be added
        }
    }
    return maximumUpToNow;
}
int numbin(int i) // finds the number of sets of bits in binary
{ 
    int sz = 0;
    while (i > 0)
    {
        if (i & 1)
            sz++;
        i >>= 1;
    }
    return sz;
}
bool check_bitmask(int j, int i) //checks whether there exists a vertex j in the subset of the bitmask i
{
    int checker = (1 << j);
    return (checker & i);
}
void Min_Vertex_Cover(int edgeList[100][2], int n, int m) // finds the the size of the minimum vertex cover of the graph and outputs a minimum vertex cover
{
    int maxvalue = (1 << n);
    int max_possible_ans = n + 5;
    int vertexKey;
    for (int i = 1; i < maxvalue; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (check_bitmask(edgeList[j][0], i) || check_bitmask(edgeList[j][1], i)) // checks if a vertex is a cover
            {
            } 
            else
                flag = false;
        }
        if (flag)
        { 
            if (numbin(i) < max_possible_ans) // now it checks the cover if it is a minimum cover
            {
                max_possible_ans = numbin(i);
                vertexKey = i;
            }
        }
    }
    cout << "\nSize of Minimum Vertex Cover : " << max_possible_ans << endl;
    cout << "The vertices of the cover are :" << endl;
    for (int i = 0; i < n; i++)
    {
        if (check_bitmask(i, vertexKey))
            cout << i + 1 << " ";
    }
    cout << endl;
}

bool chromatic(int *vertexlist, int edgelist[][2], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (edgelist[j][0] == i + 1 && vertexlist[i] == vertexlist[edgelist[j][1] - 1])
                return false;
            if (edgelist[j][1] == i + 1 && vertexlist[i] == vertexlist[edgelist[j][0] - 1])
                return false;
        }
    }
    return true;
}
void number_graph(int num, int *vertexlist, int n, int base)
{
    for (int i = 0; i < n; i++)
    {
        vertexlist[i] = num % base;
        num = num / base;
    }
}

int power(int n, int k)
{
    if (k == 0)
        return 1;
    if (k & 1)
        return n * power(n, k - 1);
    int x = power(n, k / 2);
    return x * x;
}
//{1,2},{2,3},{3,4},{3,5},{5,6},{6,7}
//{{1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}, {3, 7}, {3, 8}, {3, 9}, {4, 5}, {4, 6}, {5, 6}, {5, 8}, {7, 8}}
int main()
{
    int edges[][2] = {{1,2},{2,3},{3,4},{3,5},{5,6},{6,7}};
    int size = sizeof(edges) / sizeof(edges[0]); // this is the number of edges
    int n = 9;                                   // this is the number of vertices
    int edgeLeftShift[size][2];
    for (int i = 0; i < size; i++) // this creates the adjacency matrix of the graph and a helper tuple for the cover 
    {
        adjacency[edges[i][0]][edges[i][1]] = 1;
        adjacency[edges[i][1]][edges[i][0]] = 1;
        edgeLeftShift[i][0] = edges[i][0] - 1;
        edgeLeftShift[i][1] = edges[i][1] - 1;
    }
    cout << "The adjacency Matrix is: \n";
    for (int i = 1; i <= n; i++)
    {
        adjacency[i][i] = 1;
        for (int j = 1; j <= n; j++)
        {
            cout << adjacency[i][j] << " ";
        }
        cout << "\n";
    }
    int *vertexlist = new int[n];
    cout << "All the cliques formed are : \n";
    int pk = outPutMaximumClique(0, 1, n);
    cout << "So, we can see that the maximum size of Clique is : " << pk << "\nand the vertices of the Maximum Clique is : ";
    for (int i = 1; i <= pk; i++)
    {
        cout << list[i] << " ";
    }
    Min_Vertex_Cover(edgeLeftShift, n, size);
    for (int c = 1; c <= n; c++)
    {
        int maxval = power(c, n);
        for (int i = 0; i < maxval; i++)
        {
            number_graph(i, vertexlist, n, c);
            if (chromatic(vertexlist, edges, n, size))
            {
                cout << "The Chromatic number of the graph is : " << c << "\nThe colors of the vertices are:\n";
                for (int i = 0; i < n; i++)
                    cout << "Vertex " << i + 1 << " has the color " << vertexlist[i] + 1 << "\n";
                delete[] vertexlist;
                return 0;
            }
        }
    }
    delete[] vertexlist;
    return 0;
}