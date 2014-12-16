#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> >huff;
int main()
{
    int len,n,i;
    long long ans=0,sum=0;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&len);
        huff.push(len);
        sum+=len;
    }
    int temp1,temp2;
    for (i=1;i<n;i++)
    {
        temp1=huff.top();
        huff.pop();
        temp2=huff.top();
        huff.pop();
        ans+=temp1+temp2;
        huff.push(temp1+temp2);
    }
    ans+=huff.top();
    printf("%lld\n",ans-sum);
}
