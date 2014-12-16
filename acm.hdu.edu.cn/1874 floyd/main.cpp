#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int table[201][201];   //记录路径
int s[201][201];  //记录两点间的最短距离
int n, m;
void Floyd()
{
        int i,j,k;
        for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                        s[i][j] = table[i][j];

        for(k=0;k<n;k++)
                for(i=0;i<n;i++)
                        for(j=0;j<n;j++)
                                if(s[i][j] > s[i][k] + s[k][j])
                                        s[i][j] = s[i][k] + s[k][j];
}

int main()
{

    while (cin>>n>>m)
    {
        int a, b, c, start, end;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    table[i][j] = 0;
                else
                    table[i][j] = 0x7fff;
            }
        memset (s, 0x7fff, sizeof(s));
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b>>c;
            if (c < table[a][b])
            table[a][b] = table[b][a] = c;
        }
        cin>>a>>b;
        start = a<b?a:b;
        end = a>b?a:b;
        Floyd();
        if (s[start][end] == 0x7fff)
            cout<<-1<<endl;
        else
            cout<<s[start][end]<<endl;
    }
}
