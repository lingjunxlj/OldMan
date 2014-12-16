#include <iostream>
using namespace std;

char t[4][5]={{"ABCD"},{"EFGH"},{"IJKL"},{"MNO."}};
char map[4][5];
int b[4][5];
int main()
{
	int i,j,sum=0;
	for(i=0;i<4;i++)
	cin>>map[i];
	for(i=0;i<4;i++)
	for(j=0;j<5;j++)
	{
		if(map[i][j]==t[i][j])
		{
			b[i][j]=0;
		}
		else
		{
			for(int k=0;k<4;k++)
			{
				for(int h=0;h<5;h++)
				{
					if(map[i][j]==t[k][h])
					{
						b[i][j]=abs(i-k)+abs(j-h);
					}
				}
			}
		}
	}
	for(i=0;i<4;i++)
	for(j=0;j<5;j++)
	{
		if(map[i][j]!='.')
		sum+=b[i][j];
	}
	cout<<sum<<endl;

}
