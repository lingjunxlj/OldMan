#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int t,n;
typedef struct node
{
    short a,b;
    float c;
    node(){}
    node(short aa,short bb,float cc)
    {
        a=aa;
        b=bb;
        c=cc;
    }
    friend bool operator <(node x,node y)
    {
        return x.c>y.c;
    }
}Point;
priority_queue<Point>Q;
Point p;
int gcd (short a , short b)
{
  if (b == 0)
      return a;
  return gcd (b , a % b);
}
int main()
{
    short i,j;
    scanf("%d",&t);
//    int num = 0;
    while(t--)
    {
        scanf("%d",&n);
        printf("1/%d",n);
        while(!Q.empty())
            Q.pop();
        for(i=1;i<=n-1;i++)
            for(j=i+1;j<=n;j++)
            {
                if(i==1&&j==n)
                    continue;
                if(gcd(i,j)==1)
                {
                    Q.push(node(i,j,i*1.0/j));
                //    num ++;
                }
            }
        while(!Q.empty())
        {
            p=Q.top();
            Q.pop();
            printf(",%d/%d",p.a,p.b);
        }
        //cout<<num<<endl;
        printf("\n");
    }
    return 0;
}
