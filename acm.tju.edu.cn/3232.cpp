#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int i,sum;
	int a,b,c;
  scanf ("%d",&a);
  scanf ("%d",&b);
	scanf ("%d",&c);
	if (b-a>c-b) sum=b-a-1;
	else sum=c-b-1;
	printf ("%d\n",sum);
	system("pause");
}
	
