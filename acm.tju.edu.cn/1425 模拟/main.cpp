#include<iostream>
using namespace std;

int main()
{
    int sum,a,b,c,d;
    while(1)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(!a && !b && !c && !d)break;
        sum=1080;
        a-=b;
        while(a<0)a+=40;
        sum+=9*a;

        b=c-b;
        while(b<0)b+=40;
        sum+=9*b;

        c-=d;
        while(c<0)c+=40;
        sum+=9*c;

        printf("%d\n",sum);
    }
    return 0;
}


