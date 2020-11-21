#include<iostream>
using namespace std;
class GeneralBank
{
private:
    double savings_rate, fixed_acc_rate;

public:
    virtual double getSavingInterestRate()
    {
        return savings_rate;
    }
    virtual double getFixedInterestRate()
    {
        return fixed_acc_rate;
    }
};
class ICICIBank : public GeneralBank
{
public:
    double savings_rate = 4, fixed_acc_rate = 8.5;
    double getSavingInterestRate()
    {
        return savings_rate;
    }
    double getFixedInterestRate()
    {
        return fixed_acc_rate;
    }
};
class ICICIBank : public GeneralBank
{
public:
    double savings_rate = 6, fixed_acc_rate = 9;
    double getSavingInterestRate()
    {
        return savings_rate;
    }
    double getFixedInterestRate()
    {
        return fixed_acc_rate;
    }
};
int main()
{
    ICICIBank ic;
    GeneralBank * ptr;
    ptr = &ic;
    cout<<ptr->getSavingInterestRate();
    cout<<ptr->getFixedInterestRate();
}