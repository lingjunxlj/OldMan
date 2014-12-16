#include <iostream>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926
using namespace std;
int main ()
{
	int x,y=0;
	cin>>x;
	while (x--)
	{
		y++;
		float a,b,s;
		scanf ("%f",&a);
		scanf ("%f",&b);
		
		float i;
		int n;
		s=pi*(a*a+b*b);
		n=int(float(s/100.0))+1;								
		printf ("Property %d: This property will begin eroding in year %d.\n",y,n);
				
			
		
	}
	printf ("END OF OUTPUT.\n");
	system("pause");
}
		
		
