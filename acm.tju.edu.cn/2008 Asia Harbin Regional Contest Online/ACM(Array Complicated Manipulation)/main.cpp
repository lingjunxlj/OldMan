#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<stdlib.h>
char s[1000];
bool mod(char b[],int m)
{
    int len=0;
    len=strlen(b);
    int sum=0,p=0;
    for(int i=0;i<len;i++)
    {
        sum=sum*10+b[i]-'0';
        if(sum>=m)
        {
            s[p++]=(sum/m)+'0';
            sum=sum%m;
        }
        else
            s[p++]='0';

    }
    s[p]='\0';
    if(sum==0)
        return true;
    return false;
}
int main()
{
    char a[1000];
    bool biaoz[65538];
    memset(biaoz,true,sizeof(biaoz));
    for(int i=2;i<=65536/2;i++)
    {
        if(biaoz[i])
        {
            for(int j=2;i*j<=65536;j++)
                biaoz[i*j]=false;
       }
    }
    int sushu[65536]={0};
    int len=1;
    for(int q=2;q<=65536;q++)
    {
        if(biaoz[q]==true)
        {
            sushu[len++]=q;
            //printf("%d\n",q);
        }
    }
    while(scanf("%s",a)!=EOF)
    {
        if(strcmp(a,"0")==0)
            break;
        if(strcmp(a,"1")==0)
        {
            printf("no\n");
            continue;
        }
        int flag;
        for(int e=1;e<len;e++)
        {
            flag=0;
            while(mod(a,sushu[e]))
            {
                flag++;
                strcpy(a,s);
                if(flag>=2)
                    break;
            }
            if(flag>=2)
                break;
        }
        if(flag>=2)
            printf("no\n");
        else
            printf("yes\n");

    }
}
