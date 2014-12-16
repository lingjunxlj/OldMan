#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	int x,g=0;
	cin>>x;
	while (x--)
	{
		g++;
		int a,b;
		cin>>a>>b;
		float s;
		if (a*b%2==0)
		{
			s=(float)a*b;
			printf ("Scenario #%d:\n%.2f\n\n",g,s);
		}
		else
		{
			s=(float)a*b+sqrt(2)-1;
			printf ("Scenario #%d:\n%.2f\n\n",g,s);
		}
	}
	system("pause");
}
		
		
		
	
