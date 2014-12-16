#include<iostream>
#include <cstdio>

#include <cstdlib>
#include<cstring>
using namespace std;

int main()

{
	int mile,r=0;
	char code;
	string a,b;
	int sum=0;
	while(cin>>a&&a!="#")
	{
		if(a[0]=='0') {printf("%d\n",sum);sum=0;continue;}
		
		
		
			  
		cin>>b;
			scanf("%d",&mile);
		cin>>code;
		
			if(code=='F')
			
			{	r=mile*2;  }
			
			
			 if(code=='B')
			
				{r=int(mile+(0.5*float(mile)));}
				
			
			 if(code=='Y'&&mile>500)
			
			{	r=mile;}
			
			
			if(code=='Y'&&mile<=500)
			
			{	r=500;}
				
			
		
		sum=sum+r;
		
	}

	return 0;
}
