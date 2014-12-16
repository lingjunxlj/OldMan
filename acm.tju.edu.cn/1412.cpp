#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int y;
		scanf ("%d",&y);
		int a[y];
		int i,sum=0;
		for (i=0;i<y;i++)
		{
		scanf ("%d",&a[i]);
		sum+=a[i];
	    }
	     float p;
	     p=(float)sum/y;
	     int k=0;
	     for (i=0;i<y;i++)
	     {
				if (a[i]>p)
				k++;
		 }
			float m;
			m=(float)k/y;
			printf ("%.3f%%\n",m*100);
	}
		system("pause");
}
