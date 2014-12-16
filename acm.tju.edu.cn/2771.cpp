#include <cstdio>
#include <string>
using namespace std;
char a[1000001];
int b[1000001];
int main()
{
    int x;
    scanf ("%d",&x);
    getchar();
    while (x--)
    {
        
        gets(a);
        int i,len=strlen(a);
        memset(b,0,sizeof (a));
        for (i=0;i<len;i++)
        b[a[i]]++;
        int max=0;
        char l;
        for (i=64;i<=123;i++)
        if (b[i]>max)
        {
            max=b[i];
            l=i;
        } 
        printf ("%c\n",l);
    }
}
        
