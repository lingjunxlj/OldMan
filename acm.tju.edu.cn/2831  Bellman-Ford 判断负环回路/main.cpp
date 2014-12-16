#include <cstdio>
#define clr(a) memset(a,0,sizeof(a))
#define INF (1<<28)
#define N 505
#define M 6005
int n,m,w;
int e[M][3],ne;
int d[N];

int Bellman_Ford(int e[][3], int m, int n, int d[])
{
    int k, v, flag, i, j;

    for(k = 0; k < n; k++)
    d[k] = INF;

    d[0] = 0;
    for(k = 0; k < n - 1; k++)
    {
        flag = 0;

        for(v = 0; v < m; v++)
        {
            i = e[v][0];
            j = e[v][1];

            if(d[j] > d[i] + e[v][2])
            {
                d[j] = d[i] + e[v][2];
                flag = 1;
            }
        }
        if(!flag)
            return 1;
    }

    for(v = 0; v < m; v++)
        if(d[e[v][1]] - e[v][2] > d[e[v][0]])
            return 0;

    return 1;
 }


 void addEdge(int i, int j, int k)
 {
     e[ne][0] = i;
     e[ne][1] = j;
     e[ne][2] = k;
     ne++;
 }

 int main()
 {
     int i, j, k, t, T;

     scanf("%d", &T);
     while(T--)
     {
         //input
         ne = 0;
         scanf("%d %d %d", &n, &m, &w);
         for(k = 0;k < m + w; k++)
         {
             scanf("%d %d %d", &i, &j, &t);
             if(k < m)
             {
                 addEdge(i, j, t);
                 addEdge(j, i, t);
             }
             else
                 addEdge(i, j, -t);

         }

         if(Bellman_Ford(e, ne, n, d))
            puts("NO");

         else
            puts("YES");
     }

     return 0;
 }
