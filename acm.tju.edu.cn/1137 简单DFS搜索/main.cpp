#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int num[101],ans[101],res,n;
void DFS(int p)
{
    int i,j;
    if (res<p && num[p-1]!=n)
    return;
    for (i=p-1;i>=0;i--)
    {
        num[p]=num[p-1]+num[i];
        if (num[p]<n)
        DFS(p+1);
        else if (num[p]==n)
        {
            for (j=0;j<=p;j++)
            ans[j]=num[j];
            res=p;
            return;
        }
    }
}
int main()
{

    while (cin>>n,n)
    {
        if (n==1){
        printf("1\n");
        continue;
        }
        int i;
        memset(num,0,sizeof(num));
        num[0]=1;
        res=100;
        DFS(1);
        for (i=0;i<res;i++)
        printf("%d ",ans[i]);
        printf("%d\n",ans[res]);
    }
}
