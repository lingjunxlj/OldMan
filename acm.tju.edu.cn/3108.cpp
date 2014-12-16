#include <iostream>
using namespace std;
int first[1001],last[1001],num[1001];
bool flag[1001];
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		int k=0;
		memset(flag,true,sizeof(flag));
		int n,m,i,j;
		cin>>n>>m;
		for (i=0;i<n;i++)
		cin>>first[i];
		for (i=0;i<m;i++)
		cin>>last[i];
		for (i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(flag[first[i]]&&first[i]==last[j])
			{
				flag[first[i]]=0;
				num[k++]=first[i];
			}
		}
		sort(num,num+k);
		for(i=0;i<k-1;i++)
		cout<<num[i]<<" ";
		cout<<num[k-1];
		cout<<endl;
	}
	
}
		
		
