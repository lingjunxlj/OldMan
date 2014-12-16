#include <cstdio>
int J(int n,int m)
{
    int s=1,i;
    for (i=2;i<n;i++)
    s=(s+m-1)%i+1;
    return s+1;
}
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        int m=1;
        while (1)
        {
            if (J(n,m)==2)
            break;
            m++;
        }
        printf("%d\n",m);
    }
}
/*在没有明白约瑟夫问题之前,只能用模拟来做.
      约瑟夫问题是这样的:
      假设n个人,编号为1到n,排成一个圈,顺时针从1开始数字m,数到m的人杀了,剩下的人继续游戏.活到最后的一个人是胜利者.一般来说需要编程求解最后一个人的编号.
      思路是这样的:
     假设当前剩下i个人(i<=n),显然这一轮m要挂(因为总是从1开始数).经过这一轮,剩下的人是:1 2 3 ... m- 1 m + 1 ... i, 我们将从m+1开始的数映射成1， 则m+2对应2， n对应i - m， 1对应成i - m + 1  m - 1对应i - 1，那么现在的问题变成了已知i - 1个人进行循环报数m，求出去的人的序号。假设已经求出了i- 1个人循环报数下最后一个出去的人的序号X0，那么它在n个人中的序号X1=(X0+ m - 1) % n + 1,  最初的X0=1 ,反复迭代X0和X1可以求出.
     简单约瑟夫问题的解法:
#include <stdio.h >
main()
{
    int n, m,i, s=0;
    printf( "N  M  =  "); scanf("%d%d ",&n,&m);
    for(i=2;i<=n;i++)s=(s+m)%i;
    printf("The winner is %d\n ", s+1);
}  */
