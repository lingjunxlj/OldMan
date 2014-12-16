#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int m,n;
	int i;
	char a[10][10];
	char se[20];
	while(cin>>se)
	{
		if(strcmp(se,"ENDOFINPUT")==0)
		break;

		if(strcmp(se,"START")==0)
		cin>>m>>n;
        getchar();

		for(i=0;i<m;i++)
		gets(a[i]);
		cin>>se;

		if(strcmp(se,"END")==0)
		for(i=0;i<m-1;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				int d = (a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1] ) /4 -48;
				cout<<d;
			}
			cout<<endl;
		}
	}
	return 0;
}
