#include <iostream>
#include <string>
using namespace std;
const int MAX=501;
char diction[MAX][MAX],encrypt[MAX];
int ACS[MAX],lens[MAX];
int main()
{
	int x,i,j,y;
	char p;
	cin>>x;
	for (i=0;i<x;i++)
	{
		cin>>diction[i];
		lens[i]=strlen(diction[i]);
	}
	for (i=0;i<x;i++)
	for (j=1;j<lens[i]-1;j++)
	ACS[i]+=diction[i][j];
	while (cin>>encrypt)
	{
		p=getchar();
		int len=strlen(encrypt),sum=0;
		for (i=1;i<len-1;i++)
		sum+=encrypt[i];
		if (len<=2)
		cout<<encrypt<<p;
		else
	    {
			for (i=0;i<x;i++)
			{
				int s=lens[i];
				if (encrypt[0]==diction[i][0]&&encrypt[len-1]==diction[i][s-1]&&sum==ACS[i])
				cout<<diction[i]<<p;
			}
		}
	}
	}
		
