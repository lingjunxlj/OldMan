#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
  int i=0,j,k;
  int p,s;

  while(1)
  {
    scanf("%d%d",&p,&s);
    if(p==0) break;

    printf("Hole #%d\n",++i);
    if(s==1)
       printf("Hole-in-one.\n");
    else if(s==p)
       printf("Par.\n");
    else if(s==p-1)
       printf("Birdie.\n");
    else if(s==p+1)
       printf("Bogey.\n");
    else if(s==p-2)
       printf("Eagle.\n");
    else if(s==p-3)
       printf("Double Eagle.\n");
    else if(s==p+2)
       printf("Double Bogey.\n");
    else
       printf("Double Bogey.\n");
    printf("\n");
   }

return 0;
}
