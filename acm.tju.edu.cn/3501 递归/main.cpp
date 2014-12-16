#include<iostream>
using namespace std;
int n, k, p;
int find(int n,int k)
{
	int temp = n;
	while(temp < k)
	{
		temp =  temp* 2;
	}
	return temp/2;
}
int solve(int temp1, int q, int temp2)
{
	if(temp1 == n)
	{
		if(q%2 == 0)
		{
			int temp = temp1+q/2;
			return temp;
		}
		else return ((q+1)/2);
	}
	if(q <= temp2 * 2)
	{
		if(q%2 == 0)
        return (temp1 + q/2);
	    else
        return solve(temp1/2,(q+1)/2,temp1/2);
	}
	else
    return solve(temp1/2,q-temp2,temp1/2);
}

int main()
{
	int i,j,q;
	int temp1,temp2;
	while(scanf("%d%d%d",&n,&k,&p) != EOF)
	{
		temp1 = find(n,k);
		temp2 = k - temp1;
        for(i = 0;i < p;i++)
		{
			scanf("%d",&q);
			printf("%d\n",solve(temp1,q,temp2));
		}
	}
}
