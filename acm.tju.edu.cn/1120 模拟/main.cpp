#include <iostream>
#include <cstring>
using namespace std;

char from[40], to[30], flag;
int main()
{
    int miles, sum = 0;
    while(1)
    {
        cin>>from;

        if(from[0]=='#')  break;

        if(from[0] == '0')
        {
            cout <<sum<<endl;
            sum = 0;
            continue;
        }
        cin>>to>>miles>>flag;


        if(flag=='F')   sum += miles*2;
        if(flag=='B')   sum += (miles + miles/2);
        if(flag=='Y')
        {
            if(miles <= 500)  sum += 500;
            else sum += miles;
        }


    }
    return 0;
}


