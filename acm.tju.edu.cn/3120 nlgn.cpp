#include<stdio.h>
#include<string.h>
int d[40001];
int main()
{
 	int i,j,k,m,n;

 	int p,q,a;
 	int left,right,mid;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
  		memset(d,0,sizeof(d));
  		scanf("%d",&p);
  		int len=0;
  		for(j=0;j<p;j++)
  		{
   			scanf("%d",&a);
   			if(a>d[len])
   			{
    			len++;
    			d[len]=a;
   			}
   			else
   			{
    			left=0;
    			right=len;
    			while(right-left>1)
    			{
     				mid=(left+right)/2;
     				if(a<=d[mid])
     				right=mid;
     				else
     				left=mid;
    			}
    			d[right]=a;
   			}
  		}
  		printf("%d\n",len);
 	}
 	return 0;
}

 

