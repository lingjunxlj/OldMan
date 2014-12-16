#include <stdio.h>
#include <stdlib.h>

#define MAX 500001

int n, a[MAX], t[MAX];
__int64 sum;

/* �鲢 */
void Merge(int l, int m, int r)
{
    /* pָ��������� */
    int p = 0;
    /* i��jָ��2���������� */
    int i = l, j = m + 1;
    /* 2���������䶼��Ϊ��ʱ */
    while(i <= m && j <= r)
    {
        /* ȡ�ؼ���С�ļ�¼ת����������� */
        if (a[i] > a[j])
        {
            t[p++] = a[j++];
            /* a[i]��������ֶ���a[j]��������� */
            sum += m - i + 1;
        }
        else
        {
            t[p++] = a[i++];
        }
    }
    /* ���ǿյ���������ת����������� */
    while(i <= m) t[p++] = a[i++];
    while(j <= r) t[p++] = a[j++];
    /* �鲢��ɺ󽫽�����Ƶ�ԭ�������� */
    for (i = 0; i < p; i++)
    {
        a[l + i] = t[i];
    }
}

/* �鲢���� */
void MergeSort(int l, int r)
{
    int m;
    if (l < r)
    {
        /* ������Ϊn���������зֳ���������Ϊn/2�������� */
        m = (l + r) / 2;
        /* �����������зֱ���й鲢���� */
        MergeSort(l, m);
        MergeSort(m + 1, r);
        /* ��2���źõ������кϲ��������������� */
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
