#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int father[1501], n;
struct Node
{
    int f1,f2;
}dp[1505];
//Node记录以当前结点为根的子树的信息
//f1表示当前结点放置士兵的情况，f2表示当前结点不放置士兵的情况
void dfs(int root)
{
    int child;
    dp[root].f2 = 0;//根不放士兵
    dp[root].f1 = 1;//根放士兵
    for(child = 0;child < n;child++ )
    {
        if( father[child] == root )//判断是根节点的孩子
        {
            dfs(child);
            dp[root].f2 += dp[child].f1;//当前节点不放士兵的时候叶子节点一定要放士兵
            dp[root].f1 += min(dp[child].f1,dp[child].f2); //当前的节点放士兵的时候叶子节点要求放与不放的最小值
        }
    }
}
int main()
{
    int  i , j ;
    while(scanf("%d" , &n) != EOF)
    {
        memset(father , 0x7ffffff , sizeof(father));
        int N_father ,N_child ;
        for( i = 0 ; i < n ; i++)
        {
            char lp ,rp, colon ;
            scanf("%d" , &N_father) ;

            int roadnum;
            scanf("%c%c%d%c" ,&colon ,  &lp , &roadnum , &rp );
            for(  j = 0 ; j < roadnum ; j++)
            {
                cin >> N_child ;
                father[N_child] = N_father ;
            }
        }
        int rot = 0 ;
        while(father[rot] != -1)
        {
            rot = father[rot];
        }//找到根节点
         // cout<<root<<endl;
    dfs(rot) ;
    cout<<min(dp[rot].f1,dp[rot].f2)<<endl;
    }
}
