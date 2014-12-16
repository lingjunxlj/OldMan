#include <iostream>
#include <stdlib.h>
using namespace std;
int   maxCmd(long long   n1,long long   n2)   
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
	long long x,y;
	while (cin>>x>>y&&x>0&&y>0)
	{
		cout<<y/maxCmd(x,y)<<endl;
	}
	system("pause");
}
 
