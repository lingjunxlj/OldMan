#include<iostream>
using namespace std;
#define INF 0x7f
#define MAX 101
int a[MAX];
int ans;
void dfs(int locate,int sum,int x,int n,int s)
{
   int i;
   if( n<sum ) return ;
   if( n==sum && locate>=3 )
   {
      ans ++;
      return ;
   }
   for(i=x;i<=s;i++)
   {
      sum += i;
      dfs(locate+1,sum,i+1,n,n-sum);
      sum -= i;
   }
}

int main()
{
    int i,j;
    int n;
    for (i=3;i<=100;i++)
    {
        ans=0;
        dfs(1,0,1,i,i);
        a[i]=ans;

    }
    while( scanf("%d", &n),n )
    {

        printf("%d\n",a[n]);
    }

}
/*
这是打出来的表
#include<iostream>
using namespace std;

int a[100] = {1,1,2,3,4,5,7,9,11,14,17,21,26,31,
               37,45,53,63,75,88,103,121,141,
               164,191,221,255,295,339,389,
               447,511,584,667,759,863,981,
               1112,1259,1425,1609,1815,
               2047,2303,2589,2909,3263,3657,
               4096,4581,5119,5717,6377,7107,
               7916,8807,9791,10879,12075,
               13393,14847,16443,18199,20131,
               22249,24575,27129,29926,32991,
               36351,40025,44045,48445,53249,
               58498,64233,70487,77311,84755,
               92863,101697,111321,121791,133183,
               145577,159045,173681,189585,
               206847,225584,245919,267967,
               291873,317787,345855,376255,
               409173,444792};

int main()
{
   int n;

   while( scanf("%d", &n),n )
   {
      printf("%d\n", a[n-3]);
   }
}
*/
