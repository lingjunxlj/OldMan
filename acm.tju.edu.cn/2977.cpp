#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
	int r,y,i,x;
	while (cin>>x&&x!=0)
	{
		char a[100];		
		cin>>a;
		r=0;y=0;
		for (i=0;i<strlen(a);i++)
		{
			if (a[i]=='R')
			r++;
			if (a[i]=='Y')
			y++;
			if (a[i]=='B')
			{
				if (r==7)
				{
					cout<<"Red"<<endl;
					break;
				}
				else
				{
					cout<<"Yellow"<<endl;
					break;
				}
			}
			if (a[i]=='L')
			{
				if (y==7)
				{
					cout<<"Yellow"<<endl;
					break;
				}
				else
				{
					cout<<"Red"<<endl;
					break;
				}	
			}
		}
	}
	system("pause");
}
		
		
