#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		char a[105],b[105];
		int i,j,len1,len2,s,k;
		cin>>a;
		
		cin>>b;
		len1=strlen(a);
		len2=strlen(b);
		s=0;
		if (len1<len2)
		cout<<"no"<<endl;
		if (len1>=len2)
		{
			if (len1==len2&&strcmp(a,b)==0)
			cout<<"yes"<<endl;
			if (len1==len2&&strcmp(a,b)!=0)
			cout<<"no"<<endl;
			if (len1>len2)
			{
				s=0;
				
				k=0;
				for (i=0;i<len2;i++)
				{
					for (j=k;j<len1;j++)
					if (b[i]==a[j])
					{
						k=j+1;
						s++;	
						break;
					}
					
				}
					if (s==len2)	
					cout<<"yes"<<endl;
					else
					cout<<"no"<<endl;
				
			
			}
		}
	}
	system("pause");
}																																						
