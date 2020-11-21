#include <iostream>
#include <graphics.h> // this is for the graphical visualization, if you don't want this, then comment out this part and the drawPolygon function and wherever it is used
using namespace std;
void drawPolygon(double ar[][2], int tr[][2], int n) // graphical visualization of the triangulation of the polygon using graphics.h library
{
    int i, j;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    for (i = 0; i < (n - 1); i++) // here, the axes are mirrored over the X axis. So, the polygon visualized will also be a mirrored version
    {
        setcolor(1);
        line(50 * ar[i][0] + 10, 50 * ar[i][1] + 10, 50 * ar[i + 1][0] + 10, 50 * ar[i + 1][1] + 10);
    }
    line(50 * ar[i][0] + 10, 50 * ar[i][1] + 10, 50 * ar[0][0] + 10, 50 * ar[0][1] + 10);
    setcolor(2);
    for (i = 0; i < n - 3; i++)
    {
        line(50 * ar[tr[i][0]][0] + 10, 50 * ar[tr[i][0]][1] + 10, 50 * ar[tr[i][1]][0] + 10, 50 * ar[tr[i][1]][1] + 10);
    }
    getch(); // also, if the points get out of the boundary, for eg if it is negative or some very large value, then it cannot visualise it properly
    closegraph();
}
int main()
{
    int n;
    cin >> n;
    double ar[n][2];
    int tr[n - 3][2];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i][0] >> ar[i][1];
    }
    for (int i = 0; i < n-3; i++)
    {
        //cout<<"cok";
        cin>>tr[i][0]>>tr[i][1];
    }
    drawPolygon(ar,tr,n) ;  
    }
