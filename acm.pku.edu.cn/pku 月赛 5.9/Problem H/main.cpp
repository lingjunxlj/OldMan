#include <iostream>
#include <string>
#include <math.h>
using namespace std;
char map[3001][3001];
int p(int x,int n)
{
	int i,j;
	if (n==1)
	{
        for (i=0;i<x;i++)
        puts(map[i]);
	}
	else
	{
		p(x,n-1);
		for(i=0;i<(int)pow(x,n-1);i++)
		cout<<" ";
		p(x,n-1);
	}
}
int main()
{
	int x;
	while (cin>>x)
	{
		int i;
        for (i=0;i<x;i++)
        gets(map[i]);
		int n;
		cin>>n;
		if (n==1)
		for (i=0;i<x;i++)
        puts(map[i]);
		else
		p(n,x);
		cout<<endl;
	}


}
