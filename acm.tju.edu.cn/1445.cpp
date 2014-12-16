#include<cstdio>
#define gmin(a,b) ((a)<(b)?(a):(b))
#define gmax(a,b) ((a)>(b)?(a):(b))
int main(){
    int t,max,min,l,n,i,j,k;
    scanf("%d",&t);
    while(t--)
	{
         scanf("%d %d",&l,&n);
         max=0;
         min=0;
         for(i=1;i<=n;i++)
		 {
            scanf("%d",&k);
            min=gmax(min,gmin(k,l-k));
            max=gmax(max,gmax(k,l-k));
         }
         printf("%d %d\n",min,max);
    }
}

