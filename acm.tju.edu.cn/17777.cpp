#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long double x,n,s,i;
    while (cin>>x&&x!=0)
    {
        
        s=0;
        x=2+(x-1960)/10;
        n=pow(2,x);
        for(i=1;;i++)
        {
           s=s+(log10(i)/log10(2));
           
           if ((n)<=s)
           {
                cout<<i-1<<endl;
                break;
            }
           
        }
    }
}
           
           
           
