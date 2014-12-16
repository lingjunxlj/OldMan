#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	char a[200],b[200];
	int n,i,j,sum,num2[26],num1[26];
	scanf("%d",&n);scanf("\n");
	for(j=1;j<=n;j++)
	{
		gets(a);
		gets(b);
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		sum=0;
		for(i=0;i<strlen(a);i++) 
			num1[a[i]-'a']++;
		for(i=0;i<strlen(b);i++) 
			num2[b[i]-'a']++;
		for(i=0;i<26;i++) 
			sum+=(int)abs(num1[i]-num2[i]);
		printf("Case #%d:  %d\n",j,sum);
	}
	system("pause");
}
