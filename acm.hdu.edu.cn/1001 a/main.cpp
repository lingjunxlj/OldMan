#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
__int64 a[100000];
__int64 b[100000];
__int64 NN;

inline void fenjie(__int64 N)
{
	__int64 M;
	__int64 i, j, k, ll;
	M=N;     j=1;
	k=(long long)sqrt(N);
	for(i=2;i<=k+1;i++)
	{
		ll=0;
		if(N%i==0)
		{
			while(N%i==0) {N/=i;ll++;}
			a[j]=i;
			b[j++]=ll;

		}
	}
	if(N!=1) { a[j]=N; b[j]=1; j++; }
	NN=j;
}

int main()
{   int t, n, i, j, ll;
    __int64 x[100], y[100], sum, sum1, ans[100];
    float kk;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(ans,0,sizeof(ans));
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&x[i],&y[i]);
			fenjie(x[i]);
			for(j=1;j<NN;j++)
			ans[a[j]]+=b[j]*y[i];
		}
		sum=0;

		for(i=2;i<=97;i++)
		{
			if(ans[i]!=0)
			{
				kk=log((float)ans[i])/log(i);
				ll=(int)kk;
			  sum1=(ans[i]-ll*(ll-1)/2)*i;
			  if(sum1>sum)  sum=sum1;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
