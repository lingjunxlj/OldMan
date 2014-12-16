#include<iostream>
#define MAX 100001
#include <algorithm>
#define lowbit(x) (x&(-x))
using namespace std;

__int64 sum[MAX],tree[MAX];
int sum1[MAX],tree1[MAX];
typedef struct
{
  int data;
  int pos;
}point;

bool GY (point a , point b)
{
  return a.data < b.data;
}

__int64 query(int x)
{
    __int64 sum = 0;
    while (x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

void add(int a,int b,int n)
{
    while (a <= n)
    {
        tree[a] += b;
        a += lowbit(a);
    }
}


int query1(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += tree1[x];
        x -= lowbit(x);
    }
    return sum;
}

void add1(int a,int b,int n)
{
    while (a <= n)
    {
        tree1[a] += b;
        a += lowbit(a);
    }
}


int main()
{
    int n , i;
    __int64 ans , x , k;
    point p[ MAX ];
    while (scanf("%d",&n) == 1)
    {
        tree[0] = sum[0] = 0;
        tree1[0] = sum1[0] = 0;

        for(i=1;i<=n;i++)
        {
            scanf("%d",&p[ i ].data);
            p[ i ].pos = i;
            sum[i] = sum[i-1] + p[ i ].data;
            tree[i] = sum[i] - sum[i - lowbit(i)];

            sum1[i] = sum1[i-1] + 1;
            tree1[i] = sum1[i] - sum1[i - lowbit(i)];
        }
        sort (p + 1 , p + n + 1 , GY);

        ans = 0;
        for (i = 1;i <= n;++ i)
        {
            k = query (p[ i ].pos - 1);
            if (k)
            {
               x = query1 (p[ i ].pos - 1);
               ans = ans + k + x * p[ i ].data;
            }
           add (p[ i ].pos , - p[ i ].data , n);
           add1 (p[ i ].pos , - 1 , n);
        }
        printf ("%I64d\n" , ans);
    }
    return 0;
}
