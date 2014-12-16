#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi = 3.14159265358979323808128481117450284102701938521105559644622948954930381964428810;
const double PD = 1e-8;
double V(double r,double R,double H)
{
    return pi*H*(r*r+r*R+R*R)/3;
}
int main()
{
    int x;
    cin>>x;
    while (x--)
    {
        double cup_r,cup_R,cup_H,cup_V,wat_V,wat_H;
        cin>>cup_r>>cup_R>>cup_H>>wat_V;
        cup_V=V(cup_r,cup_R,cup_H);
        if (wat_V>=cup_V)
        printf ("%.6lf\n",cup_H);
        else
        {
            double begin=0,end=cup_H,mid,r;
            while (end-begin>=PD)
            {
                mid=(begin+end)/2;
                r=cup_r+(cup_R-cup_r)*mid/cup_H;
                if (V(r,cup_r,mid)<wat_V)
                {
                    begin=mid;
                }
                else
                end=mid;
            }
            wat_H=begin;
            printf ("%.6lf\n",wat_H);
        }
    }
}
    
        
