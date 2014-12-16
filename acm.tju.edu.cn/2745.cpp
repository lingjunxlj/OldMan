#include<stdio.h>
int main()
{
int i,j,t,n,count;
int mark[502],order[502],result[502];
while(scanf("%d",&n),n)
{
    for(i=1;i<=n;i++)
  	{
		scanf("%d",&order[i]);
  		mark[i]=0;
  	}
  	for(i=1;i<=n;i++)
  	{
   		t=order[i];
   		count=0;
   		j=1;
   		while(mark[j]!=0)
    	j++;
   		for(;j<=n&&count!=t;j++)
    	if(mark[j]==0)
    	count++;
  		while(mark[j]!=0)
    	j++;
   		mark[j]=1;
   		result[j]=i;

 	}
  	for(i=1;i<=n-1;i++)
  	printf("%d,",result[i]);
  	printf("%d\n",result[n]);
}
return 0;
}
