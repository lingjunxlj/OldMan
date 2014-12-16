#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	long m,i,sum;
	scanf("%ld ",&m);
	printf("PERFECTION OUTPUT\n");
	while(m>0){
		sum=0;
		for(i=1;i<m;i++)
			if(m%i==0) sum+=i;
		if(m==sum)
			printf("%5d  PERFECT\n",m);
		if(m>sum)
			printf("%5d  DEFICIENT\n",m);
		if(m<sum)
			printf("%5d  ABUNDANT\n",m);
		scanf("%ld ",&m);
		
	}
	scanf("\n");
	printf("END OF OUTPUT\n");
}


