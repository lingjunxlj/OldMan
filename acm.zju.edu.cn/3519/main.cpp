#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#define  MAX 501
int N[MAX];
int cmp(const void *a, const void *b)
{
 return(*(int *)a-*(int *)b);
}

int main()
{
 int i,n,l,l1,l2,m,IP;
 // freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&IP)!=EOF){
  for (i=0;i<n;i++){
   scanf("%d",&N[i]);
  }
  qsort(N,n,sizeof(N[0]),cmp);
  m=0;
  for (i=0;i<n;i++)
  {
   if(N[i]>IP) {IP+=2;m++;}
  }
  IP+=(n-m);
  printf("%d\n",IP);
 }
 return 0;
}
