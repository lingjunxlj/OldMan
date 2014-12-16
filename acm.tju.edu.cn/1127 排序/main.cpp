#include <iostream>
#include <cstdio>
using namespace std;
char map[201][151];
int num[201];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for (i=0;i<m;i++)
    {
        scanf("%s",map[i]);
    }
    memset(num,0,sizeof(num));
    for (k=0;k<m;k++)
    for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
    if (map[k][i]>map[k][j])
    num[k]++;
    int min=1000000,l;
    for (i=0;i<m;i++)
    {
        for (j=0;j<m;j++)
        {
            if(num[j]<min)
            {
                min=num[j];
                l=j;
            }
        }
        printf("%s\n",map[l]);
        num[l]=1000000;
        min=1000000;
    }
}

