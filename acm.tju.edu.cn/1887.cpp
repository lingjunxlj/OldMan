#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	double a,b,c,d,m,p,t,max,min;
	while(cin>>a>>b>>c>>d)
	{
		if(a==0&&b==0&&c==0&&d==0)
		break;
		if(c<d)
		{
			max=d;
			min=c;
			}
		else 
		{
			max=c;
			min=d;
		}
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
		m=b;
		b=max*b/a;
		if(b<=min)
		p=100*b/m;
		else 
		{
			b=min;
			p=100*b/m;
		}
		if(p<=1.0)
		p=1.0;
		if(p>=100.0)
		p=100.0;
		printf("%d%c\n",(int)p,'%');
		
	}
}
