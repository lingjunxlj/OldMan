#include <cstdio>
#include <cstring>
char a[61];
int b[61];
int main()
{
    int len, i, flag, l, temp;
    while(scanf("%s", a) != EOF)
    {
        len=strlen(a);
        l=len+1;
        memset(b,0,sizeof(int));
        flag=1;
        for(i=len-1;i>=0;i--)
            b[i]=(a[i]-'0')*l;

        for(i=len-1;i>=0;i--)
        {
            if(b[i]>9)
            {
                temp=b[i]/10;
                b[i]=b[i]%10;
                b[i-1]=b[i-1]+temp;
            }
            if(b[i]!=9)
            {
                printf("%s is not cyclic\n",a);
                flag=0;
                break;
            }
        }
        if(!flag)
            continue;
        if(len==8&&a[0]=='1'&&a[1]=='1'&&a[2]=='1')
        {
            printf("%s is not cyclic\n",a);
            flag=0;
        }
        if(flag)
            printf("%s is cyclic\n",a);
    }
    return 0;
}
