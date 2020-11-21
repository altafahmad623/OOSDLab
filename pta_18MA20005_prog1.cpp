/*
Name: Altaf Ahmad ; Roll no : 18MA20005

This is an implementation of the Ear-Clipping Method for Polygon Triangulation. The worst case run time is O(n^2).

Explanation:
An ear of a polygon is a triangle formed by three consecutive vertices Vi0,Vi1, and Vi2 for which Vi1 is a convex vertex 
(the interior angle at the vertex is smaller than π radians or 180 degrees), 
the line segment from Vi0 to Vi2 lies completely inside the polygon, and no vertices of the polygon are contained in the triangle 
other thanthe three vertices of the triangle. 
The  first  step  is  to store the polygon as a doubly linked list so that you can quickly remove ear tips.  Construction of this list is an O(n) process. 
The second step is to iterate over the vertices and find the ears. For each vertex V_i
and corresponding triangle h V_i−1 , V_i , V_i+1 i (indexing is modulo n, so V_n = V_0 and V_−1 = V_n−1 ), test
all other vertices to see if any are inside the triangle. If none are inside, you have an ear. If at least one
is inside, you do not have an ear. The actual implementation I provide tries to make this somewhat more
efficient. It is sufficient to consider only reflex vertices in the triangle containment test. A reflex vertex is one
for which the interior angle formed by the two edges sharing it is larger than 180 degrees. A convex vertex
is one for which the interior angle is smaller than 180 degrees. The data structure for the polygon maintains
four doubly linked lists simultaneously, using an array for storage rather than dynamically allocating and
deallocating memory in a standard list data structure. The vertices of the polygon are stored in a cyclical
list, the convex vertices are stored in a linear list, the reflex vertices are stored in a linear list, and the ear
tips are stored in a cyclical list.
Once the initial lists for reflex vertices and ears are constructed, the ears are removed one at a time. If V_i is
an ear that is removed, then the edge configuration at the adjacent vertices V_i−1 and V_i+1 can change. If
an adjacent vertex is convex, a quick sketch will convince you that it remains convex. If an adjacent vertex
is an ear, it does not necessarily remain an ear after V_i is removed. If the adjacent vertex is reflex, it is
possible that it becomes convex and, possibly, an ear. Thus, after the removal of V_i , if an adjacent vertex
is convex you must test if it is an ear by iterating over over the reflex vertices and testing for containment
in the triangle of that vertex. There are O(n) ears. Each update of an adjacent vertex involves an earness
test, a process that is O(n) per update. Thus, the total removal process is O(n^2).

*/
#include <iostream>
#include <graphics.h> // this is for the graphical visualization, if you don't want this, then comment out this part and the drawPolygon function and wherever it is used
//and run using g++ pta_18MA20005_prog1.cpp -lgraph
using namespace std;
struct Link // a doubly linked list structure that helps in storing current polygon
{
    int data;
    struct Link *next, *prev;
};
struct Link *head = NULL;
void insertList(int new_data) //function that adds data to the end of the linked list. This creates a queue type of structure that helps us in printing the tree
{
    struct Link *new_node = (struct Link *)malloc(sizeof(struct Link));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) // if the list is empty it adds the first element to the list
    {
        new_node->data = new_data;
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
    }
    else // if the list is not empty, then
    {
        if (head->next == NULL)
        {
            Link *temp = new Link;
            temp = head;
            temp->prev = new_node;
            temp->next = new_node;
            new_node->next = head;
            new_node->prev = head;
        }
        else
        {
            Link *temp = new Link;
            temp = head;
            new_node->next = head;
            new_node->prev = head->prev;
            temp->prev->next = new_node;
            head->prev = new_node;
        }
    }
}
void deleteList(int datapt) // function to clip or delete the edges of a polygon
{
    Link *temp = new Link;
    temp = head;
    int i = 0;
    while (temp->data != datapt)
    {
        if ((i++) > 100)
        {
            //cout<<"You have entered a wrong number\n";
            break;
        }
        temp = temp->next;
    }
    if (temp->data == datapt)
    {
        //cout<<"Link is deleted\n";
        //delete this node;
        Link *pre, *nex;
        pre = temp->prev;
        nex = temp->next;
        pre->next = nex;
        nex->prev = pre;
    }
}
void drawPolygon(double ar[][2], int tr[][2], int n) // graphical visualization of the triangulation of the polygon using graphics.h library
{
    int i, j;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    for (i = 0; i < (n - 1); i++) // here, the axes are mirrored over the X axis. So, the polygon visualized will also be a mirrored version
    {
        setcolor(5);
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
double angle_degree(double x1, double y1, double x2, double y2, double x3, double y3) // calculates the angle between the three points. This is one of the tests for ear checking
{
    double r8_pi = 3.141592653589793;
    double value;
    double x;
    double y;
    x = (x3 - x2) * (x1 - x2) + (y3 - y2) * (y1 - y2);
    y = (x3 - x2) * (y1 - y2) - (y3 - y2) * (x1 - x2);
    if (x == 0.0 && y == 0.0)
    {
        value = 0.0;
    }
    else
    {
        value = atan2(y, x);
        if (value < 0.0)
        {
            value = value + 2.0 * r8_pi;
        }
        value = 180.0 * value / r8_pi;
    }
    return value;
}
double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool isInside(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) //this checks whether point P(x, y) lies inside the triangle formed by A(x1, y1), B(x2, y2) and C(x3, y3)
{
    double A = area(x1, y1, x2, y2, x3, y3);/* Calculate area of triangle ABC */
    double A1 = area(x, y, x2, y2, x3, y3);/* Calculate area of triangle PBC */
    double A2 = area(x1, y1, x, y, x3, y3);/* Calculate area of triangle PAC */
    double A3 = area(x1, y1, x2, y2, x, y);/* Calculate area of triangle PAB */
    if (A < (A1 + A2 + A3))/* Check if sum of A1, A2 and A3 is same as A */
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool check_ear(Link *ptr_pre, Link *ptr, Link *ptr_next, double ar[][2]) // this is the final check to determine whether a given set of three nodes form an ear or not
{
    double angle = angle_degree(ar[ptr_pre->data][0], ar[ptr_pre->data][1], ar[ptr->data][0], ar[ptr->data][1], ar[ptr_next->data][0], ar[ptr_next->data][1]);
    //cout<<" \nthe angle is"<<angle<<" ";
    if (angle < 180.0)
    {
        bool k;
        Link *temp = ptr_next->next;
        while (temp->data != ptr_pre->data)
        {

            k = isInside(ar[ptr_pre->data][0], ar[ptr_pre->data][1], ar[ptr->data][0], ar[ptr->data][1], ar[ptr_next->data][0], ar[ptr_next->data][1], ar[temp->data][0], ar[temp->data][1]);
            if (k)
            {
                //cout << "This :a[" << temp->data << "] " << ar[temp->data][0] << " " << ar[temp->data][1] << "is between :a[" << ptr_pre->data << "] =  " << ar[ptr_pre->data][0] << " " << ar[ptr_pre->data][1] << " , a[" << ptr->data << "] =" << ar[ptr->data][0] << " " << ar[ptr->data][1] << " ,a[" << ptr_next->data << "] =" << ar[ptr_next->data][0] << " " << ar[ptr_next->data][1] << "\n";
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
    else
    {
        return false;
    }
}
void triangulation(double ar[][2], int n) // this is where the ear clipping method is executed
{
    Link *ptr_pre, *ptr_nex, *ptr;
    ptr = head;
    ptr_pre = head->prev;
    ptr_nex = head->next;
    int sz_tri = 0;
    int tr[n - 3][2];
    int i = 0;
    cout << "The Triangles formed can be denoted by the edges which are connected. This output array is the result where each column represents an edge of the triangulation:\n";
    while (sz_tri < (n - 3)) // goes on until the required length of the output array is achieved
    {
        if (i++ > 100) // security check for checking infinite loops
        {
            break;
        }
        if (check_ear(ptr_pre, ptr, ptr_nex, ar)) // if the ear is detected then this happens
        {
            cout << ptr_pre->data << " " << ptr_nex->data << "\n";
            tr[sz_tri][0] = ptr_pre->data; // the value is added in the given array
            tr[sz_tri][1] = ptr_nex->data;
            Link *temp;
            temp = ptr;
            ptr = ptr->next;
            ptr_nex = ptr->next;
            deleteList(temp->data); // and that node is deleted
            sz_tri++;
        }
        else // it moves on to check the next set of nodes
        {
            ptr_pre = ptr;
            ptr = ptr_nex;
            ptr_nex = ptr_nex->next;
        }
    }
    drawPolygon(ar, tr, n);
}

double areaTrap(double x1, double y1, double x2, double y2) // this is a helper for calculating the area of the Polygon
{
    double h = x1 - x2;
    double area = (h * (y1 + y2)) / 2.0;
    return area;
}
double areaPoly(double ar[][2], int n) // area of the polygon needs to be calculated to make it Anti - clockwise. If it remains clockwise, then, area would be negative else it will be positive
{
    double area = 0;
    for (int i = 0; i < n; i++)
    {
        area += areaTrap(ar[i][0], ar[i][1], ar[(i + 1) % n][0], ar[(i + 1) % n][1]);
    }
    return area;
}
void PolyTrian(int n)
{
    double ar[n][2];
    int tr[n - 3][2]; // this is the final array where each column represents an edge of the triangulation
    cout << "Enter the coordinates of the polygon one by one and by adjacent sides: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i][0] >> ar[i][1];
        insertList(i);
    }
    double a[n][2];
    
    if (areaPoly(ar, n) > 0)
    {

        //everything is fine and we can use ar itself
        for (int i = 0; i < n; i++)
        {
            a[i][0] = ar[i][0];
            a[i][1] = ar[i][1];
        }
    }
    else
    {
        /* We have to reverse the polygon as it has to be entered in an anticlockwise way*/
        for (int i = 0; i < n; i++)
        {
            a[i][0] = ar[(n - i) % n][0];
            a[i][1] = ar[(n - i) % n][1];
        }
    }
    Link *ptr;
    ptr = head; //cout << ptr->data << " ";
    cout << "Area of the given Polygon is :" << areaPoly(a, n) << "\n";
    int i = n;
    cout << "Here, we have denoted the edges by the numbers given as:\n";
    while (i > 0)
    {
        i--;
        cout << ptr->data << " has the coordinates, (" << a[ptr->data][0] << " , " << a[ptr->data][1] << ")\n"; // the values of the linked list are stored in the array for better call
        ptr = ptr->next;
    }
    triangulation(a, n);
}
int main()
{
    int n;
    cout << "Enter the Number of Edges of the polygon: ";
    cin >> n;
    PolyTrian(n);
    return 0;
}
