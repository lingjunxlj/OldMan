#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
	int x,y;
	while (cin>>x>>y)
	{
		if(gcd(x,y)>1)
		{
    	 	printf("%10d%10d    Bad Choice\n\n",x,y);
		}
		else
		{
     		printf("%10d%10d    Good Choice\n\n",x,y);
		}
	}
	system("pause");
}
