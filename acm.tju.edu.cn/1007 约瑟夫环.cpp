#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[15],i;
	for(i=0;i<15;i++)
	a[i]=0;
	while (1)
	{
		int k,m=0;
		scanf ("%d",&k);
		if (k==0)
		break;
		if (a[k]==0)
		{
			while (1)
			{
				m++;
				int bad=k*2,now=0;
				while (1)
				{
					now=(now+m-1)%bad+1;
					if (now>k)
					{	
						bad--;
						now--;
					}				
					else
					break;
				}
			
				if (bad==k)
				{
					a[k]=m;
					break;
				}
			}
		}
	printf ("%d\n",a[k]);
	}
	system("pause");
}
