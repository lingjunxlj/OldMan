#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
struct fun
{
	int a,b,c;
}s[10010];
int n;
double funmax(double x)
{
	int i;
	double Max,t;
	Max=s[0].a*x*x+s[0].b*x+s[0].c;
	for (i=1;i<n;i++)
    {
		t=s[i].a*x*x+s[i].b*x+s[i].c;
		if(Max<t)Max=t;
		printf("Max = %lf\n", Max);
	}

	return Max;

}

int main()
{
	int t;
	int i,j;
	double mid1,mid2,r,l,rest1,rest2;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		}
		l=0.0;
		r=1000.0;
		do
		{
			mid1=(r+l)/2;
			mid2=(mid1+r)/2;
			rest1=funmax(mid1);
			rest2=funmax(mid2);
			printf(" %0.4lf %0.4lf  %0.4lf %0.4lf \n",rest1,rest2,mid1,mid2);
			if(rest1>rest2)
                l=mid1;
			else
                r=mid2;
		}while(fabs(rest1-rest2)>1e-8);
		printf("%0.4lf\n",rest1);
	}
	return 0;
}

