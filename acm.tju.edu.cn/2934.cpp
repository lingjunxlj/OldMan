#include <iostream>
using namespace std;
const int MAX=50001;

struct SP
{
	long long n;
	long long m;
	long long k;
	bool flag;
}cow[MAX];
bool cmp (SP a,SP b)
{
	return a.n>b.n;
}
bool cmp1 (SP a,SP b)
{
	return a.m>b.m;
}
int main()
{
	int x,y,i,j;
	cin>>x>>y;
	for (i=0;i<x;i++)
	cow[i].flag=true;
	for (i=0;i<x;i++)
	{
		cin>>cow[i].n>>cow[i].m;
		cow[i].k=i+1;
	}
	sort(cow,cow+x,cmp);
	for (i=0;i<y;i++)
	cow[i].flag=0;
	sort(cow,cow+x,cmp1);
	for (i=0;i<x;i++)
	{
		if (!cow[i].flag)
		{
			cout<<cow[i].k<<endl;
			break;
		}
	}
	while (1);
}
	
	
	
