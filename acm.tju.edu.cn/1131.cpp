#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.141592653589793 
int main ()
{
	double xa,ya,xb,yb,xc,yc;
	while (scanf ("%lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc)!=EOF)
	{
		
		double s,a,b,c,r,cf;
		s=0.5*((xb-xa)*(yc-ya)-(xc-xa)*(yb-ya));
		a=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));  
        b=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));  
        c=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc)); 
        r=a*b*c/(4*s);
        cf=2*pi*r;
        cf=fabs(cf);
		  printf ("%.2lf\n",cf);
		}
		system("pause");
	}
