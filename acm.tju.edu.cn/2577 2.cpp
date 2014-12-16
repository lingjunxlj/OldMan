#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,m,j,k;
	char a[16];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%s",&a);
	m=strlen(a);
	if(m==1)
	{	printf("%s\n",a);
	continue;
	}
	for(k=m-1;k>=0;k--)
	{
	if(a[k]>='5')
		a[k-1]++;
	}
	if(a[0]>'9')
	{	a[0]='0';
    printf("1");}
	for(j=1;j<m;j++)
	{	 a[j]='0';}
	printf("%s\n",a);
	}
	return 0;
}

 
