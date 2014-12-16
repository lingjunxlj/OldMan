#include <cstdio>
const int MAXN=32005;
struct TPeople
{
    int dir;
    double pos;
    char name[252];
}people[MAXN];
double len, spd;
int n;
int main()
{
    int i;
    char ch;
    while (scanf("%d", &n),n)
    {
        double rlt=0,temp;
        int k=0,change=0,dir;
        scanf("%lf %lf\n",&len,&spd);
        for (i=0;i<n;i++)
        {
            scanf("%c %lf %s\n",&ch,&people[i].pos,people[i].name);
            people[i].dir=-1;

            if (ch=='p'||ch=='P')
            people[i].dir=1;

            if (people[i].dir==1)
            temp=(len-people[i].pos)/spd;

            else temp=people[i].pos/spd;

            if (rlt<temp)
            rlt=temp,k=i;
        }
        dir=people[k].dir;
        for (i=k+dir;i>=0&&i<n;i+=dir)
        if (people[i].dir!=people[k].dir)
        change+=dir;
        printf("%13.2lf %s\n",double(int(rlt*100))/100,people[k+change].name);
    }
}

