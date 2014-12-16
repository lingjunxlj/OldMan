#include <stdio.h>
#include <stdlib.h>

#define MAX 500001

int n, a[MAX], t[MAX];
__int64 sum;

/* 归并 */
void Merge(int l, int m, int r)
{
    /* p指向输出区间 */
    int p = 0;
    /* i、j指向2个输入区间 */
    int i = l, j = m + 1;
    /* 2个输入区间都不为空时 */
    while(i <= m && j <= r)
    {
        /* 取关键字小的记录转移至输出区间 */
        if (a[i] > a[j])
        {
            t[p++] = a[j++];
            /* a[i]后面的数字对于a[j]都是逆序的 */
            sum += m - i + 1;
        }
        else
        {
            t[p++] = a[i++];
        }
    }
    /* 将非空的输入区间转移至输出区间 */
    while(i <= m) t[p++] = a[i++];
    while(j <= r) t[p++] = a[j++];
    /* 归并完成后将结果复制到原输入数组 */
    for (i = 0; i < p; i++)
    {
        a[l + i] = t[i];
    }
}

/* 归并排序 */
void MergeSort(int l, int r)
{
    int m;
    if (l < r)
    {
        /* 将长度为n的输入序列分成两个长度为n/2的子序列 */
        m = (l + r) / 2;
        /* 对两个子序列分别进行归并排序 */
        MergeSort(l, m);
        MergeSort(m + 1, r);
        /* 将2个排好的子序列合并成最终有序序列 */
        Merge(l, m, r);
    }
}

int main()
{
    int i;
    while(1)
    {
        scanf("%d", &n);
        if (n == 0) break;
        sum=0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        MergeSort(0, n - 1);
        printf("%I64d\n", sum);
    }
    //system("pause");
    return 0;
}
