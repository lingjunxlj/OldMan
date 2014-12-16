#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int s1,s2,s3=0,i;
	int x,y,z;
	int shu;
	for (i=2992;i<10000;i++)
	{		
		x=i;y=i;z=i;
        s1=0;s2=0;s3=0;
        shu=i;
		while (x!=0)
		{
			s1=s1+x%10;
			x=x/10;
		}
		while (y!=0)
		{
			s2=s2+y%16;
			y=y/16;
		}
		while (z!=0)
		{
			s3=s3+z%12;
			z=z/12;
		}
		if ((s1==s2)&&(s2==s3))
		printf("%d\n",shu);
	}
	system("pause");
}
		
