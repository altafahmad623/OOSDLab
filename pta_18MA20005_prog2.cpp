/*
Name: Altaf Ahmad ; Roll no : 18MA20005
This is an implementation of the Plane-Sweep Monotone Transformation for Polygon Triangulation. The worst case run time is O(n logn ). 
The entire implementation is not complete yet. It identitfies the split and merge vertices now and tries to convert into monotone polygons

Our approach is based on a two-step process (although
with a little cleverness, both steps could be combined into one algorithm).
 First, the simple polygon is decomposed into a collection of simpler polygons, called
monotone polygons. This step takes O(n log n) time.  - this is almost complete for our case
 Second, each of the monotone polygons is triangulated separately, and the result are
combined. This step takes O(n) time. - this step has not been implemented yet
A polygonal curve C is monotone with respect to ` if each line that is orthogonal to ` intersects
C in a single connected component. (It may intersect, not at all, at a single point, or along
a single line segment.) A polygonal curve C is said to be strictly monotone with respect to
a given line `, if any line that is orthogonal to ` intersects C in at most one point.
We begin with the assumption that the vertices of the polygon have been sorted in increasing , which will be done by us later one=
order of their y-coordinates. (For simplicity we assume no duplicate x-coordinates. Otherwise,
break ties between the upper and lower chains arbitrarily, and within a chain break ties so
that the chain order is preserved.) We can simply extract the upper and lower chain, and merge them (as done in MergeSort) in O(n)
In order to run the above triangulation algorithm, we rst need to
subdivide an arbitrary simple polygon P into monotone polygons. This is also done by a plane-sweep approach.
Based on certain properties, we subdivide the vertices into 4 classes if they are special :
• Start Vertex - its two neighbors lie below it
and the interior angle < 180°
• End Vertex - its two neighbors lie above it and
the interior angle < 180°
• Split Vertex - its two neighbors lie below it and
the interior angle > 180°
• Merge Vertex - its two neighbors lie above it
and the interior angle > 180°
we need to maintain a vertex that is visible to any split
vertex that may arise between ea and eb. To do this, imagine a sweeping a vertical segment
between ea and eb to the left until it hits a vertex. Called this helper(ea) - Another way to visualize the helper is to imagine sweeping out a trapezoid to the left from
the sweep line. The top side of the trapezoid lies on ea, the bottom side lies on eb, the right
side lies on the sweep line, and the left side is sweeps as far as it can until hitting a vertex
helper(ea) is dened with respect to the current location of the sweep line. As
the sweep line moves, its value changes. The helper is dened only for those edges intersected
by the sweep line. Our approach will be to join each split vertex to helper(ea), where ea is
the edge of P immediately above the split vertex. (
whenever we see a split vertex, we add a diagonal to the helper of
the edge immediately above it. We defer adding diagonals to merge vertices until the
next opportunity arises.
Similarly, we can do the same for merge vertices i.e, attach them to the nearest helper function. 
In this way, our monotone polygon will be generated
Now, we have to triangulize a particular monotone polygon. This can be done in O(n) time using our 
hypothesis. 
We dene a reflex vertex to be a vertex of the polygon whose interior angle is at least pi, and
otherwise the vertex is nonreflex. We dene a reflex chain to be a sequence of one or more
consecutive reflex vertices along the polygon's boundary.
The idea behind the triangulation algorithm is quite simple: Try to triangulate everything you
can to the left of the current vertex by adding diagonals, and then remove the triangulated
region from further consideration. The trickiest aspect of implementing this idea is nding a
clean invariant that characterizes the untriangulated region that lies to the left of the sweep
line. Ideally, this structure will be simple enough to allow us to determine in
constant time whether it is possible to add another diagonal. And in general we can add each
additional diagonal in constant time. Since any triangulation consists of n􀀀3 diagonals, the
process runs in O(n) total time.
*/
#include <iostream>
#include <graphics.h> // this is for the graphical visualization, if you don't want this, then comment out this part and the drawPolygon function and wherever it is used
using namespace std;
struct Link // a doubly linked list structure that helps in storing current polygon
{
    int data;
    struct Link *next, *prev;
};
struct Link *head = NULL;
struct Side
{
    int val;
    double x, y;
    int type; // 0 for start, 1 for merge , 2 for split and 3 for end and 5 for not any
};
void merge(Side arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    Side L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].y <= R[j].y)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(Side arr[], int l, int r)
{
    if (l < r)
    {

        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void mergex(Side arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    Side L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].x <= R[j].x)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSortx(Side arr[], int l, int r)
{
    if (l < r)
    {

        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSortx(arr, l, m);
        mergeSortx(arr, m + 1, r);

        mergex(arr, l, m, r);
    }
}
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
bool pntSameSide(double a, double b, double c, double x1, double y1)
{
    double fx1 = a * x1 + b * y1 + c;
    if (fx1 * c > 0.0)
    {
        return true;
    }

    return false;
}
bool isVisible(Side ar[], int start, int end)
{
    double a, b, c;
    a = ar[end].y - ar[start].y;
    b = ar[start].x - ar[end].x;
    c = ar[start].y * ar[end].x - ar[end].y * ar[start].x;
    bool am = pntSameSide(a,b,c,ar[start+1].x,ar[start+1].y);
    for (int i = start + 2; i < end; i++)// if all are on the same side of the line
    {
        if(pntSameSide(a,b,c,ar[i].x,ar[i].y) != am)
        {
            return false;
        }
    }
    for (int i = start + 1; i < end; i++) // if the values are between start and end, i.e., no extra edge is there from the opposite side
    {
        if(ar[i].val<ar[start].val || ar[i].val>ar[end].val )
        {
            return false;
        }
    }
    

    return true;
}
void drawPolygon(double ar[][2], int tr[][2], int n, int trcnt) // graphical visualization of the triangulation of the polygon using graphics.h library void drawPolygon(double ar[][2], int tr[][2], int n)
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

    for (i = 0; i < trcnt; i++)
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
double areaTrap(double x1, double y1, double x2, double y2)
{
    double h = x1 - x2;
    double area = (h * (y1 + y2)) / 2.0;
    return area;
}
double areaPoly(double ar[][2], int n)
{
    double area = 0;
    for (int i = 0; i < n; i++)
    {
        area += areaTrap(ar[i][0], ar[i][1], ar[(i + 1) % n][0], ar[(i + 1) % n][1]);
    }
    return area;
}

int main()
{
    int n;
    cout << "Enter the Number of Edges of the polygon: ";
    cin >> n;
    Side sd[n], sdx[n];
    double ar[n][2];
    int tr[n - 3][2], trcnt = 0,isdx[n],isd[n];
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
            sd[i].val = i;
            sd[i].x = ar[i][0];
            sd[i].y = ar[i][1];
            sd[i].type = 5;
            sdx[i].val = i;
            sdx[i].x = ar[i][0];
            sdx[i].y = ar[i][1];
            sdx[i].type = 5;
        }
    }
    else
    {
        //cout<<"Red alert";
        /* We have to reverse the polygon as it has been entered in an anticlockwise way*/
        for (int i = 0; i < n; i++)
        {
            a[i][0] = ar[(n - i) % n][0];
            a[i][1] = ar[(n - i) % n][1];
            sd[i].val = i;
            sd[i].x = a[i][0];
            sd[i].y = a[i][1];
            sd[i].type = 5;
            sdx[i].val = i;
            sdx[i].x = ar[i][0];
            sdx[i].y = ar[i][1];
            sdx[i].type = 5;
        }
    }
cout << "Area of the given Polygon is :" << areaPoly(a, n) << "\n";
    for (int i = 0; i < n; i++)
    {
        Side prev, next;
        if (i == 0)
        {
            prev = sd[n - 1];
            next = sd[1];
        }
        else if (i == n - 1)
        {
            prev = sd[i - 1];
            next = sd[0];
        }
        else
        {
            prev = sd[i - 1];
            next = sd[i + 1];
        }
        double angl = angle_degree(prev.x, prev.y, sd[i].x, sd[i].y, next.x, next.y);
        if (angl > 180.0)
        {
            //Split Vertex - its two neighbors lie below it and the interior angle > 180°  -  2
            if (sd[i].y > prev.y && sd[i].y > next.y)
            {
                sd[i].type = 2;
            }
            //Merge Vertex - its two neighbors lie above it and the interior angle > 180° - 3
            else if (sd[i].y < prev.y && sd[i].y < next.y)
            {
                sd[i].type = 3;
            }
        }
        else
        {
            //Start Vertex - its two neighbors lie below it and the interior angle < 180° - 0
            if (sd[i].y > prev.y && sd[i].y > next.y)
            {
                sd[i].type = 0;
            }
            //End Vertex - its two neighbors lie above it and the interior angle < 180° - 1
            else if (sd[i].y < prev.y && sd[i].y < next.y)
            {
                sd[i].type = 1;
            }
        }
    }
    mergeSort(sd, 0, n - 1);
    mergeSortx(sdx,0,n-1);
    int j;
    j=0;
    int start,end;
    for (int i = 0; i < n; i++)
    {
        isdx[sdx[i].val] = i;
        isd[sd[i].val] = i;
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        cout << sd[i].val << " Has the coordinates :" << sd[i].x << " ," << sd[i].y;
        switch (sd[i].type)
        {
        case 0:
            cout << " and it is a Start Vertex\n";
            break;
        case 1:
            cout << " and it is an End Vertex\n";
            break;
        case 2:
            cout << " and it is a Split Vertex\n";
            j=0;
            start =isdx[sd[i].val];
            end = isdx[sd[i-1].val];
            while(isVisible(sdx,start,end)!=true)
            {
                j++;
                end = isdx[sd[i-1-j].val];
            }
            tr[trcnt][0] = sd[i].val;
            tr[trcnt][1] = sd[i - 1-j].val;
            cout << "Join " << sd[i].val << " with " << sd[i - j- 1].val << " and it is not a split anymore\n";
            trcnt++;
            if (sd[i - 1].type == 2)
            {
                sd[i - 1].type = 5;
            }
            break;
        case 3:
            cout << " and it is a Merge Vertex\n";
            j=0;
            start =isdx[sd[i].val];
            end = isdx[sd[i-1].val];
            while(isVisible(sdx,start,end)!=true)
            {
                j++;
                end = isdx[sd[i-1-j].val];
            }
            tr[trcnt][0] = sd[i].val;
            tr[trcnt][1] = sd[i - 1-j].val;
            trcnt++;
            cout << "Join " << sd[i].val << " with " << sd[i - 1-j].val << " and it is not a Merge anymore\n";
            if (sd[i - 1].type == 2)
            {
                sd[i - 1].type = 5;
            }
            break;
        default:
            cout << "\n";
            break;
        }
    }

    drawPolygon(a, tr, n, trcnt);
}
