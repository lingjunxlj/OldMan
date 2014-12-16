#include<cstdio>
#include<algorithm>
using namespace std;
#define MaxSize 10000005
#define INF 2147483647

int h[MaxSize];

int main()
{
	int s, sn, n, i, sum, k, mark;
	
	while(scanf("%d",&s)!=EOF)
	{	
	    sn=0;
        while(sn++<s)
	  {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&h[i]);		
		sort(h,h+n);		
		for(i=0,sum=INF;i+4<n;i++)
		{
			k=h[i+4]-h[i]+1;			
			if(sum>k)
			{
				sum=k;				
				mark=i;
			}
		}
		printf("Scenario #%d:\n",sn);
		printf("%d:",sum);		
		i=0;
		while(i++<5) 
		printf(" %d",h[mark++]);
		printf("\n\n");
	}	
   } 
   return 0;
}
