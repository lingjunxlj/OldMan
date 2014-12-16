#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<vector<int>::value_type> > for_huff_tree;
int main()
{
	int length,N;
	long long ans=0,sum_length=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&length);
		for_huff_tree.push(length);
		sum_length+=length;
	}
	int temp1,temp2;
	for(int i=1;i<N;i++)
	{
		temp1=for_huff_tree.top();
		for_huff_tree.pop();
		temp2=for_huff_tree.top();
		for_huff_tree.pop();
		ans+=temp1+temp2;
		for_huff_tree.push(temp1+temp2);
	}
	ans+=for_huff_tree.top();
	printf("%lld\n",ans-sum_length);
	return 0;
}
