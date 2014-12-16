#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int month2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int num(int x)
{
    int sum=1,i;
    for (i=0;i<x;i++)
    sum*=10;
    return sum;
}
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int y1=0,m1=0,d1=0;
        int y2=0,m2=0,d2=0;
        int i;
        char temp[15];
        cin>>temp;
        for (i=0;i<4;i++)
        y1+=(temp[3-i]-'0')*num(i);
        for (i=0;i<2;i++)
        m1+=(temp[6-i]-'0')*num(i);
        for (i=0;i<2;i++)
        d1+=(temp[9-i]-'0')*num(i);
        cin>>temp;
        for (i=0;i<4;i++)
        y2+=(temp[3-i]-'0')*num(i);
        for (i=0;i<2;i++)
        m2+=(temp[6-i]-'0')*num(i);
        for (i=0;i<2;i++)
        d2+=(temp[9-i]-'0')*num(i);
        int sum=0;
        if (y1>y2||(y1>=y2&&m1>m2)||(y1>=y2&&m1>=m2&&d1>d2))
        {
            int t;
            {
                t=y1;
                y1=y2;
                y2=t;
            }
            {
                t=m1;
                m1=m2;
                m2=t;
            }
            {
                t=d1;
                d1=d2;
                d2=t;
            }
        }

        for (i=y1;i<y2;i++)
        {
            if (i%400==0||(i%100!=0&&i%4==0))
            sum+=366;
            else
            sum+=365;
        }
        int flag1=0,flag2=0;
        if ((y1%400==0)||(y1%100!=0&&y1%4==0))
        flag1=1;
        if ((y2%400==0)||(y2%100!=0&&y2%4==0))
        flag2=1;
        if (flag1)
        {
            for (i=0;i<m1-1;i++)
            {
                sum-=month2[i];
            }
        }
        if (!flag1)
        {
            for (i=0;i<m1-1;i++)
            {
                sum-=month1[i];
            }
        }
        if (flag2)
        {
            for (i=0;i<m2-1;i++)
            {
                sum+=month2[i];
            }
        }
        if (!flag2)
        {
            for (i=0;i<m2-1;i++)
            {
                sum+=month1[i];
            }
        }
        sum=sum-d1+d2;
        printf("%d\n",sum);
    }
}
