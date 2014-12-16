#include <stdio.h>
#include <iostream>

char s[1005][1005];
bool use[1005][1005];
int c,r,tx,ty,ans,sum,f[4][2] = {0,1,1,0,0,-1,-1,0};

void dfs(int x,int y)
{
for(int i = 0;i <= 3;i ++)
{
   int aa = x + f[i][0];
   int bb = y + f[i][1];
   if(aa >= 0 && aa <= r && bb >= 0 && bb <= c && s[aa][bb] == '.' && !use[aa][bb])
   {
    use[aa][bb] = 1;
    sum ++;
    if(ans < sum) {ans = sum;tx = aa,ty = bb;}
    dfs(aa,bb);
    use[aa][bb] = 1;
    sum --;
   }
}
}
int main()
{
int i,j,t;
scanf("%d",&t);
while(t --)
{
   scanf("%d%d",&c,&r);
   for(i = 0;i < r;i ++)
    scanf("%s",s[i]);
   memset(use,0,sizeof(use));
   for(i = 0;i < r;i ++)
    for(j = 0;j < c;j ++)
     if(s[i][j] == '.')
     {
      ans = 0;
      sum = 0;
      use[i][j] = 1;
      dfs(i,j);
      goto loop;
     }
loop:;
memset(use,0,sizeof(use));
use[tx][ty] = 1;
ans = 0;
sum = 0;
dfs(tx,ty);
printf("Maximum rope length is %d.\n",ans);
}
return 0;
}
