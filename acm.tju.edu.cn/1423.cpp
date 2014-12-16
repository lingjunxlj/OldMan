#include<stdio.h>
#include<string.h>
int main()
{
	int n,i=0,j=0,t=0,flag=0;
	int h[100]={0},l[100]={0};
        
	char s[300]={0};
	while(scanf("%d",&n) != EOF && n!=0 ){

		getchar();
		gets(s);	
		if( !(strcmp(s,"too high")) ){ h[i++]=n; }
		if( !(strcmp(s,"too low")) ){ l[j++]=n; }
		if( !(strcmp(s,"right on")) ){
			t = n;
			while(i){
				i--;
				if(t>=h[i]){flag = 1;}
			}
			while(j){ 
				j--;
				if(t<=l[j]){flag = 1;}
			}
			if(flag==1)
                         { printf("Stan is dishonest\n");flag=0;}
			else{ printf("Stan may be honest\n"); }
		}
	}
	return 0;
}

