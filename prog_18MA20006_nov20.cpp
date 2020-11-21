#include<iostream>
using namespace std;
bool check(int j, int i){ //Checks whether in a bitmask denoted by i in binary there exists vertex j in the subset.
    int checker = (1<<j);
    return (checker&i);
}
int adj[100][100]; //Adjacencey matrix stored globally
int n,m; //n,m
int globalChromatic[100]; //Stores the final chromatic coloring
int size(int i){ //Returns number of set bits in a binary number
    int sz = 0;
    while(i > 0){
        if(i&1)
            sz++;
        i >>=1;
    }
    return sz;
}
void MaximumClique(int edgeList[100][2]){ //Finds maximum clique of a graph
    int clique[n][n]; //This stores the adjacency matrix of the subgraph that will be maximumclique
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            clique[i][j] = 0; //Initialization of the subgraph
        }
    }
    int upperbound = (1<<n); //Subset iteration, this is the upper bound of the hashing of the subset
    int ansmax = -1;
    int cliquehash; //This will be our final subgraph/subset of graph in bitset form.
    for(int i = 0; i<upperbound; i++){
        bool flag = true;
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                if(check(j,i) && check(k,i) && j != k){ //If BOTH vertices are within subset, but there doesnt exist edge between them this is not a cliq.
                    if(adj[j][k] == 0)
                        flag = false;
                }
            }
        }
        if(flag){ //Updating if the clique is indeed maximum clique or not.
            if(size(i) > ansmax)
                cliquehash = i;
            ansmax = max(ansmax, size(i));

        }
    }
    for(int i = 0; i<n; i++){ //Printing maximum clique vertices.
        for(int j = i+1; j<n; j++){
            if(check(i,cliquehash) && check(j,cliquehash))
                clique[i][j] = 1;
        }
    }
    cout<<"The size of maximum clique is "<<endl;
    cout<<ansmax<<endl;
    cout<<"The vertices of the maximum clique are "<<endl;
    for(int i = 0; i<n; i++){
        if(check(i,cliquehash))
            cout<<i+1<<" ";
    }
    cout<<endl;
}
void VertexCover(int edgeList[100][2]){ //Finds a vertex ccover of the graph.
    int upperbound = (1<<n); //Same as above.
    int ansmax = n+5; //An arbitrary upper bound for the vertex cover. 
    int vertexhash; //This will store the subset of vertex list of its hashed bitset in decimal.
    for(int i = 1; i<upperbound; i++){
        bool flag = true;
        for(int j = 0; j<m; j++){
            if(check(edgeList[j][0],i) || check(edgeList[j][1],i)){} //If there exists an edge with neither of its connecting vertices in the subset, it is not a vertex cover.
            else 
                flag = false;
        }
        if(flag){ //To check if a vertex cover is minimum vertex cover or not.
            if(size(i) < ansmax){
                ansmax = size(i);
                vertexhash = i;
            }
        }
    }
    //Printing the minimum vertex cover:
    cout<<"The size of vertex cover is "<<endl;
    cout<<ansmax<<endl;
    cout<<"The vertices of the cover are "<<endl;
    for(int i = 0; i<n; i++){
        if(check(i,vertexhash))
            cout<<i+1<<" ";
    }
    cout<<endl;
}
bool check(int *split, int edgeList[100][2]){ //It checks if an arbitrary coloring is valid or not.
    for(int i = 0; i<m; i++){
        if(split[edgeList[i][0]] == split[edgeList[i][1]])
            return false;
    }
    return true;
}
void recur(int idx, int k, int edgeList[100][2], bool &flag, int *splitColor){ //It tries all possible colorings given the number of colors we can use recursively
    if(idx == n-1){ //Base case: If we have assigned colors to everyone, just check if this coloring is valid
        for(int i = 1; i<=k; i++){
            splitColor[idx] = i;
            if(check(splitColor, edgeList)){
                for(int j = 0; j<n; j++)
                    globalChromatic[j] = splitColor[j];
                flag = true;
            }
        }
        return;
    } //Otherwise assign a color and then recursively move to the next node to give it some color
    for(int i = 1; i<=k; i++){
        splitColor[idx] = i;
        recur(idx+1,k,edgeList,flag,splitColor);
    }
}
void GraphColoring(int edgeList[100][2]){ //Outputs chromatic number and valid coloring
    int splitColor[n];
    int maximumsize;
    int ChromaticNumber = n;
    for(int colorable = 1; colorable<=n; colorable++){ //Checks all possible chromatic numbers from 1-n. Breaks whenever it finds a valid coloring
        bool flag = false;
        recur(0,colorable, edgeList,flag, splitColor);
        if(flag){//if we found valid coloring, update ChromaticNumber as chromatic number and proceed
            ChromaticNumber = colorable;
            break;
        }
    }
    cout<<"The chromatic number is "<<ChromaticNumber<<endl;
    cout<<"The valid coloring is: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<globalChromatic[i]<<" ";
    }
    cout<<endl;
}

int main(){
     n = 6; //This should be number of vertices (upper bound of number shown in edges + 1)
     m = 11; //This should be number of edgdes
    int edgeList[m][2] = {{1, 6}, {1, 3}, {1, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};
    for(int i = 0; i<m; i++){
        edgeList[i][0]--;
        edgeList[i][1]--; //Converts it to 0 based.
    }
    for(int i = 0; i<m; i++){ //Creates the adjacency matrix.
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    MaximumClique(edgeList);
    VertexCover(edgeList);
    GraphColoring(edgeList);
}