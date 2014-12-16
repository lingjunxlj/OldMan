#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int s;
		scanf ("%d",&s);
		char a[s-1][2];
		int i,j;
		for (i=0;i<s-1;i++)
		for (j=0;j<s-1;j++)		
		scanf ("%s",a[i][j]);
		int n=0,m=0;
		for (i=0;i<s;i++)
		{
			if (a[i][0]=='R'&&a[i][1]=='S'||a[i][0]=='S'&&a[i][1]=='P'||a[i][0]=='P'&&a[i][1]=='R')
		    n++;
		    if (a[i][0]=='S'&&a[i][1]=='R'||a[i][0]=='P'&&a[i][1]=='S'||a[i][0]=='R'&&a[i][1]=='P')
		    m++;
		}
		if (m>n)
		printf ("Player 2\n");
		if (n>m)
		printf ("Player 1\n");
		if (n==m)
		printf ("TIE\n");
	}
	system("pause");
}
		
		
