#include <iostream>
using namespace std;
int   gcd(long long   n1,long long   n2)   
  {     if(n1<0)   n1*=-1;   
        if(n2<0)   n2*=-1;   
        int   t;   
        if(n1<n2){   
        t=n1;   
        n1=n2;   
        n2=t;   
        }   
        while(n2!=0){   
        t=n1;   
        n1=n2;   
        n2=t%n2;   
        }   
        return   n1;   
  }   
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		int n,m,b1,b2;
		cin>>n>>m>>b1>>b2;
		cout<<gcd(n-b1,m-b2)<<endl;
	}
}
