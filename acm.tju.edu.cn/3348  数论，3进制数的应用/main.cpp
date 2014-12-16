#include<iostream>
#include<vector>
using namespace std;

int m[31];
int num[31];
vector<int> iv1,iv2;

int main()
{
	m[0]=1;
	for(int i=1;i<30;i++)
		m[i]=m[i-1]*3;
    int n,len;
	while(cin>>n)
	{
		iv1.clear();
		iv2.clear();
		len=0;
		memset(num,0,sizeof(num));
        while(n)
		{
           num[len++]=n%3;
		   n=n/3;
		}
		for(int i=0;i<=len;i++)
		{
			num[i+1]+=num[i]/3;
			num[i]=num[i]%3;
			if(num[i]==1)
					iv1.push_back(m[i]);
			if(num[i]==2)
			{
				iv2.push_back(m[i]);
				num[i+1]++;
			}
		}
		printf("%d",iv2.size());
		for(int i=0;i<iv2.size();i++)
			printf(" %d",iv2[i]);
		printf("\n");
		printf("%d",iv1.size());
		for(int i=0;i<iv1.size();i++)
			printf(" %d",iv1[i]);
		printf("\n");
	}
	return 0;
}
