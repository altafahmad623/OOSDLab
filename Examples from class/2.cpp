#include <iostream>
using namespace std;

class Distance
{
    private:
    int feet;
    float inches;

    public :
    void setdist (int ft, float in)
    {
        feet = ft;
        inches = in;
    }
    void getdist ()
    {
        cout<<"\nEnter feet:\n";
        cin>>feet;

        cout<<"\nEnter inches:\n";
        cin>>inches;
    }
    void showList()
    {
        cout<<"\nThe distance is " <<feet<<" feet, "<<inches<<" inches.\n";
    }
};
/*
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
};*/
int main()
{
    Distance dist1;
    dist1.setdist(12,3.4);
    dist1.showList();
    //cout<<"Student "<<stu1.roll<<" \n";
}