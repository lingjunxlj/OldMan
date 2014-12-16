#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int x,y;
	while(1)
	{
		cin>>x;
		cin>>y;
		if (x==0&&y==0)
		break;
		int i,j,a[500][500],b[500];
		memset (b,0,sizeof(b));
		for (i=0;i<y;i++)
		for (j=0;j<x;j++)
		cin>>a[i][j];
		for (i=0;i<y;i++)
		for (j=0;j<x;j++)
		{
			if (a[i][j]==1)
			b[j]++;
		}
		int k=0;
		for(i=0;i<x;i++)
		if(b[i]==y)
		{
			cout<<"yes"<<endl;
			k=1;
			break;
		}
		if(k==0)
		cout<<"no"<<endl;
		
	}
	system("pause");
}
	
	
