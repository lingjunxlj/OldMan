/*
struct node
{
    friend bool operator< (node n1, node n2)
    {
        return n1.priority < n2.priority;
    }
    short priority;
    short value;
};
自定义优先队列
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
short t,n;
typedef struct node
{
    short a;
    short b;
    float c;
    node(){}
    node(short aa,short bb,float cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
    friend bool operator <(node x,node y)
    {
        return x.c>y.c;
    }
}Point;
priority_queue<Point>Q;
Point p;
short gcd (short a , short b)
{
  if (b == 0)
      return a;
  return gcd (b , a % b);
}
int main()
{
    short i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("1/%d", n);
        while(!Q.empty())
            Q.pop();

        for(i = 1; i <= n - 1; i++)
            for(j = i + 1; j <= n; j++)
            {
                if(i == 1 && j == n)
                    continue;

                if(gcd(i, j) == 1)
                {
                    Q.push( node(i, j, i * 1.0 / j) );

                }
            }
        while(!Q.empty())
        {
            p = Q.top();
            Q.pop();
            printf(",%d/%d", p.a, p.b);
        }
        cout<<endl;
    }
}
