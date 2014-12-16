#include<iostream>
#include<algorithm>
using namespace std;
int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int*)b;
}
int main()
{
    int n;
    int max;
    int a[1000];
    while(scanf("%d",&n),n)
    {
        int i,j,k;
        for (i=0;i<n;i++)
        scanf("%d",&a[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        max=0;
        bool ok=false;
        for (i=n-1;i>=2;i--)
        {
            if (ok)
            break;
            for (j=i-1;j>=1;j--)
            {
                if (ok)
                break;
                for (k=0;k<j;k++)
                {
                    if (ok)
                    break;
                    if (a[i]<a[j]+a[k])
                    break;
                    if (a[i]==(a[j]+a[k]) )
                    {
                        max=a[i];
                        ok=true;
                        break;
                    }
                }
            }
        }
        if (ok)
        printf("%d\n",max);
        else
        printf("-1\n");
    }
}
