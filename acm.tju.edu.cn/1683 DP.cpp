#include <iostream>
#include <string>
using namespace std;
#define max(a,b) (a>b?a:b)
char a[1200],b[1200];
int len1,len2,c[1200][1200];
int main()
{
    
    while (scanf("%s %s",&a[1],&b[1])!=EOF)
    {
        len1=strlen(a);
        len2=strlen(b);
        int i,j;
        for (i=0;i<=len1;i++)
        c[i][0]=0;
        for (i=0;i<=len2;i++)
        c[0][i]=0;
        for (i=1;i<=len1;i++)
        for (j=1;j<=len2;j++)
        {
            if (a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
            else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    cout<<c[len1][len2]<<endl;
}
        
