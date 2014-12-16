#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a(int p)
{
	int w=1;
	while(p)
	{
		w=w*10;
		p--;
	}
	return w;
}
int b(char g[20])
{
	int len,i,sum=0;
	int d[20];
	memset(d,0,sizeof(d));
	len=strlen(g);
	for(i=0;i<len;i++)
	d[i]=g[i]-48;
	for(i=0;i<len;i++)
	sum+=d[i]*a(i);
	return sum;
}
int c(int o)
{
	int h[20],i,j,sum=0;
	memset(h,0,sizeof(h));
	for(i=0;i<20;i++)
	h[i]=o%a(i+1)/a(i);
	for(i=19;;i--)
	if(h[i]!=0) break;
	for(j=i;j>-1;j--)
	sum+=h[j]*a(i-j);
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char n[20],m[20];
		cin>>n>>m;
		int x,y,sum;
		x=b(n);
		y=b(m);
		sum=x+y;
		printf("%d\n",c(sum));
	}
	system("pause");
}
