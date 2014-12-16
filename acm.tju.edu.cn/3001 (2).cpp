#include<iostream>
using namespace std;
int main()
{
    long long x,y,z;
    while(cin>>x>>y)
    {
        if(x==0&&y==0)break;
        z=(y-1)*(x-1)-1;
        if(x%y==0||y%x==0||z<0)cout<<"Inf"<<endl;
        else cout<<z<<endl;
    }
         return 0;
}
