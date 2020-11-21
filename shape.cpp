#include <iostream>
#include <math.h>
#define PI 3.14159265359
using namespace std;
struct coordinates
{
    double x, y;
};
class Shape
{
public:
    virtual void area()
    {
        cout << "If this is output, there is some error\n";
    }
    virtual void perimeter()
    {
        cout << "If this is output, there is some error\n";
    }
};
class Circle : public Shape
{
private:
    double radii;
    coordinates centre;

public:
    Circle() : radii(0)
    {
    }
    void get_val()
    {
        cout << "Enter the radius: ";
        cin >> radii;
        cout << "Enter the coordinates of centre of the Circle :";
        cin >> centre.x >> centre.y;
    }
    void area()
    {
        double ar;
        ar = PI * radii * radii;
        cout << "Area of the circle is :" << ar << "\n";
    }
    void perimeter()
    {
        double per = PI * radii * 2.0;
        cout << "Perimeter of the Circle is :" << per << "\n";
    }
};
class Square : public Shape
{
private:
    coordinates x1, x2;

public:
    void get_val()
    {
        cout << "Enter the (x,y) coordinates of the first edge of diagonal :";
        cin >> x1.x >> x1.y;
        cout << "Enter the (x,y) coordinates of the 2nd edge of diagonal :";
        cin >> x2.x >> x2.y;
    }
    void area()
    {
        double a = sqrt(pow((x1.x - x2.x), 2) + pow((x1.y - x2.y), 2));
        double area = a * a / 2.0;
        cout << "Area of the square is :" << area << "\n";
    }
    void perimeter()
    {
        double a = sqrt(pow((x1.x - x2.x), 2) + pow((x1.y - x2.y), 2)) / (sqrt(2.0));
        double per = 4 * a;
        cout << "Perimeter of the square is :" << per << "\n";
    }
};
class Triangle : public Shape
{
private:
    coordinates x1, x2, x3;

public:
    void get_val()
    {
        cout << "Enter the (x,y) coordinates of the first edge :";
        cin >> x1.x >> x1.y;
        cout << "Enter the (x,y) coordinates of the 2nd edge :";
        cin >> x2.x >> x2.y;
        cout << "Enter the (x,y) coordinates of the 3rd edge :";
        cin >> x3.x >> x3.y;
    }
    void area()
    {
        double ar = (x1.x * (x2.y - x3.y) + x2.x * (x3.y - x1.y) + x3.x * (x1.y - x2.y)) / 2.0;
        cout << "Area of the traingle is :" << ar << "\n";
    }
    void perimeter()
    {
        double s1, s2, s3, per;
        s1 = sqrt(pow((x1.x - x2.x), 2) + pow((x1.y - x2.y), 2)) ;
        s2 = sqrt(pow((x2.x - x3.x), 2) + pow((x2.y - x3.y), 2)) ;
        s3 = sqrt(pow((x3.x - x1.x), 2) + pow((x3.y - x1.y), 2)) ;
        per = s1 + s2 + s3;
        //cout<<s1<<" "<<s2<<" "<<s3;
        cout << "Perimeter of the square is :" << per << "\n";
    }
};
int main()
{
    Shape *ptr;
    Circle c1;
    c1.get_val();
    ptr = &c1;
    ptr->area();
    ptr->perimeter();
    Square s1;
    s1.get_val();
    ptr = &s1;
    ptr->area();
    ptr->perimeter();
    Triangle t1;
    t1.get_val();
    ptr = &t1;
    ptr->area();
    ptr->perimeter();
    return 0;
}