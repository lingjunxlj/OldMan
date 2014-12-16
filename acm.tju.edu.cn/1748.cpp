#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int sum(int a)
{
	int s=1,j;
	for (j=0;j<a;j++)
	s=s*10;
	return s;
}	
char a[1100],b[1100];
int main()
{
	int c[10][4]={ {0,0,0,0},{1,1,1,1},
     {2,4,8,6},{3,9,7,1},
     {4,6,4,6},{5,5,5,5},
     {6,6,6,6},{7,9,3,1},
     {8,8,8,8},{9,1,9,1}  };
	while (1)
	{
		cin>>a;
		cin>>b;
		if (a[0]=='0'&&b[0]=='0')
		break;
		int len1,len2,i,j,n,t=0;
		len1=strlen(a);
		len2=strlen(b);
		if (a[len1-1]=='0')
		cout<<"0"<<endl;
		else if (b[len2-1]=='0'&&len2==1)
		cout<<"1"<<endl;
		else
		{
			for (i=0;i<len2;i++)
			{
				n=(int)(b[len2-1-i]-'0')*sum(i);						
				t=(t+3+n)%4;						
			}
			cout<<c[a[len1-1]-'0'][t]<<endl;
		}
	}
	system("pause");
}
