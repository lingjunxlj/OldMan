#include <stdlib.h>
#include <stdio.h>
int main ()
{
	int x;
	int y=0;
	scanf ("%d",&x);
	while (x--)
	{
	    y++;
		int s;
	    scanf("%d",&s);
	    int a,b,c,d;
		a=s/25;
		s=s%25;
		b=s/10;
		s=s%10;
		c=s/5;
		s=s%5;
		d=s/1;
		printf ("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",y,a,b,c,d);
	}
	system("pause");
}
