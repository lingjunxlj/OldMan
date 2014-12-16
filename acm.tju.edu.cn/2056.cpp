#include <stdio.h>
   int main()
   {
     int a,b,c;
     int x,y,z;
     while (EOF!=scanf("%d %d %d",&x,&y,&z))
     {
       a=(z-2*y+x)/2;
       b=(4*y-z-3*x)/2;
       c=x;
     printf("%d ",9*a+3*b+c);
     printf("%d ",16*a+4*b+c);
     printf("%d\n",25*a+5*b+c);
     }
      return 0;
   
   }
