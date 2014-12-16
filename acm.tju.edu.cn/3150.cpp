#include <iostream>
#include <stdlib.h>
using namespace std;
int main ()
{
	int x,y=0;
	cin>>x;
	while (x--)
	{
		y++;
		int a,b,i,m;
		cin>>a>>b;
		for (i=1;i<=max(a,b);i++)
		{
			if (a%i==0&&b%i==0)
			m=i;
		}
		int s;
		s=a*b/m;
		printf ("%d %d %d\n",y,s,m);
	}
	system("pause");
}
			
			
			
			
