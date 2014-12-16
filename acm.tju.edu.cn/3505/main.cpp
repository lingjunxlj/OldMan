#include<iostream>
using namespace std;

#define INF 0x7f7f7f7f
#define MAX 100005

char command[10];
int num[MAX];
int c[MAX];
int n;

int lowbit(int t)
{
   return t & ( t ^ (t - 1) );
}

int sum(int end)
{
   int sum = 0;
   while( end>0 )
   {
      sum +=c[end];
      end -= lowbit(end);
   }
   return sum;
}

void change(int p,int num)
{
   while( p<=n )
   {
      c[p] += num;
      p += lowbit(p);
   }
}

int main()
{
   int i,j;
   int ca;
   int suma,sumb;
   int q;
   int p,key;

   scanf("%d", &ca);

   while( ca-- )
   {
      scanf("%d", &n);

      memset(num,0,sizeof(num));
      memset(c,0,sizeof(c));

      for(i=1;i<=n;i++)
      {
         scanf("%d", &num[i]);
         change(i,num[i]);
      }
      scanf("%d", &q);
      for(i=1;i<=q;i++)
      {
         cin>>command;
         cin>>p>>key;
         if( command[0]=='I' )
         {
            suma = sum(key);
            sumb = sum(p-1);
            printf("%d\n",suma - sumb);
         }
         else if( command[0]=='A' )
         {
            num[p] += key;
            change(p,key);
         }
         else if( command[0]=='D' )
         {
            if( num[p]<key )
            {
               change(p,-num[p]);
               num[p] = 0;
            }
            else
            {
               change(p,-key);
               num[p] -= key;
            }
         }
      }
   }
}
