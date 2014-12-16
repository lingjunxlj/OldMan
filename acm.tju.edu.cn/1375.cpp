#include<iostream>

using namespace std;
int main()
{
   int n;
    while(cin>>n)
    {
        int x=0;
        for(int i=1;;i++)
        {
            x=(x*10+1)%n;
            if(x==0){cout<<i<<endl;break;}
        }
    }
    return 0;
}
