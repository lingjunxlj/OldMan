#include <stdio.h>
#include <string.h>

const int max = 701;
int a[max],c[max],n;

int main()
{
   int ii,j,k;
   for(ii = 0 ; ii < max ; ii++) a[ii] = 1;
   k = 2;
   while(k < max)
   {
       j = 0;
       while(j < max)
       {
           for(ii =  0 ; ii + j < max ; ii++) c[ii+j] += a[ii];
           j += k;
       }
       memcpy(a,c,max * sizeof(int));
       memset(c,0,sizeof(c));
       k++;
   }
   while(scanf("%d",&n),n)
   printf("%d\n",a[n]);
   return 0;
}
