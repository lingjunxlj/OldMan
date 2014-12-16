#include <cstdio>
int main()
{
    int i,j,k;
    int N,a[100][100],tmp;

    scanf("%d",&N);
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    scanf("%d",&a[i][j]);

    for(k=0;k<N;k++)
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(a[i][j]>a[i][j+1])
            {
                tmp=a[i][j];
                a[i][j]=a[i][j+1];
                a[i][j+1]=tmp;
            }
        }
    }
    for(j=0;j<N;j++)
    for(i=0;i<N-1;i++)
    if(a[i][N/2]>a[i+1][N/2])
    {
        tmp=a[i][N/2];
        a[i][N/2]=a[i+1][N/2];
        a[i+1][N/2]=tmp;
    }
    printf("%d\n",a[N/2][N/2]);
}
