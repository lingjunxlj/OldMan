#include <cstdio>
int f[5850];
int min (int x,int y)
{
    return x>y?y:x;
}
int main()
{
    int i,a,b,c,d;
    a=b=c=d=1;
    for(i=1;i<8;i++)
    f[i]=i;
    for(i=8;i<5850;i++)
    {
        while(2*f[a]<=f[i-1])
        a++;
        while(3*f[b]<=f[i-1])
        b++;
        while(5*f[c]<=f[i-1])
        c++;
        while(7*f[d]<=f[i-1])
        d++;
        f[i]=min(2*f[a],min(3*f[b],min(5*f[c],7*f[d])));
    }
    while(scanf("%d",&i),i)
    {
        printf("The %d",i);
        if(i%10 == 1 && i%100 != 11)
        printf("st");
        else if(i%10 == 2 && i%100 != 12)
        printf("nd");
        else if(i%10 == 3 && i%100 != 13)
        printf("rd");
        else printf("th");
        printf(" humble number is %d.\n",f[i]);
    }

}

