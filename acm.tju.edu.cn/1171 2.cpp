#include<stdio.h>
#include<math.h>
#define N 1000000
int a[N+1];
int main()
{
      
      int i,j,k;
      int x;
     
      a[0]=a[1]=0;
      for(i=2;i<=N;i++)
          a[i]=1;
      for(i=2;i<=sqrt(N);i++)
           if( a[i] )
          {    
               for(k=i+i;k<=N;k+=i)
                   a[k]=0;
           }  
   
           
	while(1)
	{
        scanf("%d",&x); 
        if (x==0)
		break;
		for(i=2;i<x/2;i++)
        if(a[i]&&a[x-i]) 
        {
			printf("%d = %d + %d\n",x,i,x-i);
			break;
		}
       		if(i==x/2)
			printf("Goldbach's conjecture is wrong.\n");
      		
	}
}

