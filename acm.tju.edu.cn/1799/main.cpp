#include <iostream>
#include <cstdio>
using namespace std;
bool cmp(int a,int b)
{return a>b;}
int main()
{
    int n,m,x=0;
    while (scanf("%d %d",&n,&m))
    {
        if (n==0&&m==0)
        break;
        x++;
        int num[51];
        int i;
        for (i=0;i<m;i++)
        scanf("%d",&num[i]);
        sort(num,num+m,cmp);
        int Max=n*m;
        int sum=0;
        for (i=0;i<m;i++)
        {
            if (num[i]==Max)
            {
                sum++;
                Max--;
            }
            else
            Max-=2;
        }
        printf ("Case %d: %d\n",x,sum);
    }
}
