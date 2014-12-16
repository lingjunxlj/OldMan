#include<iostream>
using namespace std;

const int Max=10;
bool mat[Max][Max];
int n,cnt,num=1;
bool flag,vis[Max];

void DFS(int i)
{	
	if(cnt==n)		
	{
		if(mat[i][0]==true)
		{
			flag=true;
			return;
		}
	}
	int j;
	for(j=1;j<=n;j++)
	{
		if(mat[i][j]==true && vis[j]==false) 
		{
			vis[j]=true;
			cnt++;
			DFS(j);
			vis[j]=false;	
			cnt--;
		}
	}
}

bool run()
{
	scanf("%d",&n);
	getchar();
	if(n==0) return false;

	int i,j;
	for(i=0;i<=n;i++)		
	{
		for(j=0;j<=n;j++)
			mat[i][j]=false;
	}
	for(i=0;i<=n;i++)
		vis[i]=false;
	
	for(i=1;i<=n;i++)
	{
		char pos;
		while(true)
		{
			scanf("%c",&pos);
			if(pos=='\n') break;		
			if(pos>='0' && pos<='9') 
			{
				mat[i][pos-'0']=true;	
				mat[pos-'0'][i]=true;
			}
		}
	}
	cnt=0;		
	flag=false;
	vis[0]=true;
	DFS(0);		

	printf("Case %d: ",num++);
	if(flag==true) printf("Granny can make the circuit.\n");
	else printf("Granny can not make the circuit.\n");

	return true;
}

int main()
{
    while(run());
    return 0;
}
