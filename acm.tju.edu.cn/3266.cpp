#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[20];
int main()
{
    f[1]=0;
	f[2]=1;
    for(int i=3; i<=15; i++) 
	f[i]=(i-1)*(f[i-2]+f[i-1]);
    int T;
    cin>>T;
    while(T--)
	{
        int a;
        cin>>a;
        cout<<f[a]<<endl;
    }
    return 0;
}
