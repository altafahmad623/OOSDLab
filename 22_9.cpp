#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
/*
1000 thou = 1 inch
12 inches = 1 foot
3 foot = 1 yard
22 yards = 1 chain
10 chains = 1 furlong
8 furlongs = 1 mile
3 miles = 1 league
*/
class Distance
{
private:
    int feet;
    int inches;
    int thou;
    int yard;
    int chain;
    int furlong;
    int mile;
    int leagues;

public:
    //constructor (no args)
    Distance() : leagues(0) , mile(0) ,furlong(0) , chain(0), yard(0), feet(0), inches(0) ,thou(0)
    {
    }
    //constructor (8 args)
    Distance(int lg, int ml, int furl, int chn, int yrd, int ft, int in, int th)
    {
        while (th >= 1000)
        {
            in++;
            th = th - 1000;
        }
        while (in >= 12)
        {
            ft++;
            in = in - 12;
        }
        while (ft >= 3)
        {
            yrd++;
            ft = ft - 3;
        }
        while (yrd >= 22)
        {
            chn++;
            yrd = yrd - 22;
        }
        while (chn >= 10)
        {
            furl++;
            chn -= 10;
        }
        while (furl >= 8)
        {
            ml++;
            furl -= 8;
        }
        while (ml >= 3)
        {
            lg++;
            ml -= 3;
        }

        leagues = lg;
        mile = ml;
        furlong =furl;
        chain = chn;
        yard = yrd;
        feet = ft;
        inches = in;
        thou = th;
    }
    void getdist()
    //get length from user
    {
        int th, in, ft, yrd, chn, furl, ml, lg;
        cout << "Enter league: ";
        cin >> lg;
        cout << "Enter Miles: ";
        cin >> ml;
        cout << "Enter furlong: ";
        cin >> furl;
        cout << "Enter chn: ";
        cin >> chn;
        cout << "Enter yard: ";
        cin >> yrd;
        cout << "Enter feet: ";
        cin >> ft;
        cout << "Enter inches: ";
        cin >> in;
        cout << "Enter thou: ";
        cin >> th;
        while (th >= 1000)
        {
            in++;
            th = th - 1000;
        }
        while (in >= 12)
        {
            ft++;
            in = in - 12;
        }
        while (ft >= 3)
        {
            yrd++;
            ft = ft - 3;
        }
        while (yrd >= 22)
        {
            chn++;
            yrd = yrd - 22;
        }
        while (chn >= 10)
        {
            furl++;
            chn -= 10;
        }
        while (furl >= 8)
        {
            ml++;
            furl -= 8;
        }
        while (ml >= 3)
        {
            lg++;
            ml -= 3;
        }
        leagues = lg;
        mile = ml;
        furlong =furl;
        chain = chn;
        yard = yrd;
        feet = ft;
        inches = in;
        thou = th;
    }
    void showdist()
    //display distanc
    {
        cout <<leagues << " leagues "<<mile << " miles "<<furlong << " furlong "<<chain << " chain "<< yard << " yard "<<feet << " feet " << inches << " inches "<<thou<<" thou";
    }
    void add_dist(Distance, Distance);
    //declaration
};
void Distance::add_dist(Distance d2, Distance d3)
{
    inches =0;
    thou = d2.thou + d3.thou;
    if(thou >= 1000)
    {
        thou-=1000;
        inches++;
    }
    inches += d2.inches + d3.inches; //add the inches
    feet = 0;
    //(for possible carry)
    if (inches >= 12)
    //if total exceeds 12.0,
    {
        //then decrease inches
        inches -= 12;
        //by 12.0 and
        feet++;
        //increase feet
    }
    //by 1
    feet += d2.feet + d3.feet;
    yard =0;
    if(feet >= 3)
    {
        feet-=3;
        yard++;
    }
    yard += d2.yard + d3.yard;
    chain =0;
    if(yard>=22)
    {
        chain++;
        yard-=22;
    }
    chain+= d2.chain + d3.chain;
    furlong =0;
    if(chain>=10)
    {
        chain-=10;
        furlong++;
    }
    furlong+= d2.furlong + d3.furlong;
    mile = 0;
    if(furlong>=8)
    {
        furlong-=8;
        mile++;
    }
    mile+=d2.mile+d3.mile;
    leagues =0;
    if(mile>=3)
    {
        mile-=3;
        leagues++;
    }
    leagues+=d2.leagues + d3.leagues;
    /*
1000 thou = 1 inch
12 inches = 1 foot
3 foot = 1 yard
22 yards = 1 chain
10 chains = 1 furlong
8 furlongs = 1 mile
3 miles = 1 league
*/
}
int main()
{
    Distance dist1,  dist3;
    //define two lengths
    //Distance dist1(1,2,7,9,21,2,11,1000);
    Distance dist2(2,3,3,5,6,3,7,355);
    //define and initialize dist2
    dist1.getdist();
    dist3.add_dist(dist1, dist2);
    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\ndist2 = ";
    dist2.showdist();
    cout << "\ndist3 = ";
    dist3.showdist();
    cout << endl;
}