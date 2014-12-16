#include <stdio.h>
#include <stdlib.h>
int main(){
    int x,i,y,m;
    scanf ("%d",&m);
    while (m--){
		int sum;
		scanf("%d",&x);
		scanf("%d",&y);
	         
		if (x%2==1&&y%2==1) {
			sum=x+y-1;
			printf ("%d\n",sum);
			}
	    else if	 (x%2==0&&y%2==0) {
			sum=x+y;
			printf ("%d\n",sum);
			}
	    else	   printf ("No Number\n");
	
	}
	system("pause");
}
