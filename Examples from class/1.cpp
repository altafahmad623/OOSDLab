#include <iostream>
using namespace std;

class Student
{
    private: // enables data abstraction i.e. hiding pieces of data from user / developer that are irrelevant to them
    int roll;
    float cgpa;

    public: // encapsulation of data and functions according to compatible or related usage into single body for better organisation
    Student () : roll (0) , cgpa (0.0)
    {
        cout<<"This is the constructor function\n";
    }
    void set_roll(int x)
    {
        roll = x;
    }
    void set_cgpa( float y)
    {
        cgpa = y;
    }
    void show_data()
    {
        cout<<"Student " <<roll <<" CGPA:"<<cgpa<<"\n";
    }
    ~Student ()
    {
        cout<<"Destroyed in Secods\n";
    }
};
int main()
{
    Student stu1;
    stu1.set_roll(2);
    stu1.set_cgpa(9.54);
    stu1.show_data();
    //cout<<"Student "<<stu1.roll<<" \n";
}