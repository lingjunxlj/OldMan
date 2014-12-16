#include<stdio.h>
#include<string.h>
long long d[100001];
int main()
{
 	long long i,j,k,m,n;

 	long long p,q,a;
 	long long left,right,mid;
 	scanf("%lld",&n);
 	while(scanf("%lld",&p)!=EOF)
 	{
  		memset(d,0,sizeof(d));
  		long long len=0;
  		for(j=0;j<p;j++)
  		{
   			scanf("%lld",&a);
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
  		printf("%lld\n",len);
 	}
 	return 0;
}

 

