#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    long long r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    long long x,y;
    while(cin>>x>>y)
    {
        if(x==0&&y==0)break;
        
        if(gcd(x,y)==1)
        cout<<x*y-x-y<<endl;
        else cout<<"Inf"<<endl;
    }
         
}

