#include<cstdio>
#include<cstring>
bool prime[20010];
int ans[20010],pr[10010],len;
void prlist()
{
	int i,j;
	for(i=2;i<20010;i++)
		prime[i]=1;
	prime[0]=prime[1]=1;
	len=0;
	for(i=2;i<20010;i++)
	{
		if(prime[i]) pr[len++]=i;
		for(j=0;j<len&&pr[j]*i<20010;j++)
		{
			prime[pr[j]*i]=0;
			if(i%pr[j]==0) break;
		}
	}
}
int main()
{
	int i,j,k,n,t1,t2;
	memset(ans,0,sizeof(ans));
	prlist();
	for(i=1;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			t1=pr[i]+pr[j];
			if(t1<=20000)
			{
				ans[t1]++;
				for(k=j+1;k<len;k++)
				{
					t2=t1+pr[k];
					if(t2<=20000)
						ans[t2]++;
					else break;
				}
			}
			else break;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",ans[n]);
	}
	return 0;
}
