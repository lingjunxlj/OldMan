#include <iostream>
#include<cstring>
using namespace std;
char s[1000010];
long next[1000010],a[1000010];
int main()
{
    long n,i,j,len,num,x=0;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        x++;
        scanf("%s",s);
        i=0;j=-1;next[0]=-1;
        len=strlen(s);
        int sum=0;
        while(i<len)
        {
            if(j==-1 || s[i]==s[j])
            {
                ++i;
                ++j;
                next[i]=j;
            }
            else j=next[j];
        }
        int t;
        for (j=1;j<=len;j++)
        for (i=1;i<=len-j;i++)
        {
            t=i-next[i];
            if(i%t==0&&i/t>1)
            printf("%d \n",next[i]);
        }

    }
return 0;
}
