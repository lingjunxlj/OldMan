#include <cstdio>
#include <string>
char map[120];
int main()
{
    int n,x=0,i;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        x++;
        gets(map);
        int len=strlen(map);
        int j;
        if (map[0]>='a'&&map[0]<='z')
        map[0]-=32;
        for (i=0;i<len-1;i++)
        {
            if ((map[i]==' ')&&(map[i+1]>='a'&&map[i+1]<='z'))
            map[i+1]-=32;
        }

        printf("Case #%d: ",x);

        printf("%s\n",map);
    }
}
