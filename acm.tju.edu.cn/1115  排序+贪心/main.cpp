#include <iostream>
#include  <cstdio>
#include <cmath>
using namespace std;
typedef struct w
{
    float x;
    float y;
}sp;
sp text[1001];
bool cmp(sp a,sp b)
{
    return a.x<b.x;
}
int main()
{
    int n,d,a,b,num=0,ans,i;
    sp temp;
    bool flag;
    while (scanf("%d %d",&n,&d))
    {
        if (n==0&&d==0)
        break;
        num++;
        flag=1;
        ans=1;
        if (d<=0)
        flag=0;
        for (i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            if (d*d-b*b<0)
            flag=0;
            else
            {
                text[i].x=a-sqrt((float)(d*d-b*b));
                text[i].y=a+sqrt((float)(d*d-b*b));
            }
        }
        if (!flag)
        printf("Case %d: %d\n",num,-1);
        else
        {
            sort(text,text+n,cmp);
            temp.x=text[0].x;
            temp.y=text[0].y;
            for (i=0;i<n;i++)
            {
                if (text[i].x>temp.y)
                {
                    ans++;
                    temp.x=text[i].x;
                    temp.y=text[i].y;
                }
                if (text[i].y<temp.y)
                temp.y=text[i].y;
                if (text[i].x>temp.x)
                temp.x=text[i].x;
            }
            printf("Case %d: %d\n",num,ans);
        }
    }
}


