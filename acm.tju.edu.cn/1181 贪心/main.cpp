#include <iostream>
#include <cstdio>
using namespace std;
int a[1001],b[1001];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    while (scanf("%d",&n),n)
    {
        int i,j;
        for (i=0;i<n;i++)
        scanf("%d",&a[i]);
        for (i=0;i<n;i++)
        scanf("%d",&b[i]);
        int head=0,tail1=n-1,tail2=n-1,sum=0;
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        for (i=0;i<n;i++)
        {
            if (a[head]>b[i])
            {
                sum+=200;
                head++;
            }
            else if (a[head]<b[i])
            {
                tail1--;
                sum-=200;
            }
            else
            {
                for (j=tail1,m=tail2;j>=head;j--,m--)
                {
                    if (a[j]>b[m])
                    {
                        sum+=200;
                        tail1--;
                        tail2--;
                    }
                    else
                    {
                        if (a[j]<b[i])
                        sum-=200;
                        j--;
                        tail1=j;
                        tail2=m;
                        break;

                    }
                }
            }
            if (head>tail1)
            break;
        }
        printf("%d\n",sum);
    }
}



