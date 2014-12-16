#include <cstdio>
#include <cstring>
int n;
char str[101][101];
char mystrrev(char str[])
{
    int i,l;
    l=strlen(str);
    for(i=0;i<l/2;i++)
    {
        char temp;
        temp=str[i];
        str[i]=str[l-1-i];
        str[l-1-i]=temp;
    }
}
int search(char minstr[])
{
    int i,j;
    int lenth=strlen(minstr);
    int reslen=lenth;
    bool flag;
    char revstr[101],sonstr[101];
    while(reslen>0)
    {
        for(i=0;i<=lenth-reslen;i++)
        {
            flag=true;
            strncpy(sonstr,minstr+i,reslen);
            strncpy(revstr,minstr+i,reslen);
            sonstr[reslen]='\0';revstr[reslen]='\0';
            mystrrev(revstr);
            for(j=0;j<n;j++)
            {
                if(strstr(str[j],sonstr)==NULL&&strstr(str[j],revstr)==NULL)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) return reslen;
        }
        reslen--;
    }
    return 0;
}
int main()
{
    int t,i,j,res;
    char minstr[101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int minlen=120;
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            int lenstr=strlen(str[i]);
            if(lenstr<minlen)
            {
                strcpy(minstr,str[i]);
                minlen=lenstr;
            }
        }
        res=search(minstr);
        printf("%d\n",res);
    }
}
