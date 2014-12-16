#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int a,b,c;
	scanf ("%d",&a);
	scanf ("%d",&b);
	scanf ("%d",&c);
	if((a>=0&&a<=300)&&(b>=0&&b<=300)&&(c>=0&&c<=300))
	{
	
	 if(a<=168) 
	 printf("CRASH %d",a); 
     else if(b<=168)
     printf("CRASH %d",b); 
     else if(c<=168) printf("CRASH %d",c); 
     else printf("NO CRASH");
  

    }
	system("pause");
}
