#include <cstdio>
#include <string>
int zhouqi[201];
int n,a[201];
char str[201],str1[201];
void period(int n)
{
    int i,j,k;
    for (i=0;i<n;i++)
    {
        for (j=a[i],k=1;j!=i+1;j=a[j-1],k++);
        zhouqi[i]=k;
    }
}
int main()
{

    while (scanf("%d",&n),n)
    {
        int i,j,k;

        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        period(n);
        while (scanf("%d",&k),k)
        {
            getchar();
            for (i = 0; i < n; i++)
            {
                scanf("%c", &str[i]);
                if (str[i] == '\n')
                {
                    break;
                }
            }
            while (i < n)
            {
                str[i++] = ' ';
            }
            int m,b;
            str[i]=str1[i]=0;
            for (i=0;i<n;i++)
            {
                m=k%zhouqi[i];
                for (j=0,b=i;j<m;j++)
                {
                    b=a[b]-1;
                }
                str1[b]=str[i];
            }
            printf("%s\n",str1);
        }
        printf("\n");
    }
}
