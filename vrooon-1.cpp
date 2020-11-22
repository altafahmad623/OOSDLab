#include <iostream>
using namespace std;
int new_vertex_tuple[256];
int adjacencyMatrix[256][256];
int store_max_clique[256];
int johny = 0;
class Graph
{
public:
    int maxCliquePrint(int i, int l, int n);
    void CoverVertex(int List_Edges[256][2], int n, int m);
    bool FindChromaticNumber(int *vertexlist, int List_Edges[][2], int n, int m);
};
bool CliqueChecking(int b) 
{
    for (int i = 1; i < b; i++) 
    {
        for (int j = i + 1; j < b; j++)
        {
            if (adjacencyMatrix[new_vertex_tuple[i]][new_vertex_tuple[j]] == 0) 
                return false;
        }
    }
    if (b > johny)
    {
        johny = b;
        for (int i = 1; i < b; i++)
        {
            store_max_clique[i] = new_vertex_tuple[i];
        }
    }
    return true;
}
int Graph::maxCliquePrint(int i, int l, int n)
{
    int cliqueCount = 0;
    for (int j = i + 1; j <= n; j++)
    {
        new_vertex_tuple[l] = j;
        if (CliqueChecking(l + 1))
        {
            cliqueCount = max(cliqueCount, l);
            cliqueCount = max(cliqueCount, maxCliquePrint(j, l + 1, n));
        }
    }
    return cliqueCount;
}

int numbero_uno(int i) 
{
    int size_bin = 0;
    while (i > 0)
    {
        if (i & 1)
            size_bin++;
        i >>= 1;
    }
    return size_bin;
}
bool listCheck(int j, int i) 
{
    int babaYaga = (1 << j);
    return (babaYaga & i);
}
void Graph ::CoverVertex(int List_Edges[256][2], int n, int m)
{
    int tlAwR = (1 << n);
    int httMTCLS = n + 5;
    int wvMM;
    for (int i = 1; i < tlAwR; i++)
    {
        bool tmhCR = true;
        for (int j = 0; j < m; j++)
        {
            if ((listCheck(List_Edges[j][0], i) || listCheck(List_Edges[j][1], i)) != true) 
            {
                tmhCR = false;
            }
        }
        if (tmhCR)
        {
            if (numbero_uno(i) < httMTCLS) // now it checks the cover if it is a minimum cover
            {
                httMTCLS = numbero_uno(i);
                wvMM = i;
            }
        }
    }
    cout << "\nMinimum Vertex Cover of the Graph is : " << httMTCLS << endl;
    cout << "It's vertices are  :" << endl;
    for (int i = 0; i < n; i++)
    {
        if (listCheck(i, wvMM))
            cout << i + 1 << " ";
    }
    cout << "\n";
}
bool Graph::FindChromaticNumber(int *vertexlist, int List_Edges[][2], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (List_Edges[j][0] == i + 1 && vertexlist[i] == vertexlist[List_Edges[j][1] - 1])
                return false;
            if (List_Edges[j][1] == i + 1 && vertexlist[i] == vertexlist[List_Edges[j][0] - 1])
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
int main()
{
    int edge = 17, vertex = 12;
    cout << "The Number of Vertices of Graph is :";
    cout << vertex;
    cout << " and the Number of Edges of Graph :";
    cout << edge;
    int zeroIndexEdges[edge][2];
    int listOfEdges[][2] = {{1, 2}, {2, 3}, {2, 7}, {2, 12}, {2, 4}, {2, 5}, {3, 7}, {3, 12}, {4, 5}, {4, 8}, {4, 9}, {4, 7}, {6, 10}, {6, 11}, {7, 12}, {8, 9}, {11, 12}};
    for (int i = 0; i < edge; i++)
    {
        adjacencyMatrix[listOfEdges[i][0]][listOfEdges[i][1]] = 1; // this creates the adjacencyMatrix matrix of
        adjacencyMatrix[listOfEdges[i][1]][listOfEdges[i][0]] = 1; // the graph and a helper tuple for the cover
        zeroIndexEdges[i][0] = listOfEdges[i][0] - 1;
        zeroIndexEdges[i][1] = listOfEdges[i][1] - 1;
    }
    int *vertexlist = new int[vertex];
    Graph gf;
    int pk = gf.maxCliquePrint(0, 1, vertex);
    cout << "The maximum Clique Size is : " << pk << "\nThe vertex that compose the Clique are as follows: ";
    for (int i = 1; i <= pk; i++)
    {
        cout << store_max_clique[i] << ",";
    }
    gf.CoverVertex(zeroIndexEdges, vertex, edge);
    for (int c = 1; c <= vertex; c++)
    {
        int maxval = power(c, vertex);
        for (int i = 0; i < maxval; i++)
        {
            number_graph(i, vertexlist, vertex, c);
            if (gf.FindChromaticNumber(vertexlist, listOfEdges, vertex, edge))
            {
                cout << "Chromatic Number, : " << c << "\nThe colors of the vertices are:\n";
                for (int i = 0; i < vertex; i++)
                    cout << "Vertex " << i + 1 << " has the color " << vertexlist[i] + 1 << "\n";
                delete[] vertexlist;
                return 0;
            }
        }
    }
    return 0;
}