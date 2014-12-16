#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int clique( int n, int *u, bool mat[][55], int size, int &max, int &bb, int *res, int *rr, int *c)
{
    int i, j, vn, v[55];
    if (n)
    {
        if (size + c[u[0]] <= max)
            return 0;//要考虑的顶点数比已经有的最大团数还要少，不再计算下去
        for (i = 0; i < n + size - max && i < n; i++)
        {
            for (j = i + 1, vn = 0; j < n; j++)
            {
                if (mat[u[i]][u[j]])
                    v[vn++] = u[j];
            }
            rr[size] = u[i];
            clique(vn, v, mat, size + 1, max, bb, res, rr, c);
            if (bb)
                return 0;
        }
    }
    else if (size > max)
    {
        max = size;
        for (i = 0; i < size; i++)
        {
            res[i] = rr[i];//res，用来存最大团的，也就是说rr存的是当前的最大团顶点
        }
        bb = 1;//搜索下去max只会变小，所以用bb标志，停止搜索
    }
    return 0;
}
int maxclique(int n,bool mat[][55],int *ret)
{
    int max = 0, bb, c[55], i, j;
    int vn, v[55], rr[55];
    for (c[i = n - 1] = 0; i >= 0; i--)
    {
        for (vn = 0, j = i + 1; j < n; j++)
        {
            if (mat[i][j])
                v[vn++] = j;
        }
        bb = 0;
        rr[0] = i;
        clique(vn, v, mat, 1, max, bb, ret, rr, c);
        c[i] = max;
    }
    return max;
}

int main()
{
    int n, i, j;
    bool mat[55][55];
    int ret[55];
    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);

        printf ("%d\n", maxclique(n, mat, ret));
    }
    return 0;
}
