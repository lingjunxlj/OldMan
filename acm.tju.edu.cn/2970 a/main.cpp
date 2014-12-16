#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef struct node
{
    char num[105];
    int len;
}Num;
void Change(Num &ob,int n)
{
    int i;
    for(i=0;i<ob.len;i++)
        ob.num[i]-=n;
}
void Rev(Num &ob)
{
    int s,e;
    char temp;
    s=0;
    e=ob.len-1;
    while(s<e)
    {
        temp=ob.num[s];
        ob.num[s]=ob.num[e];
        ob.num[e]=temp;
        s++;
        --e;
    }
    return;
}
Num Sub(Num &a,Num &b)
{
    Num c;
    memset(&c,0,sizeof(c));
    int tw=0,i,l=a.len;
    c.len=a.len;
    for(i=0;i<=l;i++)
    {
        c.num[i]=a.num[i]-b.num[i]-tw;
        if(c.num[i]<0)
        {
            tw=1;
            c.num[i]+=10;
        }
        else
            tw=0;
    }
    while(c.len>1&&!c.num[c.len-1])
        --c.len;
    return c;
}
void Mult_ten(Num &ob)
{
    int i;
    if(ob.len==1&&ob.num[0]==0)
        return;
    for(i=ob.len;i>0;i--)
    {
        ob.num[i]=ob.num[i-1];
    }
    ob.num[0]=0;
    ob.len++;
}
int Cmp(Num &a,Num &b)
{
    Num c;
    memset(&c,0,sizeof(c));
    if(a.len>b.len)
        return 1;
    else if(a.len<b.len)
        return -1;
    else
    {
        int i;
        for(i=a.len-1;i>=0;--i)
        {
            if(a.num[i]>b.num[i])
                return 1;
            else if(a.num[i]<b.num[i])
                return -1;
        }
    }
    return 0;
}
Num Mod(Num &a,Num &b)
{
    Num temp;
    memset(&temp,0,sizeof(temp));
    for(int i=a.len-1;i>=0;--i)
    {
        Mult_ten(temp);
        temp.num[0]=a.num[i];
        while(Cmp(temp,b)>=0)
        {
            temp=Sub(temp,b);
        }
    }
    return temp;
}
int main()
{
    Num a,b,ans,c;
    memset(&a,0,sizeof(a));
    memset(&b,0,sizeof(b));
    while(scanf("%s",a.num)!=EOF)
    {
        a.len=strlen(a.num);
        strcpy(b.num,"2");
        b.len=1;
        Change(a,'0');
        Change(b,'0');
        Rev(a);
        Rev(b);
        c=Sub(a,b);
        Change(c,-'0');
        Rev(c);

        strcpy(b.num,"4");
        b.len=1;
        Change(c,'0');
        Change(b,'0');
        Rev(c);
        Rev(b);
        ans=Mod(c,b);
        Change(ans,-'0');
        Rev(ans);
        if(ans.len==1&&ans.num[0]=='0')
            printf("\"Possible.\"\n");
        else
            printf("\"Not possible.\"\n");
        memset(&a,0,sizeof(a));
        memset(&b,0,sizeof(b));
    }
    return 0;
}
