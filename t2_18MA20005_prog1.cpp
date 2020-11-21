/*
By: Altaf Ahmad
Roll no: 18MA20005
*/
#include <iostream>
#include <string.h>
using namespace std;
class publication
{
public:
    string title;
    float price;

    void getdata()
    {
        cout << "Enter the title of the publication: \n";
        cin >> title;
        cout << "Enter the price of the publication: \n";
        cin >> price;
    }
    virtual void putdata()
    {
        cout << "If this is displayed, then there is some sort of error";
    }
};
class book : public publication
{
private:
    int pagecount;

public:
    void getdata()
    {
        cout << "Enter pagecount for the book:\n";
        cin >> pagecount;
    }
    void putdata()
    {
        cout << "Title of the book is :" << title << "\n";
        cout << "Pagecount is :" << pagecount << "\n";
        cout << "Price is :" << price << "\n";
    }
};
class tape : public publication
{
private:
    float play_tm;
    public:
    void getdata()
    {
        cout << "Enter playing time for the tape:\n";
        cin >> play_tm;
    }
    void putdata()
    {
        cout << "Title of the tape is :" << title << "\n";
        cout << "Playing time is :" << play_tm << "\n";
        cout << "Price is :" << price << "\n";
    }
};
int main()
{
    publication *pb;
    book bk;
    bk.getdata();//gets the data specific for the book class
    pb = &bk;
    pb->getdata();//gets the data for the book class which was extended from the publication class
    pb->putdata();

    tape tp;
    tp.getdata();
    pb = &tp;
    pb->getdata();
    pb->putdata();
}