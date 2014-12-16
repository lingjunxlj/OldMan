#include <iostream>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
char a[1000][1000];
int b[1000];
int main()
{
	int n,m,max=0;
	while(cin>>n>>m)
	{
		max=0;
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<1000;j++)
			b[j]=0;
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='1')
				{
					for(int k=i;k<n;k++)
					if(a[k][j]=='1') ++b[j];
					else break;
				}
			}
			sort(b,b+m,cmp);
			for(int g=0;g<n;g++)
			{
				if(b[g]==0) break;
				if(max<(g+1)*b[g]) max=(g+1)*b[g];
			}
		}
		cout<<max<<endl;
	}
}
