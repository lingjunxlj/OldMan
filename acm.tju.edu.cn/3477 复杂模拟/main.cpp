#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, L;
int c[MAX];
struct node
{
     int T;
     int S;
}point[MAX];
bool cmp (node x, node y)
{
    return x.T < y.T;
}
int cal(int p, int n, int d)
{
     if (p > n)
         return p + (d  -(p - n)) / 2;
     return n + ( d - (n  -p) ) / 2;
}
int main()
{
     int i, j, mx, s, t;
     while (scanf ("%d %d", &L, &N) != EOF)
     {
         for (i = 1; i <= N; i++)
             scanf ("%d %d", &point[i].T, &point[i].S);

         sort(point + 1, point + N + 1,cmp);
         point[0].T = 0;
         point[0].S = 1;
         point[N+1].T = L;
         point[N+1].S = L + 1;
         c[N + 1] = point[N + 1].S;

         for (i = N; i >= 0; i--)
             c[i] = min(point[i].S, c[i+1] + point[i+1].T - point[i].T);
         s = 1;
         mx = 1;

         for (i = 1; i <= N + 1; i++)
         {
             t = min(c[i], s + point[i].T - point[i-1].T);
             mx = max(mx, cal(s, t, point[i].T - point[i-1].T));
             s = t;
         }
         printf ("%d\n", mx);
     }
}
