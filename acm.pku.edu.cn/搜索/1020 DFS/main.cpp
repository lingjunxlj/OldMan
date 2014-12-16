#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n,count[20],q[20],flag,d;

int find()
{
    for(int i = 1;i <= d;i ++)//找到第一个有蛋糕的那一列
        if(q[i] != 0)
            return i;
    return 0;//说明全部分配完
}
bool dfs(int p)
{
    int tt = find(),j;
    if(tt == 0)
        return 1;
    else
    for(int i = 10;i >= 1;i --)
    {
        if(count[i] == 0) continue;
        flag = 0;
        for(j = tt;j < tt + i;j ++)
        {
            if(q[j] < i)
            {
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        for(j = tt;j < tt + i;j ++)
            q[j] -= i;
        count[i] --;

        if(dfs(p + 1))
            return 1;

        for(j = tt;j < tt + i;j ++)
            q[j] += i;
        count[i] ++;
    }
    return 0;
}
int main()
{
    int t,i,x;
    scanf("%d",&t);
    while(t --)
    {
        int s = 0;
        memset(count,0,sizeof(count));
        scanf("%d%d",&d,&n);
        for(i = 1;i <= n;i ++)
        {
            scanf("%d",&x);
            s += x * x;
            count[x] ++;
        }
        if(s != d * d)
        {
            printf("HUTUTU!\n");
            continue;
        }
        for(i = 1;i <= d;i ++)
            q[i] = d;
        if(dfs(1))
            printf("KHOOOOB!\n");
        else
            printf("HUTUTU!\n");
    }
    return 0;
}
