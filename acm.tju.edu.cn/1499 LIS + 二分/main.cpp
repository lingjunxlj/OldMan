#include <iostream>
using namespace std;
#define MAX 40005
int numbers[MAX],dp[MAX],p,n,b[MAX],Left,Right,mid,blen,num;
void DP()
{

	int ans = dp[1];
	for (int i = 1;i <= p;i++)
	{
		num = numbers[i];
		Left = 1;
		Right = blen;
		while (Right >= Left)
		{
			mid = (Left + Right)/2;
			if (b[mid] >= num)
				Right = mid - 1;
			else
				Left = mid + 1;
		}

		dp[i] = Left;
		b[Left] = num;
		if (Left > blen)
			blen = Left;
		if (ans < dp[i])
			ans = dp[i];
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n;
	while (n--)
	{
        blen = 0;
        cin>>p;
        for (int i = 1;i <= p;i++)
        cin>>numbers[i];
        DP();
	}
}

