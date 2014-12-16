#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=14;
int num[MAX];
int main()
{
	int n,x=0;
	while (cin>>n)
	{
		if (n==0)
		break;
		if (x!=0)
		cout<<endl;
		x++;
		int i;
		for (i=0;i<n;i++)
		cin>>num[i];
		sort(num,num+n);
		do
		{
			int flag=1;
			for (i=0;i<5;i++)
			if (num[i+1]<num[i])
			flag=0;
            if (flag)
			{
				for (i=0;i<5;i++)
				cout<<num[i]<<" ";
				cout<<num[5]<<endl;
			}
		}
		while (next_permutation(num,num+n));
	}
}

