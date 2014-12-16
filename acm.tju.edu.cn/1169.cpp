#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int x;
	while(1)
	{ 
		cin>>x;
		if (x==0)
		break;
		int a[x][4];
		int i,j,b[100]={0},sum=0;
		for (i=0;i<x;i++)
		for (j=0;j<4;j++)
		scanf ("%d",&a[i][j]);
		for (i=0;i<x;i++)
		for (j=0;j<4;j++)
		{
			if (a[i][j]==1)
			b[i]++;
		}
		for (i=0;i<x;i++)
		sum+=b[i];
		if (sum%x==0)
		printf ("OK\n");
		
		else if (sum%x==1||sum%x==3)
		{
			int m,p,q;
			m=sum/x;
			for (i=0;i<x;i++)
			{
				if (b[i]%m==1)
				{
					if (b[i]==1)
					for (j=0;j<4;j++)
					{
						if (a[i][j]==1)
						{
							q=i+1;
							p=j+1;
						}
					}
					if (b[i]==3)
					
						
						for (j=0;j<4;j++)
						{
							if (a[i][j]==0)
							{
								q=i+1;
								p=j+1;
							}
						}
				}
			}
			printf ("Chang bit (%d,%d)\n",q,p);
		}
		else 
		printf ("Corrupt\n");
	}
	system("pause");
}
			
			
			
			
			
			
			
		
		
		
		
