#include <stdio.h>
#include <string.h>

int main()
{
	int N=75,m=28;
	char ct[N],s;
	int cc[N],pc[N],k,n,i,j;
	scanf("%d",&k);
	while(k!=0)
	{
		for(i=0;i<=N;i++)
		{
			ct[i]='\0';
			cc[i]=pc[i]='\0';
		}
		scanf("%s",ct);
		n=strlen(ct);
		for(i=0;i<n;i++)
		{
			if(ct[i]>='a' && ct[i]<='z')
				cc[i]=ct[i]-'a'+1;
			else if(ct[i]=='_') cc[i]=0;
			else if(ct[i]=='.') cc[i]=27;
		}
		for(i=0;i<n;i++)
		{
			s=cc[i]+i;
			while(s>=m)s-=m;
			j=(k*i)%n;
			pc[j]=s;
		}
		for(i=0;i<n;i++)
		{
			if(pc[i]==0) ct[i]='_';
			else if(pc[i]==27) ct[i]='.';
			else ct[i]='a'+pc[i]-1;
		}
		printf("%s\n",ct);
		scanf("%d",&k);
	}
	return 0;
}
