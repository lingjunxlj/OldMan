#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a(int p)
{
	int w=1;
	while(p)
	{
		w*=10;
		p--;
	}
	return w;
}
int b(char c[6])
{
	char t;
	int i,j,len,sum=0;
	len=strlen(c);
	for(i=0;i<len-1;i++)
	for(j=0;j<len-1-i;j++)
	{
		if(c[j]>c[j+1])
		{
			t=c[j];
			c[j]=c[j+1];
			c[j+1]=t;
		}
	}
	for(i=0;i<len;i++)
	sum+=(c[i]-48)*a(len-i-1);
	return sum;
}
		
int main()
{
	int t,d;
	while(cin>>t)
	{
		if(t==0) break;
		d=t;
		int num1[d],q=0;
		char num[6];
		while(t--)
		{
			scanf("%s",num);
			getchar();
			num1[q]=b(num);
			q++;
		}
		int max=0;
		int g;
		for(g=0;g<d;g++)
		if(max<num1[g]) max=num1[g];
		cout<<max<<endl;
	}
	system("pause");
}
			
		
