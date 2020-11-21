#include <iostream>
#include <fstream> 
#include <string.h>
using namespace std;
/*
input
172.42sdf3,30g952j.2a3, 2h425e.2j5,2a4f25.7, 36536.35636, 254afa.2af5253a6,  2634af63.af633, 363.3346, 363a.3af63, 36745.4767,363447.36af37,3764.347644, 363af57.463,36544af.363,6346.336, 364.365764,  3647.37654fa

putput
172.423,30952.23, 2425.25,2425.7, 36536.35636, 254.252536, 263463.633, 363.3346, 363.363, 36745.4767,363447.3637,3764.347644, 36357.463,36544.363,6346.336, 364.365764, 3647.37654
*/
int main()
{
    string s,str;
    fstream file,file2;
    file.open("input.txt",ios::in);
    file2.open("output.txt",ios::out);
    if(file.is_open())
    {
        getline(file,s);
        for(int i=0;i<s.length();i++)
        {
            if( (s[i]>='0' && s[i]<='9') || (s[i]==' ') || (s[i] == ',') || s[i]=='.')
            {
                file2<<s[i];
            }

        }
    }

    file.close();  
    return 0;
}