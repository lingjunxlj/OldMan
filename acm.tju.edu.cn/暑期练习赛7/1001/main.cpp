#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int Max = 3026;
int p[Max];
int rank[Max];
int root[Max];
int rt[Max];
void make_set(int x)
{
    p[x] = x;
    rank[x] = 0;
}
int find_set(int x)
{
    if (x != p[x])
        p[x] = find_set(p[x]);
    return p[x];
}
void link (int x, int y)
{
    if (rank[x] > rank[y])
        p[y] = x;
    else
        p[x] = y;

    if (rank[x] == rank[y])
        rank[y] += 1;
}
void Union(int x, int y)
{
    link(find_set(x),find_set(y));
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int i;
        int x, y;
        for (i = 1; i < 3026; i++)
        make_set(i);

        for (i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
        memset (root, 0, sizeof(root));
        int k = 0;
        for (i = 1; i <= n; i++)
        {
            root[find_set(i)]++;
            if (find_set(i) == i)
            {
                rt[k++] = i;
                //printf("%d---rt\n",rt[k-1]);


            }

        }
        int sum = 0;
        for (i = 1; i <= n; i++)
        {
            if (root[i] > 0)
            {
                //printf("%d---root\n",root[i]);
                double a = root[i];
                //printf("%lf----a\n",a/4);
                sum += (int)ceil(a / 4.0);
            }

        }
        printf("%d\n",sum);
    }
}

