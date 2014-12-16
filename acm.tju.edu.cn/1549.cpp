#include <cstdio>
#include <cstdlib>

int jc(int a)
{
	int m=1,i;
	for(i=1;i<=a;i++)
	m=m*i;
	return m;
}	
int main()
{
	int e,i;
	double sum=0;
	printf("n e\n");
	printf("- -----------\n");
	for(i=0;i<10;i++)
	{
		sum=(double)sum+1/(double)jc(i);
		if(i<2)
		printf("%d %d\n",i,(int)sum);
		else if(i==2)
		printf("%d %.1f\n",i,sum);
		else
		printf("%d %.9f\n",i,sum);
	}
	system("pause");
}
	
