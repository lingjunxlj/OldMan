#include <iostream>
using namespace std;
int a[500002],temp[500002];
long long sum;
void merge(int l,int m,int r)
{
        int i, j, k;
        i=l,j=m+1;
        k=0;

        while(i <= m && j <= r)
        {

            if(a[i] <= a[j])
            {
                temp[k++] = a[i];
                i++;
            }

            else
            {
                temp[k++] = a[j];
                j++;
                sum += m - i + 1;
            }
        }

        while(i <= m)
        {
            temp[k++] = a[i];
            i++;
        }

        while(j<=r)
        {
            temp[k++] = a[j];
            j++;
        }

        for(i=0;i<=r-l;i++)
        {
            a[l + i] = temp[i];
        }
}
void mergesort(int l, int r)
{
       if(l < r)
       {
            int mid = (l + r) / 2;

            mergesort(l, mid);
            mergesort(mid + 1, r);
            merge(l, mid, r);
       }

}
int main()
{
        int n,i;
        while(scanf("%d", &n), n)
        {
            for(i = 0; i < n; i++)
            scanf("%d", &a[i]);

            sum=0;
            mergesort(0, n-1);
            printf("%lld\n", sum);

       }
}
