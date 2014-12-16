#include<stdio.h>
int main()
{
    int m,i,a[26],j,k;
    char ch;
    scanf("%d",&m);
    getchar();
    for(i=0;i<m;i++)
    {
        for(k=0;k<26;k++)
            a[k]=0;
        for(j=0;j<=100;j++)
        {
            scanf("%c",&ch);
            if(ch!='\n')
               a[ch-'a']++;
            else 
        {
            int max=a[0];
            for(j=1;j<26;j++)
            {
                 if(a[j]>max)
                     max=a[j];
            }
            for(j=0;j<26;j++)
            {
                if(a[j]==max)
                printf("%c",j+97);
            }
            printf("\n");
            break;
        }
        }
    }
    return 0;
}
