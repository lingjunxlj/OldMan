#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 999999;
const int MAX=1001;
int mat[MAX][MAX];
bool visited[MAX];
int dist[MAX];
void Dijstra(int source, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        dist[i] = mat[source][i];
    }
    for(i = 0; i < n; i++)
        visited[i] = false;
    visited[source] = true;
    for (int k = 0;; k++)
    {
        int next = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                if (next == -1 || dist[i] < dist[next])
                    next = i;
        if (next == -1)
            break;
        visited[next] = true;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] > mat[next][i] + dist[next])
               dist[i] = mat[next][i] + dist[next];
    }
}
int main()
{
    int i, j;
    int a, b, c;
    while(cin>>a>>b>>c)
    {
        for(i = 0; i < MAX; i++)
            for(j = 0; j < MAX; j++){
                if(i != j)
                    mat[i][j] = INF;
                else
                    mat[i][j] = 0;
            }
        for(i = 0; i < a; i++)
        {
            int x, y, w;
            cin>>x>>y>>w;
            if(w < mat[x][y])
            {
                mat[x][y] = w;
                mat[y][x] = w;
            }
        }
        for(i = 0; i < b; i++)
        {
            int t;
            cin>>t;
            mat[0][t] = 0;
            mat[t][0] = 0;
        }
        Dijstra(0, 1001);
        int min = INF;
        for(i = 0; i < c; i++)
        {
            int p;
            cin>>p;
            if(dist[p] < min)
            {
                min = dist[p];
            }
        }
        cout<<min<<endl;
    }
    return 0;
}


