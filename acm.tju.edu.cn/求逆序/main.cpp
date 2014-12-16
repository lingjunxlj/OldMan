#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 200;
const int inf = 0x7ffff;
int a[MAX];
int b[MAX];
int L[MAX];
int R[MAX];
int A[MAX];
int change;
/*
int merge(int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    for (i = 1; i <= n1; i++)
        L[i] = a[p + i - 1];
    for (j = 1; j <= n2; j++)
        R[i] = a[q + j];
    L[n1 + 1] = inf;
    L[n2 + 1] = inf;
    i = j = 1;
    for (k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
        {
            a[k] = R[j++];
            change += q - i + 1;
        }


    }

    return change;
}
void merge_sort(int p, int r)
{

    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}
*/
void merge(long p, long q, long r)
{
        long i, j = 0;
        long beginA = p, endA = q, beginB = q+1, endB = r;

        while(beginA <= endA && beginB <= endB)
        {
                if(a[beginA] <= a[beginB])
                    b[j++] = a[beginA++];
                 else
                 {
                        b[j++] = a[beginB++];
                        change += q - beginA + 1;
                 }
        }
        while(beginA <= endA) {
                b[j++] = a[beginA++];
        }

        while(beginB <= endB) {
                b[j++] = a[beginB++];
        }

        for(i = 0; i < j; i++) {
                a[p+i] = b[i];
        }
}
void mergeSort(long first, long last)
{
        if(first < last) {
                long mid = (first + last) / 2;
                mergeSort(first, mid);
                mergeSort(mid+1, last);
                merge(first, mid, last);
        }
}

int main()
{
    int n;
    cin>>n;


    for (int i = 0; i < n; i++)
        cin>>a[i];
    change = 0;
    mergeSort(0, n - 1);

    printf("change: %d\n",change);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";

}
