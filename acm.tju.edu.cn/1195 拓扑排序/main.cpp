#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
const int MAX = 31;
int map[MAX][MAX], degree_in[MAX], degree[MAX], Top[30];
char a, b, c;
bool only, visit[MAX];
int n, m, record, Count, circle;
int toplogical_sort()
{
        int i, j, k;
        only = 1;
        record = 0;
        stack<int>s;
        for (i = 1; i <= n; i++)
        {
            if ( visit[i] && !degree_in[i] )
            {
                s.push(i);
                degree[i] = -1;
            }
        }
        if (s.size() > 1)
        only = 0;
        while(!s.empty())
        {
            int t = s.top();
            Top[record++] = t;
            s.pop();
            for(i = 1; i <= n; i++)
            {
                if(map[t][i] == 1)
                {
                    degree[i]--;
                    for(j = 1; j <= n; j++)
                    {
                        if(visit[j] && !degree[j])
                        {
                            s.push(j);
                            degree[j] = -1;
                        }
                    }
                }
            }
            if(s.size() > 1)
            only = false;
        }
        for (k = 1; k <=n; k++)
        {
            if ( degree[k] > 0 )
            return -1;
        }
        if ( record == n && only )
        return 1;
        return 0;

}
int main()
{
    while (cin>>n>>m)
    {
        if (n==0 && m==0)
        break;
        int i, j, s;
        circle = Count = -1;
        record = 0;
        memset( map, 0, sizeof(map) );
        memset( degree_in, 0, sizeof(degree_in) );
        memset( visit, 0, sizeof(visit) );
        memset( degree, 0, sizeof(degree) );
        for(i = 1; i <= m; i++)
        {
            cin>>a>>c>>b;
            int a1 = (int)(a - 'A') + 1;
            int b1 = (int)(b - 'A') + 1;
            if(circle == -1 && Count == -1)
            {
                visit[a1] = true;
                visit[b1] = true;

                if(map[a1][b1] != 1)
                degree_in[b1]++;

                map[a1][b1] = 1;

                for(j = 1; j <= n; j++)
                degree[j] = degree_in[j];

                s = toplogical_sort();

                if(s == 1)
                Count = i;
                else if( s == -1 )
                circle = i;
            }
        }
        if(s==1)
        {
            cout<<"Sorted sequence determined after "<<Count<<" relations: ";
            for(int i=0;i<n;i++)
            cout<<char(Top[i]+64);
            cout<<"."<<endl;
        }
        if(s==-1)
        cout<<"Inconsistency found after "<<circle<<" relations."<<endl;
        if(s==0)
        cout<<"Sorted sequence cannot be determined."<<endl;
    }

}
